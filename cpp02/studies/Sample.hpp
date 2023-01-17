/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:20:24 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/17 00:36:57 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_H
# define SAMPLE_H

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
