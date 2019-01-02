#ifndef COMBODELEGATE_H
#define COMBODELEGATE_H

#include <QItemDelegate>
#include <QObject>
#include <QDateTimeEdit>
#include <QComboBox>

class ComboDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    ComboDelegate(QObject *parent=0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void    setEditorData(QWidget *editor, const QModelIndex &index) const;
    void    setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void    updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

#endif // DATEDELEGATE_H
