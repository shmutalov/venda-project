<div class="container">
  <div class="row">
    <div class="col-md-3">

    </div>
    <div class="col-md-6">
			<br/><br/>
			<div class="login-form-container img-thumbnail">
					<?php print drupal_render($form['form_build_id']); ?>
					<?php print drupal_render($form['form_id']); ?>
					<?php print drupal_render($form['name']); ?>
					<?php print drupal_render($form['pass']); ?>
					<?php print drupal_render($form['captcha']); ?>
					<div class="row">
						<div class="col-md-6">
							<button type="submit" value="<?php print t('Log in'); ?>" name="op" id="edit-submit" class="btn btn-primary form-submit"><?php print t('Log in'); ?></button>
						</div>
						<div class="col-md-6 text-right">
							<a href="<?php print url('user/password'); ?>" data-toggle="tooltip" title="Только менеджеры могут сбросить пароль. Продавцам нужно обратиться к менеджеру.">Забыли пароль?</a>
						</div>
					</div>
			</div>
    </div>
    <div class="col-md-3">

    </div>
  </div>
</div>
<?php if ($_SERVER['HTTP_HOST']=='demo.venda.uz'): ?>
<!-- Small modal -->
<div class="modal fade bs-example-modal-sm" tabindex="-1" role="dialog" aria-labelledby="demoInstruction">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
				<h4 class="modal-title">Доступ для demo-версии</h4>
			</div>
			<div class="modal-body">
				<p>Имя пользователя: <strong>demo</strong><br/>Пароль: <strong>demo</strong></p>
			</div>
		</div>
  </div>
</div>

<script>
	(function($) {
  Drupal.behaviors.cube = {
    attach:function (context, settings) {
			$('.bs-example-modal-sm').modal('show');
		}
	}
})(jQuery);
</script>
<?php endif; ?>