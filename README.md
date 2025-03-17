Today I Learned
===
목적
---
> 매일 학습한 것을 정리하면서 리뷰.   
> 이전에 학습한 것들도 매일 다시 톺아보면서 머릿속에 상기시키기.   
> 나만의 백과사전을 만드는 것.   
> 나의 자신감을 한 줄 한 줄 쌓아가는 것.

# 25/03/17 기준 깃허브 블로그 생성해서 정리 예정

학습한 것
===
22/04/12 (Tues)
---
> Calling Convention (함수 호출 규약)
   
22/04/13 (Wed)
---
> SOLID   
> 클래스 설계   
> inheritance vs composition   
> 랜덤다이스 카피 다시 시작   
> GameManager   
   
22/04/18 (Mon)
---
## 날개 게임 프로토타입 제작 시작   
## [Floating Joystick](https://github.com/knemo333/TIL/tree/master/Unity#floating-joystick)  
> IDragHandler, IPointerDownHandler, IPointerUpHandler   
> OnDrag(PointerEventData eventData), OnPointerDown(PointerEventData eventData), OnPointerDown((PointerEventData eventData)   
## [get, set 키워드](https://github.com/knemo333/TIL/blob/master/C%23/README.md#get-set-%ED%82%A4%EC%9B%8C%EB%93%9C)
> ```cs
> public float Vertical {get{return input.y;}}
> ```
   
22/04/19(Tues)
---
## 추적
> NavMeshAgent

## 특정Transform.Find("오브젝트 이름");
> GameObject.Find는 전체를 탐색   
> **특정Transform.Find** 는 특정Transform 자식 오브젝트 중에서 탐색   
> ```cs
> public Transform firePos;
> void Start()
> {
>   fireLight = firePos.Find("PointLight").GetComponent<Light>(); // firePos의 자식 오브젝트 중에서 탐색
> }
> ```
## Git
> stash, rebase, conflict, revert, reset   
   
22/04/20(Wed)
---
## [Instantiate 세가지 방법](https://github.com/knemo333/TIL/tree/master/Unity#22/04/20(Wed))
> GameObject 반환, Component 반환, 제너릭 반환   
> 각각 방법에 따른 transform 값 전달 방법의 차이   
> 각각 방법에 따른 투사체 이동방향 차이 (Vector3.forward vs transform.forward // AddForce() vs AddRelativeForce())

   
22/04/21(Thu)
---
## [투사체와 피사체 간 관계](https://github.com/knemo333/TIL/tree/master/Unity#22/04/21(Thu))
> 누가 누구를 알고 몰라야 하는지, 주도적으로 호출하게 될 지 고민   
> 투사체가 피사체를 GetComponent 하는것이 그 관점에 부합   
> 투사체에 트리거로 들어온 객체에 Health 상속받은 컴포넌트 유무로도 피격가능여부 판별하기도 함   

## 컴포넌트 패턴
