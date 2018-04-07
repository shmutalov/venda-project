<?php global $user;
$rate = config_pages_get('li'.'c'.'ense','field_exchange_rate',0);
$warehouse_currency = config_pages_get('li'.'c'.'ense','field_currency_warehouse','сум');
$pos_currency = config_pages_get('li'.'c'.'ense','field_currency_pos','сум');
$rate_round = config_pages_get('li'.'c'.'ense','field_rate_round',1);

?>
<div class="pos-terminal">
  <div class="form-item form-type-textfield form-group search-medicament hide-on-print">
    <input type="text" placeholder="Поиск продуктов по названиям или по штрих-коду" class="form-control input-lg form-text required search-md-input">
    <a href="#" class="add-to-deny-list btn btn-primary btn-lg disabled" data-toggle="tooltip" title="Добавить в отказной лист - CTRL+O">+</a>
  </div>

  <div class="row">
    <div class="col-md-8 hide-on-print">
      <div class="panel panel-default">
        <div class="panel-heading h4"><?php print t('Продукты'); ?></div>
        <div class="panel-body sell-products-container">
          <table class="check-product-table table table-condensed">
            <tbody></tbody>
          </table>
          <p class="no-product-row-text">Продукты ещё не добавлены...</p>
          <hr/>
          <div class="row">
            <div class="col-sm-6">
              <div class="client-name-input"><input type="text" placeholder="Имя клиента" class="form-control form-text input-sm client-md-input"></div>
            </div>
            <div class="col-sm-6">
              <div class="total-amount-wrapper text-right h4"><?php print t('Итого'); ?>: <span class="total-price text-strong h1">0</span> сум</div>
            </div>
          </div>
          
        </div>
        <div class="panel-footer clearfix sell-action-buttons">
          <div class="row">
            <div class="col-sm-3 text-left">
              <a href="#" class="clear-line-items btn btn-danger btn-xs-block disabled"><?php print t('Очистить F4'); ?></a>
            </div>
            <div class="col-sm-9 text-right">
              <a href="#" class="pay-for-products btn btn-info btn-xs-block pay-by-owe disabled" data-payby="10342"><?php print t('Долг F7'); ?></a>
              <a href="#" class="pay-for-products btn btn-primary btn-xs-block pay-by-card disabled" data-payby="9729"><?php print t('Терминал F6'); ?></a>
              <a href="#" class="pay-for-products btn btn-success btn-xs-block pay-by-cash disabled" data-payby="9730"><?php print t('Наличные F10'); ?></a>
              <a href="#" class="btn btn-warning btn-xs-block open-breakdown-modal disabled" data-toggle="modal" data-target="#pay_breakdown_modal"><?php print t('Разделить'); ?></a>
            </div>
          </div>
        </div>
 </div>
    </div>

    <div class="col-md-4">
      <div>
        <div class="check-container printed" id="check_container">
          <h4>
            <?php if (isset($account['main']->field_firm_name[LANGUAGE_NONE][0]['value'])): ?>
            <span class="firm-name">
              <?php print $account['main']->field_firm_name[LANGUAGE_NONE][0]['value']; ?></span><br/>
            <?php endif; ?>

            <span class="apteka-name">
              <?php
                if (isset($account['main']->field_apteka_name[LANGUAGE_NONE][0]['value'])) {
                  print $account['main']->field_apteka_name[LANGUAGE_NONE][0]['value'];
                } elseif (isset($account['main']->field_apteka_contact[LANGUAGE_NONE][0]['value'])) {
                  print $account['main']->field_apteka_contact[LANGUAGE_NONE][0]['value'];
                }
              ?>
            </span>
          </h4>
          <div class="receipt-products-list">
            <div class="pull-left kassir">Продавец: <?php print $user->name; ?></div>
            <div class="check-no pull-right">Чек №<span class="check-inc">__</span></div>
            <div class="clearfix"></div>
            <ul>
              <li class="text-center">Нажмите <strong>Терминал</strong> или <strong>Наличные</strong> чтобы сгенерировать чек...</li>
            </ul>
          </div>
          <div class="check-total text-right"></div>
          <div class="total-cash text-right"></div>
          <div class="total-card text-right"></div>
          <div class="total-owe text-right"></div>
          <div class="check-posted-date text-center"></div>
          <h4 class="thanks-text text-center">СПАСИБО ЗА ПОКУПКУ!</h4>
        </div>
      </div>

      <div class="row check-receipt hide-on-print">
        <div class="col-xs-6">
            <label data-toggle="tooltip" data-placement="top" title="Если Вы отметите этот пункт, установленный чековый принтер будет печатать чек автоматически.">
              <input type="checkbox" class="auto-print-receipt"> Авто.печать
            </label>
          <?php
            $autobarcode = 1;
            if (isset($_COOKIE['autobarcode'])) {
              $autobarcode = $_COOKIE['autobarcode'];
            } ?>
          <div class="barcode-setting hide">
            <label>
              <input type="checkbox" class="auto-barcode-add"<?php if ($autobarcode): ?> checked<?php endif; ?>>Добавить продукт автоматически по штрих кодам
            </label>
          </div>
          
          <div class="hide"><span class="current-rate"><?php print $rate; ?></span> сум</div>
          <span class="hide warehouse-currency"><?php print $warehouse_currency; ?></span>
          <span class="hide pos-currency"><?php print $pos_currency; ?></span>
          <span class="hide rate-round"><?php print $rate_round; ?></span>
        </div>
        <div class="col-xs-6 text-right">
            <button type="submit" class="btn btn-primary btn-sm print-check-manually disabled"><span class="glyphicon glyphicon-print"></span> Печать чека</button>
        </div>
      </div>
    </div>
  </div>
  
  <?php if (isset($_GET['date'])) : ?>
    <div class="sell-protect-layer">
      <h4><?php print t('Прежде чем продолжить продажу,<br/>пожалуйста нажмите <strong>Отменить</strong> кнопку чтобы очистить дата фильтр.'); ?></h4>
    </div>
  <?php endif; ?>
</div>

<!-- Modal -->
<div class="modal fade" id="pay_breakdown_modal" tabindex="-1" role="dialog" aria-labelledby="pay_breakdown_modal_label">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="pay_breakdown_modal_label">Разделить платеж</h4>
      </div>
      <div class="modal-body">
        <div class="form-horizontal">
          <div class="form-group">
            <label for="input-terminal" class="col-sm-2 control-label">Терминал</label>
            <div class="col-sm-10">
              <input type="text" class="split-input form-control input-terminal" id="input-terminal" value="0">
            </div>
          </div>
          <div class="form-group">
            <label for="input-cash" class="col-sm-2 control-label">Наличные</label>
            <div class="col-sm-10">
              <input type="text" class="split-input form-control input-cash" id="input-cash" value="0">
            </div>
          </div>
          <div class="form-group">
            <label for="input-cash" class="col-sm-2 control-label">Долг</label>
            <div class="col-sm-10">
              <div class="row">
                <div class="col-sm-6"><input type="text" class="split-input form-control input-owe" id="input-owe" value="0"></div>
                <div class="col-sm-6 client-name-input-2"><input type="text" placeholder="Имя клиента" class="form-control form-text client-md-input-2"></div>
              </div>
              
            </div>
          </div>
        </div>
        <div class="pay-breakdown-error text-danger hide">Общая сумма должна быть равна <span class="input-total-text text-strong">0</span> <?php print $pos_currency; ?>. 
          Сейчас общая сумма <span class="input-total-current text-strong">0</span> <?php print $pos_currency; ?></div>
          <div class="remaining-container text-danger hide">Ещё <span class="input-total-remaining text-strong">0</span> <?php print $pos_currency; ?> нужно добавлять</div>
      </div>
      <div class="modal-footer">
        <input type="hidden" class="form-control input-total" value="0">
        <div class="row">
          <div class="col-xs-6 text-left">
          	<button type="button" class="btn btn-default" data-dismiss="modal">Закрыть</button>
          </div>
          <div class="col-xs-6 text-right">
          	<button type="button" data-payby="9732" data-dismiss="modal" class="btn btn-primary pay-for-products pay-by-breakdown">Оплатить</button>
        	</div>
      	</div>
    	</div>
    </div>
  </div>
</div>



<!-- Refund popup -->
<div class="modal fade refund_modal" id="refund_modal" tabindex="-1" role="dialog" aria-labelledby="refund_modal_label">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="refund_modal_label">Возврат товара по чек №<span class="modal-check-no">___</span></h4>
      </div>
      <div class="modal-body">
        <div class="form-horizontal refund-products-list">

				</div>
				<div class="refund-reason form-item">
					<textarea class="form-control" rows="3" class="refund-reason-textarea" placeholder="Причина возврата"></textarea>
				</div>
				<hr/>
				<div class="text-right h4">
					Итого для возврата: <span class="refund-total strong">_____</span> сум
				</div>
      </div>
      <div class="modal-footer">
				<input type="hidden" class="form-control input-total" value="0">
				<div class="row">
					<div class="col-sm-4 text-left hidden-xs">
						<button type="button" class="btn btn-default" data-dismiss="modal">Закрыть</button>
					</div>
					<div class="col-sm-8 text-right">
            <button type="button"  data-dismiss="modal" class="btn btn-info btn-xs-block transaction-refund transaction-refund-owe">Долг</button>
            <button type="button"  data-dismiss="modal" class="btn btn-primary btn-xs-block transaction-refund transaction-refund-terminal">Терминал</button>
            <button type="button"  data-dismiss="modal" class="btn btn-success btn-xs-block transaction-refund transaction-refund-cash">Наличные</button>
					</div>
				</div>
			</div>
    </div>
  </div>
</div>



<!-- Discount popup -->
<div class="modal fade product_discount_modal" id="product_discount_modal" tabindex="-1" role="dialog" aria-labelledby="product_discount_modal_label">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="product_discount_modal_label">Скидка на "<span class="modal-product-title">___</span>"</h4>
      </div>
      <div class="modal-body">
        <div class="form-horizontal">
          <div class="form-group">
            <label for="input-discount" class="col-sm-3 control-label">Скидка</label>
            <div class="col-sm-9">
              <input type="text" class="form-control input-discount" id="input-discount" value="0">
            </div>
          </div>
          <div class="form-group">
            <label for="input-discount-price" class="col-sm-3 control-label">Цена со скидкой</label>
            <div class="col-sm-9">
              <input type="text" class="form-control input-discount-price" id="input-discount-price" value="0">
              <input type="hidden" class="input-max" value="0">
              <input type="hidden" class="input-discount-nid" value="0">
              <p class="text-muted">Оптовая цена: <span class="input-opt-price">0</span> сум</p>
            </div>
          </div>
        </div>
      </div>
      <div class="modal-footer">
				<div class="row">
					<div class="col-sm-6 text-left">
						<button type="button" class="btn btn-default" data-dismiss="modal">Закрыть</button>
					</div>
					<div class="col-xs-6 text-right">
            <button type="button"  data-dismiss="modal" class="btn btn-primary product-discount">Сохранить</button>
					</div>
				</div>
			</div>
    </div>
  </div>
</div>



<!-- Product missing popup -->
<div class="modal fade product_missing_modal" id="product_missing_modal" tabindex="-1" role="dialog" aria-labelledby="product_missing_modal_label">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="product_discount_modal_label">Не осталось на складе</h4>
      </div>
      <div class="modal-body">
        <div class="product-missing-text"><strong>___</strong> не осталось на вашем складе.</div>
      </div>
      <div class="modal-footer">
				<div class="row">
					<div class="col-sm-6 text-left">
						<a href="#" class="btn btn-primary add-to-deny-list-alert">Добавить в отказной лист</a>
					</div>
					<div class="col-xs-6 text-right">
            <button type="button" class="btn btn-default" data-dismiss="modal">Закрыть</button>
					</div>
				</div>
			</div>
    </div>
  </div>
</div>


<!-- Owe return popup -->
<div class="modal fade owe_return_modal" id="owe_return_modal" tabindex="-1" role="dialog" aria-labelledby="owe_return_modal">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="refund_modal_label">Вернуть долг</h4>
      </div>
      <div class="modal-body">
        <div class="form-horizontal">
          <div class="form-group owe-return-data">
            <label for="owe-return-amount" class="col-sm-3 control-label">Сумма долга</label>
            <div class="col-sm-9">
              <input type="text" class="form-control owe-return-amount" id="owe-return-amount" value="0">
            </div>
          </div>
        </div>
      </div>
      <div class="modal-footer">
				<input type="hidden" class="form-control input-total" value="0">
				<div class="row">
					<div class="col-sm-4 text-left hidden-xs">
						<button type="button" class="btn btn-default" data-dismiss="modal">Закрыть</button>
					</div>
					<div class="col-sm-8 text-right">
            <button type="button"  data-dismiss="modal" class="btn btn-primary btn-xs-block owe-return owe-return-terminal">Терминал</button>
            <button type="button"  data-dismiss="modal" class="btn btn-success btn-xs-block owe-return owe-return-cash">Наличные</button>
					</div>
				</div>
			</div>
    </div>
  </div>
</div>