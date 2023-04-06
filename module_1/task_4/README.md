<div class="problem-statement">
   <div class="header">
      <h1 class="title">Топ K пользователей из лога</h1>
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
         <p>Имеется лог-файл, в котором хранятся пары для N пользователей <span style="font-style:italic;">(Идентификатор пользователя, посещаемость сайта)</span>.<br> Напишите программу, которая выбирает K пользователей, которые чаще других заходили на сайт, и выводит их в порядке возрастания
            посещаемости.<br> Количество заходов и идентификаторы пользователей не повторяются. <br> <br> <span style="font-weight:bold;">Требования:</span> 
            <ul>
               <li>Время работы O(N * logK) </li>
               <li>Куча должна быть реализована в виде шаблонного класса. </li>
               <li>Решение должно поддерживать передачу функции сравнения снаружи. </li>
               <li>Куча должна быть динамической. </li>
            </ul>
         </p></span></div>
   <h2>Формат ввода</h2>
   <div class="input-specification"><span style="">
         <p>Сначала вводятся N и K, затем пары <span style="font-style:italic;">(Идентификатор пользователя, посещаемость сайта)</span>. 
         </p></span></div>
   <h2>Формат вывода</h2>
   <div class="output-specification"><span style="">
         <p>Идентификаторы пользователей в порядке возрастания посещаемости. </p></span></div>
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
            <td><pre>3    3
100  36
80   3
1    5</pre></td>
            <td><pre>80 1 100</pre></td>
         </tr>
      </tbody>
   </table>
</div></div>