/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:30:29 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/14 00:41:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <sstream>
# include <fstream>
# include <cstdlib> // exit
# include <iomanip>

# define DATABASE_FILENAME "data.csv"
# define COMMA_DB_POS 10

typedef std::map<std::string const, float const> db_map;
typedef std::map<std::string const, float const>::const_iterator map_iterator;
typedef std::pair<std::string const, float const> db_pair;

class BitcoinExchange {
public:
	BitcoinExchange(void);
	~BitcoinExchange(void);

	int run(std::string const inputFile);

private:
	BitcoinExchange(BitcoinExchange const& copy);
	BitcoinExchange const& operator=(BitcoinExchange const& copy);

	static db_map const	_dataBase;
	static db_map		_generateDataBase(void);
	static db_pair		_parseDBLine(std::string const line);
	static bool			_checkDBLine(std::string const line);

	struct Date {
		int year;
		int month;
		int day;
	};
	static Date const	_min_date;
	static Date const	_max_date;

	static void _getPrice(std::string line);
	static bool	_checkInputLine(std::string const& line);
	static bool	_checkDate(std::string& date);
	static bool	_checkDateLimits(Date d);
	static bool	_checkValue(std::string& value);

	static void	_openFile(std::string filename, std::ifstream& ifs);
	static Date _getDate(std::string const date);
	static float _getNumber(std::string const str_nb);
	static void _stripSpaces(std::string& str);
};

#endif