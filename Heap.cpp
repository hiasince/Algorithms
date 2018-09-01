nclude <iostream>
#include <vector>
#include <ctime>
using namespace std;

//Function  : correct violate the min heap order when delete data
//			  use reheapdown algorithm. work recursively. 
//Parameter : current = integer for vector index of current
//			  v_node  = vector for node of min heap
void ReheapDown(int current, vector<int>& v_node);

//Function  : correct violate the heap order when input data
//			  use reheapup algorithm. work recursively. 
//Parameter : current = integer for vector index of current
//			  v_node  = vector for node of min heap
void ReheapUp(int current, vector<int>& v_node);

int main() {
					int n, k;				//n : the number of integer data
												//k : the number of Top integer data which want to extract
													int* valueArr;			//pointer for dynamic integer array of data
														vector<int> min_Heap;	//vector for min Heap

															cin >> n;
																
																	if (n > 1000000 || n < 1) {				//check range of n (1¡Ân¡Â1,000,000)
																							cout << "Wrong Input. Out of range." << endl;
																									return 0;
																										}
																											else {

																																	valueArr = new int[n];
																																			srand(time(NULL));
																																					for (int i = 0; i < n; i++)				//put random integer (overlap ok) 
																																												valueArr[i] = rand()%10000;

																																														for (int i = 0; i < n; i++)
																																																					cout << valueArr[i] << " ";
																																																							cout << endl;

																																																									cin >> k;
																																																											
																																																													if (k > 1000 || k < 1) {					//check range of k (1¡Âk¡Â1,000)
																																																																				cout << "Wrong Input. Out of range." << endl;
																																																																							return 0;
																																																																									}

																																																																											for (int i = 0; i < k; i++) {				//first push back value amount of k
																																																																																		min_Heap.push_back(valueArr[i]);
																																																																																					ReheapUp(min_Heap.size()-1, min_Heap);
																																																																																							}
																																																																																										
																																																																																												for (int i = k; i < n; i++) {				//after check value of array with minimum value of heap vector
																																																																																																			if (min_Heap[0] < valueArr[i]) {		//if array value > minimum of heap
																																																																																																											min_Heap[0] = valueArr[i];			//change root of min heap
																																																																																																															ReheapDown(0, min_Heap);
																																																																																																																		}
																																																																																																																				}
																																																																																																																						
																																																																																																																								//print answer
																																																																																																																										for (int i = 0; i < k; i++)
																																																																																																																																	cout << min_Heap[i] << " ";
																																																																																																																																			cout << endl;

																																																																																																																																				}

																																																																																																																																					delete[] valueArr;
																																																																																																																																						return 0;
}

void ReheapDown(int current, vector<int>& v_node) {

					bool left = false;						//check value for direction of change true -> change with left
						bool right = false;						//check value for direction of change true -> change with right
							int left_index = 2 * current + 1;		//left index for current index
								int right_index = 2 * current + 2;		//right index for current index
									int min_index = current;				//initialize min_index to current

										if (left_index < v_node.size() &&v_node[current] > v_node[left_index])		//if current node > left node : change left to true
																left = true;

																	if (right_index < v_node.size() && v_node[min_index] > v_node[right_index])	//if current node > right node : change right to true
																							right = true;

																								if (left == true && right == true) {				//if left, right both true
																														if (v_node[left_index] > v_node[right_index])	//change larger node index to false
																																					left = false;
																																							else
																																														right = false;
																																															}

																																																if (left)
																																																						min_index = left_index;
																																																							else if (right)
																																																													min_index = right_index;
																																																														
																																																															if (min_index != current) {					//if min_index change swap value
																																																																					int temp = v_node[current];
																																																																							v_node[current] = v_node[min_index];
																																																																									v_node[min_index] = temp;
																																																																											ReheapDown(min_index, v_node);
																																																																												}

																																																																													return;
}

void ReheapUp(int current, vector<int>& v_node) {
					if (current == 0)
											return;

												int parentIndex = (current - 1) / 2;		//parent index for current index

													if (v_node[current] < v_node[parentIndex] ) {		//if parent node > current node chage value
																			int temp = v_node[current];
																					v_node[current] = v_node[parentIndex];
																							v_node[parentIndex] = temp;
																									ReheapUp(parentIndex, v_node);
																										}
}
