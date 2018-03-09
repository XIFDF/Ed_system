#ifndef ED_SYSTEM_H
#define ED_SYSTEM_H

#include <QtWidgets/QMainWindow>
#include "ui_ed_system.h"
#include <QSqlQueryModel> 
#include <QMessageBox>
#include <QtSql>

class Ed_system : public QMainWindow
{
	Q_OBJECT

public:
	Ed_system(QWidget *parent = 0);
	~Ed_system();

private:
	Ui::Ed_systemClass ui;
	void settabname();

private slots:
	void detail_clicked();
	void student_operation();
	void course_operation();
	void sdcourse_operation();
	void teacher_operation();
	void tccourse_operation();
};

#endif // ED_SYSTEM_H
