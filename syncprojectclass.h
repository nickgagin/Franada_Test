#ifndef SYNCPROJECTCLASS_H
#define SYNCPROJECTCLASS_H
#include <QtCore>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QXmlStreamAttributes>
#include <QDateTime>
#include <QByteArray>
#include <QTextStream>
#include <QList>

struct Geometry_Info{
    double  rotX,           // Поворот в градусах относительно оси X
            rotY,           // Поворот в градусах относительно оси Y
            rotZ;           // Поворот в градусах относительно оси Z

    double  transX,         // Смещение относительно оси X
            transY,         // Смещение относительно оси Y
            transZ;         // Смещение относительно оси Z

};

struct Channel_Info{
    QString name;               // Название канала (Телевизионный, Тепловизионный и т.д.)
    QString filePath;           // Путь к видеофайлу канала
    int frame,                  // номер синхронизированного кадра
        flash,                  // номер кадра синхронизированного вспышкой (зажигалкой)
        clap,                   // номер кадра синхронизированного хлопком, физическим явлением, движением и т.д.
        signal;                 // миллисекунды зафиксированного высокоамплитудного звукового сигнала синхронизации от начала видеозаписи
    Geometry_Info geometryInfo; // Параметры геометрических поправок для более полного совмещения между собой
};



class SyncProjectClass
{

public:
    SyncProjectClass();
    SyncProjectClass( QString );                    // Конструктор класса, входящий параметр - путь к файлу проекта
    ~SyncProjectClass();                            // Деструктор

    QList<Channel_Info> channelList;    // Список видеоканалов

    bool loadFromXmlProjectFile(QString filepath);  // Инициализация класса проекта из файла проекта полёта
    bool saveToXmlProjectFile();                    // Сохранить данные проекта в файл проекта

    QString getProjectFilePath();                   // Получить путь к файлу проекта полёта
    QString getLocation();                          // Получить место проведения полёта
    QString getProjDescription();                   // Получить описание/заметки проекта
    QDateTime getProjectDate();                     // Получить дату проведения
    int getLengthOfChannelList();                   // Получить количество видеоканалов
    QString getNavigationFilePath();                // Получить путь к навигационному файлу

    bool setLocation(QString);                      // Задать локацию/место проведения полёта
    bool setDescription(QString);                   // Задать описание/заметки проекту
    bool setDateTime(QDateTime);                    // Установить дату проведения полёта
    bool setNavigationFilePath(QString);            // Задать путь к файлу навигации
    bool addChannelToList(Channel_Info &);          // Добавить видео канал

private:
    QString     projectFilePath;        // Путь к файлу проекта
    QDateTime   dateTime;               // Дата проведения полёта
    QString     location;               // Место проведения полёта
    QString     description;            // Дополнительное описание, заметки

    QString     navigationFilePath;     // Путь к файлу навигации

    QXmlStreamReader *reader;

    void parseXml();                    // XML парсер для файла-описателя проекта
//    void parseChannelList(int count);   // XML парсер отдельного элемента файла проекта
    void parseChannelElement(Channel_Info &channelElement);// XML парсер отдельного элемента файла проекта
};
#endif // SYNCPROJECTCLASS_H
