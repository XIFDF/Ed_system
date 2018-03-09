#include "loginwindow.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase> 
#include <QSqlError> 
#include <QMessageBox> 

void OpenDatabase()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	db.setDatabaseName(QString("DRIVER={SQL SERVER};"
		"SERVER=N551WJ4200\\SQLEXPRESS;" //���������� 
		"DATABASE=SC_DATABASE;"//���ݿ��� 
		"Trusted_Connection=yes")); //Windows��ݵ�¼
	if (!db.open())
	{
		QMessageBox::critical(0, qApp->tr("Cannot open database"),
			db.lastError().databaseText(), QMessageBox::Cancel);

	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OpenDatabase();
	loginwindow w;
	w.setFixedSize(478, 362);
	w.show();
	
	return a.exec();
}
