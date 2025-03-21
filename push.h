#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				x;
	int				xmap;
	long long int	xbin;

	int				index;
	struct s_list	*next;
	struct s_list	*prev;
	char			stack;
	int				stack_size;
	struct s_data	*data_a;
	struct s_data	*data_b;
	int				smaller;
	int				bigger;
	int				smaller_stack;
	int				bigger_stack;

}					t_list;

typedef struct s_data
{
	int				pv;
	int				index_pv;
	int				head_value;
	int				tail_value;
	int				stack_min;
	int				stack_max;
	int				stack_size;

	int				map_index;

}					t_data;

enum
{
	MIN_MAX_ERROR = 9999999999LL
};

enum				e_codes
{
	ERROR = 0,
	SUCCESS = 1,
	SPLIT = 2,
	TMP = 3,
	ND_EVAL = 2,
	ST_EVAL = 1,
};

void				map_list(t_list **ends, t_list *head);
void				find_min_abs(t_list *head);
void				assign_index(t_list **ends);
void				find_min_rel(t_list *head);
void				find_max(t_list *head);
void				to_binary(t_list *head);
int					convert_binary(int ch);
void				set_stack(t_list *hed, t_list *tl, char stck, t_list *aux);
void				count_set(t_list **ends);
void				set_element_stack(t_list *tail, t_list *head);
void				reset_stack(t_list *head, char stack);
void				count_index(t_list *head);
void				extrafree(t_list **ends, t_data *data_a, t_data *data_b);
void				rev_stack(t_list **ends);
void				pass_a(t_list **ends);
void				pass_b(t_list **ends);
void				turn(t_list **ends);
int					highest_second(t_list *head, int value);
void				sorting_four_five(t_list **ends);
void				sorting_five(t_list **ends);
void				sorting_four(t_list **ends);
void				solve_one_middle(t_list **ends);
void				radix(t_list **ends, int bits);
void				sorting_five(t_list **ends);
void				sorting_three(t_list **ends);
void				sorting(t_list **ends);
void				test_sort(t_list **ends, t_list *tmp);
int					in_order(t_list **ends);
int					already_ordered(t_list **ends);
void				back_to_a(t_list **ends);

// init
void				init(t_list **ends, t_list **data, t_list *tmp);

// VALIDATE
void				basic_valid(int argc, char *argv[], t_data **datarr);
void				val_split(char *argv, t_list **ends, t_data **datarr);
void				exiting(char *str, char **splitted, t_list **ends);
int					valid(const char *s, char **splitted, t_list **ends);
int					count_split(char **numbers);
void				free_list(t_list **ends);
void				find_duplicate(t_list **ends, t_list *head, t_list *tail);

// SUPPORT
void				print(t_list *head);
void				rprint(t_list *tail);
void				testprint(t_list **ends);


// CREATE DESTROY
void				free_datarr(t_data **datarr);
void				set_element(t_list *tail, t_list *head);
void				new_element(t_list **ends, char *x, t_data **datarr);
void				free_ahead(t_list *tail);
void				free_forward(t_list *head);
void				free_backwards(t_list *tail);
int					free_pointer(char **tmp);
// PROBABLY UNUSED

// void				find_pv(t_list **ends, t_list *head);

// HANDLERS
void				pb(t_list **ends, void *print);
void				pa(t_list **ends, void *print);
void				ra(t_list **ends, void *print);
void				rb(t_list **ends, void *print);
void				rra(t_list **ends, void *print);
void				rrb(t_list **ends, void *print);
void				rrr(t_list **ends, void *print);
void				sa(t_list **ends, void *print);
void				sb(t_list **ends, void *print);
void				ss(t_list **ends, t_list *tmp, int i, void *print);
void				rr(t_list **ends, void *print);
void				*print_fun(char *str);

// got diferent return, long long to cope witn long numbers
long long int		ft_atoi(const char *str);
// LIBFt
char				**ft_split(const char *s, char c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t count, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
void				ft_bzero(void *s, size_t n);
size_t				counter(const char *s, char c);

#endif