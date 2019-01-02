#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QImage>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QMatrix>
#include <QLabel>
#include <QFontComboBox>
#include <QComboBox>
#include <QToolButton>
#include <QFontDatabase>
#include <QTextCursor>
#include <QColorDialog>
#include <QTextImageFormat>
#include <QTextListFormat>
#include <QTextList>


namespace Ui {
class MainWindow;
}

//文件菜单项
#define OpenFileActionNum      0
#define NewFileActionNum       1
#define PrintTextActionNum     2
#define PrintImageActionNum    3
#define ExitActionNum          4

//编辑菜单项
#define CopyActionNum          0
#define CutActionNum           1
#define PasteActionNum         2
#define AboutActionNum         3
#define ZoomInActionNum        4
#define ZoomOutActionNum       5

//旋转菜单项
#define Rotate90ActionNum      0
#define Rotate180ActionNum     1
#define Rotate270ActionNum     2


//镜像菜单项
#define MirrorVerticalActionNum   0
#define MirrorHorizontalActionNum 1

//操作菜单项
#define undoActionNum             0
#define redoActionNum             1

//字体菜单项
#define boldButtonNum             0
#define italicButtonNum           1
#define underlineButtonNum        2
#define colorButtonNum            3

//文件排版
#define listLeftActionNum         0
#define listRightActionNum        1
#define listCenterActionNum       2
#define listJustifyActionNum      3


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void CreatActions();
    void CreatMenus();
    void CreatToolBars();

    void CreatMainArea();



public:
    //Actions
    enum{FileActionNums = 5 };
    QAction *filesActions[FileActionNums];

    enum{EditActionsNums = 6};
    QAction *editActions[EditActionsNums];

    enum {RotateActionNums = 3};
    QAction *rotateActions[RotateActionNums];

    enum {MirrorActionNums = 2};
    QAction *mirrorActions[MirrorActionNums];

    enum {OperateActionNums = 2};
    QAction *OperateActions[OperateActionNums];

    enum {FontButtonNums = 4};
    QToolButton *FontButtons[FontButtonNums];
    QLabel          *fontLabel;
    QFontComboBox   *fontComboBox;
    QLabel          *fontSizeLabel;
    QComboBox       *fontSizeComboBox;

    enum {ListActionNums = 4};
    QAction      *ListAction[ListActionNums];
    QActionGroup *listActionGrp;
    QLabel       *listLabel;
    QComboBox    *listComboBox;



    //menus
    QMenu *fileMenu;
    QMenu *zoomMenu;
    QMenu *rotateMenu;
    QMenu *mirrorMenu;

    //font

    //toolbars
    QToolBar *fileTool;
    QToolBar *zoomTool;
    QToolBar *rotateTool;
    QToolBar *mirrorTool;
    QToolBar *doToolBar;
    QToolBar *fontToolBar;
    QToolBar *listToolBar;



    //主显示区域
    QImage    img;
    QLabel    *imageLabel;
    QTextEdit *textEdit;

private slots:
    void ShowNewFile();
    void ShowOpenFile();
    void ShowPrintText();
    void ShowPrintImage();
    void ShowZoomIn();
    void ShowZoomOut();
    void ShowRotate90();
    void ShowRotate180();
    void ShowRotate270();
    void ShowMirrorVertical();
    void ShowMirrorHorizontal();

    void ShowFontComboBox(QString font);
    void ShowFontSizeComboBox(QString fontSize);
    void ShowFontBoldBtn();
    void ShowFontItalicBtn();
    void ShowFontUnderLineBtn();
    void ShowFontColorBtn();
    void ShowCurrentFormatChanged(QTextCharFormat fmt);

    void ShowList(int index);
    void ShowAlignment(QAction *act);
    void ShowCursorPositionChanged();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
