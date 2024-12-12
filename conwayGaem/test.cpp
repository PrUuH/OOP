// Пример юнит-тестов (в комментариях, так как их реализация требует отдельного файла и фреймворка)
// TEST(GameTest, Initialization) {
//     Game game;
//     game.initializeRandomField(5, 5);
//     EXPECT_EQ(game.numRows, 5);
//     EXPECT_EQ(game.numCols, 5);
// }

// TEST(GameTest, Tick) {
//     Game game;
//     game.initializeRandomField(5, 5);
//     game.tick(1);
//     // Проверить состояние поля после итерации
// }

// Примеры интересных вселенных
// 1. #N Glider
//    #R B3/S23
//    #S 5 5
//    1 0
//    2 1
//    0 2
//    1 2
//    2 2

// 2. #N Pulsar
//    #R B3/S23
//    #S 13 13
//    5 1
//    5 2
//    5 3
//    5 4
//    5 5
//    5 6
//    5 7
//    5 8
//    5 9
//    5 10
//    5 11
//    5 12
//    5 13

#include <gtest/gtest.h>
#include <iostream>
#include "main.cpp"

TEST(GameTest, ReadFromFile_ValidFile) {
    Game game;
    game.readFromFile("test.txt");

    EXPECT_EQ(game.gameName, "My universe");
    EXPECT_TRUE(std::equal(game.survivalRules.begin(), game.survivalRules.end(), std::vector<int>{2, 3}.begin()));
    EXPECT_TRUE(std::equal(game.survivalRules.begin(), game.survivalRules.end(), std::vector<int>{2, 3}.begin()));
    EXPECT_EQ(game.numRows, 10);
    EXPECT_EQ(game.numColumns, 10);
    EXPECT_TRUE(game.field[1][1].isAlive); //test that cell is alive
}

TEST(GameTest, ReadFromInvalidFile_InvalidFile) {
    Game game;
    game.readFromFile("invalid_universe.txt"); //we think this file is invalid

    EXPECT_EQ(game.gameName, ""); //universe name should be void
}

//test to initialize game with random
TEST(GameTest, InitializeRandomField) {
    Game game;
    game.initializeRandomField(10, 10);

    EXPECT_EQ(game.numRows, 10);
    EXPECT_EQ(game.numColumns, 10);
    EXPECT_EQ(game.field.size(), 10);
    EXPECT_EQ(game.field[0].size(), 10);
}

//test of rules application
TEST(GameTest, ApplyRules) {
    Game game;
    game.numRows = 3;
    game.numColumns = 3;
    game.field = {
        {Cell{true}, Cell{true}, Cell{false}},
        {Cell{false}, Cell{true}, Cell{false}},
        {Cell{false}, Cell{false}, Cell{false}}
    };
    game.birthRules = {3};
    game.survivalRules = {2, 3};

    game.applyRules();

    EXPECT_TRUE(game.field[0][1].isAlive); // cell should be alive after applying rules
    EXPECT_FALSE(game.field[0][2].isAlive); //cell should be dead after applying rules
}

//test for counting neighbors
TEST(GameTest, CountAliveNeighbors) {
    Game game;
    game.numRows = 3;
    game.numColumns = 3;
    game.field = {
        {Cell{true}, Cell{true}, Cell{false}},
        {Cell{false}, Cell{true}, Cell{false}},
        {Cell{false}, Cell{false}, Cell{false}}
    };

    EXPECT_EQ(game.countAliveNeighbors(1,1), 2); // cell (1,1) should have 2 alive neighbors
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }