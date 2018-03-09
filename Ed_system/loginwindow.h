#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "ui_loginwindow.h"
#include "ed_system.h"
#include "studentwindow.h"
#include "teacherwindow.h"
#include <QMessageBox>

class loginwindow : public QWidget
{
	Q_OBJECT

public:
	loginwindow(QWidget *parent = 0);
	~loginwindow();
	Ed_system rootw;
	studentwindow stuw;
	teacherwindow tcrw;
	QString strU;
	QString strP;
	QList<QList<QString>> slist;
	QList<QList<QString>> tlist;
private:
	Ui::loginwindow ui;
	QString rootname = "admin";
	QString rootpassword = "admin";

private slots:
	void studentlogin();
	void teacherlogin();
	void rootlogin();

};

#endif // LOGINWINDOW_H
