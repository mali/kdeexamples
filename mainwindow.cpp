/*
*   Copyright (C) 2008 Nicola Gigante <nicola.gigante@gmail.com>
*                                                               
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or   
*   (at your option) any later version.                                 
*                                                                       
*   This program is distributed in the hope that it will be useful,     
*   but WITHOUT ANY WARRANTY; without even the implied warranty of      
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the       
*   GNU General Public License for more details.                        
*                                                                       
*   You should have received a copy of the GNU General Public License   
*   along with this program; if not, write to the                       
*   Free Software Foundation, Inc.,                                     
*   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .      
*/

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Action.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    Action::setHelperID("org.kde.auth.example");
    progressBar = new QProgressBar();
    pushButton = new QPushButton();
    pushButton->setText("Stop");
    connect(pushButton, SIGNAL(clicked()), this, SLOT(stopLongAction()));
    progressBar->setRange(0, 100);
    this->statusBar()->addPermanentWidget(progressBar);
    this->statusBar()->addPermanentWidget(pushButton);
    pushButton->hide();
    progressBar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("All (*.*)"));

    QFile file(filename);
    QTextStream stream(&file);
    QString contents;

    if(!file.open(QIODevice::ReadOnly))
    {
        if(file.error() & QFile::PermissionsError)
        {
            Action readAction = "org.kde.auth.example.read";
            readAction.arguments()["filename"] = filename;
        
            ActionReply reply = readAction.execute();
            if(reply.failed())
                QMessageBox::information(this, "Error", QString("KAuth returned an error code: %1").arg(reply.errorCode()));
            else
                contents = reply.data()["contents"].toString();
        }else
            QMessageBox::information(this, "Error", QString("Unable to open file: %1").arg(file.error()));
    }else
        contents = stream.readAll();

    ui->plainTextEdit->setPlainText(contents);

    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), "/home", tr("All (*.*)"));
    
    QFile file(filename);
    QTextStream stream(&file);
    
    if(!file.open(QIODevice::WriteOnly))
    {
        if(file.error() & QFile::PermissionsError)
        {
            Action writeAction = "org.kde.auth.example.write";
            writeAction.arguments()["filename"] = filename;
            writeAction.arguments()["contents"] = ui->plainTextEdit->toPlainText();
            
            ActionReply reply = writeAction.execute();
            if(reply.failed())
                QMessageBox::information(this, "Error", QString("KAuth returned an error code: %1").arg(reply.errorCode()));
        }else
            QMessageBox::information(this, "Error", QString("Unable to open file: %1").arg(file.error()));
    }else
        stream << ui->plainTextEdit->toPlainText();
    
    file.close();
}

void MainWindow::on_longAction_triggered()
{
    Action longAction = "org.kde.auth.example.longaction";
    connect(longAction.watcher(), SIGNAL(progressStep(int)), progressBar, SLOT(setValue(int)));
    connect(longAction.watcher(), SIGNAL(actionPerformed(ActionReply)), this, SLOT(longActionPerformed(ActionReply)));
    
    
    if(!longAction.executeAsync())
        this->statusBar()->showMessage("Could not execute the long action");
    else
    {
        pushButton->show();
        progressBar->show();
    }
}

void MainWindow::stopLongAction()
{
    Action("org.kde.auth.example.longaction").stop();
}

void MainWindow::longActionPerformed(ActionReply reply)
{
    progressBar->hide();
    pushButton->hide();
    progressBar->setValue(0);
    
    if(reply.succeded())
        this->statusBar()->showMessage("Action succeded", 10000);
    else
        this->statusBar()->showMessage(QString("Could not execute the long action: %1").arg(reply.errorCode()), 10000);
}
