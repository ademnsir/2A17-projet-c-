#include "connectioncpp.h"
#include<QtSql>
#include<QDebug>
Connection::Connection()
{

}


bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("db");
db.setUserName("Yossri");//inserer nom de l'utilisateur
db.setPassword("Yossri");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
