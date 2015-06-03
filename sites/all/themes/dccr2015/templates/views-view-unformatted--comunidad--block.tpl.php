<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<?php foreach ($rows as $id => $row): ?>

  <?php if ($id == 0) { ?>
    <? print '<div class="comunidad-superior">'; ?>
      <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
        <?php print $row; ?>
      </div>
    <?php } else { ?>

      <?php if ($id == (round(count($rows)/2)-1)) { ?>

        <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
          <?php print $row; ?>
        </div>

      <?php } else { ?>
        <?php print '</div> <div class="comunidad-inferior">'; ?>
        <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
          <?php print $row; ?>
        </div>
      <?php } ?>
  <?php } ?>

  <?php if ($id == (count($rows)-1)) { ?>
    <? print '</div>'; ?>
  <?php } ?>

<?php endforeach; ?>





