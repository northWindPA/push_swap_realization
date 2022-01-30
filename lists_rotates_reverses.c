#include "main.h"

void	rrr(t_2_stcks *stcks, int w_m)
{
	rra(stcks, 0);
	rrb(stcks, 0);
	if (w_m)
		write(1, "rrr\n", 4);
}

void	lst_pf(t_stck **stck, t_stck *n_n)
{
	n_n->nxt = *stck;
	*stck = n_n;
}

void	rra(t_2_stcks *stcks, int w_m)
{
	t_stck	*tmp;

	if (stcks->a_stck_len < 2)
		return ;
	tmp = stcks->a_stck;
	while (tmp->nxt->nxt)
		tmp = tmp->nxt;
	tmp->nxt->nxt = stcks->a_stck;
	stcks->a_stck = tmp->nxt;
	tmp->nxt = NULL;
	if (w_m)
		write(1, "rra\n", 4);
}

t_stck	*l_lst(t_stck *stck)
{
	if (stck)
	{
		while (stck->nxt)
			stck = stck->nxt;
		return (stck);
	}
	return (NULL);
}

void	rrb(t_2_stcks *stcks, int w_m)
{
	int		i;
	t_stck	*tmp;

	if (stcks->b_stck_len < 2)
		return ;
	tmp = stcks->b_stck;
	i = 0;
	while (i < stcks->b_stck_len - 2)
	{
		tmp = tmp->nxt;
		i++;
	}
	tmp->nxt->nxt = stcks->b_stck;
	stcks->b_stck = tmp->nxt;
	tmp->nxt = NULL;
	if (w_m)
		write(1, "rrb\n", 4);
}
