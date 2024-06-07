// Route Optimization and driver Navigation features


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <algorithm>

struct Node {
    int x, y;
    double g, h;
    Node* parent;

    Node(int x, int y, double g = 0, double h = 0, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), parent(parent) {}

    double f() const {
        return g + h;
    }

    bool operator>(const Node& other) const {
        return f() > other.f();
    }
};

//manhattan distance
double heuristic(const Node& a, const Node& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

std::vector<Node> reconstructPath(Node* end) {
    std::vector<Node> path;
    for (Node* node = end; node != nullptr; node = node->parent) {
        path.push_back(*node);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

// a* search algo
std::vector<Node> aStarSearch(std::vector<std::vector<int>>& grid, Node start, Node goal) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;
    std::unordered_map<int, std::unordered_map<int, bool>> closedSet;
    start.h = heuristic(start, goal);
    openSet.push(start);

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.x == goal.x && current.y == goal.y) {
            return reconstructPath(&current);
        }

        closedSet[current.x][current.y] = true;

        std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (const auto& dir : directions) {
            int newX = current.x + dir.first;
            int newY = current.y + dir.second;

            if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size() || grid[newX][newY] == 1 || closedSet[newX][newY]) {
                continue;
            }

            double newG = current.g + 1;
            Node neighbor(newX, newY, newG, heuristic(Node(newX, newY), goal), new Node(current));

            openSet.push(neighbor);
        }
    }

    return std::vector<Node>();
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    Node start(0, 0);
    Node goal(4, 4);

    std::vector<Node> path = aStarSearch(grid, start, goal);

    if (!path.empty()) {
        std::cout << "Path found:" << std::endl;
        for (const auto& node : path) {
            std::cout << "(" << node.x << ", " << node.y << ")" << std::endl;
        }
    } else {
        std::cout << "No path found!" << std::endl;
    }

    return 0;
}
