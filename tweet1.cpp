#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

std::vector<std::string> readLinesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

int main() {
    int numeroTweets = 10;

    std::vector<std::string> adjetivos = readLinesFromFile("adjetivos.txt");
    std::vector<std::string> substantivos = readLinesFromFile("substantivos.txt");
    std::vector<std::string> verbos = readLinesFromFile("verbos.txt");

    if (adjetivos.empty() || substantivos.empty() || verbos.empty()) {
        std::cout << "Não há palavras suficientes para gerar o tweet." << std::endl;
        return 0;
    }

    std::default_random_engine rng(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<int> adjDist(0, adjetivos.size() - 1);
    std::uniform_int_distribution<int> subDist(0, substantivos.size() - 1);
    std::uniform_int_distribution<int> verboDist(0, verbos.size() - 1);

    for (int i = 0; i < numeroTweets; ++i) {
        std::string adjetivoAleatorio = adjetivos[adjDist(rng)];
        std::string substantivoAleatorio = substantivos[subDist(rng)];
        std::string verboAleatorio = verbos[verboDist(rng)];

        std::cout << "Ai gente, só eu que gosto quando o(a) " << substantivoAleatorio << " " << verboAleatorio << " " << adjetivoAleatorio << "?" << std::endl;
    }

    return 0;
}
