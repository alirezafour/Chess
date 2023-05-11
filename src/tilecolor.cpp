#include "tilecolor.hpp"

#include <cassert>

namespace four
{


////////
TileColor ::TileColor(uint32_t red, uint32_t green, uint32_t blue) : m_color{red, green, blue}
{
    assert(red < 256);
    assert(green < 256);
    assert(blue < 256);
}

////////
TileColor ::~TileColor() = default;

////////
void TileColor::setColor(uint32_t red, uint32_t green, uint32_t blue)
{
    assert(red < 256);
    assert(green < 256);
    assert(blue < 256);

    m_color = {red, green, blue};
}

////////
std::tuple<uint32_t, uint32_t, uint32_t> TileColor::getColor() const
{
    return m_color;
}

} // namespace four
