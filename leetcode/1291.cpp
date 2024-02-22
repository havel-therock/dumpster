// 1291. Sequential Digits

#include <array>
#include <cstdint>
#include <iostream>
#include <vector>


class Solution
{
  public:
    std::vector<int> sequentialDigits(int low, int high)
    {
        if (low > 123456789) {
            return {};
        }
        std::vector<int> sequential_digits;
        int sequence_number = init_sequence_number_generator(low);
        while (sequence_number <= high && m_num_len <= 10) {
            sequential_digits.push_back(sequence_number);
            sequence_number = next_sequential();
        }
        return sequential_digits;
    }

  private:
    std::array<bool, 10> m_sequence_memory{};
    uint8_t m_num_len = 0;

    int init_sequence_number_generator(int low)
    {
        int seq_num = 0;
        int cpy_low = low;
        while (cpy_low > 0) {
            cpy_low /= 10;
            m_num_len++;
        }

        for (int i = 1; i <= m_num_len; i++) {
            m_sequence_memory[i] = true;
        }

        while (seq_num < low) {
            seq_num = next_sequential();
        }
        return seq_num;
    }

    int next_sequential()
    {
        int result_number = 0;
        int last_true_idx = 1;
        for (uint8_t idx = 1; idx < 10; idx++) {
            if (m_sequence_memory[idx]) {
                last_true_idx = idx;
                result_number = result_number * 10 + idx;
            }
        }

        if (m_sequence_memory[9]) {
            m_num_len++;
            m_sequence_memory = {};
            for (int i = 1; i <= m_num_len && i < 10; i++) {
                m_sequence_memory[i] = true;
            }
        } else {
            m_sequence_memory[last_true_idx - (m_num_len - 1)] = false;
            m_sequence_memory[last_true_idx + 1] = true;
        }

        return result_number;
    }
};

int main(int argc, char** argv)
{
    Solution s;

    std::vector<int> seq_dig = s.sequentialDigits(123456789, 1000000000);
    for (auto number : seq_dig)
        std::cout << number << " ";

    return 0;
}
