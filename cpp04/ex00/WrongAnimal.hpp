/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:16:26 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/18 19:21:24 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal {

protected:
	std::string type;

public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &obj);

	WrongAnimal &operator=(WrongAnimal const &obj);

	~WrongAnimal(void);

	std::string	 getType(void) const;
	void makeSound(void) const;
};

#endif
