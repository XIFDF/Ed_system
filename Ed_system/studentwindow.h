#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QWidget>
#include "ui_studentwindow.h"
#include <QSqlQueryModel> 
#include <QtSql>
#include <QMessageBox>
class studentwindow : public QWidget
{
	Q_OBJECT

public:
	studentwindow(QWidget *parent = 0);
	~studentwindow();
	QString S_NO;
	void settabname();
private:
	Ui::studentwindow ui;

private slots:
	void detail_clicked();
	void student_operation();
	void course_operation();
	void sdcourse_operation();
	void teacher_operation();
	void tccourse_operation();
};

#endif // STUDENTWINDOW_H
