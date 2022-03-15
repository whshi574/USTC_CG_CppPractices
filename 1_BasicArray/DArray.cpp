// implementation of class DArray
#include <iostream>

#include "DArray.h"

#include <cassert>

using namespace std;
// default constructor
DArray::DArray() {
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue) {
	//TODO
	m_pData = new double[nSize];

	for (int i = 0;nSize > i;i++)
	{
		m_pData[i] = dValue;
	}

	m_nSize = nSize;
	
}

DArray::DArray(const DArray& arr) {
	//TODO
	//这一块是我一开始写的，不太准确，仅仅是将地址赋予了另一个指针变量，并不是真正意义上的复制
	/*	
		m_nSize = arr.m_nSize;
		m_pData = arr.m_pData;
	*/
	//问题：他这里是逐个赋值，将数组的地址赋给一个指针变量行不
	//复制，是指把一个地址的内容复制给另一个地址，而不是为这块地址申请另一个指针变量或者另一个类名
	m_nSize = arr.m_nSize;
	//问题：同一类的不同对象能互相访问私有成员吗：可以
	m_pData = new double[m_nSize];
	for (int i = 0; i < m_nSize; i++)
	{
		m_pData[i] = arr.m_pData[i];
	}

	cout << "Copy Constructor called" << endl;
}

// deconstructor
DArray::~DArray() {
	Free();
}

// display the elements of the array
void DArray::Print() const {
	//TODO
	
	for (int i = 0; i < m_nSize; i++)
	{
		cout << m_pData[i] << endl;
	}

	/*cout << "size = " << m_nSize << ":";//samples的
	for (int i = 0; i < m_nSize; i++)
		cout << " " << GetAt(i);

	cout << endl;
	*/
}

// initilize the array
void DArray::Init() {
	//TODO
	m_pData = nullptr;
	m_nSize = 0;
	
}

// free the array
void DArray::Free() {
	//TODO
	//要不要什么限制条件啊：答案没有
	delete[] m_pData;
	m_nSize = 0;
	m_pData = nullptr;

}

// get the size of the array
int DArray::GetSize() const {
	//TODO
	
	return m_nSize; // you should return a correct value
}

// set the size of the array
void DArray::SetSize(int nSize) {
	//TODO
	//我的code思路：先copy一个一样的数组出来，不是新生成一个指针变量并指向数组地址。
	//然后将原来的数组m_pData删除并为他生成新的大小数组，判断新大小和原大小的关系，然后按情况复制过去
	double* temp = new double[m_nSize];
	int i = 0;
	for (i = 0; i < m_nSize; i++)
	{
		temp[i] = m_pData[i];
	}
	int a = i + 1;
	delete[] m_pData;
	m_nSize = nSize;
	m_pData = new double[m_nSize];
	if (a <= m_nSize)
	{
		for (int j = 0; j < a; j++)
		{
			m_pData[j] = temp[j];
		}
	}
	else {
		for (int j = 0; j < m_nSize; j++)
		{
			m_pData[j] = temp[j];
		}
	}
	delete[] temp;


}

// get an element at an index
const double& DArray::GetAt(int nIndex) const {
	//TODO
	if (nIndex < m_nSize) {
		//static double ERROR; // you should delete this line
		return m_pData[nIndex]; // you should return a correct value

	}
	else {
		cout << "your nIndex is too large, which is more than" << m_nSize << endl;
		return 0;
	}
	
}

// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
	//TODO
	if (nIndex < m_nSize) {

		m_pData[nIndex] = dValue;
	}
	else {
		cout << "your nIndex is too large, which is more than" << m_nSize << endl;
	}
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
	//TODO
	
	return m_pData[nIndex]; // you should return a correct value
}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
	//TODO
	double* temp = new double[m_nSize+1];
	int i = 0;
	for (i = 0; i < m_nSize; i++)
	{
		temp[i] = m_pData[i];
	}

	delete[] m_pData;
	m_nSize++;
	m_pData = new double[m_nSize];

	for (int j = 0; j < (m_nSize-1); j++)
	{
		m_pData[j] = temp[j];
	}
	delete[] temp;
	m_pData[m_nSize - 1] = dValue;

}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
	//TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	double* temp = new double[m_nSize - 1];
	if ((nIndex > 0) && (nIndex < (m_nSize-1))) {
		for (int i = 0; i < nIndex; i++) 
		{
			temp[i] = m_pData[i];
		}
		for (int i = nIndex + 1; i < m_nSize; i++)
		{
			temp[i] = m_pData[i];
		}
	}
	else if (nIndex == 0) 
	{
		for (int i = 0; i < (m_nSize-1); i++)
		{
			temp[i] = m_pData[i + 1];
		}
	}
	else if(nIndex == (m_nSize-1)) {
		for (int i = 0; i < (m_nSize - 1); i++)
		{
			temp[i] = m_pData[i];
		}
	}
	else {

		cout << "your num is too large" << endl;

	}

	
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
	//TODO
	assert(nIndex >= 0 && nIndex <= m_nSize); // nIndex == m_nSize is legal

	double* pTemp = new double[m_nSize + 1];

	for (int i = 0; i < nIndex; i++)
		pTemp[i] = m_pData[i];

	pTemp[nIndex] = dValue;

	for (int i = nIndex + 1; i < m_nSize + 1; i++)
		pTemp[i] = m_pData[i - 1];

	delete[] m_pData;
	m_pData = pTemp;
	m_nSize++;
}


// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
	//TODO
	
	delete[] m_pData;//这句话我忘了，属于是考虑不全面导致，没有全局思维，赋值跟复制构造函数是不一样的，赋值就意味着有可能原本的数组是有数据的，要先删除
	m_nSize = arr.m_nSize;
	m_pData = new double[m_nSize];
	for (int i = 0; i < m_nSize; i++)
	{
		m_pData[i] = arr.m_pData[i];
	}

	cout << "Copy Constructor called" << endl;

	return *this;
}