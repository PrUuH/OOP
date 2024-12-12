#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>

class Cell {
public:
    bool isAlive = false;
};

class Game {
public:
    std::string gameName;
    std::vector<std::vector<Cell>> field;
    std::vector<int> birthRules;
    std::vector<int> survivalRules;
    int numRows = 0;
    int numColumns = 0;
    int currentIteration = 0;

    void readFromFile(const std::string& filename);
    void parseRules(const std::string& ruleString);
    void parseSize(const std::string& sizeString);
    void parseCell(const std::string& cellString);
    void initializeRandomField(int rows, int columns);
    void tick(int n);
    void dump(const std::string& filename);
    void printField();
    void help();
    void applyRules();
    int countAliveNeighbors(int row, int column);
};

void Game::readFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::string line;

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input file!!!!!!!!!" << std::endl;
        return;
    }
    // reading name of field
    std::getline(inputFile, line);
    std::regex nameRegex(R"(^#N (.+)$)"); //finds any string that started with #N
    std::smatch nameMatch;
    if (std::regex_match(line, nameMatch, nameRegex)) {
        gameName = nameMatch[0];
    } else {
        std::cerr << "Missing universe name!" << std::endl;
        return;
    }

    // reading of rules
    std::getline(inputFile, line);
    std::regex rulesRegex(R"(^#R B([0-8]+)/S([0-8]+)$)"); //finds any string that started with #R B, and next number, and then S, and next number
    std::smatch rulesMatch;
    if (std::regex_match(line, rulesMatch, rulesRegex)) {
        parseRules(rulesMatch[0]);
    } else {
        std::cerr << "Missing or invalid rules!" << std::endl;
        return;
    }

    // reading of size
    std::getline(inputFile, line);
    std::regex sizeRegex(R"(^#S (\d+) (\d+)$)"); //finds any string started with #S with 2 integers with space
    std::smatch sizeMatch;
    if (std::regex_match(line, sizeMatch, sizeRegex)) {
        parseSize(sizeMatch[0]);
    } else {
        std::cerr << "Missing or invalid size!" << std::endl;
        return;
    }

    // reading cell conditions
    while (std::getline(inputFile, line)) {
        parseCell(line);
    }
    inputFile.close();
}

void Game::parseRules(const std::string& ruleString) {
    std::regex rulesRegex(R"(^#R B([0-8]+)/S([0-8]+)$)"); 
    std::smatch rulesMatch;
    if (std::regex_match(ruleString, rulesMatch, rulesRegex)) {
        std::string birthString = rulesMatch[1];
        std::string survivalString = rulesMatch[2];

        birthRules.clear();
        survivalRules.clear();
        for (char c : birthString) {
            birthRules.push_back(c - '0');
        }
        for (char c : survivalString) {
            survivalRules.push_back(c - '0');
        }
    } else {
        std::cerr << "Invalid rules format: " << ruleString << std::endl;
        birthRules = {3}; 
        survivalRules = {2, 3}; 
    }
}

void Game::parseSize(const std::string& sizeString) {
    std::regex sizeRegex(R"(^#S (\d+) (\d+)$)");
    std::smatch sizeMatch;
    if (std::regex_match(sizeString, sizeMatch, sizeRegex)) {
        numRows = std::stoi(sizeMatch[1]);
        numColumns = std::stoi(sizeMatch[2]);
        field.resize(numRows, std::vector<Cell>(numColumns));
    }
}

void Game::parseCell(const std::string& cellString) {
    std::regex cellRegex(R"(^(\d+) (\d+)$)");
    std::smatch cellMatch;
    if (std::regex_match(cellString, cellMatch, cellRegex)) {
        int column = std::stoi(cellMatch[1]);
        int row = std::stoi(cellMatch[2]);
        if (row >= 0 && row < numRows && column >= 0 && column < numColumns) {
            field[row][column].isAlive = true;
        } else {
std::cerr << "Cell coordinates out of bounds!" << std::endl;
        }
    }
}

void Game::initializeRandomField(int rows, int columns) {
    std::srand(std::time(0));
    field.resize(rows, std::vector<Cell>(columns));
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            field[i][j].isAlive = std::rand() % 2; // randomly cell state
        }
    }
}

void Game::tick(int n) {
    for(int i = 0; i < n; ++i) {
        applyRules();
        currentIteration++;
        printField();
    }
}

void Game::dump(const std::string& filename) {
    std::ofstream outputFile(filename);
    if(!outputFile.is_open()) {
        std::cerr << "Unable to open output file" << std::endl;
        return;
    }
    outputFile << "#N " << gameName << "\n";
    outputFile << "#R B";
    for(int b : birthRules) outputFile << b;
    outputFile << "/S";
    for(int s : survivalRules) outputFile << s;
    outputFile << "\n#S " << numRows << " " << numColumns << "\n";
    for(int i = 0; i < numRows; ++i) {
        for(int j = 0; j < numColumns; ++j) {
            if(field[i][j].isAlive) {
                outputFile << j << " " << i << "\n";
            }
        }
    }
    outputFile.close();
}

void Game::printField() {
    std::cout << "Universe: " << gameName << "\n";
    std::cout << "Rules: B:";
    for(int b : birthRules) std::cout << b;
    std::cout << "/S";
    for(int s : survivalRules) std::cout << s;
    std::cout << "\nIteration: " << currentIteration << "\n";
    for(const auto& row : field) {
        for(const auto& cell : row) {
            std::cout << (cell.isAlive ? '0' : '.') << ' ';
        }
        std::cout << '\n';
    }
}

void Game::help() {
    std::cout << "Available commands:\n";
    std::cout << "dump <filename> - save universe to file\n";
    std::cout << "tick <n = 1> - calculate n iterations and print result\n";
    std::cout << "exit - exit the game\n";
    std::cout << "help - print this help meassage\n";
}

void Game::applyRules() {
    std::vector<std::vector<Cell>> newField = field;
    for(int i = 0; i < numRows; ++i) {
        for(int j = 0; j < numColumns; ++j) {
            int aliveNeighbors = countAliveNeighbors(i, j);
            if(field[i][j].isAlive) {
                newField[i][j].isAlive = (std::find(survivalRules.begin(), survivalRules.end(), aliveNeighbors) != survivalRules.end());
            } else {
                newField[i][j].isAlive = (std::find(birthRules.begin(), birthRules.end(), aliveNeighbors) != birthRules.end());
            }
        }
    }
    field = newField;
}

int Game::countAliveNeighbors(int row, int column) {
    int aliveCount = 0;
    for (int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; //skip the cell itself
            int neighborRow = (row + i + numRows) % numRows; //toroidal wrap
            int neighborColumn = (column + j + numColumns) % numColumns; //toroidal wrap
            if(field[neighborRow][neighborColumn].isAlive) {
                aliveCount++;
            }
        }
    }
    return aliveCount;
}

int main(int argc, char* argv[]) {
    Game game;

    //processing command line arguments
    if(argc > 1) {
        std::string filename = argv[1];
        game.readFromFile(filename);
    } else {
        game.initializeRandomField(10, 10); //default size
    }

    std::string command;
    while(true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if(cmd == "dump") {
            std::string filename;
            iss >> filename;
            game.dump(filename);
        } else if(cmd == "tick" || cmd == "t") {
            int n = 1;
            iss >> n;
            game.tick(n);
        } else if(cmd == "exit") {
            break;
        } else if(cmd == "help") {
            game.help();
        } else {
            std::cout << "Unknown command. Type 'help' for a list of commands" << std::endl;
        }
    }
    return 0;
}