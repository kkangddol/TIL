package chap08.section2.sortwith2

data class Product(val name:String, val price: Double)

fun main(){
    val products = arrayOf(
            Product("Snow Ball",870.00),
            Product("Smart Phone A",999.00),
            Product("Drone",240.00),
            Product("Mouse",333.55),
            Product("Keyboard",125.99),
            Product("Smart Phone B",1500.99),
            Product("Mouse",512.99)
    )

    products.sortWith(compareBy({it.name},{it.price}))
    products.forEach { println(it) }
}