# Ola Portfolio

<dl>
<dt>Course Name</dt>
<dd>Algorithmic Problem Solving</dd>
<dt>Course Code</dt>
<dd>23ECSE309</dd>
<dt>Name</dt>
<dd>Girish Badamikar</dd>
<dt>University</dt>
<dd>KLE Technological University, Hubballi-31</dd>
</dl>

## Note:
This page hosts:

1. Introduction
2. Why Portfolio
3. Objectives
4. Design
5. Challenges
6. To-Do

## 1. Introduction
Welcome to the Ola Portfolio. This project showcases the implementation of various data structures and algorithms in the context of an Ola-like ride-sharing platform. The project covers functionalities such as ride requests, driver management, route optimization, fare calculation, real-time tracking, and more.

## 2. Why Portfolio
This portfolio is created to demonstrate the practical application of data structures and algorithms learned during the course. It serves as a comprehensive project that integrates multiple concepts into a real-world scenario, enhancing both understanding and skills in algorithmic problem solving.

## 3. Objectives
- Implement efficient algorithms for matching users with drivers based on proximity and availability.
- Optimize routes for rides considering traffic conditions and estimated time of arrival.
- Develop a dynamic fare calculation system that adapts to various factors such as distance and time.

## 4. Design
The design of this project involves several key components:
- **Ride Request System:** Users can request rides by specifying their current location and destination.
- **Driver Management:** Drivers can register, manage their availability, and accept or reject ride requests.
- **Route Optimization:** Algorithms calculate the most efficient routes for rides.
- **Fare Calculation:** A system to calculate fares based on multiple dynamic factors.
- **Real-time Tracking:** Enables users to track their rides and communicate with drivers.
- **Trip History:** Records details of all past rides for both users and drivers.
- **Feedback System:** Allows users to rate their rides and provide feedback.

## 5. Challenges
Throughout the development of this project, several challenges were encountered:
- Ensuring efficient matching of users with drivers in real-time.
- Optimizing routes to minimize travel time and distance considering dynamic traffic conditions.
- Implementing a flexible fare calculation system that accounts for various dynamic factors.


## 6. To-Do
Future enhancements and tasks to complete:
- Enhance the real-time tracking system with more accurate GPS data.
- Develop a mobile application interface for better user experience.
- Implement more advanced data analytics to gain insights from trip history and feedback.
- Expand the feedback system to include more detailed user reviews and suggestions.

## 7. Implemented Functionalities
The following functionalities have been implemented in the project:

## 7.1 Ride-Matching System [Code](https://github.com/girish0903/Ola-Portfolio/blob/main/priorityqueue.cpp)

This matches users with the closest available drivers using a priority queue.

### Functionality

Efficiently matches users with the nearest available driver.

### Concepts Used

- **Priority Queue**: A data structure that allows efficient retrieval of the smallest (or largest) element. In this project, it's used to keep track of available drivers, prioritized by their distance to the user.

## 7.2 Driver Management System

This manages a pool of available drivers using a red-black tree to efficiently handle driver information based on proximity to users.

### Functionality

Efficiently stores and retrieves driver information based on their availability and proximity to users.

### Concepts Used

- **Red-Black Tree**: A Red-Black Tree is a type of self-balancing binary search tree. It ensures that the tree remains approximately balanced, providing efficient operations for insertion, deletion, and lookup.

## 7.3 Route Optimization and Driver Navigation

This code implements the A* search algorithm to find the most efficient route from a start point to a goal point on a grid, considering obstacles. This is useful for optimizing routes for drivers navigating through city streets or other areas.

### Functionality

The A* algorithm expands nodes based on their total cost (g + h), prioritizing nodes with lower costs. It explores adjacent nodes in all directions (up, down, left, right) and calculates their costs. It continues until the goal node is reached or no more nodes can be expanded.

### Concepts Used 

- **A\* Search**: The A* search algorithm is a popular pathfinding algorithm used in navigation and optimization problems. It utilizes a heuristic function to estimate the cost of reaching the goal from a particular node, along with the actual cost of reaching that node from the start. A* maintains an open set of nodes to be evaluated, prioritized by their total estimated cost (heuristic cost + actual cost). At each step, it expands the node with the lowest total cost, exploring adjacent nodes and updating their costs accordingly. This algorithm guarantees to find the shortest path if a solution exists, provided that the heuristic function satisfies certain conditions.

- **Priority Queue**: A data structure that allows efficient retrieval of the smallest (or largest) element. In this project, it's used to keep track of available drivers, prioritized by their distance to the user.

## 7.4 Fare Calculation

### Functionality 

The provided code implements dynamic programming (DP) to calculate the minimum fare for traveling a given distance and time, taking into account surge pricing if applicable. It utilizes a DP table to efficiently store and retrieve the minimum fare for each combination of distance and time.

### Concepts Used

- **Dynamic Programming (DP)**: DP is a technique for solving optimization problems by breaking them down into simpler subproblems and storing the solutions to these subproblems to avoid redundant computations.
In this code, DP is used to compute the minimum fare for various combinations of distance and time, ensuring optimal fare calculation.

## 7.5 Trip History 

### Functionality

The code implements a trip history analyzer that processes queries related to analyzing trip data. It utilizes the MO's algorithm to efficiently handle queries by decomposing the array of trip records and performing range queries within the subarrays. The main functionality includes finding the most frequent routes based on the given trip data and queries.

### Concepts Used

- **MO's Algorithm**: The MO's algorithm is a square root decomposition technique used for offline processing of range queries efficiently. It divides the array of queries into blocks of size approximately sqrt(N) and sorts them based on block numbers and right endpoints. By processing queries in a sorted order and maintaining a window of relevant data, MO's algorithm achieves optimal time complexity.
