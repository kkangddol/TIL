# **[변수와 자료형]**
> _클래스 이름은 파스칼 표기법 (ClassName)_

> _함수나 변수 이름은 카멜 표기법 (functionName)_

> _!자바와 달리 코틀린의 모든 자료형은 객체!_

* **var** : 일반적으로 통용되는 변수, 언제든지 읽기쓰기 가능
* **val** : 선언시 초기화, 중간에 값 변경 불가

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
_다른 언어에서의 switch case_

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

`Person.introduce()` -> 이것과 같이 인스턴스를 변수에 담지 않고도 바로 사용할 수도 있다.


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
        fun run(){
            println("우다다다 뜁니다")
        }
        fun eat(){
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
3. 하위 스코프에서는 상위 스코프의 멤버를 재정의 할 수 있다

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


***



# [스코프함수]
