#include<stdio.h>
#include<stdlib.h>

void insert(linker head);
void delete(linker head,int a);
void find(linker head);
void print(linker *head);

struct slist
{
	int info;
	struct slist next;
};
typedef struct slist linker;
int main()
{
	int date,num;
	linker *head, p, q;
	head = NULL;
	head = (linker*)malloc(sizeof(linker*));
	p = head;
	scanf_s("%d", &date);
	printf("input the date,stop by enter an '-1'\n");
	while (date != -1)
	{
		p = q = (linker*)malloc(sizeof(linker*));
		p->info = date;
		if (p > 0)
		{
			if (head == NULL)
				head = p;
			else
				p->next = q;
			q = p;
			p = (linker*)malloc(sizeof(linker*));
			printf("p= %d\n", q);
		};
		scanf_s("%d", &date);
	};
	printf("insert enter 1\ndelete enter 2\n search enter 3\n stop with 0");
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:insert(head);
	case 2:scanf_s("%d", &date); delete(head,&date);
	case 3:scanf_s("%d", &date); find(head,&date);
	case 4:print(head);
	}
	return 0;
}
void insert(linker head)
{
	linker *tem;
	tem = head;
	int date;
	printf("please input the insert date\n");
	scanf_s("%d", &date);
	tem = (linker*)malloc(sizeof(linker*));
	tem->info = date;
	tem->next = NULL;
	free(tem);
}
void delete(linker head,int a)
{
	linker *p, *temp;
	p = head;
	while (p->info != a||p->next==NULL)
	{
		p = p->next;
	}
	if (p = NULL)
		printf("the date don't exist");
	else
		temp = p->next;
		p->next = p->next->next;
		free(temp);
}
void find(linker head,int date)
{
	linker *p;
	p = head;
	while (p->info != date)
	{
		p = p->next;
		if (p = NULL)
			break;
	};
}
void print(linker head)
{
	linker *p;
	p = head;
	while (p->next != NULL)
		printf("%d", p->info);
}