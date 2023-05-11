#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <array>

namespace four
{

class TileColor
{
public:
    TileColor(uint32_t red, uint32_t green, uint32_t blue);
    TileColor(std::array<uint32_t, 3> color);

    ~TileColor();
    TileColor(TileColor&&)                 = default;
    TileColor(const TileColor&)            = default;
    TileColor& operator=(TileColor&&)      = default;
    TileColor& operator=(const TileColor&) = default;

    void setColor(uint32_t red, uint32_t green, uint32_t blue);
    void setColor(const std::array<uint32_t, 3>& color);

    std::array<uint32_t, 3> getColor() const;

private:
    std::array<uint32_t, 3> m_color;
};


} // namespace four


#endif // !COLOR_HPP
