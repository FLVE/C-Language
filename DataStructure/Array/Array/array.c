#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>


struct Arr
{
	int* pBase;//存储的是数组第一个元素的地址
	int len;//数组所能存储的最大元素的个数
	int cnt;//当前数组有效元素的个数
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
		printf("删除成功！\n");
		printf("删除的数据为：%d\n",val);
	}
	show_arr(&arr);

	inversion_arr(&arr);
	printf("反序后的数组为");
	show_arr(&arr);

	sort_arr(&arr);
	printf("排序后的数组为");
	show_arr(&arr);

	return 0;
}

//初始化数组，动态分配内存
void init_arr(struct Arr* pArr,int length) 
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase)
	{
		printf("动态分配内存失败");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

//用来判断数组是否为空
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

//用来显示数组中的各个元素
void show_arr(struct Arr * pArr)
{
	if (is_empty(pArr))
	{
		printf("数组为空！");
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

//用来判断数组是否已满数据
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

//在数组末尾追加内容
bool append_arr(struct Arr* pArr, int i)
{
	//满时返回false
	if (is_full(pArr))
	{
		return false;
	}
	//不满追加
	pArr->pBase[pArr->cnt] = i;
	pArr->cnt++;

	return true;
}

//在数组中插入一位数据
bool insert_arr(struct Arr* pArr, int pos, int val)
{
	int i;
	//判断数据是否已满
	if (is_full(pArr))
	{
		return false;
	}
	//判断插入的位置是否正确
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

//在数组中删除一位数据
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

//数组反序
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

//数组排序（冒泡排序）
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