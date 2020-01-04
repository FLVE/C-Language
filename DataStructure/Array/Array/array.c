#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>


struct Arr
{
	int* pBase;//�洢���������һ��Ԫ�صĵ�ַ
	int len;//�������ܴ洢�����Ԫ�صĸ���
	int cnt;//��ǰ������ЧԪ�صĸ���
};

void init_arr(struct Arr * pArr, int length);
bool is_empty(struct Arr* pArr);
void show_arr(struct Arr* pArr);
bool is_full(struct Arr* pArr);
bool append_arr(struct Arr * pArr,int i);
bool insert_arr(struct Arr* pArr, int pos, int val);
bool delete_arr(struct Arr* pArr, int pos,int* pVal);
void inversion_arr(struct Arr* pArr);
bool sort_arr(struct Arr* pArr);
bool deleteAll_arr();
int get();




int main(void) 
{
	struct Arr arr;
	int val;

	init_arr(&arr,6);
	show_arr(&arr);

	printf("\n");
	/*
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4); 
	append_arr(&arr, 5);
	*/
	//append_arr(&arr, 6);
	append_arr(&arr, 34);
	append_arr(&arr, 87);
	append_arr(&arr, 12);
	append_arr(&arr, 20);
	append_arr(&arr, 92);
	append_arr(&arr, 37);
	show_arr(&arr);

	insert_arr(&arr, 3, 78);
	show_arr(&arr);

	if (delete_arr(&arr, 3, &val))
	{
		printf("ɾ���ɹ���\n");
		printf("ɾ��������Ϊ��%d\n",val);
	}
	show_arr(&arr);

	inversion_arr(&arr);
	printf("����������Ϊ");
	show_arr(&arr);

	sort_arr(&arr);
	printf("����������Ϊ");
	show_arr(&arr);

	return 0;
}

//��ʼ�����飬��̬�����ڴ�
void init_arr(struct Arr* pArr,int length) 
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase)
	{
		printf("��̬�����ڴ�ʧ��");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

//�����ж������Ƿ�Ϊ��
bool is_empty(struct Arr * pArr)
{
	if (0 == pArr->cnt) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

//������ʾ�����еĸ���Ԫ��
void show_arr(struct Arr * pArr)
{
	if (is_empty(pArr))
	{
		printf("����Ϊ�գ�");
	}
	else
	{
		for (int i = 0; i < pArr->cnt; i++)
		{
			printf("%d    ", pArr->pBase[i]);
		}
		printf("\n");
	}
	
}

//�����ж������Ƿ���������
bool is_full(struct Arr * pArr)
{
	if (pArr->cnt == pArr->len)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

//������ĩβ׷������
bool append_arr(struct Arr* pArr, int i)
{
	//��ʱ����false
	if (is_full(pArr))
	{
		return false;
	}
	//����׷��
	pArr->pBase[pArr->cnt] = i;
	pArr->cnt++;

	return true;
}

//�������в���һλ����
bool insert_arr(struct Arr* pArr, int pos, int val)
{
	int i;
	//�ж������Ƿ�����
	if (is_full(pArr))
	{
		return false;
	}
	//�жϲ����λ���Ƿ���ȷ
	if (pos < 1 || pos > pArr->cnt+1)
	{
		return false;
	}
	for (i = pArr->cnt-1; i >= pos-1; i--)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	pArr->cnt++;

	return true;

}

//��������ɾ��һλ����
bool delete_arr(struct Arr* pArr, int pos,int* pVal)
{
	int i;
	if (is_empty(pArr))
	{
		return false;
	}
	if (pos < 1 || pos >= pArr->cnt-1)
	{
		return false;
	}
	*pVal = pArr->pBase[pos - 1];
	for (i = pos; i < pArr->cnt; i++)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}

//���鷴��
void inversion_arr(struct Arr* pArr)
{
	if (is_empty(pArr))
	{
		return false;
	}
	int i = 0;
	int j = pArr->cnt-1;
	int temp;

	while (i < j)
	{
		temp = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = temp;
		i++;
		j--;
	}
	return;
}

//��������ð������
bool sort_arr(struct Arr* pArr)
{
	int i,j,temp;

	for (i = 0; i < pArr->cnt; i++)
	{
		for (j = i+1; j <pArr->cnt ; j++)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				temp = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = temp;
			}
		}
	}
}