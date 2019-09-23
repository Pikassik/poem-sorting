/*!
 * @file
 * @brief Tests for functions in TextSort
 */

#include <headers/TextSort.h>
#include <gtest/gtest.h>

struct TestTextSort : public ::testing::Test {
 public:
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

TEST_F(TestTextSort, SortInput2) {
  text.ReadText("tests/input2");
  auto std_sorted = GetStrings();
  std::sort(std_sorted.begin(), std_sorted.end());
  text::SortTextLexicographically(text);
  EXPECT_EQ(std_sorted, GetStrings());
}

TEST_F(TestTextSort, BackSortInput2) {
  text.ReadText("tests/input2");
  std::vector<std::string> std_sorted;
  for (const auto& x: GetStrings()) {
    std_sorted.emplace_back(std::string(x));
    std::reverse(std_sorted.back().begin(), std_sorted.back().end());
  }
  std::sort(std_sorted.begin(), std_sorted.end());
  text::SortTextBackLexicographically(text);
  std::vector<std::string> not_std_sorted;
  for (const auto& x: GetStrings()) {
    not_std_sorted.emplace_back(std::string(x));
    std::reverse(not_std_sorted.back().begin(), not_std_sorted.back().end());
  }
  EXPECT_EQ(std_sorted, not_std_sorted);
}

TEST(TestTextSortCmp, Cmp0) {
  auto abacaba = std::string_view("abacaba");
  auto aba = std::string_view("aba");
  auto aba_c = std::string_view("a,b,a");
  auto aba_d = std::string_view("a.b.a");
  EXPECT_TRUE(text::privatefunctions::
              StringLexicographicallyCmp(aba, abacaba));
  EXPECT_TRUE(text::privatefunctions::
              StringLexicographicallyCmp(aba_c, abacaba));
  EXPECT_TRUE(text::privatefunctions::
              StringLexicographicallyCmp(aba_d, abacaba));
}

TEST(TestTextSortCmp, BackCmp0) {
  auto abacaba = std::string_view("abacaba");
  auto aba = std::string_view("aba");
  auto aba_c = std::string_view("a,b,a");
  auto aba_d = std::string_view("a.b.a");
  EXPECT_TRUE(text::privatefunctions::
              StringBackLexicographicallyCmp(aba, abacaba));
  EXPECT_TRUE(text::privatefunctions::
              StringBackLexicographicallyCmp(aba_c, abacaba));
  EXPECT_TRUE(text::privatefunctions::
              StringBackLexicographicallyCmp(aba_d, abacaba));
}