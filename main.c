#include "main.h"

int	main(int ac, char **av)
{
	t_ns		nums;
	t_cmds		cmd;
	t_2_stcks	stacks;

	if (ac == 1)
		error_out(5);
	ns_init(&nums);
	cmds_init(&cmd);
	stcks_init(&stacks);
	args_prs(ac, av, &nums);
	chk_dup(&nums);
	if (chk_srt(&nums))
	{
		pt_lst(&stacks, &nums);
		if (stacks.a_stck_len <= 3)
			sml_srt(&stacks);
		else if (stacks.a_stck_len <= 5)
			fv_srt(&stacks);
		else
			mn_srt(&stacks, &cmd);
	}
	stcks_free(&stacks);
	return (0);
}
