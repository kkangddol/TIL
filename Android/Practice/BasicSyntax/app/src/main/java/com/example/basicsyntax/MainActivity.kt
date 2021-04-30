package com.example.basicsyntax

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var myName = "홍길동"
        var myAge : Int
        myAge = 27
        myAge = myAge + 1
        Log.d("BasicSyntax", "myName = $myName , myAge = $myAge")

        var student = IntArray(10)
        var stringArr = Array(10, {item->""})
        var mutableList = mutableListOf("A","B","C")
        var stringList = mutableListOf<String>()

        var array = arrayOf("JAN", "FEB", "MAR", "APR", "MAY", "JUN")
        for (index in 0 until array.size) {
            Log.d("ForLoop", "현재 월은 ${array[index]} 입니다.")
        }

        Log.d("sumSeq", "${sumSeq(3)}")


        class ClassUser(name: String, age: Int)
        var classUser = ClassUser("ClassUser", 99)
        data class DataUser (var name: String, var age: Int)
        var dataUser = DataUser("Michael", 21)
        Log.d("DataClass", "ClassUser는 ${classUser.toString()}")
        Log.d("DataClass", "DataUser는 ${dataUser.toString()}")

        testStringExtension()

    }

    fun sumReturn (a: Int,b: Int): Int {
        return a+b
    }
    fun sumSeq (a: Int): Int {
        if (a == 0) return a
        else return sumSeq(a - 1) + a
    }
    fun printStr (str: String) {
        Log.d("printStr", "${str}")
    }

    fun testStringExtension() {
        var original = "Hello"
        var added = " Guys~"

        Log.d("Extension", "added를 더한 값은 ${original.plus(added)}입니다.")
    }


}
fun String.plus(word: String): String { return this + word}