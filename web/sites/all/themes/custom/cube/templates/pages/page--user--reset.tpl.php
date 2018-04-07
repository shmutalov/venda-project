<div class="container-fluid">
	
	<div class="row page-title-container">
		<div class="col-sm-4 col-xs-3">
      <a class="pos-logo">
        <img src="<?php print $logo; ?>" alt="<?php print t('VENDA'); ?>" title="<?php print t('VENDA'); ?>" data-toggle="tooltip" data-placement="bottom"/>
      </a>
    </div>
		
		<div class="col-sm-4 col-xs-6  text-center">

		</div>
		
		<div class="col-sm-4 col-xs-3 text-right">
			
		</div>
	</div>
		
</div>

<div id="wrapper">

	<div class="main-container container">
	
		<div class="row">
			
			<section class="col-sm-12 main-section">
				<a id="main-content"></a>
				
				<?php print $messages; ?>
				<?php if (!empty($tabs)): ?>
					<?php print render($tabs); ?>
				<?php endif; ?>
        <div class="row">
          <div class="col-md-3">
            
          </div>
          <div class="col-md-6">
            <br/><br/>
            <div class="login-form-container img-thumbnail">
              <div class="h2"><?php print t('Сбросить пароль'); ?></div>
              <br/>
              <?php print render($page['content']); ?>
            </div>
          </div>
          <div class="col-md-3">
            
          </div>
        </div>
				
			</section>

		</div>
		
	</div>

</div>
<div class="progress sell-progress active hide">
  <div class="progress-bar progress-bar-default"></div>
</div>
