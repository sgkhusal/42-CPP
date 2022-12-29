/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:18:06 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/28 21:10:48 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include "ctime"

int main() {
	std::time_t	timetoday;
	std::tm		*timedata;

	std::time(&timetoday);
	timedata = std::localtime(&timetoday);
	std::cout << "Calendar date and time as per todays is : " \
			<< asctime(timedata);
	std::cout << "Day today is : " << timedata->tm_mday << std::endl;
	std::cout << "Month today is : " << 1 + timedata->tm_mon << std::endl;
	std::cout << "Year today is : " << 1900 + timedata->tm_year << std::endl;
	return (0);
}
