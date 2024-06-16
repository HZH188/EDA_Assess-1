#include <gtest/gtest.h>
#include "parser.h"

TEST(ParserTest, BasicParsing) {
    ParsedData data;
    ASSERT_TRUE(parseFile("../input.txt", data));
    EXPECT_EQ(data.dieSize.rows, 10);
    EXPECT_EQ(data.dieSize.cols, 10);
    EXPECT_EQ(data.instances.size(), 3);
    EXPECT_EQ(data.instances[0].name, "Instance1");
    EXPECT_EQ(data.instances[1].name, "Instance2");
    EXPECT_EQ(data.instances[2].name, "Instance3");
    EXPECT_EQ(data.nets.size(), 2);
    EXPECT_EQ(data.nets[0].name, "Net1");
    EXPECT_EQ(data.nets[0].pins.size(), 2);
    EXPECT_EQ(data.nets[0].pins[0], "Pin1");
    EXPECT_EQ(data.nets[0].pins[1], "Pin2");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

