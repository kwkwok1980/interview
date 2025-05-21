/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

struct Path {
    int data = -1;
    int parent = -1;
    int left = -1;
    int right = -1;
    bool visited = false;
    int distance = 0;
};

class Solution {

  public:

    std::vector<int> KDistanceNodes(Node* root, int target, int k) {
        std::deque<Node*> nodeList{};
        std::unordered_map<int, Path*> pathMap{};
        Path* path;
        Path* left;
        Path* right;
        Path* parent;
        Node* node;
        path = pathMap[root->data] = new Path{};
        path->data = root->data;
        nodeList.emplace_back(root);
        while (!nodeList.empty()) {
            node = nodeList.front();
            path = pathMap[node->data];
            if (node->left) {
                path->left = node->left->data;
                left = pathMap[node->left->data] = new Path{};
                left->data = node->left->data;
                left->parent = node->data;
                nodeList.emplace_back(node->left);
            }
            if (node->right) {
                path->right = node->right->data;
                right = pathMap[node->right->data] = new Path{};
                right->data = node->right->data;
                right->parent = node->data;
                nodeList.emplace_back(node->right);
            }
            nodeList.pop_front();
        }
        std::vector<int> results{};
        std::deque<Path*> distanceList{};
        path = pathMap[target];
        distanceList.push_back(path);
        path->visited = true;
        while (!distanceList.empty()) {
            path = distanceList.front();
            if (path->distance < k) {
                if (path->parent != -1) {
                    parent = pathMap[path->parent];
                    if (!parent->visited) {
                        parent->distance = path->distance + 1;
                        distanceList.push_back(parent);
                        parent->visited = true;
                    }
                }
                if (path->left != -1) {
                    left = pathMap[path->left];
                    if (!left->visited) {
                        left->distance = path->distance + 1;
                        distanceList.push_back(left);
                        left->visited = true;
                    }
                }
                if (path->right != -1) {
                    right = pathMap[path->right];
                    if (!right->visited) {
                        right->distance = path->distance + 1;
                        distanceList.push_back(right);
                        right->visited = true;
                    }
                }
            } else {
                results.push_back(path->data);
            }
            distanceList.pop_front();
        }
        std::sort(results.begin(), results.end());
        return results;
    }
};
