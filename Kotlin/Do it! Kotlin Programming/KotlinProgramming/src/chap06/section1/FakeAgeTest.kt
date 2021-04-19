package chap06.section1

fun main(){
    val kim = FakeAge()
    kim.age = 15
    println("Kim's real age = 15, pretended age = ${kim.age}")
    println("Kim's real age = 15, fake age = ${kim.fakeAge}")

    val hong = FakeAge()
    hong.age = 35
    println("Hong's real age = 35, pretended age = ${kim.age}")
    println("Hong's real age = 35, fake age = ${kim.fakeAge}")
}

class FakeAge{
    var age: Int = 0
        set(value){
            fakeAge = value
            field = when{
                value < 18 -> 18
                value in 18..30 -> value
                else -> value - 3
            }
        }

    var fakeAge: Int = 0
        get()=when{
            field < 18 -> 18
            field in 18..30 -> field
            else -> field - 3
        }
}