typedef TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
}TreeNode, *SearchTree;

SearchTree clear(SearchTree root)
{
	if(T!=NULL)
	{
		clear(root->left);
		clear(root->right);
		free(root);
	}	
	return NULL;
}

SearchTree find(int x, SearchTree root)
{
	if(root == NULL)
		return NULL;
	if(x < root->value)
		return find(x, root->left);
	else if(x > root->value)
		return find(x, root->right);
	else
		return root;
}

SearchTree find_nonrecursion(int x, SearchTree root)
{
	if(root == NULL)
		return NULL;
	while(root != NULL)
	{
		if(x == root->value)
			return root;
		else if(x < root->value)
			root = root->left;
		else if(x > root->value)
			root = root->right;
	}
	return NULL;
}

SearchTree fin_min(SearchTree root)
{
	if(root == NULL)
		return NULL;
	if(root->left == NULL)
		return root;
	else
		return find_min(root->left);
}

SearchTree find_min_nonrecursion(SearchTree root)
{
	if(root == NULL)
		return NULL;
	while(root->left !=NULL)
	{
		root = root->left;
	}
	return root;
}

SearchTree find_max(SearchTree root)
{
	if(root == NULL)
		return NULL;
	if(root->right == NULL)
		return root;
	else
		return find_max(root->right);
}

SearchTree find_max_nonrecursion(SearchTree root)
{
	if(root == NULL)
		return NULL;
	while(root->right != NULL)
	{
		root = root->right;
	}
	return root;
}

void insert(int x, SearchTree root)
{
	if(root == NULL)
	{
		root = (TreeNode*)malloc(sizeof(TreeNode));
		if(root == NULL)
			throw "Out of space!";
		else
		{
			root->value = x;
			root->left = root->right = NULL;
		}
	}
	else if (x < root->value)
		insert(x, root->left);
	else if (x > root->value)
		insert(x, root->right);
	else
		return;
}

void delete(int x, SearchTree root)
{
	TreeNode *p = root;
	int flag = 0;
	while(root != NULL && root->value != x)
	{
		if(x < root->value)
		{
			p = root;
			flag = 1;
			root = root->left;
		}
		else
		{
			p = root;
			flag = -1;
			root = root->right;
		}
	}
	if(root == NULL)
		throw "Not Found!";
	
	if(p == root) //delete the root of the tree
	{
		TreeNode *tmp = root;
		if(root->left == NULL)
		{
			root = root->right;
			free(tmp);
		}
		else if(root->right == NULL)
		{
			root = root->left;
			free(tmp);
		}
		else
		{
			TreeNode *post = root->right;
			TreeNode *ppost;
			while(post->left!=NULL)
			{
				ppost = post;
				post = post->left;
			}
			if(post == root->right)
			{
				root->value = post->value;
				root->right = post->right;
				free(post);
			}
			else
			{
				root->value = post->value;
				ppost->left = NULL;
				free(post);
			}
		}
	}
	else
	{
		if(root->left == NULL)
		{
			TreeNode *tmp = root;
			if(flag == 1)
				p->left = root->right;
			else
				p->right = root->right;
			free(tmp);
		}
		else if(root->right == NULL)
		{
			TreeNode *tmp = root;
			if(flag == 1)
				p->left = root->left;
			else
				p->right = root->left;
			free(tmp);
		}
		else
		{
			TreeNode *post = root->right;
			TreeNode *ppost;
			while(post->left != NULL)
			{
				ppost = post;
				post = post->left;
			}
			if(post == root->right)
			{
				root->value = post->value;
				root->right = post->right;
				free(post);
			}
			else
			{
				root->value = post->value;
				ppost->left = NULL;
				free(post);
			}
		}
	}
}




