#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				x;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

enum				Calls
{
	ERROR = 0,
	ST_EVAL = 0,
	ND_EVAL = -1,
};

//SUPPORT
void				print(t_list *head);
void				rprint(t_list *tail);
void				testprint(t_list **ends);
void				print_stack(t_list **ends);

//CREATE DESTROY
t_list				*new_element(t_list *current, int x, int index);
void				free_ahead(t_list *tail);
void				free_forward(t_list *head);


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
void				*print_fun(char *str, int num, void **numbers);
int					count_split(void **numbers);

//got diferent return, long long to cope witn long numbers
long long int		ft_atoi(const char *str);
//LIBFt
char				**ft_split(const char *s, char c);
char				*ft_strchr(const char *s, int c);
void				val_input(int argc, char *argv[], int eval);
size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_bzero(void *s, size_t n);
// find_duplicate(long long int num, char **numbers);
// void 		ss(t_list **ends);

#endif