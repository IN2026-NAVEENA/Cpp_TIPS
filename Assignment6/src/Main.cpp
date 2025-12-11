#include <thread>
#include "ProducerConsumer.hpp"

/*@brief Entry point of the program.*/
int main() {
    std::thread producerThread(Producer);
    std::thread consumerThread(Consumer);

    producerThread.join();
    consumerThread.join();
    return 0;
}