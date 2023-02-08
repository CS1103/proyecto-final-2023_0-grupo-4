#ifndef BOT_H
#define BOT_H

#include "../Maze/Maze.hpp"
#include <unordered_set>

enum class ALGORITHM { DFS, BFS, GBGS, A_STAR };

// clang-format off
template <ALGORITHM T>
concept IsDFSOrBFS = 
T == ALGORITHM::DFS ||
T == ALGORITHM::BFS;

template <ALGORITHM T>
concept IsGBFSOrA_STAR = 
T == ALGORITHM::GBGS ||
T == ALGORITHM::A_STAR;

class Bot {

public:
  Bot() = default;

  template <ALGORITHM T>
  bool Solve(const Maze &maze);

  template <ALGORITHM T>
    requires IsDFSOrBFS<T> bool
  Solve(const Maze &maze);

  [[nodiscard]] std::unordered_set<square, Maze::HashPair> GetSolution() const;
  [[nodiscard]] std::unordered_set<square, Maze::HashPair> GetSearchedPath() const;

private:

  struct Node: public square{
    Node() = default;
    explicit Node(const square &pos, const int &score = 0);
    bool operator==(const square &sqr);

    int w_score{};

  };

  std::unordered_set<square, Maze::HashPair> m_solution;
  std::unordered_set<square, Maze::HashPair> m_searchedPath;

  inline static std::optional<square> s_goal = std::nullopt;

  template <ALGORITHM T>
  class Compare;

  [[nodiscard]] static int Heuristic(const square &current, const square &goal);


};
#endif // !BOT_H
