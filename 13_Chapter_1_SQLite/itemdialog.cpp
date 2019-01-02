#include "itemdialog.h"
#include "ui_itemdialog.h"

ItemDialog::ItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemDialog)
{
    ui->setupUi(this);
}

ItemDialog::~ItemDialog()
{
    delete ui;
}


void ItemDialog::setData(QStringList strList)
{
    int     temp_data = 0;
    QString temp_str;

    temp_str  = strList.at(0);
    temp_data = temp_str.toInt();

    ui->Id->setValue(temp_data);
    ui->Attribute->setText(strList.at(1));

    ui->Type->setText(strList.at(2));

    ui->Kind->setText(strList.at(3));

    ui->Nation->setText(strList.at(4));

    ui->Carnumber->setText(strList.at(5));

    ui->Elevaltor->setText(strList.at(6));

    ui->Distance->setText(strList.at(7));

    ui->Oil->setText(strList.at(8));

    ui->Temperature->setText(strList.at(9));
}


//添加
void ItemDialog::on_okButton_clicked()
{
    dataList.clear();

    dataList << QString::number((ui->Id->value()));
    dataList << ui->Attribute->text();
    dataList << ui->Type->text();
    dataList << ui->Kind->text();
    dataList << ui->Nation->text();
    dataList << ui->Carnumber->text();
    dataList << ui->Elevaltor->text();
    dataList << ui->Distance->text();
    dataList << ui->Oil->text();
    dataList << ui->Temperature->text();

    QDialog::accept();
}



//取消
void ItemDialog::on_cancelButton_clicked()
{
    QDialog::reject();
}
