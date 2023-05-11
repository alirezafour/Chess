#ifndef TILES_HPP
#define TILES_HPP

#include "coordination.hpp"
#include <string_view>

namespace four
{

class Tile : public Coordination
{
public:
    Tile(uint32_t xCoordination, uint32_t yCoordination);
    Tile(const std::string_view& CoordinationString);
    Tile(Tile&&)                 = default;
    Tile(const Tile&)            = default;
    Tile& operator=(Tile&&)      = default;
    Tile& operator=(const Tile&) = default;
};

} // namespace four

#endif // !TILES_HPP
