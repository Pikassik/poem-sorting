#include <headers/ReadSortAndPrint.h>
#include <gtest/gtest.h>

//int main(int argc, char** argv) {
//  if (argc == 1) {
//    puts("Enter file name");
//    return 0;
//  }
//
//  ReadSortAndPrint(argv[1]);
//  return 0;
//}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
