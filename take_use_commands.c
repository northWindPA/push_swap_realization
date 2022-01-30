#include "main.h"

void	exec_min_cmds(t_2_stcks *stcks, t_cmds *cmds, int min, int i)
{
	int	index;

	index = get_in(stcks->a_stck, min);
	if (index <= stcks->a_stck_len / 2)
	{
		cmds->stps_a[i] = index;
		cmds->stck_a_cmds[i] = "ra";
	}
	else
	{
		cmds->stps_a[i] = stcks->a_stck_len - index;
		cmds->stck_a_cmds[i] = "rra";
	}
}

void	get_b_cmds(t_2_stcks *stcks, t_cmds *cmds)
{
	int	i;

	i = 0;
	while (++i < stcks->b_stck_len)
	{
		if (i <= stcks->b_stck_len / 2)
		{
			cmds->stps_b[i] = i;
			cmds->stck_b_cmds[i] = "rb";
		}
		else
		{
			cmds->stps_b[i] = stcks->b_stck_len - i;
			cmds->stck_b_cmds[i] = "rrb";
		}
	}
	if (stcks->b_stck_len % 2 == 0)
		if (!ft_strncmp(cmds->stck_a_cmds[stcks->b_stck_len / 2], "rra", 100))
			cmds->stck_b_cmds[stcks->b_stck_len / 2] = "rrb";
}

void	exec_mid_cmds(t_2_stcks *stcks, t_cmds *cmds, int i, t_stck *b_tmp)
{
	int		j;
	t_stck	*tmp;

	j = 0;
	tmp = stcks->a_stck;
	while (j < stcks->a_stck_len - 1)
	{
		if (b_tmp->n > tmp->n && b_tmp->n < tmp->nxt->n)
		{
			if (j < stcks->a_stck_len / 2)
			{
				cmds->stps_a[i] = j + 1;
				cmds->stck_a_cmds[i] = "ra";
			}
			else
			{
				cmds->stps_a[i] = stcks->a_stck_len - (j + 1);
				cmds->stck_a_cmds[i] = "rra";
			}
			j = stcks->a_stck_len;
		}
		tmp = tmp->nxt;
		j++;
	}
}

void	get_a_cmds(t_2_stcks *stcks, t_cmds *cmds)
{
	int		i;
	int		min;
	int		max;
	t_stck	*tmp_b;

	tmp_b = stcks->b_stck;
	i = -1;
	while (++i < stcks->b_stck_len)
	{
		max = get_max(stcks->a_stck);
		min = get_min(stcks->a_stck);
		if (tmp_b->n > max)
			exec_max_cmds(stcks, cmds, max, i);
		else if (tmp_b->n < min)
			exec_min_cmds(stcks, cmds, min, i);
		else
			exec_mid_cmds(stcks, cmds, i, tmp_b);
		if (cmds->stps_a[i] == 0)
			cmds->stck_a_cmds[i] = NULL;
		tmp_b = tmp_b->nxt;
	}
}

void	exec_max_cmds(t_2_stcks *stcks, t_cmds *cmds, int max, int i)
{
	int	index;

	index = get_in(stcks->a_stck, max);
	if (index < stcks->a_stck_len / 2)
	{
		cmds->stps_a[i] = index + 1;
		cmds->stck_a_cmds[i] = "ra";
	}
	else
	{
		cmds->stps_a[i] = stcks->a_stck_len - index - 1;
		cmds->stck_a_cmds[i] = "rra";
	}
}
