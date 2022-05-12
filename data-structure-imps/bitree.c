struct treeNode {
		  struct treeNode* right;//right child
		  struct treeNode* left;//left child
};

//creates a tree based of a matrixs, where down and right correspond to left and right respectively
treeNode* newTreeFromMatrix(lm_node* origin){
		  treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
		  if(origin->down == NULL){
					 newNode->left = NULL;
		  }
		  if(origin->right == NULL){
					 newNode->right = NULL;
		  }
		  if(origin->down == NULL && origin->right == NULL){
					 return newNode;
		  }
		  if(origin->down != NULL){
					 newNode->left = newTreeFromMatrix(origin->down);
		  }
		  if(origin->right != NULL){
					 newNode->right = newTreeFromMatrix(origin->right);
		  }

		  return newNode;
}

//remove a tree
//TODO refactor ifs
int rmTree(treeNode* root){
		  if(root->left != NULL){
					 rmTree(root->left);
		  }
		  if(root->right != NULL){
					 rmTree(root->right);
		  }
		  if(root->left == NULL && root->right == NULL){
					 free(root);
					 root = NULL;
		  }
		  
		 return 0; 

}
