// Time complexity : O(n)
// Space complexity : O(n)
RandomListNode* copyRandomList(RandomListNode *head)
{
	if(head == NULL)
		return NULL;

	map<RandomListNode*, RandomListNode*> m;
	// Build new list
	RandomListNode *newlist = new RandomListNode(head->label);
		
	RandomListNode *p = head->next, *q = newlist;
	while(p != NULL)
	{
		q->next = new RandomListNode(p->label);
		q = q->next;
		q->random = p->random;
		m.insert(pair<RandomListNode*, RandomListNode*>(p, q));
		p = p->next;
	}

	// Fill rand-link
	q = newlist;
	while(q != NULL)
	{
		q->random = m[q->random]; 
		q = q->next;
	}
	return newlist;
}
