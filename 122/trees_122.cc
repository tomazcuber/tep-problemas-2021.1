#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>

class Node {
public:
    Node(int pos):m_level(pos), m_value(-1), m_leftChild(nullptr), m_rightChild(nullptr){}
    void setChild(Node* child, char direction);

    inline int getValue() { return m_value; }
    inline void setValue(int value) { m_value = value; }

    inline Node* getLeft(){ return m_leftChild; }
    inline void setLeft(Node* left) { m_leftChild = left;}

    inline Node* getRight(){ return m_rightChild; }
    inline void setRight(Node* right) { m_rightChild = right;}

private: 
    int m_value;
    int m_level;
    Node* m_leftChild;
    Node* m_rightChild;
    // Node* m_parent; 
};

void Node::setChild(Node* child, char direction){
    if (direction == 'L')
		this->m_leftChild = child;
	else if (direction == 'R')
		this->m_rightChild = child;
}


class BinaryTree {
public:
    BinaryTree() = default;
    ~BinaryTree();
    Node* getNode(int pos);
    Node* setNode(int pos);
    void setEdge(int parent, int child, char direction);

    std::vector<Node*> nodes;

private:
    std::map<int, Node*> nodesByPosition;
};

BinaryTree::~BinaryTree(){
    for(auto& node : nodes){
        delete node;
    }
}

Node* BinaryTree::getNode(int pos){
    auto it = nodesByPosition.find(pos);

    if(it == nodesByPosition.end()){
        return setNode(pos);
    }

    return (*it).second;
}

Node* BinaryTree::setNode(int pos){
    Node* newNode = new Node(pos);
    nodes.push_back(newNode);
    nodesByPosition.insert({pos, newNode});
    return newNode;
}

void BinaryTree::setEdge(int parent, int child, char direction){
    Node* v = getNode(parent);
	Node* w = getNode(child);

    v->setChild(w, direction);
}

int main (int argc, char** argv){
    std::string input;
    Node* root{};
    Node* temp{};
    int count{1};

    BinaryTree* tree = new BinaryTree();

    root = tree->setNode(count++);
    bool isValid = true;

    while(std::cin >> input){
        if(input != "()"){
            if(isValid){
                input = input.substr(1, input.size() - 2);
                size_t comma = input.find (",");
				std::string value = input.substr(0, (int)comma);
				std::string pos = input.substr((int)comma+1);

                int currentValue = 0;
                std::reverse(value.begin(), value.end());
                for (int i = 0; i < value.size(); ++i)
			        currentValue += (value[i] - 48) * pow(10, i);
                
                if(pos.size() == 0){
                    if(root->getValue() == -1){
                        root->setValue(currentValue);
                    } else {
                        isValid = false;
                        continue;
                    }
                } else {
                    temp = root; 
                    for(int i = 0 ; i < pos.size(); ++i){
                        if(pos[i] == 'L'){
                            if(temp->getLeft() == nullptr){
                                temp->setLeft(tree->setNode(count));
                                temp = temp->getLeft();
                                ++count;
                            } else {
                                temp = temp->getLeft();
                            }
                        } else if(pos[i] == 'R'){
                            if(temp->getRight() == nullptr){
                                temp->setRight(tree->setNode(count));
                                temp = temp->getRight();
                                ++count;
                            } else {
                                temp = temp->getRight();
                            }
                        }
                    }

                    if(temp->getValue() == -1){
                        temp->setValue(currentValue);
                    } else {
                        isValid = false;
                    }
                }

                continue;
            }
        } else {
            if(!isValid){
                std::cout << "not complete" << std::endl;
            } else { 
                for(auto node : tree->nodes){
                    if(node->getValue() == -1){
                        isValid = false;
                        break;
                    }
                }

                if(!isValid) { 
                    std::cout << "not complete" << std::endl;
                } else {
                    std::queue<Node*> printQueue;
                    printQueue.push(root);

                    bool firstNode = true;
                    while(!printQueue.empty()){
                        temp = printQueue.front();
                        printQueue.pop();

                        if (!firstNode) std::cout << " "; else firstNode = false;

                        std::cout << temp->getValue();

                        if(temp->getLeft() != nullptr) printQueue.push(temp->getLeft());
                        if(temp->getRight() != nullptr) printQueue.push(temp->getRight());
                        
                    }
                    std::cout << std::endl;
                }
            }

            isValid = true;
            delete tree;

            tree = new BinaryTree();
            count = 1;
            root = tree->setNode(count++);
        }
    }

    std::cout << std::endl;

    return 0;
}