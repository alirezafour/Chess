#include "tilecolor.hpp"

#include <array>
#include <cassert>
#include <cstdint>
#include <utility>

namespace four
{

////////
TileColor::TileColor(uint8_t red, uint8_t green, uint8_t blue)
{
    setColor(red, green, blue);
}

TileColor::TileColor(uint32_t color)
{
    m_color = color;
}

////////
TileColor ::~TileColor() = default;

////////
void TileColor::setColor(uint8_t red, uint8_t green, uint8_t blue)
{
    m_color = (static_cast<uint32_t>(red) << 16) | (static_cast<uint32_t>(green) << 8) | (static_cast<uint32_t>(blue));
}

////////
void TileColor::setColor(uint32_t color)
{
    m_color = color;
}

////////
uint32_t TileColor::getColor() const
{
    return m_color;
}

////////
uint8_t TileColor::getRedValue() const
{
    return static_cast<uint8_t>((m_color & 0x00FF0000) >> 16);
}

////////
uint8_t TileColor::getGreenValue() const
{
    return static_cast<uint8_t>((m_color & 0x0000FF00) >> 8);
}

////////
uint8_t TileColor::getBlueValue() const
{
    return static_cast<uint8_t>(m_color & 0x000000FF);
}

////////
std::array<uint8_t, 3> TileColor::getColorAsArray() const
{
    std::array<uint8_t, 3> color = {getRedValue(), getGreenValue(), getBlueValue()};
    return color;
}

} // namespace four
