//341 https://leetcode.com/problems/flatten-nested-list-iterator/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 
 // remember each layer and the corresponding index
class NestedIterator {
private:
    stack<int> index;
    stack<vector<NestedInteger>*> node_list;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        node_list.push(&nestedList);
        index.push(-1);
    }

    int next() {
        return (*node_list.top())[index.top()].getInteger();
    }

    bool hasNext() {
        while(!index.empty()){
            while(!index.empty() && ++index.top() == node_list.top()->size()) {
                index.pop();
                node_list.pop();
            }
            if(index.empty() || (*node_list.top())[index.top()].isInteger()) 
                break;
            else {
                node_list.push(&(*node_list.top())[index.top()].getList());
                index.push(-1);
            }
        }
        return !index.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */