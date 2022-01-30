#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_cmds
{
	int			in;
	int			*stps_a;
	int			*stps_b;
	int			chng_2_stcks;
	int			chng_a_stck;
	int			chng_b_stck;
	char		**stck_a_cmds;
	char		**stck_b_cmds;
	int			*stcks_2_cmds;
}				t_cmds;

typedef struct s_ns
{
	int			arr_len;
	int			*ns_arr;
}				t_ns;

typedef struct s_stck
{
	int				n_in;
	int				n;
	struct s_stck	*nxt;
}					t_stck;

typedef struct s_2_stcks
{
	int			a_stck_len;
	t_stck		*a_stck;
	int			b_stck_len;
	t_stck		*b_stck;
}				t_2_stcks;

int		        main(int ac, char **av);
void	        ns_init(t_ns *ns);
void            chkr_get_cmds(t_2_stcks *stcks);
void	        error_out(int flg);
void	        pa(t_2_stcks *stcks, int w_m);
void	        stcks_free(t_2_stcks *stcks);
void            chkr_exec_cmds(t_2_stcks *stcks, char *cmd_s);
void	        ra(t_2_stcks *stcks, int w_m);
void	        pb(t_2_stcks *stcks, int w_m);
t_stck			*l_lst(t_stck *stck);
void	        lst_pb(t_stck **stck, t_stck *n_n);
void	        lst_pf(t_stck **stck, t_stck *n_n);
void	        sa(t_2_stcks *stcks, int w_m);
void	        cmds_init(t_cmds *cmds);
void	        rr(t_2_stcks *stcks, int w_m);
void	        rra(t_2_stcks *stcks, int w_m);
int		        chk_lst_srt(t_stck *stck);
void	        get_a_cmds(t_2_stcks *stcks, t_cmds *cmds);
void	        stcks_init(t_2_stcks *stcks);
void	        args_prs(int ac, char **av, t_ns *ns);
void	        get_b_cmds(t_2_stcks *stcks, t_cmds *cmds);
void	        get_all_cmds(t_2_stcks *stcks, t_cmds *cmds);
void	        chk_dig(char *s);
void	        chk_dup(t_ns *ns);
void	        pt_lst(t_2_stcks *stcks, t_ns *ns);
t_stck			*nw_lst(int n, int in);
void	        rb(t_2_stcks *stcks, int w_m);
void	        find_min_cmds(t_2_stcks *stcks, t_cmds *cmds);
void	        get_min_cmds(t_cmds *cmds);
void	        rrb(t_2_stcks *stcks, int w_m);
int		        get_in(t_stck *stck, int lst_n);
int		        chk_srt(t_ns *ns);
void	        take_min_cmds(t_2_stcks *stcks, t_cmds *cmds);
void     		mn_srt_st(t_2_stcks *stcks, t_cmds *cmds);
void	        mn_srt(t_2_stcks *stcks, t_cmds *cmds);
void		    mn_srt_cmds_init(t_2_stcks *stcks, t_cmds *cmds);
void	    	exec_max_cmds(t_2_stcks *stcks, t_cmds *cmds, int max, int i);
void	        ss(t_2_stcks *stcks, int w_m);
void	        rrr(t_2_stcks *stcks, int w_m);
void	        sml_srt(t_2_stcks *stcks);
void	        fv_srt(t_2_stcks *stcks);
void	    	exec_min_cmds(t_2_stcks *stcks, t_cmds *cmds, int min, int i);
void	        sb(t_2_stcks *stcks, int w_m);
void	    	exec_mid_cmds(t_2_stcks *stcks, t_cmds *cmds, int i, t_stck *b_tmp);
int		        get_max(t_stck *stck);
int		        get_min(t_stck *stck);

#endif
