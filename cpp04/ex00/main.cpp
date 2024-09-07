/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:18:56 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 14:43:19 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "Type: " << j->getType() << " " << std::endl;
	std::cout << "Type: " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongJ = new WrongCat();

	std::cout << "----------Wrong Part----------" << std::endl;
	std::cout << "Type: " << wrongJ->getType() << " " << std::endl;
	wrongJ->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongJ;

	return (0);
}
