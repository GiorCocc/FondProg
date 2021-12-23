class Item {
private:
	int val;
public:
	int id, nextElement;
	Item(int v = 0, int i = 0, int nE = 0) { val = v; id = i; nextElement = nE; }
	int key() const { return val; }
	bool operator>(const Item& item) const {
		if (val > item.key()) return true;
		else return false;
	}
};

template <class Item> void exch(Item& A, Item& B){
	Item t = A; 
	A = B; 
	B = t;
}

template <class Item> void MinHeapfixUp(Item a[], int k){
	while (k > 1 && a[k / 2] > a[k]) {
		exch(a[k], a[k / 2]); 
		k = k / 2;
	}
}


template <class Item> void MinHeapfixDown(Item a[], int k, int N) {
	while (2 * k <= N){
		int j = 2 * k;
		if (j < N && a[j] > a[j + 1]) j++;
		if (!(a[k] > a[j])) break;
		exch(a[k], a[j]); k = j;
	}
}

template <class Item> class MinHeap {
private:
	Item* minheap;
	int N;
public:
	MinHeap(int maxN) { minheap = new Item[maxN + 1]; N = 0; }
	~MinHeap() { delete[] minheap; }
	int empty() const { return N == 0; }
	void insert(Item item) { minheap[++N] = item; MinHeapfixUp(minheap, N); }
	Item getMin() {
		exch(minheap[1], minheap[N]);
		MinHeapfixDown(minheap, 1, N - 1);
		return minheap[N--];
	}
};
