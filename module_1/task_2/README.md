<div class="problem-statement">
   <div class="header">
      <h1 class="title">Следующий элемент</h1>
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
         <p>Дан отсортированный массив целых чисел A<span style="">[0..n-1]</span> и массив целых чисел B<span style="">[0..m-1]</span>. Для каждого элемента массива B<span style="">[i]</span> найдите минимальный индекс k минимального элемента массива A, равного или превосходящего B<span style="">[i]</span>: A<span style="">[k]</span> &gt;= B<span style="">[i]</span>. Если такого элемента нет, выведите n. Время работы поиска k для каждого элемента B<span style="">[i]</span>: O(log(k)). n, m ≤ 10000. 
         </p></span></div>
   <h2>Формат ввода</h2>
   <div class="input-specification"><span style="">
         <p>В первой строчке записаны числа n и m. Во второй и третьей массивы A и B соответственно. </p></span></div>
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
            <td><pre>2 1
1 2
2</pre></td>
            <td><pre>1</pre></td>
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
            <td><pre>4 3
2 4 5 7
4 6 1</pre></td>
            <td><pre>1 3 0</pre></td>
         </tr>
      </tbody>
   </table>
</div>