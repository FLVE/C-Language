#include<stdio.h>
#include<string.h>

struct Student
{
	int sid;
	char sname[100];
	int sage;
};


int main(void) {
	/*
	����һ
	struct Student st = { 1000,"zhangsan",20 };

	printf("%d %s %d",st.sid,st.sname,st.sage);

	printf("\n");
	st.sid = 2000;
	strcpy(st.sname,"lisi");
	st.sage = 30;
	printf("%d %s %d", st.sid, st.sname, st.sage);
	*/
	
	//������
	struct Student st = { 1000,"zhangsan",20 };
	struct Student* pst;
	pst = &st;
	pst->sid = 99;

	printf("%d %s %d", pst->sid, pst->sname, pst->sage);

	return 0;
}