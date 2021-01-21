package chap04.section3

class InvalidNameException(message: String) : Exception(message)

fun main(){
    var name = "Kildong123"

    try{
        validateName(name)
    }catch(e:InvalidNameException){
        println(e.message)
    }catch (e:Exception){
        println(e.message)
    }finally {
        println("무조건실행되는바보")
    }
}

fun validateName(name:String){
    if(name.matches(Regex(".*\\d+.*"))){
        throw InvalidNameException("Your name : $name : contains numerals.")
    }
}