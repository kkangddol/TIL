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
