#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>


class TableModel : public QAbstractTableModel
{
public:
    explicit TableModel(QObject *parent=0);

    //下面四个函数是QAbstractTAbleModel类的纯虚函数
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void        AdditemData(QStringList data, int num);
    void        ClearitemData();
    QStringList getRowData(int row);
    void        removeRow(int row);
    void        updateRow(QStringList strlist, int row);


private:
    QStringList  header;

    enum { dataNum = 10};
    QStringList Data[dataNum];

    int          RowNum;

};

#endif // TABLEMODEL_H
