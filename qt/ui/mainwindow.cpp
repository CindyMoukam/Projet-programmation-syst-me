#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTimer>
#include <QDateTime>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configurer la taille fixe de la fenêtre
    setFixedSize(1200, 650);

    // Configurer la hauteur des zones
    ui->titleLabel->setFixedHeight(30);
    ui->buttonArea->setFixedHeight(30);
    ui->statusLabel->setFixedHeight(30);
    ui->timeLabel->setFixedHeight(30);

    // Configurer les icônes des boutons
    QIcon buttonIcon1("../../assets/images/play.png");
    QIcon buttonIcon2("../../assets/images/pause.png");
    QIcon buttonIcon3("../../assets/images/accelerate.png");

    ui->button1->setIcon(buttonIcon1);
    ui->button2->setIcon(buttonIcon2);
    ui->button3->setIcon(buttonIcon3);

    ui->button1->setIconSize(QSize(40, 40));
    ui->button2->setIconSize(QSize(40, 40));
    ui->button3->setIconSize(QSize(40, 40));

    ui->button1->setFixedHeight(10);
    ui->button2->setFixedHeight(10);
    ui->button3->setFixedHeight(10);

    // Configurer les textes par défaut
    ui->statusLabel->setText("Ouvert");
    ui->timeLabel->setText("00:00:00");

    // Mettre en place un timer pour mettre à jour l'heure en temps réel
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(1000);

    // Mise à jour initiale de l'heure
    updateTime();

    // Ajouter des tables
    addTable("../../assets/images/table_unique1.png", 250, 300);  // Exemple d'ajout d'une table
    addTable("../../assets/images/table_unique2.png", 200, 300);  // Exemple d'ajout d'une autre table
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    // Obtenir et afficher l'heure actuelle
    QString currentTime = QDateTime::currentDateTime().toString("hh:mm:ss");
    ui->timeLabel->setText(currentTime);
}

void MainWindow::addTable(const QString &imagePath, int x, int y)
{
    // Créer un QLabel pour afficher l'image
    QLabel* tableLabel = new QLabel(ui->restaurantArea);  // Le parent est restaurantArea

    // Charger l'image de la table
    QPixmap tableImage(imagePath);
    if (tableImage.isNull()) {
        qDebug() << "Erreur : Impossible de charger l'image de la table : " << imagePath;
        return;
    }

    // Définir l'image sur le QLabel
    tableLabel->setPixmap(tableImage);
    tableLabel->setAlignment(Qt::AlignCenter);  // Centrer l'image si la taille du QLabel est plus grande que l'image
    tableLabel->setScaledContents(true);  // Ajuster l'image à la taille du QLabel

    // Redimensionner le QLabel à la taille de l'image (facultatif)
    tableLabel->resize(tableImage.size());

    // Positionner le QLabel dans la zone restaurantArea
    tableLabel->move(x, y);  // Utilisez `move(x, y)` pour ajuster la position
}
