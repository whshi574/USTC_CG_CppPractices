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
	//��һ������һ��ʼд�ģ���̫׼ȷ�������ǽ���ַ��������һ��ָ����������������������ϵĸ���
	/*	
		m_nSize = arr.m_nSize;
		m_pData = arr.m_pData;
	*/
	//���⣺�������������ֵ��������ĵ�ַ����һ��ָ������в�
	//���ƣ���ָ��һ����ַ�����ݸ��Ƹ���һ����ַ��������Ϊ����ַ������һ��ָ�����������һ������
	m_nSize = arr.m_nSize;
	//���⣺ͬһ��Ĳ�ͬ�����ܻ������˽�г�Ա�𣺿���
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

	/*cout << "size = " << m_nSize << ":";//samples��
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
	//Ҫ��Ҫʲô��������������û��
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
	//�ҵ�code˼·����copyһ��һ�����������������������һ��ָ�������ָ�������ַ��
	//Ȼ��ԭ��������m_pDataɾ����Ϊ�������µĴ�С���飬�ж��´�С��ԭ��С�Ĺ�ϵ��Ȼ��������ƹ�ȥ
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
	
	delete[] m_pData;//��仰�����ˣ������ǿ��ǲ�ȫ�浼�£�û��ȫ��˼ά����ֵ�����ƹ��캯���ǲ�һ���ģ���ֵ����ζ���п���ԭ���������������ݵģ�Ҫ��ɾ��
	m_nSize = arr.m_nSize;
	m_pData = new double[m_nSize];
	for (int i = 0; i < m_nSize; i++)
	{
		m_pData[i] = arr.m_pData[i];
	}

	cout << "Copy Constructor called" << endl;

	return *this;
}