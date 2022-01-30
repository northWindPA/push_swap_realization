#include "main.h"

void	rr(t_2_stcks *stcks, int w_m)
{
	ra(stcks, 0);
	rb(stcks, 0);
    if (w_m)
        write(1, "rr\n", 3);
}

void	pa(t_2_stcks *stcks, int w_m)
{
	t_stck	*tmp;
	t_stck	*new;

	if (!stcks->b_stck_len)
		return ;
	tmp = stcks->b_stck;
	stcks->a_stck_len++;
	new = nw_lst(stcks->b_stck->n, stcks->b_stck->n_in);
	if (!new)
		error_out(8);
	lst_pf(&stcks->a_stck, new);
	stcks->b_stck = stcks->b_stck->nxt;
	free(tmp);
	stcks->b_stck_len--;
	if (w_m)
		write(1, "pa\n", 3);
}

void	rb(t_2_stcks *stcks, int w_m)
{
    int		i;
    t_stck	*tmp_1;
    t_stck	*tmp_2;

    if (stcks->b_stck_len < 2)
        return ;
    tmp_1 = stcks->b_stck;
    i = 0;
    while (i < stcks->b_stck_len - 1)
    {
        tmp_1 = tmp_1->nxt;
        i++;
    }
    tmp_2 = stcks->b_stck->nxt;
	stcks->b_stck->nxt = NULL;
    tmp_1->nxt = stcks->b_stck;
	stcks->b_stck = tmp_2;
    if (w_m)
        write(1, "rb\n", 3);
}

void	pb(t_2_stcks *stcks, int w_m)
{
	t_stck	*tmp;
	t_stck	*new;

	if (!stcks->a_stck_len)
		return ;
	tmp = stcks->a_stck;
	stcks->b_stck_len++;
	new = nw_lst(stcks->a_stck->n, stcks->a_stck->n_in);
	if (!new)
		error_out(8);
	lst_pf(&stcks->b_stck, new);
	stcks->a_stck = stcks->a_stck->nxt;
	free(tmp);
	stcks->a_stck_len--;
	if (w_m)
		write(1, "pb\n", 3);
}

void	ra(t_2_stcks *stcks, int w_m)
{
    t_stck	*tmp_1;
    t_stck	*tmp_2;

    if (stcks->a_stck_len < 2)
        return ;
    tmp_1 = stcks->a_stck;
    while (tmp_1->nxt)
        tmp_1 = tmp_1->nxt;
    tmp_2 = stcks->a_stck->nxt;
	stcks->a_stck->nxt = NULL;
    tmp_1->nxt = stcks->a_stck;
	stcks->a_stck = tmp_2;
    if (w_m)
        write(1, "ra\n", 3);
}
