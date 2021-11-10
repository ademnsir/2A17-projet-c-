#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("project");
db.setUserName("rayen");//inserer nom de l'utilisateur
db.setPassword("rayen");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
