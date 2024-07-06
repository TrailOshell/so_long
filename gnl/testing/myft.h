/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:47:53 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/07 15:09:56 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFT_H
# define MYFT_H
# include <stdio.h>
# include <libc.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
// # define BLACK "black"

//	MY TEST FUNCTIONS
//	main.c 
void	print_chars(char *str);
void	output_chars(char *test, char *str);
//	coloring.c
void	ft_color(char *color);
void	printcolor(char *s, char *color);
//	cosmetic.c
void	banner_border(int len);
void	banner(char *str, char *desc);
void	divider_start(void);
void	divider_end(void);
void	program_header(void);
//	result_compare.c
int		check_overlap(void *dst, void *src);
void	compare_mem(void *s1, void *s2, size_t n);
void	compare_str_arr(char **s1, char **s2, size_t n);
void	compare_int(int i, int o);
void	compare_str(char *s, char *o);
void	compare_null(char *s, char *s2, unsigned int n);
void	compare_arr(int *o, int *l, unsigned int n);
//	result_output.c
int		find_test(char **argv, char *part, char *test);
void	print_null(char *s, unsigned int n);
void	print_arr(int *arr, int size);
void	print_str_arr(char **arr, int size);
//	result_text.c
void	print_error_text(char *s);
void	print_result_text(char *s);
void	print_compare_text(char *s);
void	print_test_line(char *s);
char	chr_rpc(unsigned int n, char c);

#endif
