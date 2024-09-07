/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:52:34 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/18 19:57:54 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>
#define NBR_IDEAS 100

class Brain {

private:
	std::string ideas[NBR_IDEAS];

public:
    Brain(void);
	Brain(Brain const &obj);

	Brain &operator=(Brain const &obj);

	~Brain(void);
};

#endif
