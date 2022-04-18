「Unity」
===

22/04/18(Mon)
---
# Floating Joystick
## IDragHandler, IPointerDownHandler, IPointerUpHandler
> OnDrag(PointerEventData eventData) 콜백을 받고 싶을 때 구현해야 하는 **인터페이스**입니다.   
> OnPointerDown(PointerEventData eventData) 콜백을 받고 싶을 때 구현해야 하는 **인터페이스**입니다.   
> OnPointerUp(PointerEventData eventData) 콜백을 받고 싶을 때 구현해야 하는 **인터페이스**입니다.   

# get 키워드
> C++ 에서 private 멤버 변수에 접근하기 위해 아래 소스처럼 접근자를 만들어 사용했다.   
> ```cpp
> class CppStyle
> {
>     private :
>             int data;
>     public :
>             int GetData() { return data; }
>             void SetData( int data ) { this->data = data;}
> };
> ```   
> C# 에서는 get과 set 키워드를 이용해 간편하게 구현이 가능하다.
> ```cs
> class CsStyle
> {
>     private int _data;
>     
>     public int data
>     {
>         get { return _data; }   //  _data 반환
>         set { _data = value; }  //  value 키워드 사용
>     }
> }
> ```   
> data 뒤에 괄호가 없으므로 메소드가 아니며 코드 사용시에 변수 쓰듯 사용하면 된다.   
> ```cs
> CsStyle csst = new CsStyle();
> csst.data = 10; //  set
> int a = csst.data;
> ```   
> 3.0 버전부터 가능한 방법으로 다음과 같은 방법도 있다.   
> ```cs
> class CsStyle
> {
>   public int data
>   {
>       get;
>       private set;
>   }
> }
> ```   
> 위의 경우에서는 data를 읽을 수는 있지만 변경은 불가능 하다.