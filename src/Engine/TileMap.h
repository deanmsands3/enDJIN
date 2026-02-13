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
	std::vector <uint32_t> _tiles;
	uint32_t _height;
	uint32_t _width;
public:
	TileMap(uint32_t newWidth, uint32_t newHeight);
	virtual ~TileMap();
	uint32_t getHeight() const;

	void setHeight(uint32_t height);

	uint32_t getWidth() const;

	void setWidth(uint32_t width);

};

} /* namespace enDJIN */

#endif /* TILEMAP_H_ */
