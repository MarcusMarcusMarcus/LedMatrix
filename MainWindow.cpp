#include "LedMatrix.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->m_image->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paint(LedMatrix &matrix)
{
    ui->m_image->setPixmap(QPixmap::fromImage(matrix.image()));
}
