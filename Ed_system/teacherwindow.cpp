#include "teacherwindow.h"

teacherwindow::teacherwindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	settabname();
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(detail_clicked()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(detail_clicked()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(detail_clicked()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(detail_clicked()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(detail_clicked()));
	//学生信息管理按钮
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(student_operation()));
	connect(ui.pushButton_10, SIGNAL(clicked()), this, SLOT(student_operation()));
	connect(ui.pushButton_14, SIGNAL(clicked()), this, SLOT(student_operation()));
	//课程信息管理按钮
	connect(ui.pushButton_16, SIGNAL(clicked()), this, SLOT(course_operation()));
	connect(ui.pushButton_17, SIGNAL(clicked()), this, SLOT(course_operation()));
	connect(ui.pushButton_15, SIGNAL(clicked()), this, SLOT(course_operation()));
	//学生选课信息管理按钮
	connect(ui.pushButton_65, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	connect(ui.pushButton_19, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	connect(ui.pushButton_18, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	connect(ui.pushButton_20, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	connect(ui.pushButton_33, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	//教师信息管理按钮
	connect(ui.pushButton_22, SIGNAL(clicked()), this, SLOT(teacher_operation()));
	connect(ui.pushButton_21, SIGNAL(clicked()), this, SLOT(teacher_operation()));
	connect(ui.pushButton_23, SIGNAL(clicked()), this, SLOT(teacher_operation()));
	//教师授课信息管理按钮
	connect(ui.pushButton_25, SIGNAL(clicked()), this, SLOT(tccourse_operation()));
	connect(ui.pushButton_24, SIGNAL(clicked()), this, SLOT(tccourse_operation()));
	connect(ui.pushButton_26, SIGNAL(clicked()), this, SLOT(tccourse_operation()));

}

teacherwindow::~teacherwindow()
{

}

void teacherwindow::settabname()
{
	ui.tabWidget->setTabText(0, QStringLiteral("学生信息查询"));
	ui.tabWidget->setTabText(1, QStringLiteral("课程信息查询"));
	ui.tabWidget->setTabText(2, QStringLiteral("学生选课信息管理"));
	ui.tabWidget->setTabText(3, QStringLiteral("教师信息查询"));
	ui.tabWidget->setTabText(4, QStringLiteral("教师授课信息查询"));
}

void teacherwindow::student_operation() /*学生信息管理*/
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton_9") {
		QString str = ui.lineEdit_9->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select S_NO, SNAME, SEX,"
							" SPNO, CLASS_NO "
						" from student where SNAME = '"
				+ str + "'");
			ui.tableView->setModel(model);
		}
	}
	else if (get == "pushButton_10") {
		QString str = ui.lineEdit_10->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select S_NO, SNAME, SEX,"
						" SPNO, CLASS_NO "
						" from student where S_NO = '"
				+ str + "'");
			ui.tableView->setModel(model);
		}
	}
	else if (get == "pushButton_14") {
		QString credit, tr;
		QString str = ui.lineEdit_17->text();
		QRegExp regExp("[0-9]");
		if (str.count() == str.count(regExp)) { credit = str; tr = "="; }
		else {
			credit = str.right(str.count(regExp));
			tr = str.left(str.count() - str.count(regExp));
		}
		if (0 != credit) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select SNAME, SEX, year(GETDATE()) - year(S_BIRTHDAY) age"
				" from student "
				"where year(GETDATE()) - year(S_BIRTHDAY)"
				+ tr + credit);
			ui.tableView->setModel(model);
		}
	}
}

void teacherwindow::course_operation() /*课程信息管理*/
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton_16") {
		QString str = ui.lineEdit_19->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from course where CNO = '"
				+ str + "'");
			ui.tableView_2->setModel(model);
		}
	}
	else if (get == "pushButton_17") {
		QString str = ui.lineEdit_18->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from course where CNAME = '"
				+ str + "'");
			ui.tableView_2->setModel(model);
		}
	}
	else if (get == "pushButton_15") {
		QString credit, tr;
		QString str = ui.lineEdit_20->text();
		QRegExp regExp("[0-9]");
		if (str.count() == str.count(regExp)) { credit = str; tr = "="; }
		else {
			credit = str.right(str.count(regExp));
			tr = str.left(str.count() - str.count(regExp));
		}
		if (0 != credit) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from course where CREDIT"
				+ tr + credit);
			ui.tableView_2->setModel(model);
		}
	}
}

void teacherwindow::sdcourse_operation() /*学生选课信息管理*/
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton_65") {
		QString S_NO = ui.lineEdit_75->text();
		QString CNO = ui.lineEdit_76->text();
		QString SCORE = ui.lineEdit_77->text();
		if (0 == S_NO.isEmpty() && 0 == CNO.isEmpty()
			&& 0 == SCORE.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("update student_course set SCORE = " + SCORE +
				" where S_NO = '" + S_NO + "'and CNO = '" + CNO + "'");
			if (value) {
				QMessageBox::information(this, "notice", "set sucessful!");
				ui.lineEdit_75->clear();
				ui.lineEdit_76->clear();
				ui.lineEdit_77->clear();
			}
			else
				QMessageBox::information(this, "notice", "set failed!");
		}
	}
	else if (get == "pushButton_19") {
		QString str = ui.lineEdit_22->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from student_course where S_NO = '"
				+ str + "'");
			ui.tableView_3->setModel(model);
		}
	}
	else if (get == "pushButton_18") {
		QString str = ui.lineEdit_23->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from student_course where CNO = '"
				+ str + "'");
			ui.tableView_3->setModel(model);
		}
	}
	else if (get == "pushButton_20") {
		QString credit, tr;
		QString str = ui.lineEdit_21->text();
		QRegExp regExp("[0-9]");
		if (str.count() == str.count(regExp)) { credit = str; tr = "="; }
		else {
			credit = str.right(str.count(regExp));
			tr = str.left(str.count() - str.count(regExp));
		}
		if (0 != credit) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from student_course where SCORE"
				+ tr + credit);
			ui.tableView_3->setModel(model);
		}
	}
	else if (get == "pushButton_33") {
		QString credit, tr;
		QString str = ui.lineEdit_21->text();
		QRegExp regExp("[0-9]");
		if (str.count() == str.count(regExp)) { credit = str; tr = "="; }
		else {
			credit = str.right(str.count(regExp));
			tr = str.left(str.count() - str.count(regExp));
		}
		if (0 != credit) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select student.S_NO, SNAME, CNAME, SCORE "
				"from student,course,student_course "
				"where SCORE"
				+ tr + credit +
				" and student.S_NO = student_course.S_NO"
				" and course.CNO = student_course.CNO");
			ui.tableView_3->setModel(model);
		}
	}
}

void teacherwindow::teacher_operation() /*教师信息管理*/
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton_22") {
		QString str = ui.lineEdit_25->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select T_NO, T_NAME, T_SEX, TECH_TITLE "
							" from teacher where T_NO = '"
							+ str + "'");
			ui.tableView_4->setModel(model);
		}
	}
	else if (get == "pushButton_21") {
		QString str = ui.lineEdit_26->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select T_NO, T_NAME, T_SEX, TECH_TITLE "
							" from teacher where T_NAME = '"
							+ str + "'");
			ui.tableView_4->setModel(model);
		}
	}
	else if (get == "pushButton_23") {
		QString str = ui.lineEdit_24->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select T_NO, T_NAME, T_SEX, TECH_TITLE "
							" from teacher where TECH_TITLE = '"
							+ str + "'");
			ui.tableView_4->setModel(model);
		}
	}
}

void teacherwindow::tccourse_operation() /*教师授课信息管理*/
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton_25") {
		QString str = ui.lineEdit_28->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from teacher_course where CNO = '"
				+ str + "'");
			ui.tableView_5->setModel(model);
		}
	}
	else if (get == "pushButton_24") {
		QString str = ui.lineEdit_29->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from teacher_course where TCID = '"
				+ str + "'");
			ui.tableView_5->setModel(model);
		}
	}
	else if (get == "pushButton_26") {
		QString str = ui.lineEdit_27->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from teacher_course where T_NO = '"
				+ str + "'");
			ui.tableView_5->setModel(model);
		}
	}
}

void teacherwindow::detail_clicked()
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton") {
		model->setQuery("select S_NO, SNAME, SEX,"
						" SPNO, CLASS_NO "
						" from student");
		ui.tableView->setModel(model);
	}
	else if (get == "pushButton_3") {
		model->setQuery("select * from course");
		ui.tableView_2->setModel(model);
	}
	else if (get == "pushButton_4") {
		model->setQuery("select * from student_course");
		ui.tableView_3->setModel(model);
	}
	else if (get == "pushButton_5") {
		model->setQuery("select T_NO, T_NAME, T_SEX, TECH_TITLE "
						" from teacher");
		ui.tableView_4->setModel(model);
	}
	else if (get == "pushButton_6") {
		model->setQuery("select * from teacher_course");
		ui.tableView_5->setModel(model);
	}
}