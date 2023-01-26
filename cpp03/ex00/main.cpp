/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/25 22:07:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap robot1;
    ClapTrap robot2;
    ClapTrap marvin("Marvin");
    ClapTrap marvinCopy = marvin;
    ClapTrap marvinCopy2(marvin);

    std::cout << std::endl;
    robot1.attack(marvin.getName());
    marvin.takeDamage(robot1.getAttackDamage());
    marvin.beRepaired(1);
    marvin.beRepaired(5);

    std::cout << std::endl;
    robot2.attack(marvinCopy.getName());
    marvinCopy.takeDamage(robot1.getAttackDamage());
    marvinCopy.beRepaired(10);

    std::cout << std::endl;
    robot1.setEnergyPoints(0);
    robot1.attack(marvinCopy2.getName());
    robot1.beRepaired(1);

    std::cout << std::endl;
    robot2.takeDamage(20);
    robot2.attack(marvin.getName());
    robot2.beRepaired(1);

    std::cout << std::endl;
    return (0);
}
