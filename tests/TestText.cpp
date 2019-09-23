/*!
 * @file
 * @brief Tests for class Text
 */

#include <headers/Text.h>
#include <gtest/gtest.h>

struct TestText : public ::testing::Test {
  void SetUp() override {}

  void TearDown() override {}

  const std::vector<std::string_view>& GetStrings() {
    return text.strings_;
  }

  size_t GetSize() {
    return text.text_size_;
  }

  char* GetPtr() {
    return text.text_.get();
  }

  text::Text text;
};

TEST_F(TestText, ReadInput0) {
  text.ReadText("tests/input0");
  EXPECT_EQ(GetStrings()[0], "abcdefgh");
  EXPECT_EQ(GetStrings()[1], "ijklmnopq");
  EXPECT_EQ(GetStrings()[2], "rstuvwxyz");
  EXPECT_EQ(GetStrings().size(), 3);
}

TEST_F(TestText, SizeInput0) {
  text.ReadText("tests/input0");
  EXPECT_EQ(GetSize(), 29);
  EXPECT_EQ(GetStrings().size(), 3);
}

TEST_F(TestText, EndZeroInput0) {
  text.ReadText("tests/input0");
  EXPECT_EQ(GetPtr()[GetSize() - 1], '\0');
}

TEST_F(TestText, ReadInput1) {
  std::vector<const char*> content = {
      "",
      "0",
      "",
      "",
      "1",
      "2",
      "",
      "3",
      "4",
      "",
      "5",
      "6",
      "",
      "7",
      "8",
      "",
      "9",
  };

  text.ReadText("tests/input1");
  for (size_t i = 0; i < content.size(); ++i) {
    EXPECT_EQ(content[i], GetStrings()[i]);
  }
}

TEST_F(TestText, SizeInput1) {
  text.ReadText("tests/input1");
  EXPECT_EQ(GetSize(), 27);
  EXPECT_EQ(GetStrings().size(), 17);
}

TEST_F(TestText, EndZeroInput1) {
  text.ReadText("tests/input1");
  EXPECT_EQ(GetPtr()[GetSize() - 1], '\0');
}
