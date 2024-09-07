/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:12:21 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/18 19:26:42 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {

protected:
	std::string type;

public:
	Animal(void);
	Animal(Animal const &obj);

	Animal &operator=(Animal const &obj);

	virtual ~Animal(void);

	std::string	 getType(void) const;
	virtual void makeSound(void) const;
};

#endif
