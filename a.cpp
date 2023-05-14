#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void replaceFirstLetterToLowercase(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Falha ao abrir o arquivo: " << filename << std::endl;
        return;
    }

    std::string line;
    std::string modifiedContent;

    while (std::getline(file, line)) {
        if (!line.empty()) {
            line[0] = std::tolower(line[0]);
        }
        modifiedContent += line + "\n";
    }

    file.close();

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cout << "Falha ao abrir o arquivo para escrita: " << filename << std::endl;
        return;
    }

    outFile << modifiedContent;
    outFile.close();

    std::cout << "Substituição concluída com sucesso: " << filename << std::endl;
}

int main() {
    replaceFirstLetterToLowercase("adjetivos.txt");
    replaceFirstLetterToLowercase("substantivos.txt");
    replaceFirstLetterToLowercase("verbos.txt");

    return 0;
}
