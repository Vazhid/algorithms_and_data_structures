<div class="problem-statement">
   <div class="header">
      <h1 class="title">Очередь с динамическим буфером</h1>
      <table>
         <tr class="time-limit">
            <td class="property-title">Ограничение времени</td>
            <td>1&nbsp;секунда</td>
         </tr>
         <tr class="memory-limit">
            <td class="property-title">Ограничение памяти</td>
            <td>10Mb</td>
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
         <p>Реализовать очередь с динамическим зацикленным буфером. </p></span><p>Обрабатывать команды push back и pop front.</p>
   </div>
   <h2>Формат ввода</h2>
   <div class="input-specification"><span style="">
         <p>В первой строке количество команд <span class="tex-math-text">n</span>. <span class="tex-math-text">n &le; 1000000</span>. 
         </p></span><p>Каждая команда задаётся как 2 целых числа: <span class="tex-math-text">a</span> <span class="tex-math-text">b</span>. 
      </p>
      <p>a = 2 - pop front<br> a = 3 - push back 
      </p>
      <p>Если дана команда pop front, то число b - ожидаемое значение. Если команда pop front вызвана для пустой структуры данных,
         то ожидается “-1”. 
      </p>
   </div>
   <h2>Формат вывода</h2>
   <div class="output-specification"><span style="">
         <p>Требуется напечатать YES - если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не оправдалось, то напечатать
            NO.
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
            <td><pre>3
3 44
3 50
2 44
</pre></td>
            <td><pre>YES
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
            <td><pre>2
2 -1
3 10
</pre></td>
            <td><pre>YES
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
            <td><pre>2
3 44
2 66
</pre></td>
            <td><pre>NO
</pre></td>
         </tr>
      </tbody>
   </table>
</div>