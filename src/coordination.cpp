#include "coordination.hpp"
#include <cassert>

namespace four
{

//////////////
Coordination::Coordination(uint32_t xCoord, uint32_t yCoord)
{
    assert(xCoord < 8u);
    assert(yCoord < 8u);

    m_symbol[0] = 'a' + xCoord;
    m_symbol[1] = '1' + yCoord;
}

//////////////
Coordination::Coordination(const std::string_view& boardCoord)
{
    assert(boardCoord.size() == 2);
    assert(static_cast<uint32_t>(boardCoord[0] - 'a') < 8u);
    assert(static_cast<uint32_t>(boardCoord[1] - '0') < 8u);

    m_symbol[0] = boardCoord[0];
    m_symbol[1] = boardCoord[1];
}

//////////////
Coordination& Coordination::operator=(const std::string_view& value)
{
    assert(value.size() == 2);
    assert(static_cast<uint32_t>(value[0] - 'a') < 8u);
    assert(static_cast<uint32_t>(value[1] - '0') < 8u);
    m_symbol[0] = value[0];
    m_symbol[1] = value[1];
    return *this;
}

//////////////
bool Coordination::operator==(const Coordination& other) const
{
    return m_symbol == other.m_symbol;
}

//////////////
bool operator==(const Coordination& cord, const std::string_view& other)
{
    return other.size() == 2 && cord.m_symbol[0] == other[0] && cord.m_symbol[1] == other[1];
}

//////////////
bool operator==(const Coordination& cord, const std::pair<uint32_t, uint32_t> other)
{
    std::pair<uint32_t, uint32_t> cordPair{static_cast<uint32_t>(cord.m_symbol[0] - 'a'),
                                           static_cast<uint32_t>(cord.m_symbol[1] - '1')};
    return cordPair == other;
}

//////////////
uint32_t Coordination::getXCoordValue() const
{
    return static_cast<uint32_t>(m_symbol[0] - 'a');
}

//////////////
uint32_t Coordination::getYCoordValue() const
{
    return static_cast<uint32_t>(m_symbol[1] - '1');
}

//////////////
std::pair<uint32_t, uint32_t> Coordination::getCoordination() const
{
    return {getXCoordValue(), getYCoordValue()};
}

//////////////
std::string Coordination::getSymbol() const
{
    std::string result;
    result = m_symbol[0];
    result += m_symbol[1];
    return result;
}

} // namespace four
