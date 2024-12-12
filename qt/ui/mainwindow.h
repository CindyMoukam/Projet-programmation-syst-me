#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTime();  // Slot pour mettre à jour l'heure affichée

private:
    Ui::MainWindow *ui;  // Interface utilisateur générée par Qt Designer

    QGraphicsScene *scene;  // Scène pour gérer le contenu

    void addTable(const QString &imagePath, int x, int y);
};

#endif // MAINWINDOW_H
