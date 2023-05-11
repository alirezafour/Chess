#include "tilecolor.hpp"

#include <cassert>
#include <utility>

namespace four
{

////////
TileColor::TileColor(uint32_t red, uint32_t green, uint32_t blue)
{
    assert(red < 256);
    assert(green < 256);
    assert(blue < 256);
    m_color[0] = red;
    m_color[1] = green;
    m_color[2] = blue;
}

TileColor::TileColor(std::array<uint32_t, 3> color)
{
    assert(!color.empty());

    m_color = std::move(color);
}

////////
TileColor ::~TileColor() = default;

////////
void TileColor::setColor(uint32_t red, uint32_t green, uint32_t blue)
{
    assert(red < 256);
    assert(green < 256);
    assert(blue < 256);

    m_color[0] = red;
    m_color[1] = green;
    m_color[2] = blue;
}

////////
void TileColor::setColor(const std::array<uint32_t, 3>& color)
{
    assert(!color.empty());
    assert(color[0] < 256);
    assert(color[1] < 256);
    assert(color[2] < 256);

    m_color = color;
}

////////
std::array<uint32_t, 3> TileColor::getColor() const
{
    return m_color;
}

} // namespace four
