/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:30:32 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/19 17:11:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

db_map	const BitcoinExchange::_dataBase = BitcoinExchange::_generateDataBase();
BitcoinExchange::Date const BitcoinExchange::_min_date = BitcoinExchange::_getDate(
	(*(BitcoinExchange::_dataBase.begin())).first
);
BitcoinExchange::Date const BitcoinExchange::_max_date = BitcoinExchange::_getDate(
	(*(--BitcoinExchange::_dataBase.end())).first
);

BitcoinExchange::BitcoinExchange(void) { }

BitcoinExchange::~BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy) { (void)copy; }

BitcoinExchange const& BitcoinExchange::operator=(BitcoinExchange const & copy) {
	(void)copy;
	return *this;
}

int BitcoinExchange::run(std::string const inputFile) {
	std::ifstream	ifs;
	std::string		line;

	_openFile(inputFile, ifs);
	std::getline(ifs, line);
	while (std::getline(ifs, line)) {
		if (_checkInputLine(line))
			_getPrice(line);
	}
	ifs.close();
	return 0;
}

void BitcoinExchange::_getPrice(std::string line) {
	std::string	date;
	float		value;
	size_t		sep;
	map_iterator	it;

	sep = line.find(" | ");
	date = line.substr(0, sep);
	value = _getNumber(line.substr(sep + 3));
	_stripSpaces(date);
	it = _dataBase.upper_bound(date);
	if (it != _dataBase.begin())
		it--;
	std::cout << date << " => " << value << " = " << (*it).second * value
		<< std::endl;
}

/* line format: "date | value" */
bool BitcoinExchange::_checkInputLine(std::string const& line) {
	std::string value;
	std::string date;
	size_t sep;

	if (line.empty())
		return false;
	sep = line.find(" | ");
	if (sep == std::string::npos) {
		std::cout << "Error: bad input => '" << line
			<< "'. Use format 'date | value'" << std::endl;
		return false;
	}
	date = line.substr(0, sep);
	if (!_checkDate(date))
		return false;
	value = line.substr(sep + 3);
	if (!_checkValue(value))
		return false;

	return true;
}

/* date format: Year-Month-Day */
bool BitcoinExchange::_checkDate(std::string& date) {
	std::string::const_iterator it;
	int							dash = 0;

	_stripSpaces(date);
	if (date.size() < 10) {
		std::cout << "Error: invalid date => '" << date << "'" << std::endl;
		return false;
	}
	for (it = date.begin(); it != date.end(); it++) {
		if (*it == '-')
			dash++;
		if (!std::isdigit(*it) && *it != '-') {
			std::cout << "Error: invalid character '" << *it << "' in date => '"
				<< date << "'. Use format 'Year-Month-Day'" << std::endl;
			return false;
		}
	}
	if (dash !=2) {
		std::cout << "Error: invalid date => '" << date
				<< "'. Use format 'Year-Month-Day'" << std::endl;
		return false;
	}
	return _checkDateLimits(_getDate(date));
}

bool	BitcoinExchange::_checkDateLimits(Date d) {
	if (
		d.year < _min_date.year
		|| (d.year == _min_date.year && d.month < _min_date.month)
		|| (d.year == _min_date.year && d.month == _min_date.month && d.day < _min_date.day)
	) {
		std::cout << "Error: date smaller than lower database date "
			<< _min_date.year << "-" << _min_date.month << "-" << _min_date.day
			<< std::endl;
		return false;
	}
	if (d.year > _max_date.year + 5) {
		std::cout << "Error: date much greater than the largest date in database "
			<< _max_date.year << "-" << _max_date.month << "-" << _max_date.day
			<< std::endl;
		return false;
	}

	if (d.month < 1 || d.month > 12) {
		std::cout << "Error: invalid month => " << d.month << std::endl;
		return false;
	}

	int	day_limit = 31;
	if (d.month == 2) {
		day_limit = 28;
		if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
			day_limit = 29;
	}
	if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
		day_limit = 30;
	if (d.day < 1 || d.day > day_limit) {
		std::cout << "Error: invalid date => "
			<< d.year << "-" << d.month << "-" << d.day << std::endl;
		return false;
	}

	return true;
}

/* value must be either a float or a positive integer, between 0 and 1000 */
bool BitcoinExchange::_checkValue(std::string& value) {
	std::string::const_iterator	it;
	float						nb;
	int 						point = 0;

	_stripSpaces(value);
	it = value.begin();
	if (*it == '-')
		it++;
	for (; it != value.end(); it++) {
		if (*it == '.')
			point++;
		if ((!std::isdigit(*it) && *it != '.') || point > 1) {
			std::cout << "Error: invalid number => '" << value << "'" << std::endl;
			return false;
		}
	}
	nb = _getNumber(value);
	if (nb < 0) {
		std::cout << "Error: not a positive number" << std::endl;
		return false;
	}
	if (nb > 1000) {
		std::cout << std::fixed << std::setprecision(1)
			<< "Error: number too large => " << value << std::endl;
		return false;
	}
	return true;
}

db_map BitcoinExchange::_generateDataBase(void) {
	std::ifstream	ifs;
	std::string		line;
	db_map			db;

	_openFile(DATABASE_FILENAME, ifs);
	std::getline(ifs, line);
	while (std::getline(ifs, line)) {
		if (!line.empty())
			db.insert(BitcoinExchange::_parseDBLine(line));
	}
	ifs.close();

	return db;
}

void BitcoinExchange::_openFile(std::string const filename, std::ifstream& ifs) {
	ifs.open(filename.c_str());
	if (ifs.fail()) {
		std::cout << "Error: could not open file " << filename << std::endl;
		exit(1);
	}
}

db_pair BitcoinExchange::_parseDBLine(std::string const line) {
	if (!_checkDBLine(line)) {
		std::cout << "Error: corrupted database at => " << line << std::endl;
		exit(1);
	}
	return std::make_pair(
		line.substr(0, COMMA_DB_POS), _getNumber(line.substr(COMMA_DB_POS + 1))
	);
}

bool BitcoinExchange::_checkDBLine(std::string const line) {
	size_t	comma;
	int		i = 0, dash = 0, point = 0;

	comma = line.find(',');
	if (line.size() < 12 || comma != COMMA_DB_POS)
		return false;

	for (std::string::const_iterator it = line.begin(); it != line.end(); it++) {
		if (i < COMMA_DB_POS) {
			if (*it == '-')
				dash++;
			if (!std::isdigit(*it) && *it != '-')
				return false;
		}
		else if (i > COMMA_DB_POS) {
			if (*it == '.')
				point++;
			if (!std::isdigit(*it) && *it != '.')
				return false;
		}
		i++;
	}
	if (dash != 2 || point > 1)
		return false;
	return true;
}

BitcoinExchange::Date BitcoinExchange::_getDate(std::string const date) {
	size_t dash1;
	size_t dash2;
	Date d;

	dash1 = date.find("-");
	dash2 = date.find_last_of("-");
	d.year = _getNumber(date.substr(0, dash1));
	d.month = _getNumber(date.substr(dash1 + 1, dash2 - dash1 - 1));
	d.day = _getNumber(date.substr(dash2 + 1));
	return d;
}

float BitcoinExchange::_getNumber(std::string const str_nb) {
	std::stringstream	ss;
	float				nb;

	ss << str_nb;
	ss >> nb;
	return nb;
}

void BitcoinExchange::_stripSpaces(std::string& str) {
	std::string::iterator	it = str.begin();
	std::string::iterator	end;

	while (it != str.end() && *it == ' ') {
		str.erase(it);
		it = str.begin();
	}
	end = str.end();
	--end;
	while (end != it && *end == ' ') {
		str.erase(end);
		end = str.end();
		--end;
	}

}
