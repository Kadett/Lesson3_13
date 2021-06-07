#include <iostream>
#include "src/Stack.h"
#include "src/QueuePriority.h"

const int n = 6;
/*

int matrix[n][n] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};
*/
/*

int matrix[n][n] = {
        {0, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0},
};
*/

int matrix[n][n] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0},
};


int visited[n] = {0};


void depthTraversStack(int st, Stack<int> &stack) {

    visited[st] = 1;
    std::cout << st << " ";
    for (int i = n - 1; i >= 0; i--) {
        if (matrix[st][i] == 1 && visited[i] == 0) {
            stack.push(i);
        }
    }
    while (stack.getSize()) {
        int tmp = stack.pop();
        if (visited[tmp] == 1) continue;
        else visited[tmp] = 1;
        std::cout << tmp << " ";
        for (int i = n - 1; i >= 0; i--) {
            if (matrix[tmp][i] == 1 && visited[i] == 0) {
                stack.push(i);
            }
        }
    }
}


void resetArr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;

    }
}

int links[n] = {0};

void countLinksDepth(int st = 0) {
    visited[st] = 1;
    for (int i = 0; i < n; ++i) {
        if (matrix[st][i] == 1) {
            links[i] += 1;
            if (!visited[i])
                countLinksDepth(i);
        }
    }
}

void countAllNodes() {
    for (int i = 0; i < n; ++i) {
        visited[i] = 1;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                links[j] += 1;
            }
        }
    }
}

int main() {


    // Task 1
    std::cout << "Task 1" << "\n";
    Stack<int> stack;
    depthTraversStack(0, stack);
    resetArr(visited, n);
    std::cout << "\n\n";


    // Task 2.1
    std::cout << "Task 2" << "\n";
    QueuePriority<int> q1;
    QueuePriority<int> q2;


    countLinksDepth(0);
    for (int i = 0; i < n; ++i) {
        q1.push(i, links[i]);
        q2.push(links[i], links[i]);
    }
    while (q1.getSize() > 0) {
        std::cout << "Node " << q1.get() << " has " << q2.get() << " input links" << std::endl;
    }

    // Task 2.2
    std::cout << "========================" << "\n";
    resetArr(links, n);
    countAllNodes();
    for (int i = 0; i < n; ++i) {
        q1.push(i, links[i]);
        q2.push(links[i], links[i]);
    }
    while (q1.getSize() > 0) {
        std::cout << "Node " << q1.get() << " has " << q2.get() << " input links" << std::endl;
    }

    return 0;
}
