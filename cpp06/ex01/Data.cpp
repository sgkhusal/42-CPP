/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:38:31 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/09 17:06:28 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void Data::setBirthDate(int year, int month, int day) {
    time_t t = time(NULL);

    this->birth_date = *localtime(&t);
    this->birth_date.tm_year = year - 1900;
    this->birth_date.tm_mon = month - 1;
    this->birth_date.tm_mday = day;
}

int Data::age(void) const {
    time_t t = time(NULL);
    struct tm now = *localtime(&t);
    double age;

    age = (
        static_cast<double>(now.tm_year)
        - static_cast<double>(this->birth_date.tm_year) - 1
    );

    return floor(age);
}

std::ostream& operator<<(std::ostream& o, Data& data) {
    o << GREY << "User: " << data.first_name << " " << data.last_name << std::endl
        << "e-mail: " << data.email << std::endl
        << "birthdate: " << (1900 + data.birth_date.tm_year) << "/"
        << (1 + data.birth_date.tm_mon) << "/"
        << data.birth_date.tm_mday << std::endl
        << "age: " << data.age() << RESET << std::endl;

    return (o);
}
