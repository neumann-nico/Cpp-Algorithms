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

TEST_F(GraphTest, test_related_components1)
{
    algorithm_->process(graphPath + "Graph2.txt");
    EXPECT_EQ(algorithm_->relatedComponents(), 4);
}

TEST_F(GraphTest, test_related_components2)
{
    algorithm_->process(graphPath + "Graph3.txt");
    EXPECT_EQ(algorithm_->relatedComponents(), 4);
}

TEST_F(GraphTest, test_related_components3)
{
    algorithm_->process(graphPath + "Graph_gross.txt");
    EXPECT_EQ(algorithm_->relatedComponents(), 222);
}

TEST_F(GraphTest, test_related_components4)
{
    algorithm_->process(graphPath + "Graph_ganzgross.txt");
    EXPECT_EQ(algorithm_->relatedComponents(), 9560);
}

TEST_F(GraphTest, test_related_components5)
{
    algorithm_->process(graphPath + "Graph_ganzganzgross.txt");
    EXPECT_EQ(algorithm_->relatedComponents(), 306);
}

TEST_F(GraphTest, test_G_1_2_prim){
    algorithm_->process(graphPath + "G_1_2.txt");
    EXPECT_TRUE(std::abs(algorithm_->prim(0) - 287.32286) < deviation);
}

TEST_F(GraphTest, test_G_1_2_kruskal){
    algorithm_->process(graphPath + "G_1_2.txt");
    EXPECT_TRUE(std::abs(algorithm_->kruskal() - 287.32286) < deviation);

}

TEST_F(GraphTest, test_G_1_20_prim){
    algorithm_->process(graphPath + "G_1_20.txt");
    EXPECT_TRUE(std::abs(algorithm_->prim(0) - 36.86275) < deviation);

}

TEST_F(GraphTest, test_G_1_20_kruskal){
    algorithm_->process(graphPath + "G_1_20.txt");
    EXPECT_TRUE(std::abs(algorithm_->kruskal() - 36.86275) < deviation);
}

TEST_F(GraphTest, test_G_1_200_prim){
    algorithm_->process(graphPath + "G_1_200.txt");
    EXPECT_TRUE(std::abs(algorithm_->prim(0) - 12.68182) < deviation);
}

TEST_F(GraphTest, test_G_1_200_kruskal){
    algorithm_->process(graphPath + "G_1_200.txt");
    EXPECT_TRUE(std::abs(algorithm_->kruskal() - 12.68182) < deviation);

}

TEST_F(GraphTest, test_G_10_20_prim){
    algorithm_->process(graphPath + "G_10_20.txt");
    EXPECT_TRUE(std::abs(algorithm_->prim(0) - 2785.62417) < deviation);
}

TEST_F(GraphTest, test_G_10_20_kruskal){
    algorithm_->process(graphPath + "G_10_20.txt");
    EXPECT_TRUE(std::abs(algorithm_->kruskal() - 2785.62417) < deviation);
}

TEST_F(GraphTest, test_G_10_200_prim){
    algorithm_->process(graphPath + "G_10_200.txt");
    EXPECT_TRUE(std::abs(algorithm_->prim(0) - 372.14417) < deviation);
}

TEST_F(GraphTest, test_G_10_200_kruskal){
    algorithm_->process(graphPath + "G_10_200.txt");
    EXPECT_TRUE(std::abs(algorithm_->kruskal() - 372.14417) < deviation);
}

TEST_F(GraphTest, test_G_100_200_prim){
    algorithm_->process(graphPath + "G_100_200.txt");
    EXPECT_TRUE(std::abs(algorithm_->prim(0) - 27550.51488) < deviation);
}

TEST_F(GraphTest, test_G_100_200_kruskal){
    algorithm_->process(graphPath + "G_100_200.txt");
    EXPECT_TRUE(std::abs(algorithm_->kruskal() - 27550.51488) < deviation);
}


TEST_F(GraphTest, test_K_10_tryAllPossibilities){
    algorithm_->process(graphPath + "K_10.txt");
    EXPECT_TRUE(std::abs(algorithm_->tryAllPossibilities() - 38.41) < deviation);
}

TEST_F(GraphTest, test_K_10_branchAndBound){
    algorithm_->process(graphPath + "K_10.txt");
    EXPECT_TRUE(std::abs(algorithm_->branchAndBound() - 38.41) < deviation);
}

TEST_F(GraphTest, test_K_10_doubleTree){
    algorithm_->process(graphPath + "K_10.txt");
    double value = algorithm_->doubleTree(0);
    EXPECT_TRUE(value >= (38.41 - deviation) && value <= 2 * (38.41 - deviation));
}

TEST_F(GraphTest, test_K_10e_tryAllPossibilities){
    algorithm_->process(graphPath + "K_10e.txt");
    EXPECT_TRUE(std::abs(algorithm_->tryAllPossibilities() - 27.26) < deviation);
}

TEST_F(GraphTest, test_K_10e_branchAndBound){
    algorithm_->process(graphPath + "K_10e.txt");
    EXPECT_TRUE(std::abs(algorithm_->branchAndBound() - 27.26) < deviation);
}

TEST_F(GraphTest, test_K_10e_doubleTree){
    algorithm_->process(graphPath + "K_10e.txt");
    double value = algorithm_->doubleTree(0);
    EXPECT_TRUE(value >= (27.26 - deviation) && value <= 2 * (27.26 - deviation));
}

TEST_F(GraphTest, test_K_12_tryAllPossibilities){
    GTEST_SKIP(); // too slow
    algorithm_->process(graphPath + "K_12.txt");
    EXPECT_TRUE(std::abs(algorithm_->tryAllPossibilities() - 45.19) < deviation);
}

TEST_F(GraphTest, test_K_12_branchAndBound){
    algorithm_->process(graphPath + "K_12.txt");
    EXPECT_TRUE(std::abs(algorithm_->branchAndBound() - 45.19) < deviation);
}

TEST_F(GraphTest, test_K_12_doubleTree){
    algorithm_->process(graphPath + "K_12.txt");
    double value = algorithm_->doubleTree(0);
    EXPECT_TRUE(value >= (45.19 - deviation) && value <= 2 * (45.19 - deviation));
}

TEST_F(GraphTest, test_K_12e_tryAllPossibilities){
    GTEST_SKIP(); // too slow
    algorithm_->process(graphPath + "K_12e.txt");
    EXPECT_TRUE(std::abs(algorithm_->tryAllPossibilities() - 36.13) < deviation);
}

TEST_F(GraphTest, test_K_12e_branchAndBound){
    algorithm_->process(graphPath + "K_12e.txt");
    EXPECT_TRUE(std::abs(algorithm_->branchAndBound() - 36.13) < deviation);
}

TEST_F(GraphTest, test_K_12e_doubleTree){
    algorithm_->process(graphPath + "K_12e.txt");
    double value = algorithm_->doubleTree(0);
    EXPECT_TRUE(value >= (36.13 - deviation) && value <= 2 * (36.13 - deviation));
}
