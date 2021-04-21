#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_count
{
	int				count;
	unsigned int	start;
	int				n_ph;
	pthread_t		ph;
	pthread_t		die_th;
	pthread_mutex_t *philo_mutex;
	pthread_mutex_t	*die_mutex;
	pthread_mutex_t	*msg_mutex;
}					t_count;

pthread_mutex_t		mutex;

void	*routine(void *arg)
{
	for (int i = 0; i < 5; i++)
	{
		// pthread_mutex_lock(&mutex);
		printf("start\n");
		sleep(1);
		printf("end\n");
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int		main(int argc, char **argv)
{
	/*int		i;
	t_count *count;

	count = malloc(sizeof(t_count));
	count->n_ph = atoi(argv[1]);
	count->count = atoi(argv[2]);
	i = -1;
	while (++i < count->n_ph)
	{
		count[i].philo_mutex = malloc(sizeof(pthread_mutex_t));
		count[i].die_mutex = malloc(sizeof(pthread_mutex_t));
		count[i].msg_mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(count[i].philo_mutex, NULL);
		pthread_mutex_init(count[i].msg_mutex, NULL);
		pthread_mutex_init(count[i].die_mutex, NULL);
	}
	i = -1;
	pthread_mutex_lock(count->die_mutex);
	while (++i < count->n_ph)
	{
		pthread_create(&count[i].ph, NULL, routine, count);
		pthread_detach(count[i].ph);
	}
	pthread_mutex_unlock(count->die_mutex);*/
	pthread_mutex_init(&mutex, NULL);
	pthread_t	th;
	pthread_mutex_lock(&mutex);

	pthread_create(&th, NULL, routine, NULL);
	pthread_detach(th);

	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
}