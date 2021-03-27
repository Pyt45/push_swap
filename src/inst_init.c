#include "../include/push_swap.h"

t_ps_env    *creat_env(char **argv)
{
    t_ps_env    *ps_env;

    ps_env->a = NULL;
    ps_env->b = NULL;
    ps_env->argv = argv;

    return (ps_env);
}