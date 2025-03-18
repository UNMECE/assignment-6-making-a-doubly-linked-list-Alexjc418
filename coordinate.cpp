#include "coordinate.h"

static int id_counter = 0;

void add_coordinate(Coordinate *&tail, float x, float y){
	Coordinate *new_node = new Coordinate{x, y, ++id_counter, nullptr, tail};
	if (tail) tail->next = new_node;
	tail = new_node;
}

void forward_display(Coordinate *head){
    	while (head){
        	std::cout << "coordinate: " << head->coord_id << " (" << head->x << ", " << head->y << ")\n";
		head = head->next;
    }
}

void backward_display(Coordinate *tail){
	while (tail){
		std::cout << "coordinate: " << tail->coord_id << " (" << tail->x << ", " << tail->y << ")\n";
		tail = tail->previous;
    }
}

void delete_coordinate(Coordinate *&head, int coord_id_to_delete){
	Coordinate *temp = head;
	while (temp && temp->coord_id != coord_id_to_delete) temp = temp->next;
	if (!temp) return;
	if (temp->previous) temp->previous->next = temp->next;
	if (temp->next) temp->next->previous = temp->previous;
	if (temp == head) head = temp->next;
	delete temp;
}

int list_length(Coordinate *head){
	int count = 0;
	while (head) {
        	count++;
        	head = head->next;
    }
	return count;
}

void closest_to(Coordinate *head, float x, float y){
	if (!head) return;
	Coordinate *nearest = head;
	float smallest_dist = std::hypot(head->x - x, head->y - y);
	for (Coordinate *current = head->next; current; current = current->next){
		float distance = std::hypot(current->x - x, current->y - y);
		if (distance < smallest_dist){
			smallest_dist = distance;
			nearest = current;
        }
    }
	std::cout << "Closest to (" << x << ", " << y << ") is coordinate " << nearest->coord_id
              << " at (" << nearest->x << ", " << nearest->y << ") with distance " << smallest_dist << "\n";
}





