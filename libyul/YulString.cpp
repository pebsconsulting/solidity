/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <libyul/YulString.h>

using namespace dev::yul;

YulStringRepository::YulStringRepository():
	m_strings{std::make_shared<std::string>()}
{
	m_ids[std::string{}] = 0;
	yulAssert(!globalInstance, "Attempted to create multiple instances of YulStringRepository.");
	globalInstance = this;
}

YulStringRepository::~YulStringRepository()
{
	yulAssert(globalInstance == this, "Unexpected global instance of YulStringRepository.");
	globalInstance = nullptr;
}

YulStringRepository* YulStringRepository::globalInstance = nullptr;
