// 11631 - Dark roads

#include <bits/stdc++.h>

int main(void) {

  bool *in_tree = (bool *)malloc(sizeof(bool));
  unsigned int vertex_cnt, edge_cnt;

  while ((scanf("%u %u", &vertex_cnt, &edge_cnt)) &&
         ((vertex_cnt != 0) && (edge_cnt != 0))) {

    std::vector<std::pair<int, std::pair<int, int>>> adj_single;

    int cost_sum = 0;
    int from, to, cost;
    for (unsigned int i = 0; i < edge_cnt; i++) {
      if (!(scanf("%d %d %d", &from, &to, &cost))) {
        return (1);
      }

      adj_single.push_back({cost, {from, to}});
      cost_sum += cost;
    }

    in_tree = (bool *)realloc(in_tree, sizeof(bool) * vertex_cnt);
    memset(in_tree, false, sizeof(bool) * vertex_cnt);

    std::sort(adj_single.begin(), adj_single.end());

    int min_span_tree = 0;
    in_tree[adj_single.at(0).second.first] = true;
    for (unsigned int i = 0; i < adj_single.size(); i++) {

      if (((in_tree[adj_single.at(i).second.first]) &&
           !(in_tree[adj_single.at(i).second.second])) ||
          (!(in_tree[adj_single.at(i).second.first]) &&
           (in_tree[adj_single.at(i).second.second]))) {
        in_tree[adj_single.at(i).second.first] = true;
        in_tree[adj_single.at(i).second.second] = true;
        min_span_tree += adj_single.at(i).first;
        i = 0;
      }
    }
    printf("%d\n", (cost_sum - min_span_tree));
  }

  free(in_tree);
  in_tree = NULL;

  return (0);
}

