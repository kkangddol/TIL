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
