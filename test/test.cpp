#include <catch2/catch_test_macros.hpp>
#include "coordination.hpp"
#include "tile.hpp"
#include "tilecolor.hpp"

TEST_CASE("Testing Coordination", "[tile]")
{
    const four::Coordination            cord(2, 1);
    const std::pair<uint32_t, uint32_t> result{2u, 1u};
    REQUIRE(cord.getCoordination() == result);
    REQUIRE(cord == result);
    REQUIRE(cord.getXCoordValue() == 2u);
    REQUIRE(cord.getXCoordValue() != 12u);
    REQUIRE(cord.getYCoordValue() == 1u);

    REQUIRE(cord.getSymbol() == "c2");
    REQUIRE(cord == "c2");
    REQUIRE(cord != "abc");

    const four::Coordination newCord("g2");
    REQUIRE(newCord == "g2");
}
TEST_CASE("Testing Tiles class ", "[tile]")
{
    const four::Tile                    tile(1, 1);
    const std::pair<uint32_t, uint32_t> result{1, 1};
    REQUIRE(tile.getCoordination() == result);
    REQUIRE(tile == result);

    REQUIRE(tile.getSymbol() == "b2");
    REQUIRE(tile == "b2");
}

TEST_CASE("Testing Color", "[Color]")
{
    const four::TileColor color(0x00FF0000);
    REQUIRE(color.getColor() == 0x00FF0000);

    const four::TileColor newColor = {0xFF, 0x1A, 0x22};
    REQUIRE(newColor.getColor() == 0x00FF1A22);
    REQUIRE(newColor.getRedValue() == 0xFF);
    REQUIRE(newColor.getGreenValue() == 0x1A);
    REQUIRE(newColor.getBlueValue() == 0x22);
    std::array<uint8_t, 3> result = {0xFF, 0x1A, 0x22};
    REQUIRE(newColor.getColorAsArray() == result);
}
