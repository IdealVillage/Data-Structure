#include <stdio.h>
#include <malloc.h>

typedef struct TreeNode *SearchTree; 
typedef int ElementType;

struct TreeNode{
	ElementType data;
	SearchTree left;
	SearchTree right;
	
};

SearchTree MakeEmpty(SearchTree T);
SearchTree Find(ElementType x,SearchTree T);
SearchTree FindMin(SearchTree T);
SearchTree FindMax(SearchTree T);
SearchTree Insert(ElementType x,SearchTree T);
SearchTree Delete(ElementType x,SearchTree T);

int main(){
	SearchTree T = (SearchTree)malloc(sizeof(struct TreeNode));
	T->data=2;
	T->left=T->right=NULL;
	Insert(1,T);
	Insert(3,T);
	printf("%d",T->left->data);
}


SearchTree MakeEmpty(SearchTree T){
	if(T!=NULL){
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	printf("over");
	return NULL;
}

SearchTree Find(ElementType x,SearchTree T){
	if(T==NULL){
		return NULL;
	}else if(x<T->data){
		return Find(x,T->left);
	}else if(x>T->data){
		return Find(x,T->right);
	}else{
		return T;
	}
}

SearchTree FindMin(SearchTree T){
	if(T==NULL){
		return NULL;
	}else if(T->left==NULL){
		return T;
	}else{
		return FindMin(T->left);
	}
}


SearchTree FindMax(SearchTree T){
	if(T==NULL){
		return NULL;
	}else if(T->right==NULL){
		return T;
	}else{
		return FindMax(T->right);
	}
}


SearchTree Insert(ElementType x,SearchTree T){
	if(T==NULL){
		T=malloc(sizeof(struct TreeNode));
		if(T==NULL){
			printf("error");
		}else{
			T->data=x;
			T->left=T->right=NULL;
		}
	}else if(x<T->data){
		T->left=Insert(x,T->left);
	}else if(x>T->data){
		T->right=Insert(x,T->right);
	}
	return T;
}


SearchTree Delete(ElementType x,SearchTree T){
	SearchTree Tmpcell;
	if(T==NULL){
		printf("ERROR");
	}else if(x<T->data){
		T->left=Delete(x,T->left);
	}else if(x>T->data){
		T->right=Delete(x,T->right);
	}else if(T->left&&T->right){
		Tmpcell=FindMin(T->right);
		T->data=Tmpcell->data;
		T->right=Delete(T->data,T->right);
	}else{
		Tmpcell=T;
		if(T->left==NULL){
			T=T->right;
		}else if(T->right==NULL){
			T=T->left;
		}
		free(Tmpcell);
	}
	return T;
}












