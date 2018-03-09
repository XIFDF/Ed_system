#include "ed_system.h"
//管理员用户界面
Ed_system::Ed_system(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	settabname();
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(detail_clicked()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(detail_clicked()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(detail_clicked()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(detail_clicked()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(detail_clicked()));
	//学生信息管理按钮
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(student_operation()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(student_operation()));
	connect(ui.pushButton_8, SIGNAL(clicked()), this, SLOT(student_operation()));
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(student_operation()));
	connect(ui.pushButton_10, SIGNAL(clicked()), this, SLOT(student_operation()));
	connect(ui.pushButton_14, SIGNAL(clicked()), this, SLOT(student_operation()));
	//课程信息管理按钮
	connect(ui.pushButton_11, SIGNAL(clicked()), this, SLOT(course_operation()));
	connect(ui.pushButton_12, SIGNAL(clicked()), this, SLOT(course_operation()));
	connect(ui.pushButton_13, SIGNAL(clicked()), this, SLOT(course_operation()));
	connect(ui.pushButton_16, SIGNAL(clicked()), this, SLOT(course_operation()));
	connect(ui.pushButton_17, SIGNAL(clicked()), this, SLOT(course_operation()));
	connect(ui.pushButton_15, SIGNAL(clicked()), this, SLOT(course_operation()));
	//学生选课信息管理按钮
	connect(ui.pushButton_28, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	connect(ui.pushButton_65, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	connect(ui.pushButton_27, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	connect(ui.pushButton_19, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	connect(ui.pushButton_18, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	connect(ui.pushButton_20, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	connect(ui.pushButton_33, SIGNAL(clicked()), this, SLOT(sdcourse_operation()));
	//教师信息管理按钮
	connect(ui.pushButton_66, SIGNAL(clicked()), this, SLOT(teacher_operation()));
	connect(ui.pushButton_29, SIGNAL(clicked()), this, SLOT(teacher_operation()));
	connect(ui.pushButton_30, SIGNAL(clicked()), this, SLOT(teacher_operation()));
	connect(ui.pushButton_22, SIGNAL(clicked()), this, SLOT(teacher_operation()));
	connect(ui.pushButton_21, SIGNAL(clicked()), this, SLOT(teacher_operation()));
	connect(ui.pushButton_23, SIGNAL(clicked()), this, SLOT(teacher_operation()));
	//教师授课信息管理按钮
	connect(ui.pushButton_67, SIGNAL(clicked()), this, SLOT(tccourse_operation()));
	connect(ui.pushButton_31, SIGNAL(clicked()), this, SLOT(tccourse_operation()));
	connect(ui.pushButton_32, SIGNAL(clicked()), this, SLOT(tccourse_operation()));
	connect(ui.pushButton_25, SIGNAL(clicked()), this, SLOT(tccourse_operation()));
	connect(ui.pushButton_24, SIGNAL(clicked()), this, SLOT(tccourse_operation()));
	connect(ui.pushButton_26, SIGNAL(clicked()), this, SLOT(tccourse_operation()));

}

Ed_system::~Ed_system()
{
}

void Ed_system::settabname()
{
	ui.tabWidget->setTabText(0, QStringLiteral("学生信息管理"));
	ui.tabWidget->setTabText(1, QStringLiteral("课程信息管理"));
	ui.tabWidget->setTabText(2, QStringLiteral("学生选课信息管理"));
	ui.tabWidget->setTabText(3, QStringLiteral("教师信息管理"));
	ui.tabWidget->setTabText(4, QStringLiteral("教师授课信息管理"));
}

void Ed_system::student_operation() /*学生信息管理*/
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton_2") {
		QString S_NO = ui.lineEdit->text();
		QString SNAME = ui.lineEdit_2->text();
		QString SEX = ui.lineEdit_3->text();
		QString S_BIRTHDAY = ui.lineEdit_4->text();
		QString SPNO = ui.lineEdit_5->text();
		QString CLASS_NO = ui.lineEdit_6->text();
		QString PASSWORD = ui.lineEdit_38->text();

		if (0 == S_NO.isEmpty() && 0 == SNAME.isEmpty() && 0 == SEX.isEmpty()
		 && 0 == S_BIRTHDAY.isEmpty() && 0 == SPNO.isEmpty() && 0 == CLASS_NO.isEmpty()
			&& 0 == PASSWORD.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("insert into student values ('"
						+ S_NO + "','" + SNAME + "','" + SEX + "','"+ S_BIRTHDAY + 
				  "','" + SPNO + "','" + CLASS_NO + "','" + PASSWORD +"')");
			if (value) {
				QMessageBox::information(this, "notice", "add sucessful!");
				ui.lineEdit->clear();
				ui.lineEdit_2->clear();
				ui.lineEdit_3->clear();
				ui.lineEdit_4->clear();
				ui.lineEdit_5->clear();
				ui.lineEdit_6->clear();
				ui.lineEdit_38->clear();
			}
			else
				QMessageBox::information(this, "notice", "add failed!");
		}
	}
	else if (get == "pushButton_7") {
		QString str = ui.lineEdit_7->text();
		if (0 == str.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("delete from student where SNAME = '"
												 + str + "'");
			if (value) {
				QMessageBox::information(this, "notice", "delete sucessful!");
				ui.lineEdit_7->clear();
			}
			else
				QMessageBox::information(this, "notice", "delete failed!");
		}
	}
	else if (get == "pushButton_8") {
		QString str = ui.lineEdit_8->text();
		if (0 == str.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("delete from student where S_NO = '"
												+ str + "'");
			if (value) {
				QMessageBox::information(this, "notice", "delete sucessful!");
				ui.lineEdit_8->clear();
			}
			else
				QMessageBox::information(this, "notice", "delete failed!");
		}
	}
	else if (get == "pushButton_9") {
		QString str = ui.lineEdit_9->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from student where SNAME = '"
												+ str + "'");
			ui.tableView->setModel(model);
		}
	}
	else if (get == "pushButton_10") {
		QString str = ui.lineEdit_10->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from student where S_NO = '"
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

void Ed_system::course_operation() /*课程信息管理*/
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton_11") {
		QString CNO = ui.lineEdit_11->text();
		QString CNAME = ui.lineEdit_12->text();
		QString SPNO = ui.lineEdit_13->text();
		QString CREDIT = ui.lineEdit_14->text();

		if (0 == CNO.isEmpty() && 0 == CNAME.isEmpty() 
			&& 0 == SPNO.isEmpty() && 0 == CREDIT.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("insert into course values ('"
				+ CNO + "','" + CNAME + "','" + SPNO + "','" + CREDIT + "')");
			if (value) {
				QMessageBox::information(this, "notice", "add sucessful!");
				ui.lineEdit_11->clear();
				ui.lineEdit_12->clear();
				ui.lineEdit_13->clear();
				ui.lineEdit_14->clear();
			}
			else
				QMessageBox::information(this, "notice", "add failed!");
		}
	}
	else if(get == "pushButton_12"){
		QString str = ui.lineEdit_15->text();
		if (0 == str.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("delete from course where CNO = '"
				+ str + "'");
			if (value) {
				QMessageBox::information(this, "notice", "delete sucessful!");
				ui.lineEdit_15->clear();
			}
			else
				QMessageBox::information(this, "notice", "delete failed!");
		}
	}
	else if (get == "pushButton_13") {
		QString str = ui.lineEdit_16->text();
		if (0 == str.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("delete from course where CNAME = '"
				+ str + "'");
			if (value) {
				QMessageBox::information(this, "notice", "delete sucessful!");
				ui.lineEdit_16->clear();
			}
			else
				QMessageBox::information(this, "notice", "delete failed!");
		}
	}
	else if (get == "pushButton_16") {
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
		else { credit = str.right(str.count(regExp)); 
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

void Ed_system::sdcourse_operation() /*学生选课信息管理*/
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton_28") {
		QString S_NO = ui.lineEdit_36->text();
		QString CNO = ui.lineEdit_37->text();
		if (0 == S_NO.isEmpty() && 0 == CNO.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("insert into student_course values ('"
						+ S_NO + "','" + CNO + "'," + "NULL)");
			if (value) {
				QMessageBox::information(this, "notice", "add sucessful!");
				ui.lineEdit_36->clear();
				ui.lineEdit_37->clear();
			}
			else
				QMessageBox::information(this, "notice", "add failed!");
		}
	}
	else if (get == "pushButton_65") {
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
	else if (get == "pushButton_27") {
		QString str1 = ui.lineEdit_30->text();
		QString str2 = ui.lineEdit_31->text();
		if (0 == str1.isEmpty() && 0 == str2.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("delete from student_course where S_NO = '"
										+ str1 + "' and CNO = '" + str2 + "'");
			if (value) {
				QMessageBox::information(this, "notice", "delete sucessful!");
				ui.lineEdit_30->clear();
				ui.lineEdit_31->clear();
			}
			else
				QMessageBox::information(this, "notice", "delete failed!");
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

void Ed_system::teacher_operation() /*教师信息管理*/
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton_66") {
		QString T_NO = ui.lineEdit_81->text();
		QString T_NAME = ui.lineEdit_82->text();
		QString T_SEX = ui.lineEdit_78->text();
		QString T_BIRTHDAY = ui.lineEdit_79->text();
		QString TECH_TITLE = ui.lineEdit_80->text();
		QString T_PASSWORD = ui.lineEdit_39->text();

		if (0 == T_NO.isEmpty() && 0 == T_NAME.isEmpty() && 0 == T_SEX.isEmpty()
			&& 0 == T_BIRTHDAY.isEmpty() && 0 == TECH_TITLE.isEmpty() 
			&& 0 == T_PASSWORD.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("insert into teacher values ('"
				+ T_NO + "','" + T_NAME + "','" + T_SEX + "','"
				+ T_BIRTHDAY + "','" + TECH_TITLE + "','" + T_PASSWORD + "')");
			if (value) {
				QMessageBox::information(this, "notice", "add sucessful!");
				ui.lineEdit_81->clear();
				ui.lineEdit_82->clear();
				ui.lineEdit_78->clear();
				ui.lineEdit_79->clear();
				ui.lineEdit_80->clear();
				ui.lineEdit_39->clear();
			}
			else
				QMessageBox::information(this, "notice", "add failed!");
		}
	}
	else if (get == "pushButton_29") {
		QString str = ui.lineEdit_32->text();
		if (0 == str.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("delete from teacher where T_NO = '"
				+ str + "'");
			if (value) {
				QMessageBox::information(this, "notice", "delete sucessful!");
				ui.lineEdit_32->clear();
			}
			else
				QMessageBox::information(this, "notice", "delete failed!");
		}
	}
	else if (get == "pushButton_30") {
		QString str = ui.lineEdit_33->text();
		if (0 == str.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("delete from teacher where T_NAME = '"
				+ str + "'");
			if (value) {
				QMessageBox::information(this, "notice", "delete sucessful!");
				ui.lineEdit_33->clear();
			}
			else
				QMessageBox::information(this, "notice", "delete failed!");
		}
	}
	else if (get == "pushButton_22") {
		QString str = ui.lineEdit_25->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from teacher where T_NO = '"
				+ str + "'");
			ui.tableView_4->setModel(model);
		}
	}
	else if (get == "pushButton_21") {
		QString str = ui.lineEdit_26->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from teacher where T_NAME = '"
				+ str + "'");
			ui.tableView_4->setModel(model);
		}
	}
	else if (get == "pushButton_23") {
		QString str = ui.lineEdit_24->text();
		if (0 == str.isEmpty()) {
			QSqlQueryModel *model = new QSqlQueryModel;
			model->setQuery("select * from teacher where TECH_TITLE = '"
				+ str + "'");
			ui.tableView_4->setModel(model);
		}
	}
}

void Ed_system::tccourse_operation() /*教师授课信息管理*/
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton_67") {
		QString TCID = ui.lineEdit_87->text();
		QString T_NO = ui.lineEdit_83->text();
		QString SPNO = ui.lineEdit_86->text();
		QString CLASS_NO = ui.lineEdit_85->text();
		QString CNO = ui.lineEdit_84->text();

		if (0 == TCID.isEmpty() && 0 == T_NO.isEmpty() && 0 == SPNO.isEmpty()
			&& 0 == CLASS_NO.isEmpty() && 0 == CNO.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("insert into teacher_course values ('"
				+ TCID + "','" + T_NO + "','" + SPNO + "','"
				+ CLASS_NO + "','" + CNO + "')");
			if (value) {
				QMessageBox::information(this, "notice", "add sucessful!");
				ui.lineEdit_87->clear();
				ui.lineEdit_83->clear();
				ui.lineEdit_86->clear();
				ui.lineEdit_85->clear();
				ui.lineEdit_84->clear();
			}
			else
				QMessageBox::information(this, "notice", "add failed!");
		}
	}
	else if (get == "pushButton_31") {
		QString str = ui.lineEdit_34->text();
		if (0 == str.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("delete from teacher_course where CNO = '"
				+ str + "'");
			if (value) {
				QMessageBox::information(this, "notice", "delete sucessful!");
				ui.lineEdit_34->clear();
			}
			else
				QMessageBox::information(this, "notice", "delete failed!");
		}
	}
	else if (get == "pushButton_32") {
		QString str = ui.lineEdit_35->text();
		if (0 == str.isEmpty()) {
			QSqlQuery query;
			bool value = query.exec("delete from teacher_course where TCID = '"
				+ str + "'");
			if (value) {
				QMessageBox::information(this, "notice", "delete sucessful!");
				ui.lineEdit_35->clear();
			}
			else
				QMessageBox::information(this, "notice", "delete failed!");
		}
	}
	else if (get == "pushButton_25") {
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

void Ed_system::detail_clicked()
{
	QString get = this->sender()->objectName();
	QSqlQueryModel *model = new QSqlQueryModel;
	if (get == "pushButton") {
		model->setQuery("select * from student");
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
		model->setQuery("select * from teacher");
		ui.tableView_4->setModel(model);
	}
	else if (get == "pushButton_6") {
		model->setQuery("select * from teacher_course");
		ui.tableView_5->setModel(model);
	}
}