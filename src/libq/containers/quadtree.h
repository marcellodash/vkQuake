/*

   quadtree.h

   Quadtree implementation in c++

   TODO: Need to improve the memory handling here, should use some type of memory block structure for the whole tree.

*/
#pragma once

template<class T>
class CQTreeNode
{
private:
	/* Signature indicating validity */
	char valid = 1;
public:
	/* Children, 4 of them */
	CQTreeNode<T>* children[4];
	/* Value of this node */
	T val;

public:
	/* Empty node */
	CQTreeNode()
	{
		children[0] = NULL;
		children[1] = NULL;
		children[2] = NULL;
		children[3] = NULL;
	}

	/* Simple copy constructor */
	CQTreeNode(const CQTreeNode& node)
	{
		children[0] = node.children[0];	
		children[1] = node.children[1];
		children[2] = node.children[2];
		children[3] = node.children[3];
		val = node.val;

	}

	CQTreeNode(CQTreeNode&& node)
	{
		children[0] = node.children[0];	
		children[1] = node.children[1];
		children[2] = node.children[2];
		children[3] = node.children[3];
		val = node.val;	
		node.children[0] = NULL;
		node.children[1] = NULL;
		node.children[2] = NULL;
		node.children[3] = NULL;
	}

	/* Initialize new Quadtree node with 4 children */
	CQTreeNode(T v1, T v2, T v3, T v4)
	{
		/* Allocate this as a contiguous block */
		CQTreeNode<T>* nodes = (CQTreeNode<T>*)malloc(sizeof(CQTreeNode<T>) * 4);
		children[0] = &nodes[0];
		children[1] = &nodes[1];
		children[2] = &nodes[2];
		children[3] = &nodes[3];
		children[0]->val = v1;
		children[1]->val = v2;
		children[2]->val = v3;
		children[3]->val = v4;
	}

	/* Destructor */
	~CQTreeNode()
	{
		for(int i = 0; i < 4; i++)
		{
			if(children[i])
				delete children[i];
		}
	}

	/* Naming:
	 * Note: TL stands for top-left, etc.
	 *    TL    TR
	 *     1  |  2
	 *   -----|-----
	 *     3  |  4
	 *    BL    BR
	 */

	T* GetTL() const
	{
		if(children[0])
			return children[0]->val;
		return NULL;
	}

	T* GetTR() const
	{
		if(children[1])
			return children[1]->val;
		return NULL;
	}

	T* GetBL() const
	{
		if(children[2])
			return children[2]->val;
		return NULL;
	}

	T* GetBR() const
	{
		if(children[3])
			return children[3]->val;
		return NULL;
	}

	/* Clears all nodes */
	void ClearNodes()
	{

	}
};

template<class T>
class CQTree
{
public:
	CQTreeNode<T> root;
private:
public:

};
