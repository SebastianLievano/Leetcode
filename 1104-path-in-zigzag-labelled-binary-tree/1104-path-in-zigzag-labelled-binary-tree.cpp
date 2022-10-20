class Solution {
    vector<int> answer;
public:
    void retParent(int child, int numChildNodes){
        //Base case
        if(numChildNodes == 2){
            answer.push_back(1);
            return;
        }
        //at a depth n, there will be 2^n nodes, and the first node in the order will be number 2^n
        
        //Number of nodes in parent rank
        int numParentNodes = numChildNodes/2;
        
        //The child node is node number val - number at that lvl
        int childNum = child - numChildNodes;

        //The parent node will be childNum/2 (node 0,1 have parent 0 etc)
        int parentNum = childNum/2;
        
        //However, since parent row goes in opposite order, it is actually numParentNodes - num
        //Since zero indexed, we want parentNum = numParentNodes to turn into 0, 
        parentNum = numParentNodes - parentNum - 1;
        
        int parent = numParentNodes + parentNum;
        //Call function first so parent gets added to vector first
        retParent(parent, numParentNodes);
        answer.push_back(parent);
    }
    
    vector<int> pathInZigZagTree(int label) {
        if(label == 1) return {1};
        //Number of nodes at label level is 2^(floor(log2label))
        retParent(label, pow(2,floor(log2(label))));
        answer.push_back(label);
        return answer;
    }
};