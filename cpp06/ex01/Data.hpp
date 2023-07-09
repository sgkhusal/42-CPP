/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:21:21 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/09 16:39:52 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <ctime>
# include <cmath>

# define BLUE	"\033[38;5;75m"
# define ORANGE	"\033[0;38;5;166m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

struct Data {
    std::string first_name;
    std::string last_name;
    std::string email;
    tm birth_date;
    int age(void) const;
    void setBirthDate(int year, int month, int day);
};

std::ostream& operator<<(std::ostream& o, Data& data);

#endif
