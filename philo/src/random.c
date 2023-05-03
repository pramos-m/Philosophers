
void	philo_check_iterator(t_list *table)
{
	int	idx;
	
	idx = 0;
	
	do_sleep_cycle(2);
	while (!table->die && table->ecnt != table->num_philos)
	{
		if (table->ecnt == table->num_philos)
			break ;
		if (table->philo[idx].num_eats == table->times->t_p_eats)
			table->ecnt++;
		if (idx == table->pcntr)
			idx = 0;
		if (get_time() - table->times->t_start >= get_time() - table->philo[idx].last_eat + table->times->t_die)
		{
			table->die = 1;
			print_die(table, &table->philo[idx]);
			break ;
		}
	}
}