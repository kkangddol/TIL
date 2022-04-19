Today I Learned
===
목적
---
> 매일 학습한 것을 정리하면서 리뷰.   
> 이전에 학습한 것들도 매일 다시 톺아보면서 머릿속에 상기시키기.   
> 나만의 백과사전을 만드는 것.   
> 나의 자신감을 한 줄 한 줄 쌓아가는 것.   

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
소현우
