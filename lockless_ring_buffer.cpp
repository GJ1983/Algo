#include<iostream>
#include<atomic>

#define RING_BUFFER_SIZE 1000

class lockless_ring_buffer
{
private:
std::atomic<int64_t> read;
std::atomic<int64_t> write;
};

int main()
{
return 0;
}
