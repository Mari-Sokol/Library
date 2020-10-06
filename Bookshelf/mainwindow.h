#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "BShelf.h"
#include "Shelf.h"
#include "PrintBook.h"
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_addBShelf_clicked();

    void on_listWidget_BShelfs_itemClicked(QListWidgetItem *item);

    void on_pushButton_addShelf_clicked();

    void on_listWidget_Shelfs_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    vector<BookShelf> bookShelfs;
    int bshelfID;
    int shelfID;
};
#endif // MAINWINDOW_H
