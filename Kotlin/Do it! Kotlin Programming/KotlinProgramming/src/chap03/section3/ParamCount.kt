package chap03.section3

fun main(){
    noParam({"Hello World!"})
    noParam{"Hello World!"}

    oneParam({ a -> "Hello World! $a" })
    oneParam { a -> "Hello World! $a" }
    oneParam { "Hello World! $it" }

    moreParam({a,b->"Hello World! $a $b"})
    moreParam{a,b->"Hello World! $a $b"}
    moreParam{_,b->"대체 $b"}

    withArgs("바보다","멍청이다",{a,b->"진짜 $a. 진짜 $b."})
    withArgs("밖이다","완전밖이다"){babo1,babo2->"엄청나게 $babo1. 대단하게 $babo2"}

    twoLambda({a,b->"$a :) $b"} , {"!$it!"})
    twoLambda({a,b->"$a ;( $b"}){"!!$it!!"}
}
fun noParam(out:()->String) = println(out())

fun oneParam(out:(String)->String) = println(out("OneParam"))

fun moreParam(out:(String,String)->String) = println(out("One","Two"))

fun withArgs(a:String, b:String, out:(String,String)->String) = println(out(a,b))

fun twoLambda(first:(String,String)->String , second:(String)->String){
    println(first("FirstOne","FirstTwo"))
    println(second("SecondOne"))
}