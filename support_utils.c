#include "main.h"

void	cmds_init(t_cmds *cmds)
{
	cmds->chng_a_stck = 0;
	cmds->chng_b_stck = 0;
	cmds->chng_2_stcks = 0;
	cmds->in = 0;
	cmds->stps_a = 0;
	cmds->stps_b = 0;
	cmds->stcks_2_cmds = 0;
	cmds->stck_a_cmds = NULL;
	cmds->stck_b_cmds = NULL;
}

void	chk_dig(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i++;
	if (!s[i])
		error_out(2);
	while (s[i])
		if (!ft_isdigit(s[i++]))
			error_out(3);
}

void	ns_init(t_ns *ns)
{
	ns->ns_arr = 0;
	ns->arr_len = 0;
}

void	chk_dup(t_ns *ns)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ns->arr_len)
	{
		j = -1;
		while (++j < i)
			if (ns->ns_arr[j] == ns->ns_arr[i])
				error_out(4);
	}
}

void	stcks_init(t_2_stcks *stcks)
{
	stcks->a_stck = NULL;
	stcks->b_stck = NULL;
	stcks->a_stck_len = 0;
	stcks->b_stck_len = 0;
}
