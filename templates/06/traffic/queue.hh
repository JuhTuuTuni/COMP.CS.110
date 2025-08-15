#ifndef QUEUE_HH
#define QUEUE_HH

#include <string>
#include <memory>

class Queue
{
public:
    // Constructor that initializes the attribute cycle_.
    // (The other attibutes are initialized in the private part below.)
    Queue(unsigned int cycle);

    // If the color of traffic light is red, inserts a vehicle, the register
    // number of which is reg, to the queue.
    void enqueue(std::string const& reg);

    // Switches the color of traffic light from green to red or vice versa.
    // If the new color is green, lets at least <cycle_> vehicles
    // go on (i.e. calls dequeue at least <cycle_> times), and finally
    // resets the color to red again.
    void switch_light();

    // Resets the attribute cycle_.
    void reset_cycle(unsigned int cycle);

    // Prints the color of traffic light and the register numbers of those
    // cars that are waiting in the traffic light queue (if any).
    void print() const;

private:
    // A single vehicle, i.e. queue element
    struct Vehicle {
        std::string reg_num;
        std::shared_ptr<Vehicle> next;
    };

    // Pointer to the first vehicle in the traffic light queue
    std::shared_ptr<Vehicle> first_ = nullptr;

    // Pointer to the last vehicle in the traffic light queue
    std::shared_ptr<Vehicle> last_ = nullptr;

    // Tells if the color of the traffic light is green or not
    bool is_green_ = false;

    // The number of vehicles that can pass the traffic lights during
    // the same green period
    unsigned int cycle_;

    // You can define more private features here, e.g. the following method
    // could be useful:

    // If the color of traffic light is green and if there are cards waiting,
    // removes the first vehicle from the queue.
    // The register number of the removed car is passed to the caller
    // in the reference parameter reg.
    // Returns true, if a removal was done, otherwise returns false.
    // bool dequeue(std::string& reg);
};

#endif // QUEUE_HH
