#include"admin.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
vector<ComputerRoom> vCom;
Manager::Manager() {

}
Manager::Manager(string name,string pwd) {
	this->m_name = name;
	this->m_Pwd = pwd;
	this->initVector();
	
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);
	ComputerRoom c;
	while (ifs >> c.m_comid && ifs >> c.m_maxmum) {
		vCom.push_back(c);
	}
	cout << "��ǰ��������" << vCom.size() << endl;
	ifs.close();
}
void printStudent(Student& s) {
	cout << "number:" << s.m_Id << "name:" << s.m_name << "password" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ� " << t.m_EmpId << " ������ " << t.m_name << " ���룺" << t.m_Pwd << endl;
}
void Manager::openMenu() {
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
void Manager::add() {
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	string filename;
	string tip;
	string errorTip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "input student number";
		errorTip = "ѧ���ظ�";
	}
	else {
		filename = TEACHER_FILE;
		tip = "input teacher number:";
		errorTip = "ְ�����ظ�����������";

	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) {
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	
	cout << "input  name" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();

}
void Manager::showPerson() {
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "����ѧ����Ϣ���£� " << endl;
		for_each(vstu.begin(), vstu.end(), printStudent);
	}
	else 
	{
			cout << "������ʦ��Ϣ���£� " << endl;
			for_each(vtea.begin(), vtea.end(), printTeacher);
	}
	system("pause");
	system("cls");
	
}
void Manager::showComputer() {
	cout << "������Ϣ���£� " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end();it++) {
		cout << "������ţ� " << it->m_comid << " ������������� " << it->m_maxmum << endl;
	}
	system("pause");
	system("cls");
}
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}
void Manager::initVector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "file read failed" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_name && ifs >> s.m_Pwd) {
		vstu.push_back(s);
	}
	cout << "the number of studnet is" << vstu.size() << endl;
	ifs.close();
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_name && ifs >> t.m_Pwd)
	{
		vtea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ�� " << vtea.size() << endl;

	ifs.close();
}
bool Manager::checkRepeat(int id,int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vtea.begin(); it != vtea.end(); it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}
	}
	return false;
	
}
