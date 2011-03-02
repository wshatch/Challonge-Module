<?php if($tournaments): ?>
<div id="challonge_tournament_index_container">
  <ul id="challonge_tournament_list">
    <?php foreach($tournaments as $tournament): ?>
        <li class="challonge_tournament_element"><?php print($tournament->title) ?> </li>

    <?php endfor; ?>
  </ul>
  <div id="challonge_tournament_info">
    <!--info to be provided via JQuery --!>
  </div>
<?php else: ?>
   No tournaments to display
<?php endif; ?>
