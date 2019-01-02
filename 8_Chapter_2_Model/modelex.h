#ifndef MODELEX_H
#define MODELEX_H

#include <QAbstractTableModel>
#include <QObject>

class ModelEx : public QAbstractTableModel
{
public:
    explicit ModelEx(QObject *parent=0);

    //下面四个函数是QAbstractTAbleModel类的纯虚函数
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QVector<short> army;
    QVector<short> weaponType;
    QMap<short, QString> armyMap;                //使用QMap数据保存数值和文字的映射
    QMap<short, QString> weaponTypeMap;

    QStringList  weapon;
    QStringList  header;

    void populateModel();

};

#endif // MODELEX_H
