// 247 - Calling Circles

#include <bits/stdc++.h>

#include <deque>
#include <map>
#include <string>
#include <vector>

#define MAX_LEN 25

bool visited_all(bool *visited, unsigned int size);
void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[],
         std::map<unsigned int, std::string> dict);
void dfs_ord(unsigned int start, bool *visited, std::vector<unsigned int> adj[],
             std::deque<unsigned int> &order);
int main(void) {

  unsigned int vertex_cnt, edge_cnt, cnt = 1;
  while ((scanf("%u %u", &vertex_cnt, &edge_cnt))) {

    if (((vertex_cnt == 0) && (edge_cnt == 0))) {
      break;
    } else {
      if (cnt > 1) {
        putchar('\n');
      }
    }

    if (edge_cnt == 0) {
      printf("Calling circles for data set %u:\n\n", cnt++);
      continue;
    }

    std::map<std::string, unsigned int> dict;
    std::map<unsigned int, std::string> dict_rev;
    std::vector<unsigned int> adj[vertex_cnt + 1];
    std::vector<unsigned int> adj_rev[vertex_cnt + 1];

    char first[MAX_LEN];
    char second[MAX_LEN];
    char temp;

    unsigned int id = 1;
    getchar();
    for (unsigned int i = 0, j = 0, k = 0; i < edge_cnt; i++, j = 0, k = 0) {
      // first name
      while ((temp = getchar()) && (temp != ' ')) {
        first[j++] = temp;
      }
      first[j] = '\0';

      // second name
      while ((temp = getchar()) && (temp != '\n')) {
        second[k++] = temp;
      }
      second[k] = '\0';

      if (!(dict[first])) {
        dict_rev[id] = first;
        dict[first] = id++;
      }

      if (!(dict[second])) {
        dict_rev[id] = second;
        dict[second] = id++;
      }

      adj[dict[first]].push_back(dict[second]);
      adj_rev[dict[second]].push_back(dict[first]);
    }

    // dfs + ordering
    std::deque<unsigned int> order;
    bool *visited = (bool *)malloc(sizeof(bool) * (vertex_cnt + 1));
    memset(visited, false, sizeof(bool) * (vertex_cnt + 1));

    for (unsigned int i = 1; i <= vertex_cnt; i++) {
      if (!(visited[i])) {
        dfs_ord(i, visited, adj, order);
      }
    }

    memset(visited, false, sizeof(bool) * (vertex_cnt + 1));

    printf("Calling circles for data set %u:\n", cnt++);

    for (unsigned int i = 1; i <= vertex_cnt; i++) {
      while (visited[order.back()]) {
        order.pop_back();
      }
      // dfs
      std::cout << dict_rev[order.back()];
      visited[order.back()] = true;

      for (auto u : adj_rev[order.back()]) {
        dfs(u, visited, adj_rev, dict_rev);
      }
      putchar('\n');
      if (visited_all(visited, vertex_cnt + 1)) {
        break;
      }
    }
    free(visited);
  }

  return 0;
}
void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[],
         std::map<unsigned int, std::string> dict) {

  if (visited[start])
    return;
  visited[start] = true;

  std::cout << ", " << dict[start];
  for (auto u : adj[start]) {
    dfs(u, visited, adj, dict);
  }
}
void dfs_ord(unsigned int start, bool *visited, std::vector<unsigned int> adj[],
             std::deque<unsigned int> &order) {

  if (visited[start])
    return;
  visited[start] = true;

  for (auto u : adj[start]) {
    dfs_ord(u, visited, adj, order);
  }
  order.push_back(start);
}
bool visited_all(bool *visited, unsigned int size) {
  for (unsigned int i = 1; i < size; i++) {
    if (!(visited[i])) {
      return false;
    }
  }
  return true;
}

