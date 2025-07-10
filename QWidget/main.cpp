// This is Program is a NotePad write by C++ (Qt_QWidget).
// THis is version from Notepad have only does basics (open,save,save as,exit) and We don't use Qt-Disgin
// This is Program making to learning, and there will be many versions in future.

#include "mainwindow.h"   // head file of program.

#include <QApplication>   //This is library to create App and start run it.

int main(int argc, char* argv[])    // The program is begin from this Function.
{
    QApplication App(argc, argv);  //this line to create and start on empty Application.

    MWNotepad window ;    // this is class from head file, class dose create window notepad .

    return App.exec();    // the function "exec()" is do event loop of App.
}
