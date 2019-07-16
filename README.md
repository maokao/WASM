# WASM
> 網路上與官網上的網路教學，有需多都是從簡單C/C++轉換為WASM的範例開始教學，當然也有神人直接編輯WAT。我當然也是拜讀各位大大的心血，慢慢地開始學習。但是往往之前寫好的C++ code並不是只是單純的輸入/輸出單一數字，通常都包含了陣列的傳輸，與在C++程式中動態產生陣列。然而這部分的教學就相對少了許多，結果就開始到處碰壁。
> 
> 之前想說先不安裝Emscripten，利用線上編譯WASM網站，下載C++轉出的.wasm檔，再自己照著網路查到的教學文，自己刻對接的js。然而在不觸碰Memory相關的程式，大致上都沒什麼問題。但是只要是包含了陣列的傳輸，和在C++程式中動態產生陣列時，就會出現各種奇妙的問題。
> 
> 經過多次的測試，決定還是乖乖地使用Emscripten的emcc來編譯C++程式碼，產生出.js與.wasm，然後再編寫html檔。想不到這解決了許多之前完全手動load wasm檔的問題，或者應該說不太需要顧慮那些問題，因為Emscripten自動產生的膠水語言(glue language)-.js檔，都幫你處理掉了(或許？)。而且程式也變得簡單乾淨許多，寫起來沒那麼挫折。
> 
> 另外，因為我的開發環境在Mac上，原本都是用Apache來當web server，但是會發現某些js方的WASM的寫法，會產生MIME TYPE的error。而這情況也會發生在利用emcc編譯出的js檔上。因此目前強力建議還是利用Emscripten所附帶的web server。
> 
## 使用方式說明
安裝Emscripten的部分，在此先跳過，有空再補上。
當你安裝好Emscripten後，要做的事順序如下：
1. 撰寫cpp檔。
2. 編譯cpp檔成wasm和產生js的glue language。  
`emcc cpp檔名 -s "EXPORTED_FUNCTIONS=['_你要給js呼叫的function名']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall','cwrap']" -o 要產生的js檔名`
3. 撰寫html/js檔。
4. 啟動Emscripten所附帶的web server，看結果囉。  
`emrun --no_browser --port 8000 .`


未完
