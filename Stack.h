#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class T>
class Stack : public LinkedList<T>{
	public:
		virtual bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first == 0) // 기본적으로 this는 class의 멤버변수에 접근하기 위한 것입니다..!!
			{
				return false;
			} // this->first가 NULL(0)이라는 소리는 현재 스택에 아무런 원소도 들어있지 않다는 소리입니다..!! 
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T>* temp = this->first;
			element = temp->data;
			this->first = (this->first)->link;
			delete temp;
			this->current_size -= 1;
			return true;
			}
};
