#include <cstdlib>
#include <string>
#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <list>
#include <fstream>
#include <cstddef>

using write_sequence = std::list<std::string>;
using read_sequence = std::list<std::pair<uint64_t, std::string>>;

uint64_t get_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    return tv.tv_sec * 1000000LL + tv.tv_usec;
}

write_sequence get_write_sequence()
{
    std::ifstream infile("insert.txt");
    write_sequence result;

    std::string item;

    while (infile >> item)
    {
        result.emplace_back(item);
    }

    return result;
}

read_sequence get_read_sequence()
{
    std::ifstream infile("read.txt");
    read_sequence result;

    uint64_t index;
    std::string str;

    while(infile >> index >> str)
    {
        result.emplace_back(std::make_pair(index, str));
    }

    return result;
}

class storage
{
public:
    void insert(const std::string &str)
    {
        //TODO insert str with sorting
    }
    const std::string &get(uint64_t index)
    {
        //TODO return string via index
    }
};

void test(const write_sequence &write, const read_sequence &read)
{
    storage st;

    uint64_t timestamp_us;
    uint64_t total_time = 0;

    write_sequence::const_iterator iitr = write.begin();
    read_sequence::const_iterator ritr = read.begin();
    while (iitr != write.end() && ritr != read.end())
    {
        timestamp_us = get_time();
        st.insert(*iitr);
        total_time += get_time() - timestamp_us;

        timestamp_us = get_time();
        const std::string &str = st.get(ritr->first);
        total_time += get_time() - timestamp_us;

        if (ritr->second != str)
        {
            std::cout << "test failed" << std::endl;
            return;
        }

        iitr++;
        ritr++;
    }

    std::cout << "total time: " << total_time << std::endl;
}


int main()
{
    write_sequence insert =  get_write_sequence();
    read_sequence read = get_read_sequence();

    test(insert, read);
}
