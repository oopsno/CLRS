#include "CLRS/core/tree.hpp"
#include <catch.hpp>
#include <iostream>
#include "CLRS/core/print.hpp"

using namespace CLRS;

TEST_CASE("CLRS::core::BinaryTreeNode") {
  using node_t = BinaryTreeNode<int>;
  auto tree = new node_t{3, new node_t{9}, new node_t{39}};

  REQUIRE(!tree->is_leaf());
  REQUIRE(tree->left->is_leaf());
  REQUIRE(tree->right->is_leaf());
  REQUIRE(tree->height() == 2);
  REQUIRE(tree->left->height() == 1);
  REQUIRE(tree->right->height() == 1);

  auto succ = [](int& v) { ++v; };
  tree->preorder(succ);
  tree->inorder(succ);
  tree->postorder(succ);

  auto ss = std::ostringstream();
  auto print = Printer<int>{ss};
  tree->preorder(print);
  tree->inorder(print);
  tree->postorder(print);
  REQUIRE(ss.str() == "612421264212426");
}
