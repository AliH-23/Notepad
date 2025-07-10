#include "mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

MWNotepad::MWNotepad(QWidget *parent)  // class of main window of Notepad
: QMainWindow(parent)
{
    addMenuBarFunction();  // add MenuBar to main window of Notepad
    addTextEditFunction();   // add Central Text Box (you will write it) to main window of Notepad

    showWindowNotepadFunction();  // to add function to main window and it show the window
}

MWNotepad::~MWNotepad()   // destroyer not use here
{
}

void MWNotepad::addTextEditFunction()
{
    textEdit = new QTextEdit(this);   // add value to varaible "textEdit".
    this->setCentralWidget(textEdit);  // setup variable textEdit(Text Bos) to main window
}

void MWNotepad::addMenuBarFunction()
{
    addMenuFileFunction();   // add ready made file menu to MenuBar
}

void MWNotepad::addMenuFileFunction()
{
    QAction *openFile = new QAction("Open File",this);  // create Action "open file".
    openFile->setShortcut(QKeySequence("Ctrl+O"));  // add Shortcut (Ctrl+O) to "open file".

    QAction *saveFile = new QAction("Save",this);   // create Action "Save"
    saveFile->setShortcut(QKeySequence("Ctrl+S")); // add Shortcut (Ctrl+S) to "Save"

    QAction *save_asFile = new QAction("Save as",this);    // create Action "Save as"
    save_asFile->setShortcut(QKeySequence("Ctrl+Shift+S"));   // add Shortcut (Ctrl+Shift+S) to "Save as"

    QAction *exitProgram = new QAction("Exit",this);  // create Action  "Exit"
    exitProgram->setShortcut(QKeySequence("Ctrl+E"));   // add Shortcut (Ctrl+O) to "Exit"

    QMenu *File = new QMenu("File",this);   // create menu File

    File->addAction(openFile);      // add Action "open file" to menu "file"
    File->addAction(saveFile);      // add Action "save" to menu "file'
    File->addAction(save_asFile);   // add Action "save as" to menu "file"
    File->addSeparator();        // add line to menu "file"
    File->addAction(exitProgram);   // add Action "exit" to Menu "file"

    menuBar()->addMenu(File);   // add menu "menu" to MenuBar

    connect(openFile,&QAction::triggered,this,&MWNotepad::openFileFunction);
    connect(saveFile,&QAction::triggered,this,&MWNotepad::saveFileFunction);
    connect(save_asFile,&QAction::triggered,this,&MWNotepad::save_asFileFunction);
    connect(exitProgram,&QAction::triggered,this,&MWNotepad::close);
}

void MWNotepad::openFileFunction()
{
    currentFileName = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath(),"Text Files(*.txt);;All Files(*.*)");
    if(!currentFileName.isEmpty())
    {
        QFile File(currentFileName);
        if(File.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&File);
            QString Text = in.readAll();
            textEdit->setPlainText(Text);
            File.close();
        }
    }
}

void MWNotepad::saveFileFunction()
{
    if(!currentFileName.isEmpty())
    {
        QFile File(currentFileName);
        if(File.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&File);
            QString text = textEdit->toPlainText();
            out << text ;
            File.close();
        }
        else
        {
            save_asFileFunction();
        }
    }
    else
    {
        save_asFileFunction();
    }
}

void MWNotepad::save_asFileFunction()
{
    currentFileName = QFileDialog::getSaveFileName(this,"Save File",
                                                   QDir::homePath()+"/Text.txt",
                                                   "Text Files(*.txt);;All Files(*.*");
    if(!currentFileName.isEmpty())
    {
        QFile File(currentFileName);
        if(File.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&File);
            QString text = textEdit->toPlainText();
            out << text ;
            File.close();
        }
    }
}

void MWNotepad::showWindowNotepadFunction()
{
    this->resize(1000,900);
    this->show();      // The function "show()" use to show window user screen.
}

























