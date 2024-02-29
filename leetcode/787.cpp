// 787. Cheapest Flights Within K Stops

#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>


// dijkstra with priority queue
// with a counter for k max stops
// before adding to a priority queue check if the allowed number of stops hasn't been exceeded

struct Node {
    int city_id = -1;
    int pri_to_city = INT_MAX;
    int nr_of_stops = -1;
};

class Solution
{
  public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k)
    {
        Node destination{}; // {dst};
        destination.city_id = dst;

        // n - #cities
        // flight[from, to, price]
        // k - #max stops

        // TODO: @Kacper
        // define ordering by pri_to_city
        auto cmp = [](Node first, Node second) -> bool { return first.pri_to_city > second.pri_to_city; };

        std::priority_queue<Node, std::vector<Node>, decltype(cmp)> neighbours;

        // set of city_ids, and jumps to
        std::unordered_map<int, int> visited;

        Node current_node{};
        current_node.city_id = src;
        current_node.pri_to_city = 0;
        neighbours.push(current_node);

        while (!neighbours.empty()) {
            current_node = neighbours.top();
            neighbours.pop();
            visited.insert(std::make_pair(current_node.city_id, current_node.nr_of_stops));

            if (current_node.city_id == dst) {
                destination = current_node;
                break;
            }
            // if going to neighbours require more than k stops don't fly there
            if (current_node.nr_of_stops + 1 > k) {
                continue;
            }

            for (const auto flight : flights) {
                if (flight.at(0) == current_node.city_id) {
                    if (!visited.count(flight.at(1)) || visited.at(flight.at(1)) > current_node.nr_of_stops + 1) {
                        Node neighbour{};
                        neighbour.city_id = flight.at(1);
                        neighbour.pri_to_city = current_node.pri_to_city + flight.at(2);
                        neighbour.nr_of_stops = current_node.nr_of_stops + 1;
                        neighbours.push(neighbour);
                    }
                }
            }
        }

        if (destination.pri_to_city == INT_MAX) {
            destination.pri_to_city = -1;
        }

        return destination.pri_to_city;
    }
};


int main(int argc, char** argv)
{
    Solution s;
    std::vector<std::vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    std::vector<std::vector<int>> flights2 = {{0, 3, 3}, {3, 4, 3},   {4, 1, 3},  {0, 5, 1},  {5, 1, 100},
                                              {0, 6, 2}, {6, 1, 100}, {0, 7, 1},  {7, 8, 1},  {8, 9, 1},
                                              {9, 1, 1}, {1, 10, 1},  {10, 2, 1}, {1, 2, 100}};

    std::vector<std::vector<int>> flights3 = {
        {11, 12, 74}, {1, 8, 91},  {4, 6, 13},  {7, 6, 39},   {5, 12, 8},   {0, 12, 54},  {8, 4, 32},   {0, 11, 4},
        {4, 0, 91},   {11, 7, 64}, {6, 3, 88},  {8, 5, 80},   {11, 10, 91}, {10, 0, 60},  {8, 7, 92},   {12, 6, 78},
        {6, 2, 8},    {4, 3, 54},  {3, 11, 76}, {3, 12, 23},  {11, 6, 79},  {6, 12, 36},  {2, 11, 100}, {2, 5, 49},
        {7, 0, 17},   {5, 8, 95},  {3, 9, 98},  {8, 10, 61},  {2, 12, 38},  {5, 7, 58},   {9, 4, 37},   {8, 6, 79},
        {9, 0, 1},    {2, 3, 12},  {7, 10, 7},  {12, 10, 52}, {7, 2, 68},   {12, 2, 100}, {6, 9, 53},   {7, 4, 90},
        {0, 5, 43},   {11, 2, 52}, {11, 8, 50}, {12, 4, 38},  {7, 9, 94},   {2, 7, 38},   {3, 7, 88},   {9, 12, 20},
        {12, 0, 26},  {10, 5, 38}, {12, 8, 50}, {0, 2, 77},   {11, 0, 13},  {9, 10, 76},  {2, 6, 67},   {5, 6, 34},
        {9, 7, 62},   {5, 3, 67}};

    std::cout << s.findCheapestPrice(4, flights, 0, 3, 1) << std::endl;
    std::cout << s.findCheapestPrice(11, flights2, 0, 2, 4) << std::endl;

    std::cout << s.findCheapestPrice(13, flights3, 10, 1, 10) << std::endl;

    return 0;
}
