/**
 * 
 * Definition for singly-linked list.
 * */
  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    struct LocalResult{
        ListNode* ans;
        bool carry {false}; 
    };
    LocalResult addHelper(ListNode* l1, ListNode* l2, bool carry){
        int ans = l1->val + l2->val + (carry ? 1 : 0);
        ListNode* thisAns;
        if (ans < 10){
         thisAns = new ListNode(ans);
         return LocalResult{thisAns, false};
        }
        // ans >= 10
        else{
         thisAns = new ListNode(ans - 10);
         return LocalResult{thisAns, true};
        }
        
    }

    bool copyOver(ListNode* l, bool carry, ListNode*& result){
        while(l){

            ListNode* thisAns;
            int ans = l->val;
            if (carry){
                ans++;
            }
            if (ans == 10){
                thisAns =  new ListNode(0);  
                carry = true;              
            }
            else{
                thisAns =  new ListNode(ans);
                carry = false;
            }
            result->next  = thisAns;
            
            result = result->next;
            l = l->next;
        }
        return carry;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultToReturn = new ListNode;
        ListNode* result = resultToReturn;
        bool carry = false;
        bool init = true;
        while (l1 && l2){
            LocalResult localResult = addHelper(l1, l2, carry);
            carry = localResult.carry;
            if (init){
                result->val = localResult.ans->val;
            }
            else{
                result->next = localResult.ans;
                result = result->next;
            }
            l1 = l1->next;
            l2= l2->next;
            
            init = false;

        }

        if (l1 && !l2){
            carry = copyOver(l1, carry, result);
        }
        else if (l2 && !l1)
        {
            carry = copyOver(l2, carry, result);
        }
        
        if (carry){
            result->next = new ListNode(1);
        }
        

        return resultToReturn;
        
    }
};

int main()
{
    // ListNode l1
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);

     ListNode* l2 = new ListNode(9);


    Solution s;
    s.addTwoNumbers(l1, l2);
}