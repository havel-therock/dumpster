// 787. Cheapest Flights Within K Stops

#include <climits>
#include <iostream>
#include <queue>
#include <unordered_set>
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

        int result = -1;
        // n - #cities
        // flight[from, to, price]
        // k - #max stops
        std::priority_queue<Node> neighbours;
        // set of city_ids
        std::unordered_set<int> visited;

        Node current_node = Node();
        current_node.city_id = src;
        neighbours.push(current_node);

        while (!neighbours.empty()) {
            current_node = neighbours.top();
            neighbours.pop();
            visited.insert(current_node.city_id);

            for ( const auto flight : flights) {
                if (flight.at(0) == current_node.city_id) {
                    if(flight.at(1)
                }
            }

        }

        return result;
    }
};


int main(int argc, char** argv)
{
    Solution s;
    std::vector<std::vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    std::cout << s.findCheapestPrice(4, flights, 0, 3, 1);
    return 0;
}
