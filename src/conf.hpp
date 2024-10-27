#ifndef CONF_HPP
#define CONF_HPP

#include <string>
namespace conf
{
    const uint TILE_SIZE = 64;
    const uint WINDOW_WIDTH_PX = 512;
    const uint WINDOW_HEIGHT_PX =512;

    const uint GRID_COLS = WINDOW_WIDTH_PX / TILE_SIZE;
    const uint GRID_ROWS = WINDOW_HEIGHT_PX / TILE_SIZE;

    const std::string FONT_1 = "res/fonts/dh.otf";
}

#endif