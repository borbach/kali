#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <sys/resource.h>
#include <sys/time.h>

using namespace std::chrono;
using namespace std::chrono_literals;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

using namespace std;
bool debug = false;
bool output = false;
long lookups = 0;
long entries = 0;

// Function to get CPU usage
double get_cpu_usage() {
    std::ifstream file("/proc/self/stat");
    std::string line;
    std::getline(file, line);
    std::istringstream iss(line);
    
    // Extracting utime (user time) and stime (system time) from /proc/self/stat
    long utime, stime;
    for (int i = 1; i <= 13; ++i) {
        iss.ignore();
    }
    iss >> utime >> stime;

    // Calculating total time
    long total_time = utime + stime;

    // Getting total elapsed time
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    long total_elapsed_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);

    // Calculating CPU usage percentage
    double cpu_usage = 100.0 * total_time / total_elapsed_time;

    return cpu_usage;
}

// Function to get memory usage
long get_memory_usage() {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        return usage.ru_maxrss; // Max resident set size in kilobytes
    }
    return -1;
}


struct Node {
  string name;
  string id;
  string data;
  Node* next;
  Node* prev;
};

std::string addCommasToNumber(long long number) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(0) << number; // Set precision to 0 to avoid decimal places

    std::string numberWithCommas = ss.str();

    int len = numberWithCommas.length();

    // Add commas to the number
    for (int i = len - 3; i > 0; i -= 3) {
        numberWithCommas.insert(i, ",");
    }

    return numberWithCommas;
}


class DoublyLinkedList {
  private:
     Node* head;
     Node* tail;

  public:
     DoublyLinkedList() {
    	head = nullptr;
    	tail = nullptr;
     }	

  int countNodes()
  {
	  int count = 0;
	  Node *current = head;

	  while( current ){
		current = current->next;
		count++;
	  }
	  return( count );
  }

  void addNode(string name, string id, string data) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->id = id;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
    entries++;
    if( debug )
    	cout << "Added Node: " << countNodes() << endl;
  }

  void deleteNodeByName(string name) {
    Node* current = findNodeByName( name );
    if( !current ){
	    output = true;
    	    cout << "\033[31m" << endl;
	    cout << "Unable to delete " << name << " from list." << endl;
            cout << "\033[0m" << endl;
	    return;
    }
    if (current == head) 
        head = current->next;
    if (current == tail)
        tail = current->prev;
    if( current->next )
    	current->next->prev = current->prev;
    if( current->prev )
    	current->prev->next = current->next;    
    delete current;
    return;
  }

  void deleteNodeById(string id) {
    Node* current = findNodeById( id );
    if( !current ){
	    output = true;
    	    cout << "\033[31m" << endl;
	    cout << "Unable to delete " << id << " from list." << endl;
            cout << "\033[0m" << endl;
	    return;
    }
    if (current == head) 
        head = current->next;
    if (current == tail)
        tail = current->prev;
    if( current->next )
    	current->next->prev = current->prev;
    if( current->prev )
    	current->prev->next = current->next;    
    delete current;
    return;
  }

  Node *findNodeByName(string name) {
    Node* current = head;
    lookups = 0;

    while (current){
      lookups++;
      if (current->name == name) 
        return( current );
      current = current->next;
    }
    return(0);
  }

  Node *findNodeById(string id) {
    Node* current = head;
    lookups = 0;

    while (current) {
      lookups++;
      if (current->id == id) 
        return( current );

      current = current->next;
    }
    return(0);
  }


  void printList() {
    Node* current = head;
    long i = 0;

    output = true;
    cout << "\033[34m" << endl;
    cout << "\033[1m" << endl;
    cout << " All Nodes in List " << endl;
    cout << "=====================================================================" <<  endl;

    while (current) {
      cout << ++i << ":->  ";
      cout << current->name << " |  ";
      cout << current->id << " |  ";
      cout << current->data << " |  ";
      cout << endl;
      current = current->next;
    }

    cout << "=====================================================================" <<  endl;
    cout << "End of List"  <<  endl;
    cout <<  endl;
    cout << "\033[31m" << endl;
    cout << "List has " << addCommasToNumber( entries ) << " entries." << endl;
    cout << "\033[0m" << endl;
    cout <<  endl;
 }

  void saveToFile() {
    Node* current = head;

    ofstream outfile;
    outfile.open( "data.sav" );
    int i = 0;

    while (current) {
      //outfile << current->name << endl << current->id << endl << current->data << endl;
      outfile << current->name << endl;
      outfile << current->id << endl;
      outfile << current->data <<  endl;
      current = current->next;
      i++;
      if(!(i % 50000 )) 
	      cout << "." << std::flush;
    }
    outfile.close();
 }

  void saveToCSVFile() {
    Node* current = head;

    ofstream outfile;
    outfile.open( "data.csv" );

    while (current) {
      outfile << current->name << ",";
      outfile << current->id << ",";
      outfile << current->data <<  endl;
      current = current->next;
    }
    outfile.close();
 }

  void readFromFile() {
    string name;
    string id;
    string data;

    ifstream infile;
    infile.open( "data.sav" );

    while ( !infile.eof()) {
      infile >> name;
      infile >> id;
      infile >> data;
      if( debug )
          cout << "Read from file: " << name << "," << id << "," << data << endl;
      if( !infile.eof() )
      	addNode(name,id,data);
      else
      	break;
    }
    infile.close();
 } 
};


int main() {
  DoublyLinkedList list;

  int choice = 0;
  string name;
  string id;
  string data;
  string error;
  Node *temp;
  int counter = 0;
  high_resolution_clock::time_point  start;
  high_resolution_clock::time_point  stop;
  duration<double> time_span;
  std::cout << std::fixed << std::showpoint << std::setprecision(5);
  long initial_memory = 0;
  double initial_cpu = 0.0;
  long final_memory = 0;
  double final_cpu = 0.0;
  long memory_usage_diff = 0;
  double cpu_usage_diff = 0.0;

  while (true) {
    if( counter >= 7 )
	    counter = 0;
    counter++;
    if( !output ){	  
    	cout << "\033[2J\033[1;1H";
    }
    switch( counter ){
	case 1:
           cout << "\033[31m" << endl;
		break;
	case 2:
           cout << "\033[32m" << endl;
		break;
	case 3:
           cout << "\033[33m" << endl;
		break;
	case 4:
           cout << "\033[34m" << endl;
		break;
	case 5:
           cout << "\033[35m" << endl;
		break;
	case 6:
           cout << "\033[36m" << endl;
		break;
	case 7:
           cout << "\033[37m" << endl;
		break;
    }
		
    output = false;
    cout << "\nDoubly Linked List Menu" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    if( error.length() > 0 )
	    cout << "ERROR!: " << error << endl;
    cout << endl;
    cout << "1. Add Node" << endl;
    cout << "2. Remove Node By Name" << endl;
    cout << "3. Remove Node By Id" << endl;
    cout << "4. Find Node By Name" << endl;
    cout << "5. Find Node By Id" << endl;
    cout << "6. Print List" << endl;
    cout << "7. Save To File" << endl;
    cout << "8. Read From File" << endl;
    cout << "9. Exit" << endl;
    error = "";

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
	name = "";
	id = "";
	data = "";
       	cout << "Enter name to add: ";
       	cin >> name;
       	cout << "Enter id to add: ";
       	cin >> id;
        cout << "Enter data to add: ";
        cin >> data;
	initial_memory = get_memory_usage();
	initial_cpu = get_cpu_usage();
        list.addNode(name,id,data);
	final_memory = get_memory_usage();
        final_cpu = get_cpu_usage();
	memory_usage_diff = final_memory - initial_memory;
	cpu_usage_diff = final_cpu - initial_cpu;
    	cout << "\033[31m" << endl;
        cout << "Memory Usage: " << memory_usage_diff << " KB" << std::endl;
        cout << "CPU Usage: " << cpu_usage_diff << "%" << std::endl;
        cout << "\033[0m" << endl;
	output = true;
        break;

      case 2:
        cout << "Enter name to remove: ";
        cin >> name;
	initial_memory = get_memory_usage();
	initial_cpu = get_cpu_usage();
        list.deleteNodeByName(name);
	final_memory = get_memory_usage();
        final_cpu = get_cpu_usage();
	memory_usage_diff = final_memory - initial_memory;
	cpu_usage_diff = final_cpu - initial_cpu;
    	cout << "\033[31m" << endl;
        cout << "Memory Usage: " << memory_usage_diff << " KB" << std::endl;
        cout << "CPU Usage: " << cpu_usage_diff << "%" << std::endl;
        cout << "\033[0m" << endl;
	output = true;
       	break;

      case 3:
        cout << "Enter id to remove: ";
        cin >> id;
	initial_memory = get_memory_usage();
	initial_cpu = get_cpu_usage();
        list.deleteNodeById(id);
	final_memory = get_memory_usage();
        final_cpu = get_cpu_usage();
	memory_usage_diff = final_memory - initial_memory;
	cpu_usage_diff = final_cpu - initial_cpu;
    	cout << "\033[31m" << endl;
        cout << "Memory Usage: " << memory_usage_diff << " KB" << std::endl;
        cout << "CPU Usage: " << cpu_usage_diff << "%" << std::endl;
        cout << "\033[0m" << endl;
	output = true;
       	break;

      case 4:
        cout << "Enter name to find: ";
        cin >> name;
	initial_memory = get_memory_usage();
	initial_cpu = get_cpu_usage();
	start = high_resolution_clock::now();
        temp = list.findNodeByName(name);
	stop = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>( stop - start );
	final_memory = get_memory_usage();
        final_cpu = get_cpu_usage();
	memory_usage_diff = final_memory - initial_memory;
	cpu_usage_diff = final_cpu - initial_cpu;
    	cout << "\033[31m" << endl;
	cout <<  "Time taken: " << time_span.count() << " seconds" << endl;
	cout << "Lookups: " << addCommasToNumber( lookups )   << endl;
	cout << "Total Entries: " << addCommasToNumber( entries ) << endl;
	if( temp )
		cout << temp->name << "    "  << temp->id << "     " << temp->data << endl;
	else
		cout << "Unable to find node" << endl;
        cout << "Memory Usage: " << memory_usage_diff << " KB" << std::endl;
        cout << "CPU Usage: " << cpu_usage_diff << "%" << std::endl;
        cout << "\033[0m" << endl;
	output = true;
       	break;

      case 5:
        cout << "Enter id to find: ";
        cin >> id;
	initial_memory = get_memory_usage();
	initial_cpu = get_cpu_usage();
	start = high_resolution_clock::now();
        temp = list.findNodeById(id);
	stop = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>( stop - start );
	final_memory = get_memory_usage();
        final_cpu = get_cpu_usage();
	memory_usage_diff = final_memory - initial_memory;
	cpu_usage_diff = final_cpu - initial_cpu;
    	cout << "\033[31m" << endl;
	cout <<  "Time taken: " << time_span.count() << " seconds" << endl;
	cout << "Lookups: " << addCommasToNumber( lookups ) << endl;
	cout << "Total Entries: " << addCommasToNumber( entries ) << endl;
	if( temp )
		cout << temp->name << "    "  << temp->id << "     " << temp->data << endl;
	else
		cout << "Unable to find node" << endl;
        cout << "Memory Usage: " << memory_usage_diff << " KB" << std::endl;
        cout << "CPU Usage: " << cpu_usage_diff << "%" << std::endl;
        cout << "\033[0m" << endl;
	output = true;
       	break;

      case 6:
	initial_memory = get_memory_usage();
	initial_cpu = get_cpu_usage();
        list.printList();
	final_memory = get_memory_usage();
        final_cpu = get_cpu_usage();
	memory_usage_diff = final_memory - initial_memory;
	cpu_usage_diff = final_cpu - initial_cpu;
    	cout << "\033[31m" << endl;
        cout << "Memory Usage: " << memory_usage_diff << " KB" << std::endl;
        cout << "CPU Usage: " << cpu_usage_diff << "%" << std::endl;
        cout << "\033[0m" << endl;
	output = true;
        break;

      case 7:
	initial_memory = get_memory_usage();
	initial_cpu = get_cpu_usage();
	start = high_resolution_clock::now();
        list.saveToFile();
	stop = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>( stop - start );
	final_memory = get_memory_usage();
        final_cpu = get_cpu_usage();
	memory_usage_diff = final_memory - initial_memory;
	cpu_usage_diff = final_cpu - initial_cpu;
    	cout << "\033[31m" << endl;
	cout <<  "Time taken: " << time_span.count() << " seconds" << endl;
	cout << "Total Entries: " << addCommasToNumber( entries ) << endl;
        cout << "Memory Usage: " << memory_usage_diff << " KB" << std::endl;
        cout << "CPU Usage: " << cpu_usage_diff << "%" << std::endl;
        cout << "\033[0m" << endl;
	output = true;
        //list.saveToCSVFile();
        break;

      case 8:
	initial_memory = get_memory_usage();
	initial_cpu = get_cpu_usage();
        list.readFromFile();
	final_memory = get_memory_usage();
        final_cpu = get_cpu_usage();
	memory_usage_diff = final_memory - initial_memory;
	cpu_usage_diff = final_cpu - initial_cpu;
    	cout << "\033[31m" << endl;
        cout << "Memory Usage: " << memory_usage_diff << " KB" << std::endl;
        cout << "CPU Usage: " << cpu_usage_diff << "%" << std::endl;
        cout << "\033[0m" << endl;
	output = true;
        break;

      case 9:
        cout << "Exiting..." << endl;
        exit(0);

      default:
        cout << "Invalid choice. Please enter a valid option." << endl;
    }
  }

  return 0;
}


