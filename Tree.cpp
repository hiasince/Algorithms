nclude <iostream>
#include <string>
#include <vector>
using namespace std;


//Definition of Treenode
struct TreeNode {
					int content = -10;			//operator or operand

						TreeNode* left = NULL;		//pointer to node's left
							TreeNode* right = NULL;		//pointer to node's right
};



//Function  : initialize tree with information of prefix expression vector 
//Parameter : arrNum = vector that has prefix expression for int
//			  root = Root node of tree
void initTreePrefix(vector<int> arrNum, TreeNode* root);

//Function  : recursive function for calculation tree as post travasal 
//Parameter : node = root node of tree which want to calcaulate
int calcTree(TreeNode* node);


int main() {

					TreeNode* root = new TreeNode();	//define root node of expression tree
						vector<int> v_expression;			//vector for save expression
							string expression = "";				//string for save expression number
								int temp = 0;						//temporary value for get input


																		//while input return(10)
																			while (temp != 10) {

																									//get input as ascii code
																											temp = getchar();

																													//if input space(32) or return(10)
																															if (temp == 32 || temp == 10) {
																																						if (expression.size())
																																														v_expression.push_back(stoi(expression, nullptr, 10));
																																																	expression = "";		//save in expression vector and initialize to ""
																																																			}
																																																					else {
																																																												//if input operator
																																																															if (temp < 49) {
																																																																							v_expression.push_back(temp - 50);		//save operator as minus integer -> * : -8, + : -7, - : -5, / : -3
																																																																											expression = "";						//ascii code of operand -> * : 42, + : 43, - : 45, / : 47
																																																																																									//save in expression vector
																																																																																												}
																																																																																															//if input operand
																																																																																																		else
																																																																																																										expression += (char)temp;				//save in expression  because if operand more than 10 
																																																																																																												}												//have to merge string
																																																																																																													}

																																																																																																														initTreePrefix(v_expression, root);		//make tree with inforamtion of expression vector 
																																																																																																															cout << calcTree(root) << endl;			//calculate expression of tree as postfix travasal

}


void initTreePrefix(vector<int> arrNum, TreeNode* root) {

					TreeNode* current = root;				//pointer for current
						vector<TreeNode*> operatorStack;		//stack for operator node

																	//initialize root node
																		if (arrNum[0] < 0)
																								current->content = arrNum[0];
																									current->left = NULL;
																										current->right = NULL;

																											//push root operator Stack because root always operator
																												operatorStack.push_back(current);

																													for (int i = 1; i < arrNum.size(); i++) {
																																			//if current content is operator
																																					if (current->content < 0) {
																																												//if left is empty
																																															if (current->left == NULL) {
																																																							current->left = new TreeNode();
																																																											current->left->content = arrNum[i];
																																																															if (arrNum[i] < 0)		//if content is operator push in stack
																																																																								operatorStack.push_back(current->left);
																																																																												current = current->left;
																																																																															}
																																																																																		//if right is empty
																																																																																					else if (current->right == NULL) {
																																																																																													current->right = new TreeNode();
																																																																																																	current->right->content = arrNum[i];
																																																																																																					if (arrNum[i] < 0)		//if content is operator push in stack
																																																																																																														operatorStack.push_back(current->right);
																																																																																																																		current = current->right;
																																																																																																																					}
																																																																																																																								//if full
																																																																																																																											else {
																																																																																																																																			//pop stack
																																																																																																																																							current = operatorStack[operatorStack.size() - 1];
																																																																																																																																											operatorStack.pop_back();
																																																																																																																																															i--;
																																																																																																																																																		}
																																																																																																																																																				}
																																																																																																																																																						//if current content is operand
																																																																																																																																																								else {
																																																																																																																																																															//pop stack
																																																																																																																																																																		current = operatorStack[operatorStack.size() - 1];
																																																																																																																																																																					operatorStack.pop_back();
																																																																																																																																																																								i--;
																																																																																																																																																																										}
																																																																																																																																																																											}
}



int calcTree(TreeNode* node) {
					//save operator as minus integer -> * : -8, + : -7, - : -5, / : -3
						//switch for content
							switch (node->content) {
												case -8:
														return calcTree(node->left)* calcTree(node->right);
															case -7:
																	return calcTree(node->left) + calcTree(node->right);
																		case -5:
																				return calcTree(node->left) - calcTree(node->right);
																					case -3:
																							return calcTree(node->left) / calcTree(node->right);
																								default:	//if content is integer -> return integer
																										return node->content;
																											}
}
