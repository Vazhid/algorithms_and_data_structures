<div class="problem-statement">
   <div class="header">
      <h1 class="title">B-дерево</h1>
      <table>
         <tr class="time-limit">
            <td class="property-title">Ограничение времени</td>
            <td>1&nbsp;секунда</td>
         </tr>
         <tr class="memory-limit">
            <td class="property-title">Ограничение памяти</td>
            <td>64Mb</td>
         </tr>
         <tr class="input-file">
            <td class="property-title">Ввод</td>
            <td colspan="1">стандартный ввод или input.txt</td>
         </tr>
         <tr class="output-file">
            <td class="property-title">Вывод</td>
            <td colspan="1">стандартный вывод или output.txt</td>
         </tr>
      </table>
   </div>
   <h2></h2>
   <div class="legend"><span style="">
         <p>Постройте B-дерево минимального порядка t и выведите его по слоям.<br> В качестве ключа используются числа, лежащие в диапазоне <span class="tex-math-text">[0..2<sup>32</sup>-1]</span><br> 
         </p></span><p><span style="font-weight:bold;">Требования:</span> 
         <ul>
            <li>B-дерево должно быть реализовано в виде шаблонного класса. </li>
            <li>Решение должно поддерживать передачу функции сравнения снаружи. </li>
         </ul>
      </p>
   </div>
   <h2>Формат ввода</h2>
   <div class="input-specification"><span style="">
         <p>Сначала вводится минимальный порядок дерева t.<br> Затем вводятся элементы дерева.
         </p></span></div>
   <h2>Формат вывода</h2>
   <div class="output-specification"><span style="">
         <p>Программа должна вывести B-дерево по слоям. <br> Каждый слой на новой строке, элементы должны выводится в том порядке, в котором они лежат в узлах. 
         </p></span></div>
   <h3>Пример 1</h3>
   <table class="sample-tests">
      <thead>
         <tr>
            <th>Ввод</th>
            <th>Вывод</th>
         </tr>
      </thead>
      <tbody>
         <tr>
            <td><pre>2
0 1 2 3 4 5 6 7 8 9</pre></td>
            <td><pre>3
1 5 7
0 2 4 6 8 9</pre></td>
         </tr>
      </tbody>
   </table>
   <h3>Пример 2</h3>
   <table class="sample-tests">
      <thead>
         <tr>
            <th>Ввод</th>
            <th>Вывод</th>
         </tr>
      </thead>
      <tbody>
         <tr>
            <td><pre>4
0 1 2 3 4 5 6 7 8 9</pre></td>
            <td><pre>3 
0 1 2 4 5 6 7 8 9 </pre></td>
         </tr>
      </tbody>
   </table>
</div></div>