#include "../push.h"

void	basic_valid(int argc, char *argv[], t_data *datarr[])
{
	if (argc == 1)
		free_datarr(datarr);
	if (argv[1][0] == '\0')
	{
		free_datarr(datarr);
		exiting(NULL, NULL, NULL);
	}
	if (argc < 2 || (argc == 2 && counter(argv[1], ' ') == 1))
	{
		free_datarr(datarr);
		exiting(NULL, NULL, NULL);
	}
}

/**
 * brief Calculates how many elements of the list are higher and smalles,
	setting those counters. So to know deviation over
 * the middle number, 1/2 +-1
 * It could be deleted, but i am not sure
 *
 * param tail last element of one stack. Top
 * param head first element of one stack. Base
 */
void	set_element(t_list *tail, t_list *head)
{
	if (tail->x > head->x)
		tail->smaller--;
	if (tail->x < head->x)
		tail->bigger++;
}

/**
 * brief checks wether is and empty space and moves forward,
 *  or if its a negative with  in its first position [0]
 * notice i moved the pointer s++ in case of emprty space, so the [0] position
 * should be the first one with another content, or a unmber ebtwen 0 and 9
 *
 * later on, it it finds ampty space again is gonaa return the SPLIT enum
 *
 * else its a nonvalid chain and returns error
 *
 * ih the chain ends up wit no SPLIT or ERROR return, it wil return SUCCESS
 *
 */
int	valid(const char *s, char **splitted, t_list **ends)
{
	int	i;

	if (!s)
		exiting("Error", splitted, ends);
	i = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	while (s[i])
	{
		if (((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' && i == 0)))
			i++;
		else if (s[i] == ' ' || s[i] == '\t')
			return (SPLIT);
		else
			exiting("Error", splitted, ends);
	}
	return (SUCCESS);
}

/**
 * brief  make the vaidations and splits  the argv is necessary,
	then it creates a new list element
 * or exits if Error. It
 *
 * param argv it gets from the main function the argv's one by one

	* param ends t_list *ends[]- holds head pointers to head and tail of stack a and stack b

	* param datarr struct holding usefull data from the tlist so to be vailale for every element
 * see valid
 * see exiting
 * see count_split
 * see new_element
 *
 */
void	val_split(char *argv, t_list **ends, t_data **datarr)
{
	int		i;
	char	**tmp;
	int		j;

	if (valid(argv, NULL, ends) == SPLIT)
	{
		i = 0;
		tmp = ft_split(argv, ' ');
		j = count_split(tmp);
		while (i < j)
		{
			if (valid(tmp[i], tmp, ends) == SUCCESS)
				new_element(ends, tmp[i], datarr);
			i++;
		}
		free_pointer(tmp);
	}
	else
	{
		if (valid(argv, NULL, ends) == SUCCESS)
			new_element(ends, argv, datarr);
		else
			exiting("Error", NULL, ends);
	}
}

/**
 * brief After the list is already created,
	it search for duplicates throwing error
 * in case of finding one

 */
void	find_duplicate(t_list **ends, t_list *head, t_list *tail)
{
	head = ends[0];
	tail = ends[1];
	while (head)
	{
		while (tail)
		{
			if (tail->x == head->x && head != tail)
				exiting("Error", NULL, ends);
			if (tail->prev)
				tail = tail->prev;
			else
			{
				tail = ends[1];
				break ;
			}
		}
		if (head->next)
			head = head->next;
		else
			break ;
	}
}
