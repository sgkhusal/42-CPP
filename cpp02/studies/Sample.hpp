/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:20:24 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HPP
# define SAMPLE_HPP

#include <iostream>

class Sample {
	public:
		Sample(void); // Canonical
		Sample(int const n);
		Sample(Sample const& src); // Canonical
		~Sample(void); // Canonical

		Sample& operator=(Sample const& rhs); // Canonical

		int getFoo(void) const;
	private:
		int _foo;
};

std::ostream& operator<<(std::ostream& o, Sample const& t);


#endif
