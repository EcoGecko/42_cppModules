/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:18:56 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/02 10:28:52 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define PACK_SIZE 10

int main() {

	//Animal cannot be instantiated cause is an abstract class | Does not compile
/* 	const Animal *meta = new Animal();

	meta->makeSound();
	delete meta; */


	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "Type: " << j->getType() << " " << std::endl;
	std::cout << "Type: " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

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

	Cat		  *cat = new Cat();
	Cat		  *catCopy = new Cat(*cat);

	std::cout << "\nCat: " << &cat << std::endl;
	std::cout << "Cat brain: " << cat->getBrain() << std::endl << std::endl;

	delete cat;

	std::cout << "\nCatCopy: " << &catCopy << std::endl;
	std::cout << "CatCopy brain: " << catCopy->getBrain() << std::endl
			  << std::endl;
	delete catCopy;

	std::cout << std::endl;
	Animal *animals[PACK_SIZE];

	for (int i = 0; i < PACK_SIZE; i++) {
		if (i < PACK_SIZE / 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < PACK_SIZE; i++)
	{
		std::cout << "Animal " << i << " is a " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	for (int i = 0; i < PACK_SIZE; i++) {
		delete animals[i];
	}

		return (0);
}
