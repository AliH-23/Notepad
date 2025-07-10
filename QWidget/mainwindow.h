#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>   //library of window have MenuBar,ToolBar,StatusBar,CenterWidget
#include <QTextEdit>

QT_BEGIN_NAMESPACE      // to say I'm begin use Qt_NameSpace here.
namespace Ui {          // NameSpace of Qt_Disgin (File.ui).
    class MainWindow;   // name of class well be work it and we don't use this version.
}
QT_END_NAMESPACE       // to say I'm finish use Qt_NameSpace here.



class MWNotepad : public QMainWindow   // create class inherits library QMainWindow(it's class too).
{
    Q_OBJECT      // this is obj to allow use the Siginal&Slots in this class.
public:
    MWNotepad (QWidget *parent = nullptr);   // This is cinstructor function for window
    ~MWNotepad();   // This is distroyer function.

private:
    void addMenuBarFunction();      // This is function to add MenuBar(When you finish it) to where you put it down
    void addMenuFileFunction();     // This is function to add Menu name "File" to where you put it down.
    void addTextEditFunction();     // This is function to add QTextEdit when you put it down.

private:
    void showWindowNotepadFunction();  // this Function to Control and show Window of Notepad to the User

private slots:
    void openFileFunction();      // this Function to open file form file system to textspace of Notebad.
    void saveFileFunction();      // this Function to save file you open in NotePad or transferred work to save-asFileFunction if you don't open any file
    void save_asFileFunction();   // this Function to save file in place the the user defined

private:
    QString currentFileName;  // this is current of text file  it's to  select the path of Text file when user Chooses file
    QTextEdit *textEdit;  // the varaible of text box, user weite and read it.
};

#endif  // end MAINWINDOW_H
