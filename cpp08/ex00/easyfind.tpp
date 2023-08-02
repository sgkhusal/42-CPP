/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:09:41 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/02 17:41:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

namespace ex00 {

template<typename T>
typename T::iterator easyfind(T& container, int number) {
	typename T::iterator position;

	position = std::find(container.begin(), container.end(), number);
	if (position == container.end())
		throw NumberNotFound();
	return position;
}

const char* NumberNotFound::what() const throw() {
	return "Number not found";
}

template<typename T>
void test(T& container, int number) {
	typename T::iterator pos;

	try {
		pos = easyfind<T>(container, number);
		std::cout << GREY << *pos << " found at container at position "
				<< std::distance(container.begin(), pos) << RESET << std::endl;

	}
	catch (std::exception const& e) {
		std::cout << ORANGE << "Exception: " << e.what() << RESET << std::endl;
	}
}

} // namespace ex00


#endif