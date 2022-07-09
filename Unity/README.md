「Unity」
===

22/04/18(Mon)
---
# Floating Joystick
## IDragHandler, IPointerDownHandler, IPointerUpHandler
> OnDrag(PointerEventData eventData) 콜백을 받고 싶을 때 구현해야 하는 **인터페이스**입니다.   
> OnPointerDown(PointerEventData eventData) 콜백을 받고 싶을 때 구현해야 하는 **인터페이스**입니다.   
> OnPointerUp(PointerEventData eventData) 콜백을 받고 싶을 때 구현해야 하는 **인터페이스**입니다.   

# get, set 키워드
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

22/04/19(Tues)
---
# 추적
## NavMeshAgent

# 특정Transform.Find("오브젝트 이름");
> GameObject.Find는 전체를 탐색   
> **특정Transform.Find** 는 특정Transform 자식 오브젝트 중에서 탐색   
> ```cs
> public Transform firePos;
> void Start()
> {
>   fireLight = firePos.Find("PointLight").GetComponent\<Light>(); //firePos의 자식 오브젝트 중에서 탐색
> }
> ```

22/04/20(Wed)
---
## Instantiate 세가지 방법
> GameObject 반환, Component 반환, 제너릭 반환   
> 각각 방법에 따른 transform 값 전달 방법의 차이   
> 각각 방법에 따른 투사체 이동방향 차이 (Vector3.forward vs transform.forward // AddForce() vs AddRelativeForce())


22/04/21(Thu)
---
## 투사체와 피사체 간 관계
> 누가 누구를 알고 몰라야 하는지, 주도적으로 호출하게 될 지 고민   
> 투사체가 피사체를 GetComponent 하는것이 그 관점에 부합   
> 투사체에 트리거로 들어온 객체에 Health 상속받은 컴포넌트 유무로도 피격가능여부 판별하기도 함   

## 컴포넌트 패턴


22/05/10(Tue)
---
## Scene 관리
> 계속 바뀌지 않아도 되는 오브젝트들은 따로 씬을 두고 스테이지 씬을 중첩하는 방식   
> Additive로 다중 씬 추가   


## Math 와 Mathf 차이점
## LoadingScene, LoadingUI, LoadSceneAsync
## 이벤트에 콜백함수 붙이기
## Ctrl + . 로 메소드 구현부 자동생성
## Time.unscaledDeltaTime 및 scale에 관해
## Rigidbody 물체 이동방법의 차이. transform vs rigidbody
> https://ajh322.tistory.com/273   
> https://cajava.tistory.com/3   
> https://sensol2.tistory.com/10   
> https://blog.naver.com/sabotduke/220802330662   
> https://themestock7.tistory.com/56   

  
22/05/16(Mon)
---
## delegate, lambda
## Linq
## virtual abstract interface


22/05/19(Thur)
---
## 컴포넌트 패턴
## 스크립터블 오브젝트

22/05/23(Mon)
---
## Transform.RotateAround()

22/06/07(Tue)
---
## ToString() Formatting

22/06/08(Wed)
---
## 리치텍스트

22/07/09(Sat)
---
## 
