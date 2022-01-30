#include "main.h"

void	sb(t_2_stcks *stcks, int w_m)
{
	t_stck	*tmp;

	if (stcks->b_stck_len < 2)
		return ;
	tmp = stcks->b_stck->nxt;
	stcks->b_stck->nxt = stcks->b_stck->nxt->nxt;
	tmp->nxt = stcks->b_stck;
	stcks->b_stck = tmp;
	if (w_m)
		write(1, "sb\n", 3);
}

void	lst_pb(t_stck **stck, t_stck *n_n)
{
	t_stck	*last;

	last = l_lst(*stck);
	if (last)
		last->nxt = n_n;
	else
		*stck = n_n;
}

void	ss(t_2_stcks *stcks, int w_m)
{
	sa(stcks, 0);
	sb(stcks, 0);
	if (w_m)
		write(1, "ss\n", 3);
}

t_stck	*nw_lst(int n, int in)
{
	t_stck	*new;

	new = malloc(sizeof(t_stck));
	if (!new)
		return (NULL);
	new->n = n;
	new->n_in = in;
	new->nxt = NULL;
	return (new);
}

void	sa(t_2_stcks *stcks, int w_m)
{
	t_stck	*tmp;

	if (stcks->a_stck_len < 2)
		return ;
	tmp = stcks->a_stck->nxt;
	stcks->a_stck->nxt = stcks->a_stck->nxt->nxt;
	tmp->nxt = stcks->a_stck;
	stcks->a_stck = tmp;
	if (w_m)
		write(1, "sa\n", 3);
}
