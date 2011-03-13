<?php
  if($error):
?>
<h2> There was a problem joining the tournament </h2>
<p> <?php print($error) ?> </p>
<?php
  else:
?>
<h2> You have sucessfully been added to the tournament. </h2>
<?php endif ?>
