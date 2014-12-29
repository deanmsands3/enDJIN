/*
 * FileName.h
 *
 *  Created on: Dec 29, 2014
 *      Author: dean
 */

#ifndef FILENAME_H_
#define FILENAME_H_
#include "Types.h"
#include <stack>
#include <string>
namespace enDJIN {

class FileName {
	std::stack<std::string> _folder_tree;
public:
	FileName();
	virtual ~FileName();
};

} /* namespace enDJIN */

#endif /* FILENAME_H_ */
