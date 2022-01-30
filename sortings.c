#include "main.h"

void	mn_srt(t_2_stcks *stcks, t_cmds *cmds)
{
	int	min;
	int	index_of_min;

	while (stcks->a_stck_len > 5)
		pb(stcks, 1);
	fv_srt(stcks);
	mn_srt_st(stcks, cmds);
	min = get_min(stcks->a_stck);
	index_of_min = get_in(stcks->a_stck, min);
	while (stcks->a_stck->n != min)
	{
		if (index_of_min <= stcks->a_stck_len / 2)
			ra(stcks, 1);
		else
			rra(stcks, 1);
	}
}

void	fv_srt(t_2_stcks *stcks)
{
    int	i;
    int	min;
    int	max;

    i = stcks->b_stck_len;
    min = get_min(stcks->a_stck);
    max = get_max(stcks->a_stck);
    while (stcks->b_stck_len - i != 2)
    {
        if (stcks->a_stck->n == min || stcks->a_stck->n == max)
			pb(stcks, 1);
        else
			ra(stcks, 1);
    }
	sml_srt(stcks);
	pa(stcks, 1);
	pa(stcks, 1);
    if (stcks->a_stck->n == max)
		ra(stcks, 1);
    else
    {
		sa(stcks, 1);
		ra(stcks, 1);
    }
}

void	mn_srt_st(t_2_stcks *stcks, t_cmds *cmds)
{
	while (stcks->b_stck_len)
	{
		mn_srt_cmds_init(stcks, cmds);
		get_a_cmds(stcks, cmds);
		get_b_cmds(stcks, cmds);
		get_all_cmds(stcks, cmds);
		find_min_cmds(stcks, cmds);
		get_min_cmds(cmds);
		take_min_cmds(stcks, cmds);
		pa(stcks, 1);
		free(cmds->stps_a);
		free(cmds->stps_b);
		free(cmds->stck_a_cmds);
		free(cmds->stck_b_cmds);
		free(cmds->stcks_2_cmds);
	}
}

void	sml_srt(t_2_stcks *stcks)
{
    int	max;

    max = get_max(stcks->a_stck);
    if (stcks->a_stck_len == 1)
        return ;
    else if (stcks->a_stck_len == 2)
    {
        if (stcks->a_stck->n > stcks->a_stck->nxt->n)
			sa(stcks, 1);
    }
    else if (stcks->a_stck_len == 3)
    {
        if (stcks->a_stck->n == max)
			ra(stcks, 1);
        if (stcks->a_stck->nxt->n == max)
			rra(stcks, 1);
        if (stcks->a_stck->n > stcks->a_stck->nxt->n)
			sa(stcks, 1);
    }
}

void	mn_srt_cmds_init(t_2_stcks *stcks, t_cmds *cmds)
{
	cmds->chng_a_stck = 0;
	cmds->chng_b_stck = 0;
	cmds->chng_2_stcks = 0;
	cmds->in = 0;
	cmds->stps_a = (int *)ft_calloc(sizeof(int), stcks->b_stck_len);
	cmds->stps_b = (int *)ft_calloc(sizeof(int), stcks->b_stck_len);
	cmds->stck_a_cmds = (char **)ft_calloc(sizeof(char *), stcks->b_stck_len);
	cmds->stck_b_cmds = (char **)ft_calloc(sizeof(char *), stcks->b_stck_len);
	cmds->stcks_2_cmds = (int *)ft_calloc(sizeof(int), stcks->b_stck_len);
	if (!(cmds->stps_a && cmds->stps_b && cmds->stck_a_cmds && \
			cmds->stck_b_cmds && cmds->stcks_2_cmds))
		error_out(9);
}
