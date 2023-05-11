#ifndef COORDINATION_HPP

#define COORDINATION_HPP

#include <cstdint>
#include <string>
#include <array>
#include <string_view>

namespace four
{

class Coordination
{
public:
    Coordination(uint32_t xCoord, uint32_t yCoord);
    Coordination(const std::string_view& boardCoord);
    Coordination(const Coordination&)     = default;
    Coordination(Coordination&&) noexcept = default;

    Coordination& operator=(const Coordination&) = default;
    Coordination& operator=(const std::string_view& value);
    Coordination& operator=(Coordination&&) = default;

    bool operator==(const Coordination& other) const;

    friend bool operator==(const Coordination& cord, const std::string_view& other);

    friend bool operator==(const Coordination& cord, const std::pair<uint32_t, uint32_t> other);

    /* return coordination as number */
    std::pair<uint32_t, uint32_t> getCoordination() const;

    /* return x coordination (0-7) */
    uint32_t getXCoordValue() const;

    /* return y coordination (0-7) */
    uint32_t getYCoordValue() const;

    /* return coordination symbol of chess board */
    std::string getSymbol() const;

private:
    std::array<char, 2> m_symbol;
};

} // namespace four
#endif // COORDINATION_HPP
