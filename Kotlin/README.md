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

