#include "Bot.hpp"
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

template <ALGORITHM T>
  requires IsDFSOrBFS<T> bool
Bot::Solve(const Maze &maze /*matriz de chars*/) {

  m_solution = {};
  m_searchedPath = {};

  std::unordered_set<square, Maze::HashPair> searched_path;

  square start = maze.GetStart();

  std::conditional_t<T == ALGORITHM::BFS, std::queue<square>,
                     std::stack<square>>
      frontier;

  std::unordered_map<square, square, Maze::HashPair> parent;
  parent[start] = start;

  frontier.push(start);

  searched_path.emplace(start);
  m_searchedPath.emplace(start);

  bool found = false;
  while (!frontier.empty()) {

    square current;
    if constexpr (T == ALGORITHM::DFS) {
      current = frontier.top();
    } else {
      current = frontier.front();
    }

    frontier.pop();

    if (current == maze.GetGoal()) {
      found = true;
      break;
    }
    for (square neighbor : maze.GetNeighbors(current)) {
      if (searched_path.find(neighbor) == searched_path.end()) {
        frontier.push(neighbor);
        m_searchedPath.emplace(neighbor);
        searched_path.emplace(neighbor);
        parent[neighbor] = current;
      }
    }
  }
  if (!found) {
    return false;
  }

  square current = maze.GetGoal();

  while (current != maze.GetStart()) {

    m_solution.emplace(current);

    current = parent[current];
  }
  if (T == ALGORITHM::DFS) {
    m_solution.emplace(current);
  }

  return true;
}

// Manhattan distance heuristic function
int Bot::Heuristic(const square &current, const square &goal) {
  return std::abs(current.first - goal.first) +
         std::abs(current.second - goal.second);
}

template <> class Bot::Compare<ALGORITHM::GBFS> {
public:
  bool operator()(const square &sq1, const square &sq2) {
    if (!s_goal.has_value()) {
      throw std::runtime_error("Goal not set");
    }
    return Heuristic(sq1, Bot::s_goal.value()) >
           Heuristic(sq2, Bot::s_goal.value());
  }
};

template <> class Bot::Compare<ALGORITHM::A_STAR> {
public:
  bool operator()(const Node &sq1, const Node &sq2) {
    if (!s_goal.has_value()) {
      throw std::runtime_error("Goal not set");
    }
    return Heuristic(sq1, Bot::s_goal.value()) + sq1.w_score >
           Heuristic(sq2, Bot::s_goal.value()) + sq2.w_score;
  }
};

Bot::Node::Node(const square &pos, const int &score)
    : square(pos), w_score(score) {}

bool Bot::Node::operator==(const square &sqr) {
  return sqr.first == first && sqr.second == second;
}

template <> bool Bot::Solve<ALGORITHM::A_STAR>(const Maze &maze) {

  m_solution = {};
  m_searchedPath = {};
  s_goal = maze.GetGoal();

  std::unordered_set<square, Maze::HashPair> searched_path;
  auto start = maze.GetStart();

  std::priority_queue<Node, std::vector<Node>, Compare<ALGORITHM::A_STAR>>
      frontier;

  std::unordered_map<square, square, Maze::HashPair> parent;

  parent[start] = start;

  frontier.push(Node(start));

  searched_path.emplace(start);

  bool found = false;

  square current;

  while (!frontier.empty()) {

    current = frontier.top();
    int current_score = frontier.top().w_score;

    frontier.pop();

    if (current == maze.GetGoal()) {
      found = true;
      break;
    }

    m_searchedPath.emplace(current);
    for (square neighbor : maze.GetNeighbors(current)) {
      if (searched_path.find(neighbor) == searched_path.end()) {
        m_searchedPath.emplace(neighbor);
        searched_path.emplace(neighbor);
        frontier.emplace(neighbor, current_score + 1);
        parent[neighbor] = current;
      }
    }
  }
  if (!found) {
    return false;
  }

  square current_sq = maze.GetGoal();
  while (current_sq != maze.GetStart()) {
    m_solution.emplace(current_sq);
    current_sq = parent[current_sq];
  }

  return true;
}

template <> bool Bot::Solve<ALGORITHM::GBFS>(const Maze &maze) {

  m_solution = {};
  m_searchedPath = {};
  s_goal = maze.GetGoal();

  auto start = maze.GetStart();

  std::unordered_set<square, Maze::HashPair> searched_path;
  std::priority_queue<square, std::vector<square>, Compare<ALGORITHM::GBFS>>
      frontier;

  std::unordered_map<square, square, Maze::HashPair> parent;

  parent[start] = start;

  frontier.push(start);

  searched_path.emplace(start);

  bool found = false;

  square current;

  while (!frontier.empty()) {

    current = frontier.top();
    frontier.pop();

    if (current == maze.GetGoal()) {
      found = true;
      break;
    }

    m_searchedPath.emplace(current);
    for (square neighbor : maze.GetNeighbors(current)) {

      if (searched_path.find(neighbor) == searched_path.end()) {
        m_searchedPath.emplace(neighbor);
        searched_path.emplace(neighbor);
        frontier.push(neighbor);
        parent[neighbor] = current;
      }
    }
  }
  if (!found) {
    return false;
  }

  square current_sq = maze.GetGoal();
  while (current_sq != maze.GetStart()) {
    m_solution.emplace(current_sq);
    current_sq = parent[current_sq];
  }

  return true;
}

template <bool hasNode>
[[maybe_unused]] void PrintPriorityQueue(const auto &queue) {
  auto copy = queue;
  std::cout << "Priority Queue: \n";
  if constexpr (hasNode) {
    while (!copy.empty()) {
      std::cout << copy.top().first << " " << copy.top().second << std::endl;
      std::cout << "Score: " << copy.top().w_score << std::endl;
      copy.pop();
    }
  } else {
    while (!copy.empty()) {
      std::cout << copy.top().first << " " << copy.top().second << std::endl;
      copy.pop();
    }
  }
}

std::queue<square> Bot::GetSolution() const { return m_solution; }
std::queue<square> Bot::GetSearchedPath() const { return m_searchedPath; }

// Explicit template instantiations

template bool Bot::Solve<ALGORITHM::DFS>(const Maze &maze);
template bool Bot::Solve<ALGORITHM::BFS>(const Maze &maze);
