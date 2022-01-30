#include "main.h"

void	find_min_cmds(t_2_stcks *stcks, t_cmds *cmds)
{
	int	i;
	int	cmd_min;

	cmd_min = cmds->stcks_2_cmds[0];
	cmds->in = 0;
	i = 1;
	while (i < stcks->b_stck_len)
	{
		if (cmds->stcks_2_cmds[i] < cmd_min)
		{
			cmd_min = cmds->stcks_2_cmds[i];
			cmds->in = i;
		}
		i++;
	}
}

void	take_min_cmds(t_2_stcks *stcks, t_cmds *cmds)
{
	while (cmds->chng_a_stck)
	{
		if (!ft_strncmp(cmds->stck_a_cmds[cmds->in], "ra", 25))
			ra(stcks, 1);
		else if (!ft_strncmp(cmds->stck_a_cmds[cmds->in], "rra", 25))
			rra(stcks, 1);
		cmds->chng_a_stck--;
	}
	while (cmds->chng_b_stck)
	{
		if (!ft_strncmp(cmds->stck_b_cmds[cmds->in], "rb", 25))
			rb(stcks, 1);
		else if (!ft_strncmp(cmds->stck_b_cmds[cmds->in], "rrb", 25))
			rrb(stcks, 1);
		cmds->chng_b_stck--;
	}
	while (cmds->chng_2_stcks)
	{
		if (!ft_strncmp(cmds->stck_a_cmds[cmds->in], "ra", 25))
			rr(stcks, 1);
		else if (!ft_strncmp(cmds->stck_a_cmds[cmds->in], "rra", 25))
			rrr(stcks, 1);
		cmds->chng_2_stcks--;
	}
}

void	get_min_cmds(t_cmds *cmds)
{
	if ((!ft_strncmp(cmds->stck_a_cmds[cmds->in], "ra", 25) && \
			!ft_strncmp(cmds->stck_b_cmds[cmds->in], "rb", 25)) || \
			(!ft_strncmp(cmds->stck_a_cmds[cmds->in], "rra", 25) && \
			 !ft_strncmp(cmds->stck_b_cmds[cmds->in], "rrb", 25)))
	{
		if (cmds->stps_a[cmds->in] > cmds->stps_b[cmds->in])
		{
			cmds->chng_a_stck = cmds->stps_a[cmds->in] - cmds->stps_b[cmds->in];
			cmds->chng_2_stcks = cmds->stps_b[cmds->in];
		}
		else
		{
			cmds->chng_b_stck = cmds->stps_b[cmds->in] - cmds->stps_a[cmds->in];
			cmds->chng_2_stcks = cmds->stps_a[cmds->in];
		}
	}
	else
	{
		cmds->chng_a_stck = cmds->stps_a[cmds->in];
		cmds->chng_b_stck = cmds->stps_b[cmds->in];
	}
}

void	pt_lst(t_2_stcks *stcks, t_ns *ns)
{
    int		i;
    t_stck	*list;

    i = 0;
    while (i < ns->arr_len)
    {
        list = nw_lst(ns->ns_arr[i], -1);
        if (!list)
			error_out(6);
		lst_pb(&stcks->a_stck, list);
        stcks->a_stck_len++;
        i++;
    }
    free(ns->ns_arr);
}

void	get_all_cmds(t_2_stcks *stcks, t_cmds *cmds)
{
	int	i;

	cmds->stcks_2_cmds[0] = cmds->stps_a[0];
	i = 1;
	while (i < stcks->b_stck_len)
	{
		if ((!ft_strncmp(cmds->stck_a_cmds[i], "ra", 25) && \
			!ft_strncmp(cmds->stck_b_cmds[i], "rb", 25)) || \
			(!ft_strncmp(cmds->stck_a_cmds[i], "rra", 25) && \
			 !ft_strncmp(cmds->stck_b_cmds[i], "rrb", 25)))
		{
			if (cmds->stps_a[i] > cmds->stps_b[i])
				cmds->stcks_2_cmds[i] = cmds->stps_a[i];
			else
				cmds->stcks_2_cmds[i] = cmds->stps_b[i];
		}
		else if ((!ft_strncmp(cmds->stck_a_cmds[i], "ra", 25) && \
				!ft_strncmp(cmds->stck_b_cmds[i], "rrb", 25)) || \
				(!ft_strncmp(cmds->stck_a_cmds[i], "rra", 25) && \
				 !ft_strncmp(cmds->stck_b_cmds[i], "rb", 25)))
			cmds->stcks_2_cmds[i] = cmds->stps_a[i] + cmds->stps_b[i];
		else if (!cmds->stck_a_cmds[i])
			cmds->stcks_2_cmds[i] = cmds->stps_b[i];
		i++;
	}
}
