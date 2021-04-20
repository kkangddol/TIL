package com.example.helloandroid

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.TextView
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

/*        val tvTitle = findViewById<TextView>(R.id.tv_title)
        tvTitle.text = "자 이제 시작이야!"
*/
        tv_title.text = "자 이제 진짜 시작이야!!"

        titleOn()
    }
}

fun MainActivity.titleOn() {
    tv_title.text = "뭘보냐"
    tv_title.visibility = View.VISIBLE
}