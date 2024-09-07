/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:24:47 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/19 17:24:48 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {

private:

public:
    Cure(void);
	Cure(Cure const &obj);

	Cure &operator=(Cure const &obj);

	~Cure(void);

	AMateria* clone(void) const;
	void use(ICharacter& target);
};

#endif
