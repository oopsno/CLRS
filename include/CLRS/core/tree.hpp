#pragma once

#include <functional>
#include <algorithm>

namespace CLRS {

template <typename T>
class BinaryTreeNode {
 public:
  using ptr_t = BinaryTreeNode<T>*;
  using value_t = T;

  value_t value;
  ptr_t left;
  ptr_t right;

  BinaryTreeNode(const T& value, ptr_t left = nullptr, ptr_t right = nullptr)
      : value{value}, left{left}, right{right} {}

  BinaryTreeNode(T&& value, ptr_t left = nullptr, ptr_t right = nullptr)
      : value{value}, left{left}, right{right} {}

  inline bool is_leaf() const { return left == nullptr and right == nullptr; }

  inline size_t height() const {
      size_t h = 1;
      if (left != nullptr) {
          h = std::max(h, 1 + left->height());
      }
      if (right != nullptr) {
          h = std::max(h, 1 + right->height());
      }
      return h;
  }

  inline void preorder(std::function<void(const T&)> callable) const {
    preorder(this, callable);
  }

  inline void inorder(std::function<void(const T&)> callable) const {
    inorder(this, callable);
  }

  inline void postorder(std::function<void(const T&)> callable) const {
    postorder(this, callable);
  }

  inline void preorder(std::function<void(T&)> callable) {
    preorder(this, callable);
  }

  inline void inorder(std::function<void(T&)> callable) {
    inorder(this, callable);
  }

  inline void postorder(std::function<void(T&)> callable) {
    postorder(this, callable);
  }

 private:
  void preorder(const BinaryTreeNode<T>* root,
                std::function<void(const T&)> callable) const {
    if (root != nullptr) {
      callable(root->value);
      preorder(root->left, callable);
      preorder(root->right, callable);
    }
  }

  void inorder(const BinaryTreeNode<T>* root,
               std::function<void(const T&)> callable) const {
    if (root != nullptr) {
      preorder(root->left, callable);
      callable(root->value);
      preorder(root->right, callable);
    }
  }

  void postorder(const BinaryTreeNode<T>* root,
                 std::function<void(const T&)> callable) const {
    if (root != nullptr) {
      preorder(root->left, callable);
      preorder(root->right, callable);
      callable(root->value);
    }
  }

  void preorder(BinaryTreeNode<T>* root, std::function<void(T&)> callable) {
    if (root != nullptr) {
      callable(root->value);
      preorder(root->left, callable);
      preorder(root->right, callable);
    }
  }

  void inorder(BinaryTreeNode<T>* root, std::function<void(T&)> callable) {
    if (root != nullptr) {
      preorder(root->left, callable);
      callable(root->value);
      preorder(root->right, callable);
    }
  }

  void postorder(BinaryTreeNode<T>* root, std::function<void(T&)> callable) {
    if (root != nullptr) {
      preorder(root->left, callable);
      preorder(root->right, callable);
      callable(root->value);
    }
  }
};  // class BinaryTreeNode

}  // namespace CLRS
