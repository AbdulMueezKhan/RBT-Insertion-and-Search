#include <iostream>
#include <stack>
#include <queue>
using namespace std;


struct bstnode
{
	int data;
	bstnode*left;
	bstnode*right;
	char color;

	bstnode(int val)
	{
		data = val;
		left = NULL;
		right = nullptr;
		color='r';
	}

};

class bst{
	bstnode*root;
	bstnode*ar;
public:

	bst()
	{
		root = nullptr;
	}

	void insertwrap(int data)
	{
		bstnode*temp = root;
		insert(root, data);
		arrange(ar);
// 		cout<<root->data<<endl;
	}

	bstnode* insert(bstnode*temp, int data)
	{
		if (root == nullptr)
		{
			bstnode*n = new bstnode(data);
			root = n;
			ar=root;
			return NULL;

		}
		if (temp == nullptr)
		{
			bstnode*n = new bstnode(data);
			temp = n;
			ar=temp;

		}
		else if (data <= temp->data)
			temp->left = insert(temp->left, data);
		else if (data >= temp->data)
			temp->right = insert(temp->right, data);

		//ager temp last ya first k ilawa return hoga to recur k through wo wala return hoga jo isse para mein mila tha
		return temp;

	}

	void printwrap()
	{
		inorder(root);
	}

	void inorder(bstnode*root){//babu confusing hai thora dehan se 
		if (root == NULL)
			return;//matlab leaf se aae jane ki koshish thi ya aisa node jis ka left ya right khale hai
	cout << " " << root->data;
		inorder(root->left);//jab tak left jate jao jab tak null na mille 
	//centre ko tab hi print krwaye ga kyun k left node jo iss se pehle pint hoi hai uska left khali tha jis kiwaja se cente ka left print hoa phir cente k left ka right bhi khali tha to center k paas wapis gya control aur wo print hogya  

		inorder(root->right);//jis node pe hain us k mazeed left nahi ja skte 
	}

void LevelOrderWrap()
{
    LevelOrder(root);
}

void LevelOrder(bstnode *root) {
	if(root == NULL) return;
	queue<bstnode*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		bstnode* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->color;
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}



void arrange(bstnode*temp)
{
    if(root->right==NULL && root->left==NULL )
    {root->color='b';
    return;}
    
    char gpc='m',p='m';
    bstnode*gp,*child,*parent,*uncle;
    child=temp;
  cout<<child->data<<endl;
    
    
    while (child!=root)
    {
         parent=searchparent(root,child->data,p);
         cout<<parent->data<<endl;
         if(parent==root)
         return;
        gp=searchparent(root,parent->data,gpc);
        uncle=unclef(gp,gpc);
       if(child->color=='r')
       {
            if(findcolor(parent)=='r'&&findcolor(uncle)=='r')
            {
                char temp_c=findcolor(gp);
                uncle->color=temp_c;
                parent->color=temp_c;
                invertcolor(gp);
            }
            else if(findcolor(parent)=='r'&&findcolor(uncle)=='b')
            {
                if(gpc=='l'&&p=='r')//lr
                {
                    leftr(parent,child);
                    swap(parent,child);
                    p='l';
                }
                else if(gpc=='r'&&p=='l')//invertcolor
                {
                    rightr(parent,child);
                    swap(parent,child);
                    p='r';
                }
                
                if(gpc=='l'&&p=='l')//ll
                {
                    rightr(gp,parent);
                }
                else if(gpc=='r'&&p=='r')//rightr
                {
                    leftr(gp,parent);
                    
                }
                parent->color='b';
                gp->color='r';
                
            }
       }    
        root->color='b';
        child=parent;
    }
    
    
}

void rightr(bstnode*parent,bstnode*child)
{
       char grrc;bstnode*grr;
       if(parent!=root)
     {grr=searchparent(root,parent->data,grrc);
    if(grrc=='l')
    grr->left=child;
    else
    grr->right=child;
         
     }
    else
    root=child;
    parent->left=child->right;
    child->right=parent;
    
}


void leftr(bstnode*parent,bstnode*child)
{
    char grrc;
    bstnode*grr;
    if(parent!=root)
     {grr=searchparent(root,parent->data,grrc);
    if(grrc=='l')
    grr->left=child;
    else
    grr->right=child;
     }
      else
    root=child;
    parent->right=child->left;
    child->left=parent;
    
}
    
    
void swap(bstnode*&parent,bstnode*&child)
{
    bstnode*t=parent;
    parent=child;
    child=t;
}
    
    
void invertcolor(bstnode*p)
{
    if(p->color=='r')
    p->color='l';
    else
     p->color='r';
}

char findcolor(bstnode*gp)
{
    if( gp==NULL)
    {
        return 'b';
        
    }
    else if(gp->color=='b')
    return 'b';
    return 'r';
}

bstnode*unclef(bstnode*gp,char c)
{
    if(c=='l')
    return gp->right;
    return gp->left;
    
}


	bstnode*searchparent(bstnode*temp, int data, char& c)
	{
		if (temp->left != NULL)
		{
            
			if (temp->left->data == data )
			{
         
				c = 'l';
				return temp;

			}
		}
		if(temp->right!=NULL)
		{
		if (temp->right->data == data  )
		{
			
         
				c = 'r';
			return temp;

		}}
	    if (data < temp->data)
			return searchparent(temp->left, data, c);
		else if (data > temp->data)
			return searchparent(temp->right, data, c);
	}

    
 
};

int main()
{
	bst l;

	l.insertwrap(1);
	l.insertwrap(2);
		l.insertwrap(3);
	l.insertwrap(4);

	l.insertwrap(5);
	l.insertwrap(6);
	

	l.insertwrap(7);
	l.insertwrap(8);
	l.insertwrap(9);
	l.insertwrap(10);
	l.insertwrap(11);
	l.insertwrap(12);
	l.insertwrap(13);
    // bstnode*n=l.searchwrap(16);
//     cout<<n->data<<endl;
    
	l.LevelOrderWrap(); cout << endl;


}















