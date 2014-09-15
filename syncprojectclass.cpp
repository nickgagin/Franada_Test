#include "syncprojectclass.h"

SyncProjectClass::SyncProjectClass()
{
};

SyncProjectClass::SyncProjectClass(QString filepath)
{
    loadFromXmlProjectFile(filepath);
}

bool SyncProjectClass::addChannelToList(Channel_Info &channel_info)
{
    int lengthOfList = 0;

    lengthOfList = channelList.length();


    qDebug() << "Element:" << channelList.length();
    qDebug() << "Channel Name:\t" << channel_info.name;
    qDebug() << "Videofile path:\t" << channel_info.filePath;
    qDebug() << "Syncronized frame:\t" << channel_info.frame;


    channelList.append(channel_info);
    if(lengthOfList < channelList.length()) return true; else return false;
}

QString SyncProjectClass::getProjDescription()
{
    return description;
}

int SyncProjectClass::getLengthOfChannelList()
{
    return channelList.length();
}

QString SyncProjectClass::getLocation()
{
    return location;
}

QString SyncProjectClass::getNavigationFilePath()
{
    return navigationFilePath;
}

QDateTime SyncProjectClass::getProjectDate()
{
    return dateTime;
}

QString SyncProjectClass::getProjectFilePath()
{
    return projectFilePath;
}

bool SyncProjectClass::loadFromXmlProjectFile(QString filepath)
{
    if(filepath.isEmpty()){
        qDebug() << "Путь к файлу проекта пуст!";
        return false;
    }

    projectFilePath = filepath;
    parseXml();
    return true;
}

bool SyncProjectClass::saveToXmlProjectFile()
{
    QString outputFile = "";

    int i = 0;
    QXmlStreamWriter writer(&outputFile);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("sync_project");

        writer.writeStartElement("date");
        writer.writeCharacters(dateTime.toString("yyyy.MM.dd"));
        writer.writeEndElement();

        writer.writeStartElement("location");
        writer.writeCharacters(location);
        writer.writeEndElement();

        writer.writeStartElement("description");
        writer.writeCharacters(description);
        writer.writeEndElement();

        writer.writeStartElement("navigation");
        writer.writeCharacters(navigationFilePath);
        writer.writeEndElement();

        writer.writeStartElement("channel_list");
        writer.writeAttribute("count",QString::number(channelList.size(),10));

        for(i = 0; i< channelList.size(); i++)
        {
            writer.writeStartElement("channel");
                writer.writeStartElement("name");
                writer.writeCharacters(channelList[i].name);
                writer.writeEndElement();

                writer.writeStartElement("filename");
                writer.writeCharacters(channelList[i].filePath);
                writer.writeEndElement();

                writer.writeStartElement("signal");
                writer.writeCharacters(QString::number(channelList[i].signal,10));
                writer.writeEndElement();

                writer.writeStartElement("frame");
                writer.writeCharacters(QString::number(channelList[i].frame,10));
                writer.writeEndElement();

                writer.writeStartElement("clap");
                writer.writeCharacters(QString::number(channelList[i].clap,10));
                writer.writeEndElement();

                writer.writeStartElement("flash");
                writer.writeCharacters(QString::number(channelList[i].flash,10));
                writer.writeEndElement();

                writer.writeStartElement("geometry_info");
                    writer.writeStartElement("rotX");
                    writer.writeCharacters(QString::number(channelList[i].geometryInfo.rotX,'f',4));
                    writer.writeEndElement();

                    writer.writeStartElement("rotY");
                    writer.writeCharacters(QString::number(channelList[i].geometryInfo.rotY,'f',4));
                    writer.writeEndElement();

                    writer.writeStartElement("rotZ");
                    writer.writeCharacters(QString::number(channelList[i].geometryInfo.rotZ,'f',4));
                    writer.writeEndElement();

                    writer.writeStartElement("transX");
                    writer.writeCharacters(QString::number(channelList[i].geometryInfo.transX,'f',4));
                    writer.writeEndElement();

                    writer.writeStartElement("transY");
                    writer.writeCharacters(QString::number(channelList[i].geometryInfo.transY,'f',4));
                    writer.writeEndElement();

                    writer.writeStartElement("transZ");
                    writer.writeCharacters(QString::number(channelList[i].geometryInfo.transZ,'f',4));
                    writer.writeEndElement();
                writer.writeEndElement();
            writer.writeEndElement();
        }
        writer.writeEndElement();
    writer.writeEndDocument();
    QFile xmlFile("D:\\Video Flight\\test.xml");
    if (xmlFile.open(QIODevice::WriteOnly)) {
            xmlFile.write(outputFile.toUtf8());
            xmlFile.close();
    }
    return true;
}

bool SyncProjectClass::setDateTime(QDateTime newDT)
{
    dateTime = newDT;
    if (dateTime == newDT) return true;
    else return false;
}

bool SyncProjectClass::setDescription(QString newDescription)
{
    description = newDescription;
    if(description == newDescription) return true;
    else return false;
}

bool SyncProjectClass::setLocation(QString newLocation)
{
    location = newLocation;
    if(location == newLocation) return true;
    else return false;
}

bool SyncProjectClass::setNavigationFilePath(QString newNavigationFilePath)
{
    navigationFilePath = newNavigationFilePath;
    if(navigationFilePath == newNavigationFilePath) return true;
    else return false;
}

void SyncProjectClass::parseXml()
{
    QString preread = "" ,
            source  = "";

    QFile file(projectFilePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    QTextStream in(&file);

    source = in.readAll();
    file.close();


    reader = new QXmlStreamReader(source);
    while(!reader->atEnd() && !reader->hasError())
    {
        // Читаем следующий элемент
        QXmlStreamReader::TokenType token = reader->readNext();

        if(token == QXmlStreamReader::Invalid)
        {

            qDebug() << "Invalid token" << token << reader->name() << reader->documentEncoding();
            qDebug() << reader->documentVersion() << reader->lineNumber() << reader->isWhitespace();
            continue;

        }

        if(token == QXmlStreamReader::StartDocument)
        {
            qDebug() << "Start Document token" << token << reader->name();
            reader->readNextStartElement();
            continue;
        }
        if(token == QXmlStreamReader::StartElement)
        {
            if(reader->name() == "sync_project")
            {
                qDebug() << "Sync project properties  ----------";
                continue;
            }
            if(reader->name() == "date")
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters)
                {
                    dateTime = QDateTime::fromString(reader->text().toString(),"yyyy.MM.dd");
                    qDebug() << "Date:" << dateTime.toString("yyyy.MM.dd");
                    continue;
                }
            }

            if(reader->name() == "location")
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters)
                {
                    location = reader->text().toString();
                    qDebug() << "Location:" << location.toLocal8Bit();
                    continue;
                }
            }

            if(reader->name() == "description")
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters)
                {
                    description = reader->text().toString();
                    qDebug() << "Description:" << description;
                    continue;
                }
            }

            if(reader->name() == "navigation")
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters)
                {
                    navigationFilePath = reader->text().toString();
                    qDebug() << "Navigation:" << navigationFilePath;
                    continue;
                }
            }

            if(reader->name() == "channel_list")
            {
                QXmlStreamAttributes *attr = new QXmlStreamAttributes();
                *attr = reader->attributes();
//                parseChannelList(attr->value("count").toInt(0,10));
                qDebug() << "Count of channels:" << attr->value("count").toInt(0,10);
                continue;
            }

            if(reader->name() == "channel")
            {
                Channel_Info channelElement;
                channelElement.clap = 0;
                channelElement.filePath = "";
                channelElement.flash = 0;
                channelElement.frame = 0;
                channelElement.name = "";
                channelElement.signal = 0;
                channelElement.geometryInfo.rotX = 0;
                channelElement.geometryInfo.rotY = 0;
                channelElement.geometryInfo.rotZ = 0;
                channelElement.geometryInfo.transX = 0;
                channelElement.geometryInfo.transY = 0;
                channelElement.geometryInfo.transZ = 0;
                parseChannelElement(channelElement);
                addChannelToList(channelElement);
            }
        }
    }
    if(reader->hasError())
        qDebug() << reader->errorString();
}

void SyncProjectClass::parseChannelElement(Channel_Info &channelElement)
{
    while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "channel"))
    {
        reader->readNext();
//         qDebug() << "ElementParser:" << reader->name() << reader->text().toString();
        if(reader->tokenType() == QXmlStreamReader::StartElement)
        {
            if(reader->name() == "name")
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.name = reader->text().toString();
                    continue;
                }
            }
            if(reader->name() == "filename")
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.filePath = reader->text().toString();
                    continue;
                }
            }
            if(reader->name() == "frame")
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                   channelElement.frame = reader->text().toString().toInt();
                    continue;
                }
            }
            if(reader->name() ==  "signal")
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.signal = reader->text().toString().toInt();
                    continue;
                }
            }
            if(reader->name() ==  "flash")
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.flash = reader->text().toString().toInt();
                    continue;
                }
            }
            if(reader->name() ==  "clap")
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.clap = reader->text().toString().toInt();
                    continue;
                }
            }
            if(reader->name() ==  "geometry_info")
            {
                continue;
            }

            if("rotX" == reader->name())
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.geometryInfo.rotX = reader->text().toString().toDouble(0);
                    continue;
                }
            }

            if("rotY" == reader->name())
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.geometryInfo.rotY = reader->text().toString().toDouble(0);
                    continue;
                }
            }

            if("rotZ" == reader->name())
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.geometryInfo.rotZ = reader->text().toString().toDouble(0);
                    continue;
                }
            }


            if("transX" == reader->name())
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.geometryInfo.transX = reader->text().toString().toDouble(0);
                    continue;
                }
            }


            if("transY" == reader->name())
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.geometryInfo.transY = reader->text().toString().toDouble(0);
                    continue;
                }
            }


            if("transZ" == reader->name())
            {
                reader->readNext();
                if(reader->tokenType() == QXmlStreamReader::Characters) {
                    channelElement.geometryInfo.transZ = reader->text().toString().toDouble(0);
                    continue;
                }
            }
        }
    }
}
