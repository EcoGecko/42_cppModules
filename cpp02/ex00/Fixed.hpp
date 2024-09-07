/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:15:11 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/16 11:18:44 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {

private:
	int				 _fixedValue;
	static int const _fracBits = 8;

public:
	Fixed(void);
	Fixed(Fixed const &obj);
	~Fixed();

	Fixed	&operator=(Fixed const &obj);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
