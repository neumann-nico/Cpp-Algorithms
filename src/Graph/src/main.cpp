#include <chrono>
#include <iostream>
#include <string>
#include "Graph/algorithm.h"

int main() {
    std::string filename, node;
    std::string input;
    int action;

    std::cout << "Please enter a filename to load the graph: ";
    std::cin >> filename;

    Algorithm algorithm = Algorithm("../../../src/Graph/graphs/" + filename);

    while (true) {
        std::cout << std::endl;
        std::cout << "0) Exit" << std::endl;
        std::cout << "1) Change graph file" << std::endl;
        std::cout << "2) Breadth Search" << std::endl;
        std::cout << "3) Depth Search" << std::endl;
        std::cout << "4) Related Components" << std::endl;
        std::cout << "5) Prim" << std::endl;
        std::cout << "6) Kruskal" << std::endl;
        std::cout << "7) Nearest Neighbour" << std::endl;
        std::cout << "8) Double Tree" << std::endl;
        std::cout << "9) Try all possibilities" << std::endl;
        std::cout << "10) Branch and Bound" << std::endl;
        std::cout << "11) Dijkstra" << std::endl;
        std::cout << "12) Moore-Bellman-Ford" << std::endl;
        std::cout << "13) Edmonds-Karp" << std::endl;
        std::cout << "14) Cycle-Canceling" << std::endl;
        std::cout << "15) Successive-Shortest-Path" << std::endl;

        do {
            std::cout << "action: ";
            std::cin >> input;
            try {
                action = stoi(input);
            }
            catch (std::exception e) {
                continue;
            }
        } while (!(action >= 0 && action <= 15));

        if (action == 0)
            return 0;
        if ((action >= 2 && action <= 3) || action == 5 || action == 7 || action == 8 ||
            (action >= 11 && action <= 13)) {
            std::cout << "Select start node: ";
            std::cin >> node;
        }
        if (action == 1) {
            std::cout << "Please enter a filename to load the graph: ";
            std::cin >> filename;
            algorithm.process("../../../src/Graph/graphs/" + filename);
        } else if (action == 2) {
            auto start = std::chrono::system_clock::now();
            algorithm.breadthSearch(stoi(node));
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime iterative: " << elapsed.count() << " s\n";
        } else if (action == 3) {
            std::cout << "0) Exit" << std::endl;
            std::cout << "1) Iterative" << std::endl;
            std::cout << "2) Recursive" << std::endl;

            do {
                std::cout << "action: ";
                std::cin >> input;
                try {
                    action = stoi(input);
                }
                catch (std::exception e) {
                    continue;
                }
            } while (!(action >= 0 && action <= 2));

            if (action == 0)
                continue;
            if (action == 1) {
                auto start = std::chrono::system_clock::now();
                algorithm.depthSearch(stoi(node));
                auto end = std::chrono::system_clock::now();

                std::chrono::duration<long double> elapsed = end - start;
                std::cout << "- Runtime iterative: " << elapsed.count() << " s\n";
            }
            if (action == 2) {
                auto start = std::chrono::system_clock::now();
                algorithm.depthSearch(stoi(node), true);
                auto end = std::chrono::system_clock::now();

                std::chrono::duration<long double> elapsed = end - start;
                std::cout << "- Runtime recursive: " << elapsed.count() << " s\n";
            }
        } else if (action == 4) {
            auto start = std::chrono::system_clock::now();
            std::cout << "Related components: " << algorithm.relatedComponents() << std::endl;
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
        } else if (action == 5) {
            auto start = std::chrono::system_clock::now();
            std::cout << "Prim costs: " << algorithm.prim(stoi(node)) << std::endl;
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";

        } else if (action == 6) {
            auto start = std::chrono::system_clock::now();
            std::cout << "Kruskal costs: " << algorithm.kruskal() << std::endl;
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
        } else if (action == 7) {
            auto start = std::chrono::system_clock::now();
            std::cout << "Nearest Neighbor costs: " << algorithm.nearestNeighbor(stoi(node)) << std::endl;
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
            algorithm.printVisitedPath();
        } else if (action == 8) {
            auto start = std::chrono::system_clock::now();
            std::cout << "Double Tree costs: " << algorithm.doubleTree(stoi(node)) << std::endl;
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
            algorithm.printVisitedPath();
        } else if (action == 9) {
            auto start = std::chrono::system_clock::now();
            std::cout << "Try all possibilities costs: " << algorithm.tryAllPossibilities() << std::endl;
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
            algorithm.printVisitedPath();
        } else if (action == 10) {
            auto start = std::chrono::system_clock::now();
            std::cout << "Branch and Bound costs: " << algorithm.branchAndBound() << std::endl;
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
            algorithm.printVisitedPath();
        } else if (action == 11) {
            std::string end_node;
            std::cout << "Select end node: ";
            std::cin >> end_node;
            std::string directed;
            std::cout << "Directed (y/N): ";
            std::cin >> directed;

            bool directedB = directed == "y";

            double distance;
            auto start = std::chrono::system_clock::now();
            try {
                algorithm.dijkstra(distance, stoi(node), stoi(end_node), directedB);

            } catch (const std::exception &e) {
                std::cout << "Error during execution -> no path ?\n";
            }
            auto end = std::chrono::system_clock::now();


            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
        } else if (action == 12) {
            std::string end_node;
            std::cout << "Select end node: ";
            std::cin >> end_node;

            double distance;
            auto start = std::chrono::system_clock::now();
            try {
                algorithm.mooreBellmanFord(distance, stoi(node), stoi(end_node), true);

            } catch (const std::exception &e) {
                std::cout << "Error during execution -> no path ?\n";
            }
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
        } else if (action == 13) {
            std::string end_node;
            std::cout << "Select end node: ";
            std::cin >> end_node;

            auto start = std::chrono::system_clock::now();
            std::cout << "Edmonds Karp costs: " << algorithm.edmondsKarp(stoi(node), stoi(end_node)) << std::endl;
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
            algorithm.printVisitedPath();
        } else if (action == 14) {
            auto start = std::chrono::system_clock::now();
            std::cout << "Cycle-Canceling costs: " << algorithm.cycleCanceling() << std::endl;
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
        } else if (action == 15) {
            auto start = std::chrono::system_clock::now();
            std::cout << "Successive-Shortest-Path costs: " << algorithm.successiveShortestPath() << std::endl;
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<long double> elapsed = end - start;
            std::cout << "- Runtime: " << elapsed.count() << " s\n";
        }
    }

    return 0;
}
