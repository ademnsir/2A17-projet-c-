#include "connectioncpp.h"
#include<QtSql>
#include<QDebug>
Connection::Connection()
{

}


bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("oraclejwhr");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
