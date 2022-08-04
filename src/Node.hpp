#pragma once

namespace graph{
    struct Node{
        Node* left{nullptr};
        Node* right{nullptr};
        int value;
    };
}