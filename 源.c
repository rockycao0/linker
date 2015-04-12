#include <stdio.h>
#include <stdlib.h>


struct list
{
	int date;
	struct list *next;
};
void insert(struct list *head, int num);
void put(struct list *head);
void delate(struct list *head, int num);
void find(struct list *head, int num);
int main()
{
	int number;
	struct list *head;
	head = (struct list*)malloc(sizeof(struct list));
	head->date = 0;
	head->next = NULL;
	while (1)
	{
	scanf_s("%d", &number);
	if (number < 0)
	break;
	insert(head, number);
	}
	while (1)
	{
		int i;
		printf("if you want to do action below\n");
		printf("intsert for 1\n");
		printf("delate for 2\n");
		printf("find for 3\n");
		printf("printf for 4\n");
		printf("stop for 0\n");
		scanf_s("%d", &i);
		if (i > 0)
		{
			printf("enter the number\n");
			scanf_s("%d", &number);
			switch  (i)
			{
				case 1:insert(head, number);
					break;
				case 2:delate(head, number);
					break;
				case 3:find(head, number);
					break;
				case 4:put(head);
					break;
				default:printf("wrong number\n");
			}
		}
		printf("-------------------------------\n\n");
		if (i == 0)
			break;
	}
	system("pause");
	return 0;
}
void insert(struct list *head, int num)
{
	struct list *p;
	p = (struct list*)malloc(sizeof(struct list));
	p->date = num;
	p->next = head->next;
	head->next = p;
}
void put(struct list *head)
{
	struct list *p;
	p = (struct list*)malloc(sizeof(struct list));
	p = head;
	while (p != NULL)
	{
		printf("%5d\n", p->date);
		p = p->next;
	}
}
void delate(struct list *head, int num)
{
	struct list *p, *q;
	p = (struct list*)malloc(sizeof(struct list));
	q = (struct list*)malloc(sizeof(struct list));
	p->date = num;
	q = head;
	while (p->date != (q->next->date) && (q->next->next) != NULL)
	{
		q = q->next;
	}
	if ((q->next->next) != NULL)
	{
		p->next = q->next;
		q->next = q->next->next;
		free(p);
	}
	printf("delate\n");
}
void find(struct list *head, int num)
{
	struct list *p;
	p = (struct list*)malloc(sizeof(struct list*));
	p = head;
	int i = 0;
	while (p->next != NULL)
	{
		if (p->date == num)
			printf("the NO.%d point\n", i);
		i++;
		p = p->next;
	}
}