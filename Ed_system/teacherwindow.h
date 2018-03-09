#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QWidget>
#include "ui_teacherwindow.h"
#include <QSqlQueryModel> 
#include <QtSql>
#include <QMessageBox>

class teacherwindow : public QWidget
{
	Q_OBJECT

public:
	teacherwindow(QWidget *parent = 0);
	~teacherwindow();
	QString T_NO;
	void settabname();

private:
	Ui::teacherwindow ui;

private slots:
	void detail_clicked();
	void student_operation();
	void course_operation();
	void sdcourse_operation();
	void teacher_operation();
	void tccourse_operation();
};

#endif // TEACHERWINDOW_H
