#include<bits/stdc++.h>
using namespace std;

	typedef struct page {
	    page* prev_page = nullptr;
	    page* next_page = nullptr;
	    int start_add = 0;
	    int count_records = 0;
	    vector<int> records;
	} page;

	class Heap_File{
	    private:
	    int no_of_pages;
	    int page_size;
	    page* start = nullptr;

	    public:
	    Heap_File(int size) {
	        page_size = size;
	        no_of_pages = 0;
	    }

	    //For iterating through pages
	    page* curr;

	    void insert(int record_size, int val) {
	        if (start == nullptr) {
	            start = new page();
	            (start->records).push_back(val);
	            (start->count_records)++;
	            (start->start_add) += record_size;
	            ++no_of_pages;
	            return;
	        }

	        else {
	            curr = start;
	            int ans = 0;
	            while (curr->next_page != nullptr) {
	                if ((page_size - (curr->start_add)) >= record_size) {
	                    ans = 1;
	                    break;
	                }

	                curr = curr->next_page;
	            }

	            if (ans == 0) {
	                if ((page_size - (curr->start_add)) >= record_size) {
	                    ans = 1;
	                }

	                else {
	                    ++no_of_pages;
	                    page* new_page = new page();
	                    new_page->prev_page = curr;
	                    curr->next_page = new_page;
	                    curr = new_page;
	                }
	            }
	        }

	        (curr->records).push_back(val);
	        (curr->count_records)++;
	        curr->start_add += record_size;
	        return;
	    }

	    void search_file(int val) {
	        curr = start;
	        int page_no = 0;
	        while (curr != nullptr) {
	            for (int i = 0; i < (curr->records).size(); ++i) {
	                if ((curr->records)[i] == val) {
	                    cout << page_no << " " << i << endl;
	                    return;
	                }
	            }

	            ++page_no;
	            curr = curr->next_page;
	        }

	        cout << -1 << " " << -1 << endl;
	        return;
	    }

	    void display() {
	        cout << no_of_pages << " ";

	        curr = start;
	        for (int i = 0; i < no_of_pages; ++i) {
	            cout << curr->count_records << " ";

	            curr = curr->next_page;
	        }

	        cout << endl;
	        return;
	    }
	};

	int main() {
	    int size, operation;
	    cin >> size >> operation;

	    Heap_File *file = new Heap_File(size - 16);

	    while (operation != 4) {
	        if (operation == 1) {
	            int rsize, val;
	            cin >> rsize >> val;
	            (*file).insert(rsize + 4, val);
	        }

	        if (operation == 2) {
	            (*file).display();
	        }

	        if (operation == 3) {
	            int val;
	            cin >> val;
	            (*file).search_file(val);
	        }

	        cin >> operation;
	    }

	    return 0;
	}
