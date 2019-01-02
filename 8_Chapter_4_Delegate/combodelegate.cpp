#include "combodelegate.h"

ComboDelegate::ComboDelegate(QObject *parent) : QItemDelegate(parent)
{

}

//完成创建控件的工作，创建由参数中的QModleIndex对象指定的表项数据的编辑控件，并对控件的内容进行限定
 QWidget *ComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
 {
     QComboBox *editor = new QComboBox(parent);

     editor->addItem(tr("工人"));
     editor->addItem(tr("农民"));
     editor->addItem(tr("医生"));
     editor->addItem(tr("律师"));
     editor->addItem(tr("军人"));
     editor->installEventFilter(const_cast<ComboDelegate *>(this));//调用QObject类的installEventFilter()函数安装事件过滤器，使ComboDelegate能够捕获QComboBox对象的事件

     return editor;
 }

 //设置控件显示的数据，将model中的数据更新至Delegate中，相当于一个初始化工作
 void ComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
 {
     QString dateStr = index.model()->data(index).toString();              //获取指定index数据项的数据，调用QModelIndex的model()函数可获得提供index的model对象
                                                                           //daa()函数返回的是一个QVariant对象，toString()函数将它转换成一个QString类型数据
     QComboBox *box = static_cast<QComboBox *>(editor);

     int i=box->findText(dateStr);
     box->setCurrentIndex(i);
 }


 //将Delegate中数据改变更新至Model中
 void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
 {
     QComboBox *box = static_cast<QComboBox *>(editor);                    //通过紧缩转换获得编辑控件的对象指针

     QString   str  = box->currentText();

     model->setData(index, str);
 }

 //更新控件区的显示内容
 void ComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
 {
     editor->setGeometry(option.rect);
 }





























































