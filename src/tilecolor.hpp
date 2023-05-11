#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <tuple>

namespace four
{

class TileColor
{
public:
    TileColor(uint32_t red, uint32_t green, uint32_t blue);

    ~TileColor();
    TileColor(TileColor&&)                 = default;
    TileColor(const TileColor&)            = default;
    TileColor& operator=(TileColor&&)      = default;
    TileColor& operator=(const TileColor&) = default;

    void setColor(uint32_t red, uint32_t green, uint32_t blue);

    std::tuple<uint32_t, uint32_t, uint32_t> getColor() const;

private:
    std::tuple<uint32_t, uint32_t, uint32_t> m_color;
};


} // namespace four


#endif // !COLOR_HPP
