var s = `<footer id="footer">

<div class="w1200">

 <div class="logo">

          <img src="/html/_skin/seil/img/main/footerlogo.png" alt="sgo">

      </div>

  <div class="footer_cont">

      <div class="footer_tab">

          <button class="tablinks" onclick="openCity(event, &#39;location01&#39;)">本社と工場</button>

          <button class="tablinks" onclick="openCity(event, &#39;location02&#39;)">ソウル支店</button>

          <button class="tablinks" onclick="openCity(event, &#39;location03&#39;)">京畿支店</button>

          <button class="tablinks" onclick="openCity(event, &#39;location04&#39;)">南部ポイント</button>

      </div>



      <div id="location01" class="tabcontent active">

          <div class="info">

              <p>㈱SGO 代表 : Choi Taesu 事業者登録番号 : 134-81-61935 Email : info@sgoilless.co.kr</p>

              <p>本社と工場 : 28-10, Namdongseo-ro 113beon-gil, Namdong-gu, Incheon, Republic of Korea Tel.+82-32-813-3401 Fax.+82-32-813-4259</p>

          </div>

      </div>



      <div id="location02" class="tabcontent">

         <p>ソウル支店</p>

          <p>Badong 1216-1217, 15, Gyeongin-ro 53-gil, Guro-gu, Seoul, Republic of Korea Tel.+82-2-2614-8837 Fax.+82-2-2614-8878</p>

      </div>

      <div id="location03" class="tabcontent">

        <p>京畿支店</p>

          <p>8 Tool Stores #120, 244, Gongdan 1-daero, Siheung-si, Gyeonggi-do, Republic of Korea Tel.+82-31-430-3494 Fax.+82-31-430-3495</p>

      </div>



      <div id="location04" class="tabcontent">

        <p>京畿支店</p>

          <p>21, Wollim-ro 39beon-gil, Seongsan-gu, Changwon-si, Gyeongsangnam-do, Republic of Korea Tel.+82-55-262-3401 Fax.+82-55-262-3403</p>

      </div>

      <div class="copy">

          <p>Copyright©SGO. All RIGHT RESERVED.</p>

      </div>

  </div>

  </div>

</footer>



<script>

  function openCity(evt, cityName) {

      var i, tabcontent, tablinks;

      tabcontent = document.getElementsByClassName("tabcontent");

      for (i = 0; i < tabcontent.length; i++) {

          tabcontent[i].style.display = "none";

      }

      tablinks = document.getElementsByClassName("tablinks");

      for (i = 0; i < tablinks.length; i++) {

          tablinks[i].className = tablinks[i].className.replace(" active", "");

      }

      document.getElementById(cityName).style.display = "block";

      evt.currentTarget.className += " active";

  }

</script>`;

console.log(s.length);