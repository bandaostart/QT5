#include "datedelegate.h"

DateDelegate::DateDelegate(QObject *parent) : QItemDelegate(parent)
{

}

//完成创建控件的工作，创建由参数中的QModleIndex对象指定的表项数据的编辑控件，并对控件的内容进行限定
 QWidget *DateDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
 {
     QDateTimeEdit *editor = new QDateTimeEdit(parent);           //新建一个QDateTimeEdit对象作为编辑是的输入控件

     editor->setDisplayFormat("yyyy-MM-dd");                      //显示格式
     editor->setCalendarPopup(true);                              //设置日历选择的显示以Popup的方式，即下拉菜单的方式显示
     editor->installEventFilter(const_cast<DateDelegate *>(this));//调用QObject类的installEventFilter()函数安装事件过滤器，使DataDelegate能够捕获QDateTimeEdit对象的事件

     return editor;
 }

 //设置控件显示的数据，将model中的数据更新至Delegate中，相当于一个初始化工作
 void DateDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
 {
     QString dateStr = index.model()->data(index).toString();              //获取指定index数据项的数据，调用QModelIndex的model()函数可获得提供index的model对象
                                                                           //daa()函数返回的是一个QVariant对象，toString()函数将它转换成一个QString类型数据
     QDate   date    = QDate::fromString(dateStr, Qt::ISODate);            //通过QDate的fromString函数将以QString类型表示的日期数据转换成QDate类型，

     QDateTimeEdit *edit = static_cast<QDateTimeEdit *>(editor);           //将editor转换为QDateTimeEdit对象,获得编辑控件的对象指针
     edit->setDate(date);                                                  //设置控件数据
 }


 //将Delegate中数据改变更新至Model中
 void DateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
 {
     QDateTimeEdit *edit = static_cast<QDateTimeEdit *>(editor);             //通过紧缩转换获得编辑控件的对象指针
     QDate         date  = edit->date();                                     //获得编辑控件中的数据更新
     model->setData(index, QVariant(date.toString(Qt::ISODate)));            //调用setData函数将数据修改跟新到Model中
 }

 //更新控件区的显示内容
 void DateDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
 {
     editor->setGeometry(option.rect);
 }





























































