# **[변수와 자료형]**
> _클래스 이름은 파스칼 표기법 (ClassName)_   
> _함수나 변수 이름은 카멜 표기법 (functionName)_   
> _!자바와 달리 코틀린의 모든 자료형은 객체!_

* **var** : 일반적으로 통용되는 변수, 언제든지 읽기쓰기 가능
* **val** : 선언시 초기화, 중간에 값 변경 불가

**여기서 val은 최초에 변수에 할당했던 객체 대신 다른 객체를 할당할 수 없다는 얘기임. val A에 MutableList를 할당하고 그 객체의 내부 구조에 따라 데이터를 조작할 수 있지만**   
**앞서 할당한 val A에 다른 MutableList를 할당할 수는 없다는 뜻.**

**Property(속성)** : 클래스에 선언된 변수

**Local Variable(로컬변수)** : 이 외의 Scope 내에 선언된 변수

`var a : Int` -> 코틀린은 기본변수에서 null을 허용하지 않고 초기화하지않으면 컴파일이 안된다. 의도치않는 에러나 null pointer exception을 원천적으로 차단?

`var a : Int? = null` -> 자료형 뒤에 물음표를 붙여 nullable 변수로 활용 가능. 꼭 필요할때만 사용할것

lateinit , lazy 속성은 추후 추가예정

### 정수자료형

* Byte 1bytes
* Short 2bytes
* Int 4bytes
* Long 8bytes

### 실수자료형

* Float 4bytes
* Double 8bytes -> 기본

### 문자자료형

* Char 2bytes

### 논리형

* Boolean

### 정수형 리터럴
> _2진수 10진수 16진수. (8진수는 지원 X)_

`var intValue:Int = 1234`
 
`var longValue:Long = 1234L`

`var intValueByHex:Int = 0x1af` _16진수_

`var intValueByBin:Int = 0b10110110` _2진수_

### 실수형 리터럴

`var doubleValue:Double = 123.5`

`var doubleValueWithExp:Double = 123.5e10` -> 지수표기법

### Char의 리터럴
> _코틀린은 내부적으로 문자열을 유니코드 인코딩 중에 한 방식인 UTF-16 BE로 관리_   
> _따라서 글자 하나하나가 2bytes의 메모리 공간을 사용_

`var charValue:Char = 'a'`

`var koreanCharValue:Char = '가'`

`\t` : 탭
`\b` : 백스페이스
`\r` : 첫 열로 커서 옮김
`\n` : 개행
`\'` : 작은 따옴표
`\"` : 큰 따옴표
`\\` : 역 슬래시
`\$` : $ 문자
`\uxxxx` : 유니코드 문자

### Boolean의 리터럴

`var booleanValue:Boolean = true`

### 문자열

`val stringValue = "문자열"`

`val multiLineStringValue = """여러 줄의 문자열"""` -> 줄바꿈이나 특수문자까지 그대로 문자열로 사용

### 따옴표 안에서 변수출력

> _변수 앞에 $ 를 붙여 출력_

`println("i : $i, j : $j")`

`println("안녕하세요. ${personA.birthYear}년생 ${personA.name} 입니다.")` -> println이 문자로 오인할 수 있기때문에 {}로 감싼것


***


# [형변환과 배열]

## 형변환
> _형변환 함수를 제공_ -> **명시적 형변환**   
> _코틀린에는 '암시적 형병환' 지원하지 않음_

`toByte()` `toShort()` `toInt()` `toLong()` `toFloat()` `toDouble()` `toChar()`

`var a: Int = 54321`

`var b: Long = a` -> Type dismatch

`var c: Long = a.toLong()`

## 배열
> _Array\<T\>_     _T는 제너릭_

`var intArr = arrayOf(1, 2, 3, 4, 5)`

`var nullArr = arrayOfNulls<Int>(5)` -> 비어있는 배열

`intArr[2]` 의 값은 `3`


***


# [타입추론과 함수]

## 타입추론
> **타입추론** : _변수나 함수들을 선언할 때나 연산이 이루어 질 때 자료형을 코드에 명시하지 않아도 코틀린이 자동으로 자료형을 추론해주는 기능_   
> _명시가 필요한 상황이 아니면 타입추론을 이용해 코드량을 줄임_

`val stringValue`**:String**` = "문자열"`

`var intArr`**:Array\<Int\>**` = arrayOf(1,2,3,4,5)`

`var a = 1234` -> Int

`var b= 1234L` -> Long

`var c = 12.45` -> Double

`var d = 12.45f` -> Float

`var e = 0xABCD` -> Int

`var f = 0b0101010` -> Int

`var g = true` -> Boolean

`var h = 'c'` -> Char

## 함수

`fun add(a: Int, b: Int, c: Int): Int` -> 함수 뒤에 있는 `: Int`는 반환형. 반환값이 없다면 생략가능.

`fun add(a: Int, b: Int, c: Int): Int { return a+b+c }`

`fun babo(a: Any) { }` -> **Any** 라는 자료형은 어떤 자료형이든 상관없이 호환되는 코틀린의 **최상위 자료형**

### 단일 표현식 함수
> _반환형의 타입추론이 가능_ -> 반환형 생략가능

`fun add(a: Int, b: Int, c: Int) = a + b + c`


***


# [조건문과 비교연산자]

## if
`if (a>10){ }`
`else { }`

### is연산자 / !is연산자

`a is Int` -> 좌측 변수가 우측 자료형인지 **'호환'** 되는지 여부를 체크하고 **'형변환'** 까지 한번에 진행

## when
> _다른 언어에서의 switch case_

    when(a) {
    1 -> println("정수 1입니다")
    "Babo" -> println("바보입니다")
    is Long -> println("Long 타입 입니다")
    !is String -> println("String 타입이 아닙니다")
    else -> println("어떤 조건도 만족하지 않습니다")
    }

### when의 동작 대신 반환하게하는 표현식으로써의 역할

    var result = when(a) {
    1 -> "정수 1입니다"
    "Babo" -> "바보입니다"
    is Long -> "Long 타입 입니다"
    !is String -> "String 타입이 아닙니다"
    else -> "어떤 조건도 만족하지 않습니다"
    }


***


# [반복문과 증감연산자]
## 반복문
> _조건형 반복문_ while do...while   
> _범위형 반복문_

### 조건형 반복문

`while(a<5){ println(a++) }`

`do{ println(a++) } while(a<5)` -> 최초 한번은 구문을 실행함.

### 범위형 반복문
> _사람이 좀 더 이해하기 쉬운 방법_   
> _인덱스로 사용할 변수에는 var등을 붙이지 않아도 됨_

`for(i in 0..9) { print(i) }` -> 0123456789

`for(i in 0..9 step 3){ print(i) }` -> 0369

`for(i in 9 downTo 0){ print(i) }` -> 9876543210

`for(i in 9 downTo 0 step 3){ print(i) }` -> 9630

`for(i in 'a'..'e') { print(i) }` -> abcde

## 증감연산자
`++a a++` 증가연산자 (전위연산자 후위연산자)

`--a a--` 감소연산자 (전위연산자 후위연산자)

전위연산자 : '해당 구문'부터 연산적용 후 사용

후위연산자 : '다음 구문'부터 연산적용 후 사용


***


# [흐름제어와 논리연산자]
## 흐름제어
> _코틀린은 다중 반복문에서 break나 continue가 적용되는 반복문을 lable을 통해 지정할 수 있다._

* `return` : 함수를 '종료'하고 값을 '**반환**'
* `break` : 반복문 내의 구문이 실행되는 중간에 즉시 반복문을 '종료'하고 다음 구문으로 넘어감
* `continue` : 다음 반복조건으로 즉시 넘어감


### 레이블
> _레이블이 달린 반복문을 기준으로 즉시 흐름제어_

**레이블 이름@** ---> **break@loop**

    loop@for (i in 1..0) {
        for(j in 1..10){
            if(1 == 1 && j == 2) break@loop
        }
    }

## 논리연산자
> _논리 값을 연산하여 새로운 논리값을 도출할 때 쓰는 연산자_

* `&&` : and 연산자
* `||` : or 연산자
* `!` : not 연산자

## 비트연산자

* `and` : and 연산자 (자바에서 & 연산자)
* `or` : or 연산자 (자바에서 | 연산자)
* `xor` : xor 연산자 (자바에서 ^ 연산자)
* `inv` : not 연산자 (자바에서 ~ 연산자)
* `sh1` : 왼쪽 쉬프트 연산자 (자바에서 << 연산자)
* `shr` : 오른쪽 쉬프트 연산자 (자바에서 >> 연산자)
* `ushr` : 부호비트 포함 오른쪽 쉬프트 연산자 (자바에서 >>> 연산자)


    ddshl - signed shift left (equivalent of << operator) 
    shr - signed shift right (equivalent of >> operator)
    ushr- unsigned shift right (equivalent of >>> operator)
    and - bitwise and (equivalent of & operator)
    or - bitwise or (equivalent of | operator)
    xor - bitwise xor (equivalent of ^ operator)
    inv - bitwise complement (equivalent of ~ operator)

    1 shl 2 // Equivalent to 1.shl(2), 출력 = 4
    16 shr 2 // 출력 = 4
    2 and 4 // 출력 = 0
    2 or 3 // 출력 = 3
    4 xor 5 // 출력 = 1
    4.inv() // 출력 = -5


***


# [클래스]
## 클래스의 기본 구조
> _객체들의 집합_   
> _클래스는 '값'과 그 값을 사용하는 '기능들을 묶어놓은것_   
> _기본 자료형들도 코틀린 내부에서는 전부 클래스_


**클래스** = **속성** + **함수** (고유의 특징값 + 기능의 구현)


`class Person (var name:String, val birthYear:Int)` -> 함수 없는 클래스의 선언

    class Person (var name:String, val birthYear:Int) {
        fun introduce(){
            println("안녕하세요. ${birthYear}년생 ${name} 입니다.")
        }
    }


### 인스턴스
> _클래스를 이용해서 만들어 내는 서로 다른 속성의 객체를 지칭하는 용어_

`var personA = Person("강석원", 1995)` -> 인스턴스 생성

`Person("강석원", 1995).introduce()` -> 이것과 같이 인스턴스를 변수에 담지 않고도 바로 사용할 수도 있다. 익명객체형식임!


### 참조연산자
> _변수명.속성명 -> '.' 이 참조연산자_

`println("안녕하세요. ${personA.birthYear}년생 ${personA.name} 입니다.")` -> println이 문자로 오인할 수 있기때문에 {}로 감싼것

`personA.introduce()`


## 클래스의 생성자
> _생성자 : 새로운 인스턴스를 만들기 위해 호출하는 특수한 함수_   
> _생성자를 호출하면 클래스의 인스턴스를 만들어 '반환'받음_   
> _1. 인스턴스의 속성을 초기화_   
> _2. 인스턴스 생성시 구문을 수행_

* **기본 생성자** : 클래스를 만들 때 기본으로 선언

* **보조 생성자** : 필요에 따라 추가적으로 선언


`class Person` **(var name:String, val birthYear:Int)** -> 클래스의 '속성'들을 선언함과 동시에 '생성자' 역시 선언하는 방법


### init
> _인스턴스 생성시 구문 수행_   
> _패러미터나 반황형이 없는 특수한 함수_   
> _생성자를 통해 인스턴스가 만들어질 때 호출되는 함수_

    class Person (var name:String, val birthYear:Int) {
        init {
            pirntln ("${this.birthYear}년생 ${this.name}님 생성")
        }
    }

`this` : 인스턴스 자신의 속성이나 함수를 호출하기 위해 **클래스 내부에서 사용** 되는 키워드


### 보조생성자
> _기본 생성자와 다른 형태의 생성자를 제공하여 인스턴스 생성시 편의를 제공하거나 추가적인 구문을 수행하는 기능을 제공하는 역할_   
> **constructor()**

**!보조생성자를 만들때는 반드시 기본생성자를 통해 속성을 초기화 해줘야 함!**

    class Person (var name:String, val birthYear:Int) {
        init {
            pirntln ("${this.birthYear}년생 ${this.name}님 생성")
        }
        
        constructor(name:String) : this(name,1995) {
            println ("보조 생성자가 사용됨")
        }
    }

## 클래스의 상속
> _코틀린은 상속 금지가 기본값_   
> _1. 서브 클래스는 슈퍼 클래스에 존재하는 속성과 '같은 이름'의 속성을 가질 수 없음_   
> _2. 서브 클래스가 생성될 때 반드시 슈퍼 클래스의 생성자까지 호출되어야 함_

### open
> _클래스가 상속될 수 있도록 클래스 선언시 붙여줄 수 있는 키워드_

    open class Animal (var name:String, var age:Int, type:String) {
        fun introduce() {
        println("저는 ${type} ${name}이고, ${age}살 입니다.")
        }
    }
    
    class Dog (name:String, age:Int) : Animal (name, age, "개"){
        fun bark() {
            println("멍멍")
        }
    }
    
**!지나친 상속구조는 코드를 더 어렵게 만든다!**


***


# [오버라이딩과 추상화]
## 오버라이딩
> _서브클래스에서 수퍼클래스와 같은이름과 형태를 가진 함수를 만들 수 없다_   
> _수퍼클래스에서 허용해주면 오버라이딩이 가능하다._

### open
> _상속과 마찬가지로 수퍼클래스에서는 함수 앞에 open 키워드를 붙여주는 것으로 오버라이딩 허용_

    open class Animal {
        open fun eat() {
        println("음식을 먹습니다")
        }
    }
    
### override
> _서브클래스에서는 함수 앞에 override 키워드를 붙여주는 것으로 오버라이딩_

    class Tiger : Animal(){
        override fun eat() {
            println("고기를 뜯습니다")
        }
    }

## 추상화
> _추상함수 : 선언부만 있고 기능이 구현되지 않은 함수_   
> _추상클래스 : 추상함수를 포함하는 클래스_

### abstact
> _클래스 앞에 abstract 키워드를 붙여주는 것으로 추상화_

    abstract class Animal {
        abstract fun eat()
        fun sniff() {
            println("킁킁")
        }
    }
    
    class Rabbit : Animal() {
        override fun eat(){
            println("당근을 먹습니다.")
        }
    }
    
### 인터페이스
> _추상함수로만 이루어져있는 '순수 추상화 기능' 이라고 알려져있지만_   
> _코틀린에서는 인터페이스가 속성,추상함수,일반함수 모두 가질 수 있다._   
> _다만 추상함수는 생성자를 가질 수 있는 반면 인터페이스는 불가능!!!!!_   
> _여러개의 인터페이스 상속 가능_

* 구현부가 있는 함수 -> open 함수로 간주
* 구현부가 없는 함수 -> abstract 함수로 간주

**!따라서, 별도의 open , abstract 키워드가 없어도 포함된 모든 함수를 서브클래스에서 구현 및 재정의가 가능!**

    interface Runner{
        fun run()
    }
    
    interface Eater{
        fun eat(){
            println("음식을 먹습니다")
        }
    }
    
    class Dog : Runner, Eater {
        override fun run(){
            println("우다다다 뜁니다")
        }
        override fun eat(){
            println("허겁지겁 먹습니다")
        }
    }

!**'여러개'** 의 인터페이스나 클래스에서 같은 이름과 형태를 가진 함수를 구현하고 있다면 서브클래스에서는 혼선이 없도록 필수적으로 **오버라이딩** 할것!


***


# [기본 프로젝트 구조]
## 물리적 구조
### 프로젝트
> _코틀린으로 어플리케이션을 짤 때 관련한 모든 내용을 담는 '큰 틀'_

### 모듈
* 직접 구현한 모듈
* 라이브러리 모듈

모듈은 다수의 폴더와 파일로 이루어짐

코틀린 코드뿐만 아니라 모듈과 관련된 설정 및 리소스 파일 등도 포함될 수 있다.

## 논리적 구조
### 패키지
> _개발시에 소스 코드의 '소속'을 지정하기 위한 논리적 단위_
> _명시하지 않으면 자동으로 'default' 패키지로 묶임_

**명명법** : 개발한 회사의 도메인을 거꾸로 한것 + .프로젝트명 (eg. com.youtube.woowakgood) -> 그 뒤에 기능별로 세분화 (eg. com.youtube.woowakgood.messi)

    package com.youtube.woowakgood
    
    fun main() {
    }
    
코틀린은 자바와 달리 폴더 구조와 패키지 명을 일치시키지 않아도 됨. 단순히 파일 상단에 패키지만 명시하면 컴파일러가 알아서 처리함.

같은 패키지 내에서는 변수 함수 클래스를 공유할 수 있다.


### 패키지 import
> _다른 패키지의 변수 함수 클래스를 사용하기 위해_   
> _이름이 중복되는 것이 있다면 패키지를 포함한 FULL NAME으로 명시해야함_

    package com.youtube.woowakgood
    
    import com.youtube.dogswellfish
    
    fun main() {
    }

코틀린은 자바와 달리 클래스명과 파일명이 일치하지 않아도 되며 하나의 파일에 '여러개의 클래스'를 넣어도 컴파일이 됨

이는 파일이나 폴더를 기준으로 구분하지 않고 파일내에 있는 **package 키워드를 기준** 으로 구분하기 때문!


***


# [변수, 함수, 클래스의 접근범위와 접근제한자]
## 스코프
> _패키지 구조 내에서 변수나 함수, 클래스의 '공용 범위'를 제어하는 단위_   
> _언어차원에서 변수나 함수, 클래스 같은 '멤버'들을 서로 공유하여 사용할 수 있는 범위를 지정해 둔 단위_

eg. 패키지 내부, 클래스 내부, 함수 내부

### 스코프에 대한 세가지 규칙
1. 스코프 외부에서는 스코프 내부의 멤버를 '참조연산자'로만 참조가 가능하다 (eg. dogA.eat())
2. 동일 스코프 내에서는 멤버들을 '공유'할 수 있다
3. 하위 스코프에서는 상위 스코프의 멤버를 재정의 할 수 있다 -> 작은 스코프에서 동일한 이름의 멤버가 나오면 `name shadowed` 경고가 뜨며 작은 스코프에 지정된 변수가 

    val str = "패키지 스코프"
    
    class B{
        val str = "클래스 스코프"
        fun print() { println(str) }
    }
    
    fun main() {
        val str = "함수 스코프"
        println(str)
        B().print()
    }


## 접근제한자
> _스코프 외부에서 스코프 내부에 접근할 때 그 권한을 '개발자가 제어'할 수 있는 기능_   
> _변수 , 함수 , 클래스 선언시 맨 앞에 붙임_

* public
* internal
* private
* protected

### 패키지 스코프에서 접근제한자
* public : **(기본값)** 어떤 패키지에서도 접근 가능
* internal : 같은 모듈 내에서만 접근 가능
* private : 같은 파일 내에서만 접근 가능

### 클래스 스코프에서 접근제한자
* public : **(기본값)** 클래스 외부에서 늘 접근 가능
* private : 클래스 내부에서만 접근 가능
* protected : 클래스 자신과 상속받은 클래스에서 접근 가능


***


# [고차함수와 람다함수]
## 고차함수
> _함수를 마치 클래스에서 만들어낸 '인스턴스처럼' 취급하는 방법_   
> _함수를 '패러미터'로 넘겨 줄 수도 있고 '결과값으로 반환' 받을 수도 있는 방법_   
> _코틀린에서는 모든 함수를 고차함수로 사용 가능_

    fun main(){
        b(::a)
    }

    fun a (str: String) {
        println("$str 함수 a")
    }
    
    fun b (function: (String)->Unit){
        function("b가 호출한")
    }
        
`Unit` : 값이 없다는 형식

`::` : 일반 함수를 고차 함수로 변경해 주는 연산자

근데 넘길때 꼭 함수를 만들어서 넘겨야함? 그래서 나온게 람다함수 ↓

## 람다함수
> _람다함수는 그 자체가 고차함수. 따라서, 별도의 연산자 없이 변수에 담을 수 있다_

    fun main(){
        b(::a)
        
        val c: (String)->Unit = { str -> println("$str 람다함수") } //원래 패러미터의 자료형까지 다 써주는게 맞다.
               //이미 패러미터의 자료형이 기술되어 있어 자료형이 자동으로 추론되므로 str: String 에서 자료형은 생략가능하다.
        b(c)
    }

    fun a (str: String) {
        println("$str 함수 a")
    }
    
    fun b (function: (String)->Unit){
        function("b가 호출한")
    }

`val a: Int` 일반적인 자료형을 쓴것처럼 `val a: (String)->Unit` 그 자리에 함수의 형식을 쓴것

### 타입추론을 이용한 람다함수 축약
`val c: (String)->Unit = { str -> println("$str 람다함수") }` ----> `val c = { str:String -> println("$str 람다함수") }`

### 람다함수의 특별한 케이스들
* 람다함수도 여러 구문의 사용이 가능 -> **마지막 구문의 결과값** 이 '반환'됨
    val a: (Int, Int)->Int = { a,b ->
        println("여러줄")
        println("쌉가능")
        a+b }
        
* 패러미터가 없는 람다함수는 실행할 구문들만 나열하면 됨
    val a = {println("패러미터가 없듬")}
* 패러미터가 하나뿐이라면 `it` 사용
    val a: (String)->Unit = {"$it 발테리 잇츠 제임스"}


***

# [스코프함수]
> _함수형 언어의 특징을 좀 더 편리하게 사용할 수 있도록 기본 제공하는 함수들_   
> _main함수와 '별도의 scope'에서 인스턴스의 변수와 함수를 조작하므로 코드가 깔끔해지는 장점_

?클래스에서 생성한 인스턴스를 스코프 함수에 전달하면 인스턴스의 속성이나 함수를 스코프 함수 내에서 더 편하게 사용할 수 있도록 하는 기능?

인스턴스의 속성이나 함수를 scope 내에서 깔끔하게 분리하여 사용할 수 있다는 점 때문에 코드의 가독성을 향상시킨다는 장점

* apply
* run
* with
* also
* let

### apply
> 인스턴스를 생성한 후 변수에 담기 전에 '초기화 과정'을 수행할 때 많이 사용
> '인스턴스 자신'을 다시 반환

    fun main() {
        var a = Book("물먹는법특강", 30000).apply{
            name = "[초한정판]" + name
            discount()
        }
    }

    class Book(var name:String, var price:Int){
        fun discount(){
        price -= 2000
        }
    }
    
람다함수 형식으로 참조연산자 없이 바로 사용

인스턴스 자신을 다시 반환하므로 생성되자마자 조작된 인스턴스를 변수에 바로 넣어줄 수 있다.

### run
> 이미 인스턴스가 만들어진 후에 인스턴스의 함수나 속성을 스코프 내에서 사용할 때 유용   
> '마지막 구문'을 반환

    var b = a.run{
        println(a.prince)
        a.name
    }


    fun main() {
        var a = Book("물먹는법특강", 30000).apply{
            name = "[초한정판]" + name
            discount()
        }
        
        a.run{
            println("상품명 : ${name}, 가격 : ${price} 원")
        }
    }

    class Book(var name:String, var price:Int){
        fun discount(){
        price -= 2000
        }
    }
    
### with
> run과 동일한 기능, 단지 인스턴스를 참조연산자 대신 '패러미터'로 받는다는 차이

`a.run{...}` -> `with(a){...}`


### also 와 let
apply/also 는 처리가 끝나면 '인스턴스'를 반환

run/let 은 처리가 끝나면 최종값을 반환

apply, run 과의 차이점으로는 **also** , **let** 은 마치 패러미터로 인스턴스를 넘긴것처럼 `it`을 통해서 인스턴스를 사용할 수 있다.

**이유** : 같은 이름의 변수나 함수가 **'scope 바깥에 중복'**  되어 있는 경우에 혼란을 방지하기 위함

    fun main() {
        var price = 5000
    
        var a = Book("물먹는법특강", 30000).apply{
            name = "[초한정판]" + name
            discount()
        }
        
        a.run{
            println("상품명 : ${name}, 가격 : ${price} 원")
        }
    }

    class Book(var name:String, var price:Int){
        fun discount(){
        price -= 2000
        }
    }

-> `상품명 : [초한정판]물먹는법특강, 5000 원` **price라는 변수가 중복!**


    fun main() {
        var price = 5000
    
        var a = Book("물먹는법특강", 30000).apply{
            name = "[초한정판]" + name
            discount()
        }
        
        a.let{
            println("상품명 : ${it.name}, 가격 : ${it.price} 원")
        }
    }

    class Book(var name:String, var price:Int){
        fun discount(){
        price -= 2000
        }
    }
    
-> `상품명 : [초한정판]물먹는법특강, 28000 원`


***


# [오브젝트]
> _생성자 없이 객체를 직접 만들어 냄_   
> _단 하나의 객체만으로 공통적인 속성과 함수를 사용해야하는 코드에서 사용_   
> _ **Singleton Pattern** 을 언어차원에서 지원!!_

기존의 클래스는 내부에 있는 속성이나 함수를 사용하려면 '생성자'를 통해 실체가 되는 인스턴스 객체를 만들어야 한다.

오브젝트는 그 자체로 객체이기 때문에 생성자는 사용하지 않음.

오브젝트로 선언된 객체는 '최초 사용 시' 자동으로 생성되고, 이후에는 코드 전체에서 '공용으로 사용'될 수 있기 때문에 프로그램이 종료되기 전까지 공통적으로 사용할 내용들을 믂어 만드는 것이 좋다.

    fun main(){
        println(Counter.count)
        
        Counter.countUp()
        Counter.countUp()
        
        println(Counter.count)
        
        Counter.clear()
        
        println(Counter.count)
    }
    
    object Counter {
        var count = 0
        
        fun countUp(){
            count++
        }
        
        fun clear(){
            count = 0
        }
    }
    
## Companion Object
> _클래스 안에 오브젝트 사용_   
> _인스턴스간의 서로 공용 속성 및 함수로 사용_   
> _기존의 언어들의 Static 멤버와 비슷_

    fun main(){
        var a = FoodPoll("짜장")
        var b = FoodPoll("짬뽕")
        
        a.vote()
        a.vote()
        
        b.vote()
        b.vote()
        b.vote()
        
        println("${a.name} : ${a.count}")
        println("${b.name} : ${b.count}")
        println("총계 : ${FoodPoll.total}")
    }
    
    class FoodPoll (val name: String){
        companion object{
            var total = 0
        }
        var count = 0
        
        fun vote(){
            total++
            count++
        }
    }


***


# ☆☆☆ [익명객체와 옵저버 패턴] ☆☆☆ 20.08.23 많이 어렵다 다시 제대로 이해하고 넘어
## 옵저버 패턴
> '이벤트가 일어나는 것을 감시'하는 감시자의 역할

e.g. 안드로이드 : 키의 입력, 터치의 발생, 데이터의 수신등 함수로 직접 요청하지 않았지만 시스템 또는 루틴에 의해 발생하게 되는 동작들을 '이벤트' 라고 부르며 이 '이벤트' 가 발생할 때 마다 '즉각적으로 처리' 할 수 있도록 만드는 프로그래밍 패턴을 '옵저버 패턴' 이라고 부른다.

### 옵저버 패턴의 구조
* 이벤트를 수신하는 클래스 : A 라고 지칭
* 이벤트의 발생 및 전달하는 클래스 : B 라고 지칭

A에 B의 인스턴스를 생성하여 사용하기 때문에 A는 B를 직접 참조할 수 있지만 반대로 B는 A를 참조할 수 없기때문에 사이에 **인터페이스** 를 끼워넣음.

이 인터페이스를 **'observer'** , 코틀린에서는 **'listener'** 라고 함.

이렇게 이벤트를 넘겨주는 행위를 **'callback'** 이라고 함.

_리스너를 통해 이벤트를 반환하는 함수 이름은 관례적으로 `on(행위)` 라는 규칙을 따름_

    fun main(){
        EventPrinter().start()
    }
    
    interface EventListener{
        fun onEvent(count: Int)
    }
    
    class Counter(var listener: EventListener){
        fun count(){
            for(i in 1..100){
                if(i % 5 == 0) listener.onEvent(i)
            }
        }
    }
    
    class EventPrinter: EventListener{
        override fun onEvent(count: Int){
            print("${count}-")
        }
        
        fun start(){
        //this는 EventPrinter 객체 자신을 나타내지만 받는 쪽에서 'EventListener'만 요구했기 때문에 EventListener 구현부만 넘겨주게 됨
        //이를 객체지향의 다형성이라고 함
            val counter = Counter(this) 
            counter.count()
        }
    }
    
## 익명객체
> _오브젝트와의 차이는 이름이 없다는 점_   
> _인터페이스를 구현한 객체를 코드 중간에도 '즉시 생성'하여 사용할 수 있음_

    fun main(){
        EventPrinter().start()
    }
    
    interface EventListener{
        fun onEvent(count: Int)
    }
    
    class Counter(var listener: EventListener){
        fun count(){
            for(i in 1..100){
                if(i % 5 == 0) listener.onEvent(i)
            }
        }
    }
    
    class EventPrinter{
        fun start(){
        // Counter(익명객체) 형식임. 저 긴 문장이 익명함수로 넘길 패러미터 단 한 개.
            val counter = Counter(object: EventListener{
                override fun onEvent(count: Int){
                    print("${count}-")
                }
            })
            counter.count()
        }
    }


참고로 위의 익명객체에서 오버라이드 해야할 함수가 하나면 좀더 간단하게 구현 가능 -> **람다함수** 이용? -> 한번해볼것 20-08-25

안드로이드에서 자바로 되어있는 인터페이스? 를 사용할때만 코틀린으로 SAM 방식?으로 람다함수 이용가능

순수하게 코틀린으로 할때는 그냥 이렇게 넘기면 된다고 함.
    
    
***


# [클래스의 다형성]

**수퍼클래스** : 음료클래스 (Drink)

**서브클래스** : 콜라클래스 (Coke)

* **Up-Casting** : 하위 자료형을 상위 자료형인 수퍼클래스로 변환 `var a: Drink = Coke()`
* **Down-Casting** : Up-Casting 된 인스턴스를 다시 하위 자료형으로 변환. **별도의 연산자** 필요

### Down-Casting 연산자

* as : '변수'를 호환되는 자료형으로 변환해주는 캐스팅 연산자
    var a: Drink = Coke()
    a as Coke // 즉시 자료형 변환

    var a: Dring = Coke()
    var b = a as Coke // 변환된 결과를 반환해주고 **a 변수 자체도 다운캐스팅** 됨

* is : 변수가 자료형에 호환되는지를 먼저 **'체크한 후 변환'** 해주는 캐스팅 연산자. 조건문에서 사용하며 그 **조건문 내에서만** 캐스팅
    var a: Drink = Coke()
    if(a is Coke){
        // **이 안에서만 a가 Coke가 됨**
    }
    



***



# 제너릭 정의 정확하게 다시 설명한거 찾아서 적어놓을 수 있도록 20/08/27
# [제너릭]
> _클래스나 함수에서 사용하는 자료형을 외부에서 지정할 수 있는 기능_   
> _캐스팅 연산을 거치는 것은 프로그램의 속도를 저하시킬 수 있다는 단점 때문에 나온 제너릭_


제너릭은 함수나 클래스를 선언할 때 고정적인 자료형 대신 실제 자료형으로 대체되는 **'타입 패러미터'** 를 받아 사용하는 방법

`<T>` 이 타입 패러미터에 특정 자료형이 할당되면 `T` 제너릭을 사용하는 모든 코드는 할당된 자료형으로 대체되어 컴파일 됨.

`fun <T> genericFunc(param: T): T` -> `fun <Int> genericFunc(param: Int) Int`

`class GenericClass <T> (var pref: T)` -> `class GenericClass <Int> (var pref: Int)`

따라서, 캐스팅 연산없이도 자료형을 그대로 사용할 수 있다..?

`<T>` 타입패러미터의 이름은 클래스 이름과 규칙이 같지만 일반적으로 'Type'의 이니셜인 'T' 를 사용하는것이 관례

여러개의 제너릭을 사용할 경우 'T' 의 다음 알파벳인 'U'와 'V'를 사용하기도 함. `<T,U,V>`

제너릭을 특정한 수퍼 클래스를 상속받은 클래스 타입으로만 제한하려면 `<T: SuperClass이름>`

## 사용법?
### 함수에 제너릭을 선언한 경우
`fun <T> genericFunc (var param: T){}`   

`genericFunc(1)` 처럼 일반적인 함수처럼 사용하면 패러미터나 반환형을 통해 타입 패러미터를 통해 자동으로 추론

### 클래스의 경우
`class GenericClass <T>`   
`GenericClass<Int>()` 인스턴스를 생성할때 타입 패러미터를 수동으로 지정하거나 `<Int>`   

`class GenericClass <T> (var pref: T)`   
`GenericClass(1)` 생성자에 제너릭이 사용된 경우 지정하지 않아도 자동으로 추론

### 제너릭 예제
    fun main(){
        UsingGeneric(A()).doShouting()    //UsingGeneric<A>(A()).doShouting() 이렇게 타입패러미터를 수동으로 전달할 수도 있지만 추론가능하므로 생략
        UsingGeneric(B()).doShouting()
        UsingGeneric(C()).doShouting()
    }
    
    open class A {
        open fun shout(){
            println("A가 사자후")
        }
    }
    
    class B : A(){
        override fun shout(){
            println("B와 사자후")
        }
    }
    
    class C : A(){
        override fun shout(){
            println("C는 사자후")
        }
    }
    
    class UsingGeneric <T:A> (val t: T){
       fun doShouting(){
           t.shout()
       }
    }

**여기서 제너릭을 사용하지않고 UsingGeneric의 생성자에서 수퍼클래스인 A로 캐스팅하여 shout을 호출하여도 동작은 같겠지만**   
**이렇게 제너릭을 사용하는 경우 사용할 때 제너릭이 자료형을 대체하게 되어 캐스팅을 방지할 수 있으므로 성능을 더 높일 수 있다..?**   
`class UsingGeneric(val t:A)` -> `calss UsingGeneric <T:A> (val t:T)`

### 제너릭을 함수 사용하는법
    fun main(){
        doShouting(A())
    }
    
    fun <T:A> doShouting(t:T){
        t.shout()
    }
    
    open class A {
        open fun shout(){
            println("A가 사자후")
        }
    }

**제너릭에 대한 자세한 얘기는 나중 강의에서 설명해준다 함**



***


# [리스트]
> _데이터를 코드에서 지정한 순서대로 저장해두는 리스트_   

리스트는 '데이터를 모아 관리'하는 Collection 클래스를 상속받는 서브 클래스 중 가장 단순한 형태 중 하나로   
여러개의 데이터를 원하는 순서로 넣어 관리하는 형태


### 리스트의 종류 2가지
* List<out T>    :    생성시에 넣은 객체를 대체, 추가, 삭제 할 수 없음
* MutableList<T>    :    생성시에 넣은 객체를 대체, 추가, 삭제가 가능함

### 리스트를 생성하는 방법
전용함수 사용   
* listOf(1,2,3)
* mutableListOf("A","B","C")

### MutableList의 함수
* add(데이터)
* add(인덱스, 데이터)
* remove(데이터)
* removeAt(인덱스)
* shuffle()
* sort()
* list[인덱스] = 데이터


***


# [문자열을 다루는 법]
> _String 클래스와 관련된 여러 속성과 함수_   
> _그 중 자주쓰이는것 설명_

### 주로 사용하는 속성과 함수
* length : Int 타입의 길이 속성
* toLowerCase() : 영문 소문자로 문자열 전체 변환하여 반환 -> 해당 문자열에 바로 적용되는 것은 아님
* toUpperCase() : 영문 대문자로 문자열 전체 변환하여 반환 -> 해당 문자열에 바로 적용되는 것은 아님
* split("delimiter") : delimiter를 기준으로 문자열을 나누어 문자열 배열로 반환 -> **자바와 달리 split에 정규식이 아닌 일반 문자열을 넣어도 동작**
* joinToString() : 문자열 배열을 합쳐서 반환함? -> 정확히 어떤걸 합쳐서 문자열로 반환한다는거지?
* joinToString("문자열") : 지정한 문자열을 사이에 넣어서 합쳐서 반환함? -> 얘도마찬가지
* substring(5..10) : for문에서 사용했었던 **IntRange** 형식을 사용하여 시작과 끝을 정해주어 그 부분만 반환

### 문자열이 비어있는지 여부를 판단하여 boolean 값으로 반환받는 함수
* isNullOrEmpty() : null 이거나 empty면 true를 반환 -> null 이거나 아예 비어야함
* isNullOrBlank() : null 이거나 blank면 true를 반환 -> null 이거나 공백문자만 있어아햠 (Space, Tab, Line Feed, Carrige Return 등등)

    fun main() {
        val nullString: String? = null
        val emptyString = ""
        val balnkString = " "
        val normalString = "A"
    }

### 특수한 함수들
* startsWith("문자열") : 지정한 문자열로 시작하면 true를 반환
* endsWith("문자열") : 지정한 문자열로 끝나면 true를 반환
* contains("문자열") : 지정한 문자열을 포함하면 true를 반환


***


# [null 처리와 동일성의 확인]
> _nullable 변수에서 null을 처리하는 법과_   
> _변수 간에 동일성을 확인하는 법_

null 상태로 속성이나 함수를 쓰려고 하면 null pointer exception이 발생하기 때문에 nullable 변수를 사용할 때에는 null check 없이는 코드가 컴파일되지 않는다.
