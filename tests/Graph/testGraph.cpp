#include "gtest/gtest.h"
#include "Graph/algorithm.h"

double deviation = 0.01;
std::string graphPath = "../../../src/Graph/graphs/";

class GraphTest : public ::testing::Test {
    virtual void SetUp() {
        algorithm_ = new Algorithm();
    }

    virtual void TearDown() {
        delete algorithm_;
    }

protected:
    Algorithm *algorithm_;
};

TEST_F(GraphTest, test_related_components1) {
    algorithm_->process(graphPath + "Graph2.txt");
    EXPECT_FALSE(algorithm_->getGraph()->allVisited());
    EXPECT_EQ(algorithm_->relatedComponents(), 4);
    EXPECT_TRUE(algorithm_->getGraph()->allVisited());
}

TEST_F(GraphTest, test_related_components2) {
    algorithm_->process(graphPath + "Graph3.txt");
    EXPECT_FALSE(algorithm_->getGraph()->allVisited());
    EXPECT_EQ(algorithm_->relatedComponents(), 4);
    EXPECT_TRUE(algorithm_->getGraph()->allVisited());
}

TEST_F(GraphTest, test_related_components3) {
    algorithm_->process(graphPath + "Graph_gross.txt");
    EXPECT_FALSE(algorithm_->getGraph()->allVisited());
    EXPECT_EQ(algorithm_->relatedComponents(), 222);
    EXPECT_TRUE(algorithm_->getGraph()->allVisited());
}

TEST_F(GraphTest, test_related_components4) {
    GTEST_SKIP(); // too slow
    algorithm_->process(graphPath + "Graph_ganzgross.txt");
    EXPECT_FALSE(algorithm_->getGraph()->allVisited());
    EXPECT_EQ(algorithm_->relatedComponents(), 9560);
    EXPECT_TRUE(algorithm_->getGraph()->allVisited());
}

TEST_F(GraphTest, test_related_components5) {
    GTEST_SKIP(); // too slow
    algorithm_->process(graphPath + "Graph_ganzganzgross.txt");
    EXPECT_FALSE(algorithm_->getGraph()->allVisited());
    EXPECT_EQ(algorithm_->relatedComponents(), 306);
    EXPECT_TRUE(algorithm_->getGraph()->allVisited());
}

TEST_F(GraphTest, test_G_1_2_prim) {
    algorithm_->process(graphPath + "G_1_2.txt");
    EXPECT_NEAR(algorithm_->prim(0), 287.32286, deviation);
}

TEST_F(GraphTest, test_G_1_2_kruskal) {
    algorithm_->process(graphPath + "G_1_2.txt");
    EXPECT_NEAR(algorithm_->kruskal(), 287.32286, deviation);
}

TEST_F(GraphTest, test_G_1_20_prim) {
    algorithm_->process(graphPath + "G_1_20.txt");
    EXPECT_NEAR(algorithm_->prim(0), 36.86275, deviation);
}

TEST_F(GraphTest, test_G_1_20_kruskal) {
    algorithm_->process(graphPath + "G_1_20.txt");
    EXPECT_NEAR(algorithm_->kruskal(), 36.86275, deviation);
}

TEST_F(GraphTest, test_G_1_200_prim) {
    algorithm_->process(graphPath + "G_1_200.txt");
    EXPECT_NEAR(algorithm_->prim(0), 12.68182, deviation);
}

TEST_F(GraphTest, test_G_1_200_kruskal) {
    algorithm_->process(graphPath + "G_1_200.txt");
    EXPECT_NEAR(algorithm_->kruskal(), 12.68182, deviation);

}

TEST_F(GraphTest, test_G_10_20_prim) {
    algorithm_->process(graphPath + "G_10_20.txt");
    EXPECT_NEAR(algorithm_->prim(0), 2785.62417, deviation);
}

TEST_F(GraphTest, test_G_10_20_kruskal) {
    algorithm_->process(graphPath + "G_10_20.txt");
    EXPECT_NEAR(algorithm_->kruskal(), 2785.62417, deviation);
}

TEST_F(GraphTest, test_G_10_200_prim) {
    algorithm_->process(graphPath + "G_10_200.txt");
    EXPECT_NEAR(algorithm_->prim(0), 372.14417, deviation);
}

TEST_F(GraphTest, test_G_10_200_kruskal) {
    algorithm_->process(graphPath + "G_10_200.txt");
    EXPECT_NEAR(algorithm_->kruskal(), 372.14417, deviation);
}

TEST_F(GraphTest, test_G_100_200_prim) {
    algorithm_->process(graphPath + "G_100_200.txt");
    EXPECT_NEAR(algorithm_->prim(0), 27550.51488, deviation);
}

TEST_F(GraphTest, test_G_100_200_kruskal) {
    algorithm_->process(graphPath + "G_100_200.txt");
    EXPECT_NEAR(algorithm_->kruskal(), 27550.51488, deviation);
}


TEST_F(GraphTest, test_K_10_tryAllPossibilities) {
    algorithm_->process(graphPath + "K_10.txt");
    EXPECT_NEAR(algorithm_->tryAllPossibilities(), 38.41, deviation);
}

TEST_F(GraphTest, test_K_10_branchAndBound) {
    algorithm_->process(graphPath + "K_10.txt");
    EXPECT_NEAR(algorithm_->branchAndBound(), 38.41, deviation);
}

TEST_F(GraphTest, test_K_10_doubleTree) {
    algorithm_->process(graphPath + "K_10.txt");
    double value = algorithm_->doubleTree(0);
    EXPECT_GE(value, 38.41);
    EXPECT_LE(value, 2 * 38.41);
}

TEST_F(GraphTest, test_K_10e_tryAllPossibilities) {
    algorithm_->process(graphPath + "K_10e.txt");
    EXPECT_NEAR(algorithm_->tryAllPossibilities(), 27.26, deviation);
}

TEST_F(GraphTest, test_K_10e_branchAndBound) {
    algorithm_->process(graphPath + "K_10e.txt");
    EXPECT_NEAR(algorithm_->branchAndBound(), 27.26, deviation);
}

TEST_F(GraphTest, test_K_10e_doubleTree) {
    algorithm_->process(graphPath + "K_10e.txt");
    double value = algorithm_->doubleTree(0);
    EXPECT_GE(value, 27.26);
    EXPECT_LE(value, 2 * 27.26);
}

TEST_F(GraphTest, test_K_12_tryAllPossibilities) {
    GTEST_SKIP(); // too slow
    algorithm_->process(graphPath + "K_12.txt");
    EXPECT_NEAR(algorithm_->tryAllPossibilities(), 45.19, deviation);
}

TEST_F(GraphTest, test_K_12_branchAndBound) {
    GTEST_SKIP(); // too slow
    algorithm_->process(graphPath + "K_12.txt");
    EXPECT_NEAR(algorithm_->branchAndBound(), 45.19, deviation);
}

TEST_F(GraphTest, test_K_12_doubleTree) {
    GTEST_SKIP(); // too slow
    algorithm_->process(graphPath + "K_12.txt");
    double value = algorithm_->doubleTree(0);
    EXPECT_GE(value, 45.19);
    EXPECT_LE(value, 2 * 45.19);
}

TEST_F(GraphTest, test_K_12e_tryAllPossibilities) {
    GTEST_SKIP(); // too slow
    algorithm_->process(graphPath + "K_12e.txt");
    EXPECT_NEAR(algorithm_->tryAllPossibilities(), 36.13, deviation);
}

TEST_F(GraphTest, test_K_12e_branchAndBound) {
    GTEST_SKIP(); // too slow
    algorithm_->process(graphPath + "K_12e.txt");
    EXPECT_NEAR(algorithm_->branchAndBound(), 36.13, deviation);
}

TEST_F(GraphTest, test_K_12e_doubleTree) {
    GTEST_SKIP(); // too slow
    algorithm_->process(graphPath + "K_12e.txt");
    double value = algorithm_->doubleTree(0);
    EXPECT_GE(value, 36.13);
    EXPECT_LE(value, 2 * 36.13);
}

TEST_F(GraphTest, test_Wege1_dijkstra) {
    algorithm_->process(graphPath + "Wege1.txt", Direction::FORWARD);
    double value;
    algorithm_->dijkstra(value, 2, 0, true);
    EXPECT_NEAR(value, 6., deviation);
}

TEST_F(GraphTest, test_Wege1_mooreBellmanFord) {
    algorithm_->process(graphPath + "Wege1.txt", Direction::FORWARD);
    double value;
    bool negative_cycle = !algorithm_->mooreBellmanFord(value, 2, 0, true);
    EXPECT_NEAR(value, 6., deviation);
    EXPECT_FALSE(negative_cycle);
}

TEST_F(GraphTest, test_Wege2_dijkstra) {
    algorithm_->process(graphPath + "Wege2.txt", Direction::FORWARD);
    double value;
    algorithm_->dijkstra(value, 2, 0, true);
    EXPECT_NEAR(value, 2., deviation);
}

TEST_F(GraphTest, test_Wege2_mooreBellmanFord) {
    algorithm_->process(graphPath + "Wege2.txt", Direction::FORWARD);
    double value;
    bool negative_cycle = !algorithm_->mooreBellmanFord(value, 2, 0, true);
    EXPECT_NEAR(value, 2., deviation);
    EXPECT_FALSE(negative_cycle);
}

TEST_F(GraphTest, test_Wege3_mooreBellmanFord) {
    algorithm_->process(graphPath + "Wege3.txt", Direction::FORWARD);
    double value;
    bool negative_cycle = !algorithm_->mooreBellmanFord(value, 2, 0, true);
    EXPECT_TRUE(negative_cycle);
}

TEST_F(GraphTest, test_G_1_2_directed_mooreBellmanFord) {
    algorithm_->process(graphPath + "G_1_2.txt", Direction::FORWARD);
    double value;
    bool negative_cycle = !algorithm_->mooreBellmanFord(value, 0, 1, true);
    EXPECT_NEAR(value, 5.56283, deviation);
    EXPECT_FALSE(negative_cycle);
}

TEST_F(GraphTest, test_G_1_2_undirected_mooreBellmanFord) {
    algorithm_->process(graphPath + "G_1_2.txt", Direction::UNDIRECTED);
    double value;
    bool negative_cycle = !algorithm_->mooreBellmanFord(value, 0, 1, true);
    EXPECT_NEAR(value, 2.36802, deviation);
    EXPECT_FALSE(negative_cycle);
}

TEST_F(GraphTest, test_Fluss_edmondsKarp) {
    algorithm_->process(graphPath + "Fluss.txt", Direction::FORWARD);
    double value = algorithm_->edmondsKarp(0, 7);
    EXPECT_NEAR(value, 4., deviation);
}

TEST_F(GraphTest, test_Fluss2_edmondsKarp) {
    algorithm_->process(graphPath + "Fluss2.txt", Direction::FORWARD);
    double value = algorithm_->edmondsKarp(0, 7);
    EXPECT_NEAR(value, 5., deviation);
}

TEST_F(GraphTest, test_G_1_2_edmondsKarp) {
    algorithm_->process(graphPath + "G_1_2.txt", Direction::FORWARD);
    double value = algorithm_->edmondsKarp(0, 7);
    EXPECT_NEAR(value, 0.75447, deviation);
}

TEST_F(GraphTest, test_Kostenminimal1_cycleCanceling) {
    algorithm_->process(graphPath + "Kostenminimal1.txt", Direction::FORWARD);
    double value = algorithm_->cycleCanceling();
    EXPECT_NEAR(value, 3, deviation);
}

TEST_F(GraphTest, test_Kostenminimal2_cycleCanceling) {
    algorithm_->process(graphPath + "Kostenminimal2.txt", Direction::FORWARD);
    double value = algorithm_->cycleCanceling();
    EXPECT_NEAR(value, 0, deviation);
}

TEST_F(GraphTest, test_Kostenminimal3_cycleCanceling) {
    algorithm_->process(graphPath + "Kostenminimal3.txt", Direction::FORWARD);
    double value = algorithm_->cycleCanceling();
    EXPECT_EQ(value, INFINITY);
}

TEST_F(GraphTest, test_Kostenminimal4_cycleCanceling) {
    algorithm_->process(graphPath + "Kostenminimal4.txt", Direction::FORWARD);
    double value = algorithm_->cycleCanceling();
    EXPECT_EQ(value, INFINITY);
}

TEST_F(GraphTest, test_Kostenminimal_gross1_cycleCanceling) {
    algorithm_->process(graphPath + "Kostenminimal_gross1.txt", Direction::FORWARD);
    double value = algorithm_->cycleCanceling();
    EXPECT_NEAR(value, 1537, deviation);
}

TEST_F(GraphTest, test_Kostenminimal_gross2_cycleCanceling) {
    algorithm_->process(graphPath + "Kostenminimal_gross2.txt", Direction::FORWARD);
    double value = algorithm_->cycleCanceling();
    EXPECT_NEAR(value, 1838, deviation);
}

TEST_F(GraphTest, test_Kostenminimal_gross3_cycleCanceling) {
    algorithm_->process(graphPath + "Kostenminimal_gross3.txt", Direction::FORWARD);
    double value = algorithm_->cycleCanceling();
    EXPECT_EQ(value, INFINITY);
}

TEST_F(GraphTest, test_Kostenminimal1_successiveShortestPath) {
    algorithm_->process(graphPath + "Kostenminimal1.txt", Direction::FORWARD);
    double value = algorithm_->successiveShortestPath();
    EXPECT_NEAR(value, 3, deviation);
}

TEST_F(GraphTest, test_Kostenminimal2_successiveShortestPath) {
    algorithm_->process(graphPath + "Kostenminimal2.txt", Direction::FORWARD);
    double value = algorithm_->successiveShortestPath();
    EXPECT_NEAR(value, 0, deviation);
}

TEST_F(GraphTest, test_Kostenminimal3_successiveShortestPath) {
    algorithm_->process(graphPath + "Kostenminimal3.txt", Direction::FORWARD);
    double value = algorithm_->successiveShortestPath();
    EXPECT_EQ(value, INFINITY);
}

TEST_F(GraphTest, test_Kostenminimal4_successiveShortestPath) {
    algorithm_->process(graphPath + "Kostenminimal4.txt", Direction::FORWARD);
    double value = algorithm_->successiveShortestPath();
    EXPECT_EQ(value, INFINITY);
}

TEST_F(GraphTest, test_Kostenminimal_gross1_successiveShortestPath) {
    algorithm_->process(graphPath + "Kostenminimal_gross1.txt", Direction::FORWARD);
    double value = algorithm_->successiveShortestPath();
    EXPECT_NEAR(value, 1537, deviation);
}

TEST_F(GraphTest, test_Kostenminimal_gross2_successiveShortestPath) {
    algorithm_->process(graphPath + "Kostenminimal_gross2.txt", Direction::FORWARD);
    double value = algorithm_->successiveShortestPath();
    EXPECT_NEAR(value, 1838, deviation);
}

TEST_F(GraphTest, test_Kostenminimal_gross3_successiveShortestPath) {
    algorithm_->process(graphPath + "Kostenminimal_gross3.txt", Direction::FORWARD);
    double value = algorithm_->successiveShortestPath();
    EXPECT_EQ(value, INFINITY);
}