/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:25:51 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/22 16:55:43 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"
#include <check.h>

////////////////////////////////////////////////////////////////////////////////

////////// get_info.c

/// ft_strlen

START_TEST(ft_strlen__1)
{
	ck_assert_int_eq(ft_strlen("bonjour"), 7);
}
END_TEST

START_TEST(ft_strlen__2)
{
	ck_assert_int_eq(ft_strlen(""), 0);
}
END_TEST

/// ft_is_equal

START_TEST(ft_is_equal__1)
{
	ck_assert_int_eq(ft_is_equal("Hello my name is Morpheus", "Hello my name is Morpheus"), 1);
}
END_TEST

START_TEST(ft_is_equal__2)
{
	ck_assert_int_eq(ft_is_equal("Hello", "Hello my name"), 0);
}
END_TEST

/// ft_strchr

START_TEST(ft_strchr__1)
{
	ck_assert_str_eq(ft_strchr("hello\n", '\n'), "\n");
}
END_TEST

START_TEST(ft_strchr__2)
{
	ck_assert_ptr_eq(ft_strchr("", '\n'), NULL);
}
END_TEST

START_TEST(ft_strchr__3)
{
	ck_assert_str_eq(ft_strchr("\n\n\n\n", '\n'), "\n\n\n\n");
}
END_TEST

START_TEST(ft_strchr__4)
{
	ck_assert_ptr_eq(ft_strchr("", '\n'), NULL);
}
END_TEST

START_TEST(ft_strchr__5)
{
	ck_assert_str_eq(ft_strchr("\n", '\n'), "\n");
}
END_TEST

START_TEST(ft_strchr__6)
{
	ck_assert_str_eq(ft_strchr("ooh\nhello\n", '\n'), "\nhello\n");
}
END_TEST

START_TEST(ft_strchr__7)
{
	ck_assert_str_eq(ft_strchr("ooh\n\nhello\n", '\n'), "\n\nhello\n");
}
END_TEST

/// is_empty

START_TEST(is_empty__1)
{
	const char	str[2] = {'\0', '\0'};

	ck_assert_int_eq(is_empty(str, 2), 1);
}
END_TEST

START_TEST(is_empty__2)
{
	const char	str[4] = "";

	ck_assert_int_eq(is_empty(str, 4), 1);
}
END_TEST

START_TEST(is_empty__3)
{
	const char	str[4] = "a";

	ck_assert_int_eq(is_empty(str, 4), 0);
}
END_TEST

/// ft_strndup

START_TEST(ft_strndup__1)
{
	const char	*str = "hello !";

	ck_assert_str_eq(ft_strndup(str, 3), "hel");
}
END_TEST

START_TEST(ft_strndup__2)
{
	const char	*str = "hello !";

	ck_assert_str_eq(ft_strndup(str, 10), str);
}
END_TEST

START_TEST(ft_strndup__3)
{
	const char	*str = "My name is Morpheus";

	ck_assert_str_eq(ft_strndup(str, 0), "");
}
END_TEST

/// ft_strtok

START_TEST(ft_strtok__1)
{
	const char	*str = "My name is Morpheus";
	const char	*delim = "is";

	ck_assert_str_eq(ft_strtok(str, delim), "My name ");
}
END_TEST

START_TEST(ft_strtok__2)
{
	const char	*str = "My name is Morpheus";
	const char	*delim = "pheus";

	ck_assert_str_eq(ft_strtok(str, delim), "My name is Mor");
}
END_TEST

START_TEST(ft_strtok__3)
{
	const char	*str = "My name is Morpheus";
	const char	*delim = "";

	ck_assert_str_eq(ft_strtok(str, delim), "");
}
END_TEST

Suite	*utilities(void)
{
	Suite	*s;
	TCase	*ft_strlen;
	TCase	*ft_is_equal;
	TCase	*ft_strchr;
	TCase	*is_empty;
	TCase	*ft_strndup;
	TCase	*ft_strtok;

	s = suite_create("UTILITIES");
	ft_strlen = tcase_create("FT_STRLEN");
	ft_is_equal = tcase_create("FT_IS_EQUAL");
	ft_strchr = tcase_create("FT_STRCHR");
	is_empty = tcase_create("IS_EMPTY");
	ft_strndup = tcase_create("FT_STRNDUP");
	ft_strtok = tcase_create("FT_STRTOK");

	tcase_add_test(ft_strlen, ft_strlen__1);
	tcase_add_test(ft_strlen, ft_strlen__2);

	tcase_add_test(ft_is_equal, ft_is_equal__1);
	tcase_add_test(ft_is_equal, ft_is_equal__2);
	
	tcase_add_test(ft_strchr, ft_strchr__1);
	tcase_add_test(ft_strchr, ft_strchr__2);
	tcase_add_test(ft_strchr, ft_strchr__3);
	tcase_add_test(ft_strchr, ft_strchr__4);
	tcase_add_test(ft_strchr, ft_strchr__5);
	tcase_add_test(ft_strchr, ft_strchr__6);
	tcase_add_test(ft_strchr, ft_strchr__7);
	
	tcase_add_test(is_empty, is_empty__1);
	tcase_add_test(is_empty, is_empty__2);
	tcase_add_test(is_empty, is_empty__3);
	
	tcase_add_test(ft_strndup, ft_strndup__1);
	tcase_add_test(ft_strndup, ft_strndup__2);
	tcase_add_test(ft_strndup, ft_strndup__3);
	
	tcase_add_test(ft_strtok, ft_strtok__1);
	tcase_add_test(ft_strtok, ft_strtok__2);
	tcase_add_test(ft_strtok, ft_strtok__3);

	suite_add_tcase(s, ft_strlen);
	suite_add_tcase(s, ft_strchr);
	suite_add_tcase(s, ft_is_equal);
	suite_add_tcase(s, is_empty);
	suite_add_tcase(s, ft_strndup);
	suite_add_tcase(s, ft_strtok);

	return (s);
}

////////////////////////////////////////////////////////////////////////////////

/// get_next_line

START_TEST(gnl__1)
{
	int	fd;

	fd = open("./tests/assets_test/file.txt", O_RDONLY);

	ck_assert_str_eq(get_next_line(fd), "I'm Morpheus,");
	ck_assert_str_eq(get_next_line(fd), "");
	ck_assert_str_eq(get_next_line(fd), "Follow the white rabbit Neo...");
	ck_assert_str_eq(get_next_line(fd), "");
	ck_assert_str_eq(get_next_line(fd), "");
	ck_assert_str_eq(get_next_line(fd), "...or take the blue pill.");
	close(fd);
}
END_TEST

START_TEST(gnl__2)
{
	int	fd;

	fd = -1;
	ck_assert_ptr_eq(get_next_line(fd), NULL);
}
END_TEST

/// is_start_inst

START_TEST(is_start_inst__1)
{
	const char	*command = "#start bahbah";

	ck_assert_int_eq(is_start_inst(command), 1);
}
END_TEST

START_TEST(is_start_inst__2)
{
	const char	*command = "#sta rt bahbah";

	ck_assert_int_eq(is_start_inst(command), 0);
}
END_TEST

START_TEST(is_start_inst__3)
{
	const char	*command = "#start";

	ck_assert_int_eq(is_start_inst(command), 0);
}
END_TEST

/// is_end_inst

START_TEST(is_end_inst__1)
{
	const char	*command = "#end bahbah";

	ck_assert_int_eq(is_end_inst(command), 1);
}
END_TEST

START_TEST(is_end_inst__2)
{
	const char	*command = " #end bahbah";

	ck_assert_int_eq(is_end_inst(command), 0);
}
END_TEST

START_TEST(is_end_inst__3)
{
	const char	*command = "#end";

	ck_assert_int_eq(is_end_inst(command), 0);
}
END_TEST

/// is_link_inst

START_TEST(is_link_inst__1)
{
	const char	*command = "burger-sandwich";

	ck_assert_int_eq(is_link_inst(command), 1);
}
END_TEST

START_TEST(is_link_inst__2)
{
	const char	*command = "ends";

	ck_assert_int_eq(is_link_inst(command), 0);
}
END_TEST

START_TEST(is_link_inst__3)
{
	const char	*command = "-ho";

	ck_assert_int_eq(is_link_inst(command), 1);
}
END_TEST

START_TEST(is_link_inst__4)
{
	const char	*command = "";

	ck_assert_int_eq(is_link_inst(command), 0);
}
END_TEST

Suite	*parser(void)
{
	Suite	*s;
	TCase	*gnl;
	TCase	*find_inst;

	s = suite_create("PARSER");
	gnl = tcase_create("GNL");
	find_inst = tcase_create("FIND_INSTRUCTIONS");

	tcase_add_test(gnl, gnl__1);
	tcase_add_test(gnl, gnl__2);

	tcase_add_test(find_inst, is_start_inst__1);
	tcase_add_test(find_inst, is_start_inst__2);
	tcase_add_test(find_inst, is_start_inst__3);
	
	tcase_add_test(find_inst, is_end_inst__1);
	tcase_add_test(find_inst, is_end_inst__2);
	tcase_add_test(find_inst, is_end_inst__3);

	tcase_add_test(find_inst, is_link_inst__1);
	tcase_add_test(find_inst, is_link_inst__2);
	tcase_add_test(find_inst, is_link_inst__3);
	tcase_add_test(find_inst, is_link_inst__4);

	suite_add_tcase(s, gnl);
	suite_add_tcase(s, find_inst);

	return (s);
}

////////////////////////////////////////////////////////////////////////////////

/// create_list

START_TEST(create_list__1)
{
	t_list	*list;
	const char	*name = "Strawberry";

	list = create_list(name, NULL);
	ck_assert_str_eq(list->data, name);
	ck_assert_ptr_eq(list->next, NULL);
}
END_TEST

START_TEST(create_list__2)
{
	t_list		*list;
	const char	*name = "";
	char		*ptr;

	ptr = ft_strdup(name);
	list = create_list(name, ptr);
	ck_assert_str_eq(list->data, "");
	ck_assert_ptr_eq(list->next, ptr);
}
END_TEST

/// add

START_TEST(add__1)
{
	const char	*name = "Apple";
	const char	*new_name = "Cherry";
	t_list		*list;
	t_list		*new;

	list = create_list(name, NULL);
	new = create_list(new_name, NULL);
	add(&list, new);
	ck_assert_str_eq(list->data, name);
	ck_assert_ptr_eq(list->next, new);
}
END_TEST

START_TEST(add__2)
{
	const char	*name = "Cherry";
	t_list		*list;
	t_list		*new;

	list = NULL;
	new = create_list(name, NULL);
	add(&list, new);
	ck_assert_str_eq(list->data, name);
	ck_assert_ptr_eq(list->next, new->next);
	ck_assert_ptr_eq(list, new);
}
END_TEST

START_TEST(add__3)
{
	const char	*name1 = "Airplane";
	const char	*name2 = "Bottle";
	const char	*name3 = "Chicken";
	t_list		*node1;
	t_list		*node2;
	t_list		*node3;

	node1 = create_list(name1, NULL);
	node2 = create_list(name2, NULL);
	node3 = create_list(name3, NULL);
	add(&node1, node2);
	add(&node1, node3);
	ck_assert_str_eq(node1->data, name1);
	ck_assert_ptr_eq(node1->next, node2);
	ck_assert_ptr_eq(node2->next, node3);
}
END_TEST

/// destroy

START_TEST(destroy__1)
{
	const char	*name1 = "Airplane";
	const char	*name2 = "Bottle";
	t_list		*node1;
	t_list		*node2;

	node1 = create_list(name1, NULL);
	node2 = create_list(name2, NULL);
	add(&node1, node2);
//	destroy((t_list *)node2, full_free);
//	ck_assert_str_eq(node1->data, name1);
//	ck_assert_ptr_eq(node1->next, NULL);
}
END_TEST

Suite	*linked_list(void)
{
	Suite	*s;
	TCase	*structure;

	s = suite_create("LINKED_LIST");
	structure = tcase_create("STRUCTURE");

	tcase_add_test(structure, create_list__1);
	tcase_add_test(structure, create_list__2);

	tcase_add_test(structure, add__1);
	tcase_add_test(structure, add__2);
	tcase_add_test(structure, add__3);

	tcase_add_test(structure, destroy__1);

	suite_add_tcase(s, structure);

	return (s);
}

////////////////////////////////////////////////////////////////////////////////

int	get_failed_from_suite(Suite *suite)
{
	int		not_failed;
	Suite	*s;
	SRunner	*runner;

	not_failed = 0;
	s = suite;
	runner = srunner_create(s);

	srunner_run_all(runner, CK_NORMAL);
	not_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return (not_failed);
}

int	main(void)
{
	Suite	*(*suite[NBOF_SUITE])(void) = {utilities, parser, linked_list};
	int		nbof_failed;
	size_t	i;

	i = 0;
	nbof_failed = 0;
	while (i < NBOF_SUITE)
	{
		nbof_failed += get_failed_from_suite(suite[i]());
		++i;
	}
	return (nbof_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
