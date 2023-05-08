<div class="problem-statement">
   <div class="header">
      <h1 class="title">Обход дерева в порядке in-order</h1>
      <table>
         <tr class="time-limit">
            <td class="property-title">Ограничение времени</td>
            <td>0.2&nbsp;секунды</td>
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
         <p>Дано число <span class="tex-math-text">N &le; 10<sup>4</sup></span> и последовательность целых чисел из <span class="tex-math-text">[-2<sup>31</sup>..2<sup>31</sup>]</span> длиной N. Требуется построить бинарное дерево, заданное наивным порядком вставки. Т.е., при добавлении очередного числа K
            в дерево с корнем root, если root→Key ≤ K, то узел K добавляется в правое поддерево root; иначе в левое поддерево root. Выведите
            элементы в порядке in-order (слева направо).
         </p></span><p>Рекурсия запрещена.</p>
   </div>
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
            <td><pre>10
9
10
4
3
2
7
8
5
1
6
</pre></td>
            <td><pre>1 2 3 4 5 6 7 8 9 10 
</pre></td>
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
            <td><pre>10
4
7
5
10
3
2
8
1
6
9
</pre></td>
            <td><pre>1 2 3 4 5 6 7 8 9 10 
</pre></td>
         </tr>
      </tbody>
   </table>
   <h3>Пример 3</h3>
   <table class="sample-tests">
      <thead>
         <tr>
            <th>Ввод</th>
            <th>Вывод</th>
         </tr>
      </thead>
      <tbody>
         <tr>
            <td><pre>10
2
3
6
1
10
8
4
9
7
5
</pre></td>
            <td><pre>1 2 3 4 5 6 7 8 9 10 
</pre></td>
         </tr>
      </tbody>
   </table>
</div></div>