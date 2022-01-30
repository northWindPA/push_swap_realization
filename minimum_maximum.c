#include "main.h"

int	get_min(t_stck *stck)
{
	int		min;
	t_stck	*tmp;

	min = stck->n;
	tmp = stck;
	while (tmp)
	{
		if (tmp->n < min)
			min = tmp->n;
		tmp = tmp->nxt;
	}
	return (min);
}

void	get_ns(t_ns *ns, char **buff)
{
    int	i;
    int	*tmp;

    i = 0;
    while (buff[i])
        i++;
    tmp = ns->ns_arr;
    ns->ns_arr = (int *)ft_calloc(sizeof(int), (ns->arr_len + i));
    if (!ns->ns_arr)
		error_out(7);
    i = 0;
    while (i < ns->arr_len)
        i++;
    i = -1;
    while (++i < ns->arr_len)
        ns->ns_arr[i] = tmp[i];
    if (tmp)
        free(tmp);
    i = -1;
    while (buff[++i])
    {
		chk_dig(buff[i]);
        ns->ns_arr[ns->arr_len++] = ft_atoi(buff[i]);
        free(buff[i]);
    }
}

void	args_prs(int ac, char **av, t_ns *ns)
{
    int		i;
    char	**buff;

    i = 0;
    while (++i < ac)
    {
        buff = ft_split(av[i], ' ');
        if (!buff)
			error_out(10);
		get_ns(ns, buff);
        free(buff);
    }
}

int	get_max(t_stck *stck)
{
	int		max;
	t_stck	*tmp;

	max = stck->n;
	tmp = stck;
	while (tmp)
	{
		if (tmp->n > max)
			max = tmp->n;
		tmp = tmp->nxt;
	}
	return (max);
}

int	get_in(t_stck *stck, int lst_n)
{
	int		i;
	t_stck	*tmp;

	tmp = stck;
	i = 0;
	while (tmp)
	{
		if (tmp->n == lst_n)
			return (i);
		i++;
		tmp = tmp->nxt;
	}
	return (i);
}
