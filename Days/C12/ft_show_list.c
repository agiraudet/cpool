#include "ft_list.h"

void	ft_show_list(t_list **begin_list)
{
	t_list *read;
	int *x;

	read = *begin_list;
	while (read)
	{
		x = (int *)read->data;
		printf("%d\n", *x);
		read = read->next;
	}
}

int main()
{
	t_list **begin_list;
	t_list *elem1;

	int data = 42;
	elem1 = ft_create_elem(data);
	*begin_list->next = elem1;

	ft_show_list(begin_list);
}:w

