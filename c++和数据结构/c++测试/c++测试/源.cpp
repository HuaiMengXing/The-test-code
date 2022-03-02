#include<vector>
#include<deque>
#include<string>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<iostream>
#include<numeric>
#include<functional>
#include<algorithm>//算法
using namespace std;

//class person
//{
//public:
//	person(string name,int age,int height);
//
//	string m_name;
//	int m_age;
//	int m_height;
//};
//
//person::person(string name, int age,int height)
//{
//	m_name = name;
//	m_age = age;
//	m_height = height;
//}
//
////void test01()
////{
////	vector<person>v;
////
////	person p1("aaa", 10);
////	person p2("bbb", 20);
////	person p3("ccc", 30);
////	person p4("ddd", 40);
////	person p5("eee", 50);
////
////	v.push_back(p1);
////	v.push_back(p2);
////	v.push_back(p3);
////	v.push_back(p4);
////	v.push_back(p5);
////
////	
////}
//
////template<class T>
void Vectorprint(vector<int>&v)
{
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
//
//void Vectorprint01(vector<int>& v)
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//		cout << v.at(i) << " ";
//	}
//	cout << endl;
//}
//
////void print(person a)
////{
////	cout << a.m_name << "  " << a.m_age << endl;
////}
//
////void test02()
////{
////	vector<person>v;
////
////	person p1("aaa", 80);
////	person p2("bbb", 90);
////	person p3("ccc", 30);
////	person p4("ddd", 40);
////	person p5("eee", 50);
////
////	v.push_back(p1);
////	v.push_back(p2);
////	v.push_back(p3);
////	v.push_back(p4);
////	v.push_back(p5);
////
////	for_each(v.begin(), v.end(), print);
////}
//
//void test03()
//{
//	string s1 = "adcdefg";
//
//	s1.replace(3 ,1,"xx");
//
//	cout << s1 << endl;
//
//	s1.insert(1, "www");
//	cout << s1 << endl;
//
//	s1.erase(1, 2);
//	cout << s1 << endl;
//
//	string s3 = "zhangmingyu@ll.com";
//	int pos = s3.find('@');
//	string s2 = s3.substr(0, pos);
//	cout << s2 << endl;
//
//}
//
//void test04()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	Vectorprint(v1);
//
//	vector<int>v2;
//	v2 = v1;
//	Vectorprint(v2);
//
//	vector<int>v3,v4;
//	v3.assign(v1.begin(), v1.end());
//	Vectorprint(v3);
//
//	v4.assign(10, 11);
//	Vectorprint(v4);
//}
//
//void test05()
//{
//	vector<int>v1,v2,v3;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	Vectorprint(v1);
//
//	if (v1.empty())//判断是否为空
//	{
//		cout << "空" << endl;
//	}
//	else
//	{
//		cout<<"不为空" << endl;
//		cout << v1.capacity() << endl;//容量
//		cout << v1.size() << endl;//大小
//	}
//
//	v1.resize(15);//重新赋大小
//	Vectorprint(v1);
//	v1.resize(17, 11);
//	Vectorprint(v1);
// }
//
//void test06()
//{
//	vector<int>v1;
//	for (int i = 0; i < 5; i++)
//	{
//		v1.push_back(i);//尾插入
//	}
//	Vectorprint(v1);
//
//	v1.pop_back();//尾删除
//	Vectorprint(v1);
//
//	v1.insert(v1.begin(), 19);//插入
//	Vectorprint(v1);
//
//	v1.insert(v1.begin(), 2, 18);//区间插入
//	Vectorprint(v1);
//
//	v1.erase(v1.begin());//删除
//	Vectorprint(v1);
//
//	cout << "第一个" << v1.front() << endl;
//	cout << "最后一个" << v1.back() << endl;
//
//	Vectorprint01(v1);
//
//	v1.erase(v1.begin(), v1.end());//区间删除
//	Vectorprint(v1);
//
//	
//}
//
//void test07()
//{
//	vector<int>v,v1,v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	Vectorprint(v1);
//
//	for (int i = 9; i >= 0; i--)
//	{
//		v2.push_back(i);
//	}
//	Vectorprint(v2);
//
//	cout << "交换" << endl;
//	v1.swap(v2);//交换
//	Vectorprint(v1);
//	Vectorprint(v2);
//
//	for (int i = 0; i < 10000; i++)
//	{
//		v.push_back(i);
//	}
//	cout << v.capacity() << endl;//容量
//	cout << v.size() << endl;//大小
//	cout << endl;
//
//	v.resize(5);
//	cout << v.capacity() << endl;//容量
//	cout << v.size() << endl;//大小
//	cout << endl;
//
//	vector<int>(v).swap(v);//(v)匿名，匿名对象用完马上回收
//	cout << v.capacity() << endl;//容量
//	cout << v.size() << endl;//大小
//
//}
//
//void test08()
//{
//	vector<int>v;//数组
//	v.reserve(100000);//预留空间，减少动态开辟内存的次数（不可以指定）
//
//	int num = 0;
//	int* p = NULL;
//
//	for (int i = 0; i < 100000; i++)
//	{
//		v.push_back(i);
//
//		if (p!=&v[0])
//		{
//			p = &v[0];
//			num++;//看它开辟了多少次
//		}
//	}
//	cout << num<<endl;
//}
//
//void dequeprint(const deque<int>&d)//让它不可以改
//{
//	for (deque<int>::const_iterator i = d.begin(); i != d.end(); i++)
//	{
//		cout << *i << " ";
//	}
//	cout << endl;
//}
//
//void test09()
//{
//	deque<int>d;//队列
//	for (int i = 0; i < 10; i++)
//	{
//		d.push_back(i);
//	}
//	dequeprint(d);
//
//	deque<int>d2(d.begin(), d.end());//某一个函数区间内赋值
//	dequeprint(d2);
//
//	deque<int>d3(10, 11);//将n个elem拷贝
//	dequeprint(d3);
//
//	deque<int>d4(d3);//拷贝
//	dequeprint(d4);
//
//	deque<int>d5 = d2;//operator= 赋值
//	dequeprint(d5);
//
//	deque<int>d6;
//	d6.assign(d.begin(), d.end());
//	dequeprint(d6);
//
//	deque<int>d7;
//	d7.assign(10, 14);
//	dequeprint(d7);
//}
//
//void test10()
//{
//	deque<int>d;//没有容量的概念
//	for (int i = 0; i < 10; i++)
//	{
//		d.push_back(i);
//	}
//	dequeprint(d);
//
//	if (d.empty())
//	{
//
//		cout << "空" << endl;
//	}
//	else
//	{
//		cout << "不为空" << endl;
//		cout << "大小:" << d.size() << endl;
//	}
//
//	d.resize(15, 11);//重新指定大小
//	dequeprint(d);
//
//	d.resize(5);
//	dequeprint(d);
//}
//
//void test11()
//{
//	deque<int>d;
//	d.push_back(10);
//	d.push_back(11);//尾插入
//	d.push_front(9);
//	d.push_front(8);//头插入
//	dequeprint(d);
//
//	d.pop_back();//尾删除
//	d.pop_front();//头删除
//	dequeprint(d);//9 10
//	deque<int>d1 = d;
//
//	d.insert(d.begin(), 8);
//	d.insert(d.end(), 11);
//	d.insert(d.end(), 2, 12);
//	dequeprint(d);
//
//	d.insert(d.begin(),d1.begin(), d1.end());
//	dequeprint(d);//9 10 8 9 10 11 12 12
//
//	deque<int>::iterator it = d.begin();
//	it += 3;
//	d.erase(it);
//	dequeprint(d);
//
//	deque<int>::iterator t = d.begin();
//	t += 3;
//	d.erase(t, d.end());
//	dequeprint(d);
//
//	d.clear();
//	dequeprint(d);
//}
//
//void test12()
//{
//	deque<int>d;
//	d.push_back(11);
//	d.push_back(14);
//	d.push_back(17);
//	d.push_front(58);
//	d.push_front(65);
//	d.push_front(444);
//	dequeprint(d);
//	
//	//排序
//	sort(d.begin(), d.end());
//	dequeprint(d);
//}
//
////class person
////{
////public:
////	person(string name,double score)
////	{
////		m_name = name;
////		m_score = score;
////	}
////	~person()
////	{
////
////	}
////	string m_name;//姓名
////	double m_score;//分数
////};
//
//void createperson(vector<person>& v)
//{
//	string nameSeed = "ABCDE";
//	for (int i = 0; i < 5; i++)
//	{
//		string name = "选手";
//		name += nameSeed[i];
//
//		double score = 0;
//
//		//person p(name, score);
//		//v.push_back(p);
//	}
//}
//
////void vectorprint(const vector<person>&v)
////{
////	for (vector<person>::const_iterator it=v.begin();it!=v.end();it++)
////	{
////		cout << "姓名:" << it->m_name<<"  " << "分数:" << it->m_score << endl;
////	}
////}
//
//void setScore(vector<person>& v)
//{
//   
//	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		 deque<int>d;
//		for (int i = 0; i < 10; i++)
//		{
//			int score = rand() % 41 + 60;
//			d.push_back(score);
//			cout << score << " ";
//	
//		}
//		cout << endl;
//		sort(d.begin(), d.end());
//		d.pop_back();
//		d.pop_front();
//
//		int sum = 0;
//		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
//		{
//			sum += *dit;
//		}
//		 int a = d.size();
//		int avg = sum / a;
//
//		//it->m_score = avg;
//		//cout << "姓名:" << it->m_name << "  " << "分数:" << it->m_score << endl;
//		cout << endl;
//	}
//}
//
//void test13()
//{
//	stack<int>s;//先进后出
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	s.push(40);
//
//	while (!s.empty())
//	{
//		cout << s.top() << endl;
//
//		s.pop();
//
//		cout << s.size() << endl;
//	}
//}
//
//void test14()
//{
//	queue<person>q;//先进先出
//	string o = "ABCDE";
//	for (int i = 0; i < 5; i++)
//	{
//		string name = "xs";
//		name += o[i];
//	  // person p(name, i);
//	  // q.push(p);
//	}
//	//person p1("aa", 10);
//	//person p2("bb", 50);
//	//person p3("cc", 70);
//	//person p4("dd", 80);
//
//	//q.push(p1);
//	//q.push(p2);
//	//q.push(p3);
//	//q.push(p4);
//
//	while (!q.empty())
//	{
//		cout << q.front().m_name << "  " << q.front().m_age << endl;
//		cout << q.back().m_name << "  " << q.back().m_age << endl;
//		cout << q.size() << endl;
//		q.pop();
//	}
//	
//}
//
//void printlist(const list<int>&L)
//{
//	for (list<int>::const_iterator i=L.begin(); i!=L.end(); i++)
//	{
//		cout << *i <<" ";
//	}
//	cout << endl;
//}
//
//void test15()
//{
//	list<int>L;
//	for (int i = 0; i < 5; i++)
//	{
//		L.push_back(i);
//	}
//	printlist(L);
//
//	list<int>L1(L.begin(), L.end());
//	printlist(L1);
//
//	list<int>L2(L);
//	printlist(L2);
//
//	list<int>L3(5, 11);
//	printlist(L3);
//
//	list<int>L4;
//	L4 = L;
//	printlist(L4);
//
//	list<int>L5;
//	L5.assign(L.begin(), L.end());
//	printlist(L5);
//
//	L5.swap(L3);
//	printlist(L5);
//	printlist(L3);
//
//	if (L3.empty())
//	{
//		cout << "空";
//	}
//	else
//	{
//		cout << "不为空" << endl;
//	}
//
//	cout << "大小" << L3.size() << endl;
//	L3.resize(10, 11);
//	cout << "大小" << L3.size() << endl;
//	printlist(L3);
//}
//
//void test16()
//{
//	list<int>L;
//	for (int i = 0; i < 5; i++)
//	{
//		L.push_back(i);
//	}
//	L.push_front(6);
//	L.push_front(7);
//	printlist(L);
//	//6 7 0 1 2 3 4
//
//	L.pop_back();
//	L.pop_front();
//	printlist(L);
//	//6  0  1  2  3
//
//	L.insert(L.begin(), 7);
//	L.insert(L.end(), 4);
//	printlist(L);
//	//6 7 0 1 2 3 4
//
//	list<int>::iterator it = L.begin();
//	while (it!=L.end())
//	{
//		it++;
//	}
//	it--;
//	L.erase(L.begin());
//	L.erase(it);
//	printlist(L);
//	//6  0  1  2  3
//
//	L.push_back(11);
//	L.push_front(11);
//	printlist(L);
//	L.remove(11);
//	printlist(L);
//
//	L.clear();
//	printlist(L);
//}
//
//bool v(int v1, int v2)
//{
//	return v1 > v2;
//}
//
//void test17()
//{
//	list<int>L;
//	L.push_back(34);
//	L.push_back(41);
//	L.push_back(71);
//	L.push_back(45);
//	L.push_back(86);
//
//	printlist(L);
//	L.reverse();//反
//	printlist(L);
//
//	L.sort();
//	printlist(L);
//	L.sort(v);
//	printlist(L);
//
//}
//
//void printlist0(const list<person>& L)
//{
//	for (list<person>::const_iterator it=L.begin();it!=L.end();it++)
//	{
//		cout << it->m_name << "  " << it->m_age << "  " << it->m_height << endl;
//	}
//}
//
//bool compareperson(person& p1, person& p2)
//{
//	if (p1.m_age==p2.m_age)
//	{
//		return p1.m_height < p2.m_height;
//	}
//	else
//	{
//		return p1.m_age < p2.m_age;
//	}
//
//}
//
//void test18()
//{
//	list<person>L;
//	person p1("a", 35, 175);
//	person p2("b", 45, 180);
//	person p3("c", 40, 170);
//	person p4("d", 25, 190);
//	person p5("e", 35, 160);
//	person p6("f", 35, 200);
//
//	L.push_back(p1);
//	L.push_back(p2);
//	L.push_back(p3);
//	L.push_back(p4);
//	L.push_back(p5);
//	L.push_back(p6);
//
//	printlist0(L);
//
//	cout << "*****************************************" << endl;
//	L.sort(compareperson);
//	printlist0(L);
//	
//}
//
//void printset(set<int>& s)
//{
//	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout << *it << "  ";
//	}
//	cout << endl;
//}
//
//void test19()
//{
//	set<int>s;//二叉树
//	for (int i = 0; i < 5; i++)
//	{
//		s.insert(i);
//	}
//	printset(s);
//
//	set<int>s0 = s;
//
//	s.insert(7);
//	s.insert(6);
//	printset(s);
//
//	set<int>s1(s);
//	printset(s1);
//
//	set<int>s2;
//	s2 = s1;
//	printset(s2);
//
//	if (s2.empty())
//	{
//		cout << "空" << endl;
//	}
//	else
//	{
//		cout << "不为空" << endl;
//	}
//	cout << s2.size() << endl;
//	s2.swap(s0);
//	printset(s0);
//	printset(s2);
//
//}
//
//void test20()
//{
//	set<int>s;
//	for (int i = 0; i < 9; i++)
//	{
//		s.insert(i);
//	}
//	printset(s);
//
//	s.erase(s.begin());
//	printset(s);
//	s.erase(7);
//	printset(s);
//
//	s.erase(s.begin(), s.end());
//	printset(s);
//
//	set<int>s1;
//	for (int i = 0; i < 9; i++)
//	{
//		s1.insert(i);
//	}
//	printset(s1);
//
//	set<int>::const_iterator pos=s1.find(6);
//	if (pos==s1.end())
//	{
//		cout << "没有找到" << endl;
//	}
//	else
//	{
//		cout << "找到了,删除" << endl;
//		s1.erase(pos);
//	}
//	printset(s1);
//
//	set<int>s3;
//	pair<set<int>::iterator, bool>er = s3.insert(1);
//
//	if (er.second)
//	{
//		cout << "a" << endl;
//	}
//	else
//	{
//		cout << "b" << endl;
//	}
//
//	er = s3.insert(1);
//	if (er.second)
//	{
//		cout << "a" << endl;
//	}
//	else
//	{
//		cout << "b" << endl;
//	}
//
//	multiset<int>m;
//	m.insert(10);
//	m.insert(10);
//
//}
//
//void test21()//pair对组创建
//{
//	pair<string, int>p("Tom", 15);
//	cout << p.first << "  " << p.second << endl;
//
//	pair<string, int>p2 = make_pair("jerry", 12);
//	cout << p2.first << "  " << p2.second << endl;
//
//	pair<int, int>p3;
//	p3.first = 10;
//	p3.second = 15;
//	cout << p3.first << p3.second << endl;
//}
//
//class MYset//仿函数
//{
//public:
//	bool operator()(int s1, int s2)const
//	{
//		return s1 > s2;
//	}
//private:
//};
//
//void test22()
//{
//	set<int>s;
//	s.insert(11);
//	s.insert(21);
//	s.insert(13);
//	s.insert(41);
//	s.insert(10);
//	printset(s);
//
//	set<int,MYset>s1;
//	s1.insert(11);
//	s1.insert(21);
//	s1.insert(13);
//	s1.insert(41);
//	s1.insert(10);
//
//	for (set<int,MYset>::iterator i = s1.begin(); i != s1.end(); i++)
//	{
//		cout << *i << "  ";
//	}
//	cout << endl;
//}
//
class Person
{
public:

	bool operator==(const Person&p)
	{
		if (this->m_name==p.m_name&&this->m_age==p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
//
//class setperson
//{
//public:
//	bool operator()(const Person& p1,const Person& p2)const
//	{
//		return p1.m_age > p2.m_age;
//	}
//private:
//
//};
//
//void test23()
//{
//	Person p1("aa", 15);
//	Person p2("bb", 35);
//	Person p3("cc", 25);
//	Person p4("dd", 45);
//
//	set<Person, setperson>s;
//	s.insert(p1);
//	s.insert(p2);
//	s.insert(p3);
//	s.insert(p4);
//
//	for (set<Person,setperson>::iterator i = s.begin(); i !=s.end(); i++)
//	{
//		cout << i->m_name << "  " << i->m_age << endl;
//	}
//}
//
//void mapprint(map<int, int>& m)
//{
//	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
//	{
//		cout <<"key="<< i->first << "  " << "value="<<i->second << endl;
//	}
//	cout << endl;
//}
//
//void test24()//map散列表
//{
//	map<int, int>m;
//	m.insert(pair<int, int>(1, 12));
//	m.insert(pair<int, int>(3, 32));
//	m.insert(pair<int, int>(4, 42));
//	m.insert(pair<int, int>(2, 22));
//	mapprint(m);
//
//	map<int, int>m2(m);
//	mapprint(m2);
//
//	map<int, int>m3;
//	m3 = m;
//	mapprint(m3);
//
//	if (m3.empty())
//	{
//		cout << " " << endl;
//	}
//	else
//	{
//		cout << "不为空" << endl;
//		cout << "大小为;" << m3.size() << endl;
//	}
//
//	map<int, int>m4;
//	m4.insert(pair<int, int>(5, 12));
//	m4.insert(pair<int, int>(6, 32));
//	m4.insert(pair<int, int>(8, 42));
//	m4.insert(pair<int, int>(7, 22));
//	mapprint(m4);
//
//	cout << "后：" << endl;
//
//	m4.swap(m3);
//	mapprint(m3);
//	mapprint(m4);
//}
//
//void test25()
//{
//	map<int, int>m;
//	m.insert(make_pair(1, 11));//好用
//	m.insert(map<int, int>::value_type(2, 12));
//	m[3] = 14;
//	m[3] = 13;//误插
//	m.insert(pair<int, int>(4, 14));
//	mapprint(m);
//
//	cout << m[3] << endl;
//
//	m.erase(m.begin());
//	mapprint(m);
//
//	m.erase(3);
//	mapprint(m);
//
//	m.clear();
//	mapprint(m);
//}
//
//class mappx
//{
//public:
//	bool operator()(int v1,int v2)const
//	{
//		return v1 > v2;
//	}
//private:
//
//};
//
//void test26()
//{
//	map<int, int>m;
//	m.insert(make_pair(1, 11));
//	m.insert(make_pair(2, 12));
//	m.insert(make_pair(3, 13));
//	m.insert(make_pair(4, 14));
//	m.insert(make_pair(5, 15));
//	mapprint(m);
//
//	map<int, int>::iterator pos = m.find(3);
//	cout << "key=" << pos->first << "value=" << pos->second << endl;
//	int mun = m.count(3);
//	cout << mun << endl;
//
//	map<int, int,mappx>m1;
//	m1.insert(make_pair(1, 11));
//	m1.insert(make_pair(2, 12));
//	m1.insert(make_pair(3, 13));
//	m1.insert(make_pair(4, 14));
//	m1.insert(make_pair(5, 15));
//	for (map<int, int,mappx>::iterator i = m1.begin(); i != m1.end(); i++)
//	{
//		cout << "key=" << i->first << "  " << "value=" << i->second << endl;
//	}
//}
//
////案例
//#define CEHUA 1
//#define MEISHU 2
//#define YANFA 3
//
//class Worker
//{
//public:
//	string m_Name;
//	int m_Salary=0;//工资
//private:
//
//};
//
//void setGroup(vector<Worker>& v, multimap<int, Worker>& m)	//员工分组 
//{
//	for (vector<Worker>::iterator i = v.begin(); i != v.end(); i++)
//	{
//		int deptId = rand() %3+1;//(b-a)+a => [a,b)
//
//		m.insert(make_pair(deptId, *i));
//	}
//}
//
//void showWorkerByGourp(multimap<int, Worker>& m)	//分组显示员工
//{
//	cout << "策划部门：" << endl;
//	multimap<int,Worker>::iterator pos = m.find(CEHUA);
//	int count = (int)m.count(CEHUA);
//	int index = 0;
//
//	for (;index<count; pos++,index++)
//	{
//		cout << "姓名：" << pos->second.m_Name << "  " << "工资：" << pos->second.m_Salary << endl;
//	}
//
//	cout << "-----------------------------------" << endl;
//	cout << "美术部门：" << endl;
//	pos = m.find(MEISHU);
//	count = m.count(MEISHU);
//	index = 0;
//	for (; index < count; pos++, index++)
//	{
//		cout << "姓名：" << pos->second.m_Name << "  " << "工资：" << pos->second.m_Salary << endl;
//	}
//
//	cout << "-----------------------------------" << endl;
//	cout << "研发部门：" << endl;
//	pos = m.find(YANFA);
//	count = (int)m.count(YANFA);
//	index = 0;
//	for (; index < count; pos++, index++)
//	{
//		cout << "姓名：" << pos->second.m_Name << "  " << "工资：" << pos->second.m_Salary << endl;
//	}
//}
//
//void test27()
//{
//	vector<Worker>vWorker;
//	string nameSeed = "ABCDEFGHIJ";
//	for (int i = 0; i < 10; i++)
//	{
//		Worker worker;
//		worker.m_Name = "员工";
//		worker.m_Name += nameSeed[i];
//
//		worker.m_Salary = rand() % 10001 + 30000;
//
//		vWorker.push_back(worker);
//	}
//	//员工分组 
//	multimap<int, Worker>mWorker;
//	setGroup(vWorker,mWorker);
//
//	//分组显示员工
//	showWorkerByGourp(mWorker);
//	
//	//for (vector<Worker>::iterator i = vWorker.begin(); i != vWorker.end(); i++)
//	//{
//	//	cout << "姓名：" << i->m_Name <<"  " << "工资：" << i->m_Salary << endl;
//	//}
//}
//
//class Myadd
//{
//public:
//	int operator()(int a,int b)
//	{
//		return a + b;
//	}
//private:
//
//};
//
//void test28()
//{
//	Myadd add;
//	cout << add(10, 12) << endl;
//}
//
//class GreaterFive
//{
//public:
//	bool operator()(int vel)
//	{
//		return vel > 5;
//	}
//private:
//
//};
//
//class Compare
//{
//public:
//	bool operator()(int v1, int v2)
//	{
//		return v1 > v2;
//	}
//private:
//
//};
//
//void test29()
//{
//	vector<int>v;
//	for (int i = 0; i < 8; i++)
//	{
//		v.push_back(i);
//	}
//
//	sort(v.begin(), v.end(), Compare());
//	Vectorprint(v);
//
//	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
//	if (it==v.end())
//	{
//		cout << "没有找到" << endl;
//	}
//	else
//	{
//		cout << "找到了:" << *it << endl;;
//	}
//}

void test30()
{
	negate<int>n;//取反
	cout << n(5) << endl;

	plus<int>p;//加法
	cout << p(15, 16) << endl;

	minus<int>m;//减法
	cout << m(56, 6) << endl;

	multiplies<int>m1;//乘法
	cout << m1(10, 10) << endl;

	modulus<int>m0;
	cout << m0(101, 10) << endl;
}

void test31()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(60);
	v.push_back(20);

	Vectorprint(v);

	sort(v.begin(), v.end(), greater<int>());//greater 大于仿函数
	Vectorprint(v);
}

void print(int v1)
{
	cout << v1 << "  ";
}

class Print
{
public:
	void operator()(int v2)
	{
		cout << v2 << " ";
	}
private:

};

class Myprint
{
public:
	int operator()(int v2)
	{
		return v2 + 1;
	}
private:

};

void test32()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>v1;
	v1.resize(v.size());//提前开辟空间

	transform(v.begin(), v.end(), v1.begin(), Myprint());//搬运函数

	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	for_each(v.begin(), v.end(), Print());
	cout << endl;
}

class Great5
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
private:

};

class Great23
{
public:
	bool operator()(Person &p)
	{
		return p.m_age > 23;
	}
private:

};

void test33()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it==v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到：" << *it << endl;
	}

	vector<int>::iterator it1 = find_if(v.begin(), v.end(), Great5());
	if (it1 == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到：" << *it1 << endl;
	}

	vector<Person>v1;

	Person p1("aaa", 15);
	Person p2("bbb", 25);
	Person p3("ccc", 35);
	Person p4("ddd", 45);
	Person p5("eee", 55);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);

	Person pp("bbb", 25);

	vector<Person>::iterator t = find(v1.begin(), v1.end(), pp);
	if (t == v1.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到  姓名：" << t->m_name <<"年龄:"<<t->m_age<< endl;
	}

	vector<Person>::iterator t1 = find_if(v1.begin(), v1.end(), Great23());
	if (t1 == v1.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到  姓名：" << t1->m_name << "年龄:" << t1->m_age << endl;
	}
}

void test34()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(5);
	v.push_back(5);
	v.push_back(1);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());//查找相邻重复元素
	if (pos==v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到：" << *pos << endl;
	}
}

void test35()
{
	set<int>s;
	s.insert(2);
	s.insert(1);
	s.insert(3);
	s.insert(8);
	s.insert(7);
	s.insert(5);

	bool o = binary_search(s.begin(), s.end(), 5);//折半查找
	if (o)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}

class AgeGreat
{
public:
	bool operator()(Person& p)
	{
		return p.m_age > 23;
	}
private:

};

void test36()
{
	vector<Person>v;

	Person p1("aa", 24);
	Person p2("bb", 14);
	Person p3("cc", 24);
	Person p4("dd", 64);
	Person p5("ee", 24);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = (int)count_if(v.begin(), v.end(), AgeGreat());
	cout << num << endl;
}

void test37()
{
	srand((unsigned int)time(NULL));//随机种子

	vector<int>v,v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i + 1);
	}

	vector<int>vTarget;
	vTarget.resize(v.size() + v1.size());

	merge(v.begin(), v.end(), v1.begin(), v1.end(), vTarget.begin());//合并
	//random_shuffle(v.begin(), v.end());//打乱
	replace(vTarget.begin(), vTarget.end(), 2, 2000);//替换

	for_each(vTarget.begin(), vTarget.end(), print);
	cout << endl;

	replace_if(vTarget.begin(), vTarget.end(), Great5(), 100);
	for_each(vTarget.begin(), vTarget.end(), print);
	cout << endl;

	fill(vTarget.begin(), vTarget.end(), 100);//区间内数据换成100

	int total = accumulate(vTarget.begin(), vTarget.end(), 0);//累计算法
	cout << total << endl;
}

void test38()
{
	vector<int>s1,s2;
	for (int i = 0; i < 10; i++)
	{
		s1.push_back(i);
		s2.push_back(i + 5);
	}

	vector<int>s3,s4;
	s3.resize(min(s1.size(), s2.size()));
	s4.resize(s1.size() + s2.size());
	vector<int>::iterator it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), s3.begin());
	for_each(s3.begin(),it, print);
	cout << endl;

	vector<int>::iterator itEnd = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), s4.begin());
	for_each(s4.begin(), itEnd, print);
	cout << endl;
}

void test39()
{
	string str = "abcdefg";
	int num = str.find("e", 0);
	int num1 = str.find("p", 2);
	string m = str.substr(2, 3);
	cout << num << endl;
	cout << num1 << endl;
	cout << m << endl;
}

int main()
{
	//test01();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	//test11();
	//test12();
	/*vector<person>v;
	createperson(v);
	setScore(v);
	*/
	//test13();
	//test14();
	//test15();
	//test16();
	//test17();
	//test18();
	//test19();
	//test20();
	//test21();
	//test22();
	//test23();
	//test24();
	//test25();
	//test26();
	//test27();
	//test28();
	//test29();
	//test30();
	//test31();
	//test32();
	//test33();

	//test34();
	//test35();
	//test36();
	//test37();
	//test38();
	test39();
    system("pause");
	return 0;
}