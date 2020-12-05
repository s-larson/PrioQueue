#include "Tree.h"


struct TreeWrapper {
	TreeWrapper() {
		tree = NULL;
	}

	TreeWrapper(Tree* t) {
		tree = t;
	}

	bool operator<(const TreeWrapper &tw) const {
		return tree->getWeight() > tw.tree->getWeight();
	}

	Tree* tree;
};

Tree::Tree(int w, char c) {
	weight = w;
	this->c = c;
	left = NULL;
	right = NULL;
}

Tree::Tree(int w, Tree* t1, Tree* t2) {
	left = t1;
	right = t2;
	weight = w;
	c = NULL;
}

int Tree::getWeight() const {
	return this->weight;
}

char Tree::getChar() const {
	return this->c;
}

void Tree::printTree(vector<char>& bitString, vector<char>& input) const {

	// Make sure it's breadth first.

	if(!input.empty()) {
		vector<char> temp = input;
		// True if current node is leaf
		if(this->left && this->right == NULL) {
			// Check if leaf node is the letter we're searching for
			if(temp.front() == this->c) {
				// Node found! Remove front letter and call printTree for next character
				temp.erase(temp.begin());
				printTree(bitString, temp);
			}

		// Add 1 to bitString if left child exists
		} else if (this->left != NULL) {
			bitString.push_back(1);
			this->left->printTree(bitString, temp);

		// Add 0 to bitString if right child exists
		} else if (this->right != NULL) {
			bitString.push_back(0);
			this->right->printTree(bitString, temp);
		}
	} else {
		for (vector<char>::iterator it = bitString.begin(); it != bitString.end(); ++it) {
			cout << *it;
		}
	}
}

//priority_queue<TreeWrapper> createTree(unsigned char input[]) {
TreeWrapper createTree(vector<char>& input) {

	cout << "create trr����d";

	priority_queue<TreeWrapper> q;

	// Count character occurance and save in array 'count'. Size 256 to fit all possible characters
	int count[256] = {0};
	//vector<char>& charCount = input;

	for(int i = 0; input[i] != '\0'; i++) {
		unsigned char c = input[i];
		count[c]++;
		//cout << "occ: "<< count[input[i]] << endl;
		//cout << "input: "<< input[i] << endl;
	}

	// Create tree for each character and insert in priority queue
	for(unsigned int i = 0; i < sizeof(count)/sizeof(count[0]); i++) {
		cout << count[i];
		if(count[i] > 0) {
			cout << "hej";
			q.push(TreeWrapper(new Tree(count[i], input[i])));
		} else {
			cout << "wtf";
		}
		cout << q.top().tree->getChar() << q.top().tree->getWeight() << endl;
	}

	while(q.size() > 1 ){

		// Pick the top 2 elements (retrieve and remove) and create a new tree with weight ele1 + ele2
		Tree *temp1 = new Tree(q.top().tree->getChar(), q.top().tree->getWeight());
		q.pop();
		Tree *temp2 = new Tree(q.top().tree->getChar(), q.top().tree->getWeight());
		q.pop();
		int weightSum = temp1->getWeight()+temp2->getWeight();

		// Put new tree in prio queue
		q.push(TreeWrapper(new Tree(weightSum, temp1, temp2)));
	}

	//Return remaining tree in prio queue
	cout << q.top().tree->getWeight();
	return q.top();
}

int main() {

	cout << "�RU DUM ELLR";

	vector<char> input;
	input.push_back('a');
	input.push_back('b');
	input.push_back('b');
	input.push_back('a');
	input.push_back('m');

	cout << "HALL�";

	TreeWrapper t = createTree(input);
	cout << "create yes very nice";
	vector<char> bitString = {};
	t.tree->printTree(bitString, input);
	cout << "print yes very nice";
	return 0;
}

/*
 * Problem:
 */
