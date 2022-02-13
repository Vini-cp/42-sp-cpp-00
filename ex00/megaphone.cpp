/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:11:20 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 17:30:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>

int main (int argc, char **argv)
{
	std::string megaphone = "";

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			for (size_t j = 0; j < strlen(argv[i]); j++)
				argv[i][j] = toupper(argv[i][j]);
			megaphone += argv[i];
		}
	}
	else
		megaphone = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	std::cout << megaphone << std::endl;
	return (0);
}
