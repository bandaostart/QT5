#ifndef ITEMDIALOG_H
#define ITEMDIALOG_H

#include <QDialog>

namespace Ui {
class ItemDialog;
}

class ItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ItemDialog(QWidget *parent = 0);
    ~ItemDialog();
    void setData(QStringList strList);

    QStringList dataList;

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ItemDialog *ui;

};

#endif // ITEMDIALOG_H
