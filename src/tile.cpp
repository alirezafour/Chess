#include "tile.hpp"
#include "coordination.hpp"
#include <string_view>

namespace four
{

Tile::Tile(uint32_t xCoord, uint32_t yCoord) : Coordination(xCoord, yCoord)
{
}
Tile::Tile(const std::string_view& coordinationString) : Coordination(coordinationString)
{
}

} // namespace four
