class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
public:
    Node *head, *tail;
    Queue() {
        head = NULL;
        tail = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (head == NULL && tail == NULL);
    }

    void enqueue(int data) {
        Node *new_node = new Node(data);
        if(head == NULL){
            head = new_node;
            tail = new_node;
        }else{
            tail->next = new_node;
            tail = new_node;
        }
    }

    int dequeue() {
        if(head == NULL) return -1;
        Node *temp = head;
        head = head->next;
        if(head==NULL)tail = NULL;
        int x = temp->data;
        delete(temp);
        return x;
    }

    int front() {
        if(head==NULL) return -1;
        return head->data;
    }
};