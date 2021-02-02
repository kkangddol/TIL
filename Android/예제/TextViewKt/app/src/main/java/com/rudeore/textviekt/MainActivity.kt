package com.rudeore.textviekt

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {    // 앱이 최초 실행됐을 때 수행
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)  // xml 화면 뷰를 연결.

        btn_getText.setOnClickListener{ // 에딧 텍스트의 입력된 값을 텍스트뷰에 전달
            //it : View!
            var resultText = et_id.text.toString()
            tv_result.setText(resultText)
        }

    }
}