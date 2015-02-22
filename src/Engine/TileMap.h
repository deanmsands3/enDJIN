/*
 * TileMap.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_
#include <vector>
#include "TileEngine.h"
namespace enDJIN {

class TileMap {
	std::vector< std::vector <unsigned long> > TileMap;
public:
	TileMap();
	virtual ~TileMap();
};

} /* namespace enDJIN */

#endif /* TILEMAP_H_ */
