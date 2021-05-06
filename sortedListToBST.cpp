class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        if(!head->next)
            return new TreeNode(head->val);
        
        
        //finding the mid;
        
        ListNode *s = head, *p = NULL, *f = head;
        
        while(f && f->next){
            p = s;
            s = s->next;
            f = f->next->next;
        }
        
        p->next = NULL;
        
        TreeNode* root = new TreeNode(s->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(s->next);
        s->next = NULL;
        
        return root;
    }
};
