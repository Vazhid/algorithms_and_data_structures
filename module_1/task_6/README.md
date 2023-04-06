<div class="problem-statement">
   <div class="header">
      <h1 class="title">Порядковая статистика и параметры множества</h1>
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
         <p>Дано множество целых чисел из <span class="tex-math-text">[0..10<sup>9</sup>]</span> размера n. <br> 
         </p></span><p>Используя алгоритм поиска k-ой порядковой статистики, требуется найти следующие параметры множества:<br> 
         <ul>
            <li>10% перцентиль </li>
            <li>медиана </li>
            <li>90% перцентиль </li>
         </ul>
      </p>
      <p><span style="font-weight:bold;">Требования:</span> 
         <ul>
            <li>К дополнительной памяти: O(n). </li>
            <li>Среднее время работы: O(n) </li>
            <li>Должна быть отдельно выделенная функция partition. </li>
            <li>Рекурсия запрещена. </li>
            <li>Решение должно поддерживать передачу функции сравнения снаружи. </li>
         </ul>
      </p>
   </div>
   <h2>Формат ввода</h2>
   <div class="input-specification"><span style="">
         <p>Сначала вводится кол-во элементов массива n. После сам массив. </p></span></div>
   <h2>Формат вывода</h2>
   <div class="output-specification"><span style="">
         <p>Параметры множества в порядке: 
            <ul>
               <li>10% перцентиль </li>
               <li>медиана </li>
               <li>90% перцентиль </li>
            </ul>
         </p></span></div>
   <h2>Пример</h2>
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
1 2 3 4 5 6 7 8 9 10 </pre></td>
            <td><pre>2
6
10
</pre></td>
         </tr>
      </tbody>
   </table>
</div>