#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <array>

namespace four
{

class TileColor
{
public:
    TileColor(uint8_t red, uint8_t green, uint8_t blue);
    TileColor(uint32_t color);

    ~TileColor();
    TileColor(TileColor&&)                 = default;
    TileColor(const TileColor&)            = default;
    TileColor& operator=(TileColor&&)      = default;
    TileColor& operator=(const TileColor&) = default;

    void setColor(uint8_t red, uint8_t green, uint8_t blue);
    void setColor(uint32_t color);

    uint32_t               getColor() const;
    uint8_t                getRedValue() const;
    uint8_t                getGreenValue() const;
    uint8_t                getBlueValue() const;
    std::array<uint8_t, 3> getColorAsArray() const;

private:
    uint32_t m_color;
};


} // namespace four


#endif // !COLOR_HPP
