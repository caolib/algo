#include "./2017.h"
#include "./treeUtils.h"

int main() {

  inOrder(createExpressionTree(), true);
  cout << endl;
  inOrder(createExpressionTreeII(), true);

  return 0;
}
