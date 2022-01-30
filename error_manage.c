#include "main.h"

int	chk_lst_srt(t_stck *stck)
{
	t_stck	*tmp;

	tmp = stck;
	while (tmp->nxt)
	{
		if (tmp->n > tmp->nxt->n)
			return (1);
		tmp = tmp->nxt;
	}
	return (0);
}

void	stcks_free(t_2_stcks *stcks)
{
	int		i;
	t_stck	*del;
	t_stck	*cur;

	i = 0;
	cur = stcks->a_stck;
	while (i < stcks->a_stck_len)
	{
		del = cur;
		cur = cur->nxt;
		free(del);
		i++;
	}
}

void	error_out(int flg)
{
	if (flg == 1)
		write(0, "No such command\nError\n", 22);
	else if (flg == 2)
		write(0, "Empty number\nError\n", 19);
	else if (flg == 3)
		write(0, "Non-digit symbol\nError\n", 23);
	else if (flg == 4)
		write(0, "Duplicated numbers\nError\n", 25);
	else if (flg == 5)
		write(0, "No arguments\nError\n", 19);
	else if (flg == 6)
		write(0, "Empty list\nError\n", 17);
	else if (flg == 7)
		write(0, "Memory allocation for numbers array\nError\n", 42);
	else if (flg == 8)
		write(0, "Empty new list\nError\n", 21);
	else if (flg == 9)
		write(0, "Bad stacks initialization\nError\n", 32);
	else if (flg == 10)
		write(0, "Bad split-function usage\nError\n", 31);
	else
		write(0, "Error\n", 6);
	exit(1);
}

int	chk_srt(t_ns *ns)
{
	int	i;

	i = 0;
	while (i < ns->arr_len - 1)
	{
		if (ns->ns_arr[i] > ns->ns_arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}
