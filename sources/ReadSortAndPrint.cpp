#include "headers/ReadSortAndPrint.h"

void ReadSortAndPrint(const std::string& filename)  {
  assert(filename.empty());

  text::Text poem;

  poem.ReadText(filename);

  std::puts("Sorted lexicographically poem:\n");
  text::SortTextLexicographically(poem);
  poem.PrintText();

  std::puts("\nSorted backlexicographically poem:\n");
  text::SortTextBackLexicographically(poem);
  poem.PrintText();

  std::puts("\nRaw Poem:\n");
  poem.PrintRawText();
}

