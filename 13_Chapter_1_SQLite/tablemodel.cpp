#include "tablemodel.h"

TableModel::TableModel(QObject *parent): QAbstractTableModel(parent)
{
    RowNum = 0;
    header << "Id" << "Attribute" << "Type" << "Kind" << "Nation" << "Carnumber" << "Elevaltor" << "Distance" << "Oil" << "Temperature";
}



//添加数据
void TableModel::AdditemData(QStringList data, int num)
{
    for (int j=0; j<num; j++)
    {
        for (int i=0; i<dataNum; i++)
        {
            Data[i] << data[i+j*dataNum];
        }
        RowNum++;
    }

    endResetModel();
}


//清空数据
void TableModel::ClearitemData()
{
    RowNum = 0;
    for (int i=0; i<dataNum; i++)
    {
        Data[i].clear();
    }
}


//删除行
void TableModel::removeRow(int row)
{
    for(int i=0; i<dataNum; i++)
    {
        Data[i].removeAt(row);
    }
    RowNum--;

    endResetModel();
}


//更新行数据
void TableModel::updateRow(QStringList strlist, int row)
{
    for(int i=0; i<dataNum; i++)
    {
        Data[i].replace(row, strlist.at(i));
    }

    endResetModel();
}



//列
int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(&parent);

    return dataNum;
}



//行
int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(&parent);

    return RowNum;
}



//返回指定索引的数据，即将数值映射为文字
QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        return Data[index.column()][index.row()];
    }

    if(role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignHCenter | Qt::AlignVCenter);
    }

    return QVariant();
}



//获取行数据
QStringList TableModel::getRowData(int row)
{
    QStringList strList;

    for (int i=0; i<dataNum; i++)
    {
        strList << Data[i][row];
    }

    return strList;
}



//获取头数据
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        return header[section];
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}




































