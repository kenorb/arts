<?php

	$trail				= end (menu_get_active_trail ());
	
	$viewNameOrig	= $view -> query -> pager -> display -> display_title;
	
	$viewName			= strtolower ($viewNameOrig);
	$subdomain 		= '';
	
	$subdomainUserId	= null;//subdomain_get_sid ($subdomain);
	
?>

<h1 class="title">
<?php if ($viewNameOrig == 'User Profile Arts'): ?>
	<?php global $user_content_profile; ?>
	<a href="/users/<?php echo $user_content_profile -> name; ?>"><?php echo $user_content_profile -> name; ?></a>'s arts
<?php else: ?>
	<?php if (substr ($viewName, 0, 7) != 'default'): echo $viewNameOrig; ?><?php endif;?> arts
<?php endif; ?>
</h1>

<?php if ($viewName != 'user profile arts'): ?>
<div class="arts-filters">
	<span class="preface">You can filter by:</span>
	<a href="/arts/most-viewed" class="filter <?php if ($viewName == 'most viewed'): ?>active<?php endif; ?>">Most viewed</a>
	<a href="/arts/most-recent" class="filter <?php if ($viewName == 'most recent'): ?>active<?php endif; ?>">Most recent</a>
	<a href="/arts/best-selling-artists" class="filter <?php if ($viewName == 'best selling artists'): ?>active<?php endif; ?>">Best selling artists</a>
	<a href="/arts/featured-artists" class="filter <?php if ($viewName == 'featured artists'): ?>active<?php endif; ?>">Featured artists</a>
	<a href="/arts/highest-rated" class="filter <?php if ($viewName == 'highest rated'): ?>active<?php endif; ?>">Highest rated</a>
</div>
<?php endif; ?>

<div class="arts-rows">

<?php if ($view -> style_plugin -> rendered_fields): ?>
	<?php foreach ($view -> style_plugin -> rendered_fields as $fieldId => $row): ?>
		<div class="arts-row">
			<div class="image">
				<?php echo $row ['field_image_fid']; ?>
			</div>
				<div class="details">
					<table cellpadding="0" cellspacing="0" border="0">
						<tbody>
							<tr>
								<td class="title">
									<?php echo $row ['title']; ?>
								</td>
								<td class="price">
									<?php echo $row ['name']; ?>
								</td>
							</tr>
							<tr>
								<td class="original-price">
									<b>Original</b> - <?php echo $row ['sell_price']; ?>
								</td>
								<td class="price">
								</td>
							</tr>
						</tbody>
					</table>
				</div>
		</div>
	<?php endforeach; ?>

<?php else: ?>
	<i>We're sorry. No arts here</i>
<?php endif; ?>
	
	<div class="clear"></div>
	
</div>


<?php echo $view -> exposed_widgets; ?>

<?php echo $pager; ?>