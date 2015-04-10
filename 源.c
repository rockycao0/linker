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
int main()
{
	int number[10];
	struct list *head;
	head = (struct list*)malloc(sizeof(struct list));
	head->date = NULL;
	head->next = NULL;
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &number[i]);
		insert(head, number[i]);
	}
	delate(head, 55);
	put(head);
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
	struct list *p,*q;
	p = (struct list*)malloc(sizeof(struct list));
	q = (struct list*)malloc(sizeof(struct list));
	p->date = num;
	q = head;
	while (p->date != (q->next->date)&&(q->next->next)!=NULL)
	{
		q = q->next;
	}
	if ((q->next->next) != NULL)
	{
		p->next = q->next;
		q->next = q->next->next;
		free(p);
	}
}