#include <QApplication>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "Database.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    //RestaurantView view;

    // Récupération de l'instance unique de DatabaseManager
    Database& dbManager = Database::instance();

    // Connexion à la base PostgreSQL
    if (dbManager.connect("localhost", "restaurantmanagement", "postgres", "Mgm+02C")) {
        qDebug() << "Connexion réussie!";
    } else {
        qDebug() << "Échec de la connexion!";
        return -1;
    }
    return app.exec();
}
