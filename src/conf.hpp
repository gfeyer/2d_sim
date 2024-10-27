#ifndef CONF_HPP
#define CONF_HPP

namespace conf
{
    const uint TILE_SIZE = 32;
    const uint WINDOW_WIDTH_PX = 64;
    const uint WINDOW_HEIGHT_PX = 64;

    const uint GRID_COLS = WINDOW_WIDTH_PX / TILE_SIZE;
    const uint GRID_ROWS = WINDOW_HEIGHT_PX / TILE_SIZE;
}

#endif