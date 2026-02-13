/*
 * TileMap.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#include "TileMap.h"

namespace enDJIN {

TileMap::TileMap(uint32_t newWidth, uint32_t newHeight):_width(newWidth),_height(newHeight) {
	_tiles.reserve(_width*_height);

}

TileMap::~TileMap() {
	// TODO Auto-generated destructor stub
}
uint32_t TileMap::getHeight() const {
	return _height;
}

void TileMap::setHeight(uint32_t height) {
	_height = height;
}

uint32_t TileMap::getWidth() const {
	return _width;
}

void TileMap::setWidth(uint32_t width) {
	_width = width;
}


} /* namespace enDJIN */
