#include "loginwindow.h"

loginwindow::loginwindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(studentlogin()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(teacherlogin()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(rootlogin()));
	
	QSqlQuery query, query_;
	query.exec("select S_NO, PASSWORD from student");
	while (query.next())
	{
		QList<QString> S;
		S.append(query.value(0).toString());
		S.append(query.value(1).toString());
		slist.append(S);
	}

	query_.exec("select T_NO, T_PASSWORD from teacher");
	while (query_.next())
	{
		QList<QString> S;
		S.append(query_.value(0).toString());
		S.append(query_.value(1).toString());
		tlist.append(S);
	}
}

loginwindow::~loginwindow()
{
}

void loginwindow::studentlogin()
{
	strU = ui.lineEdit->text();
	strP = ui.lineEdit_2->text();
	int loginstate = 0;
	QList<QString> S;
	S.append(strU);
	S.append(strP);
	if (strU.isEmpty() == 1)
		QMessageBox::warning(NULL, "warning", QStringLiteral("用户名不能为空"));
	else if (strP.isEmpty() == 1)
		QMessageBox::warning(NULL, "warning", QStringLiteral("密码不能为空"));
	else {
			foreach (QList<QString> ss, slist)
			{
				if (ss.at(0).trimmed() == S.at(0) && ss.at(1).trimmed() == S.at(1))
				{
					loginstate = 1; break;
				}
			}
			if (loginstate == 1) {
				QMessageBox::information(NULL, "sucessful", QStringLiteral("登陆成功"));
				stuw.S_NO = strU;
				this->hide();
				stuw.setWindowTitle(QStringLiteral("用户ID：") + strU);
				stuw.setFixedSize(710, 450);
				stuw.show();
			}
			else
				QMessageBox::critical(NULL, "fail", QStringLiteral("登陆失败"));
	}
}


void loginwindow::teacherlogin()
{
	strU = ui.lineEdit->text();
	strP = ui.lineEdit_2->text();
	int loginstate = 0;
	QList<QString> S;
	S.append(strU);
	S.append(strP);
	if (strU.isEmpty() == 1)
		QMessageBox::warning(NULL, "warning", QStringLiteral("用户名不能为空"));
	else if (strP.isEmpty() == 1)
		QMessageBox::warning(NULL, "warning", QStringLiteral("密码不能为空"));
	else {
		foreach(QList<QString> ts, tlist)
		{
			if (ts.at(0).trimmed() == S.at(0) && ts.at(1).trimmed() == S.at(1))
			{
				loginstate = 1; break;
			}
		}
		if (loginstate == 1) {
			QMessageBox::information(NULL, "sucessful", QStringLiteral("登陆成功"));
			tcrw.T_NO = strU;
			this->hide();
			tcrw.setWindowTitle(QStringLiteral("用户ID：") + strU);
			tcrw.setFixedSize(710, 460);
			tcrw.show();
		}
		else
			QMessageBox::critical(NULL, "fail", QStringLiteral("登陆失败"));
	}
}

void loginwindow::rootlogin()
{
	strU = ui.lineEdit->text();
	strP = ui.lineEdit_2->text();
	if (strU.isEmpty() == 1)
		QMessageBox::warning(NULL, "warning", QStringLiteral("用户名不能为空"));
	else if (strP.isEmpty() == 1)
		QMessageBox::warning(NULL, "warning", QStringLiteral("密码不能为空"));
	else if (strU == rootname && strP == rootpassword) {
		QMessageBox::information(NULL, "sucessful", QStringLiteral("登陆成功"));
		this->hide();
		rootw.setWindowTitle(QStringLiteral("简单的学生选课管理系统"));
		rootw.setFixedSize(710, 570);
		rootw.show();
	}
	else
		QMessageBox::critical(NULL, "fail", QStringLiteral("登陆失败"));
}
