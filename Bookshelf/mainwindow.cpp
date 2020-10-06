#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //первичные настройки и инициализация
   ui->groupBox_2_shelfs->setEnabled(false);
   ui->groupBox_3_books->setEnabled(false);
   ui->pushButton_delBShelf->setEnabled(false);
   shelfID=0;
   bshelfID=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_addBShelf_clicked()
{
    //создать объект BShelfs
    BookShelf bshelf;
    //добавление объекта в вектор
    bookShelfs.push_back(bshelf);
    //добавление в список интерфейса
    ui->listWidget_BShelfs->addItem(QString::number(bookShelfs.size()));

}

void MainWindow::on_listWidget_BShelfs_itemClicked(QListWidgetItem *item)
{
    //получить ID шкафа
    shelfID=item->text().toInt();
    ui->listWidget_Shelfs->clear();
    ui->groupBox_2_shelfs->setEnabled(true);
    ui->pushButton_delBShelf->setEnabled(true);
    //получить кол-во полок
    int shelfNum = bookShelfs[shelfID-1].getShelfN();
    if(shelfNum>0){
        for (int i=0;i<shelfNum;i++){
            ui->listWidget_Shelfs->addItem(QString::number(i+1));
        }
    }

}



void MainWindow::on_pushButton_addShelf_clicked()
{
    bookShelfs[shelfID-1].addShelf();
    int shelfNum= bookShelfs[shelfID-1].getShelfN();
    ui->listWidget_Shelfs->
            addItem(QString::number(shelfNum));
}

void MainWindow::on_listWidget_Shelfs_itemClicked(QListWidgetItem *item)
{

}
