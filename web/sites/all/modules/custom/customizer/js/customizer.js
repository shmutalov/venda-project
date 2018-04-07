(function($) {
  Drupal.behaviors.customizer = {
    attach:function (context, settings) {
      //Put scripts into once() to execute them only once.
      $('.node-product-form').once(function () {

        $( ".product-parts-table .income-date-field" ).datepicker({
          format: "dd.mm.yyyy",
          endDate: "today",
          startView: 2,
          maxViewMode: 2,
          clearBtn: true,
          language: "ru",
          orientation: "top auto",
          todayHighlight: true,
          toggleActive: true
		});
          
        $(".product-parts-table .expiry-date-field").datepicker({
          format: "dd.mm.yyyy",
          startView: 2,
          maxViewMode: 2,
          clearBtn: true,
          language: "ru",
          orientation: "top auto",
          todayHighlight: true,
          toggleActive: true
		});
				
        //product node add form submit
        $('#product-node-form').submit(function(){
          if ($(this).find('.product-submit').hasClass('disabled') || $('.field-name-field-md-up-barcode input[type=text]').attr('disabled')) {
            return false;
          }
        });
        
        
				
				//Add a new row
				$('.product-parts-add-row').on('click', function(e){
					e.preventDefault();
					$('.product-parts-table tbody').append('<tr>'+$('.product-parts-table tbody tr:last').html()+'</tr>');
					$('.product-parts-table tbody tr:last input').val('').removeClass('error');
					$('.product-parts-table tbody tr:last input.product-package-qty').val('0');
					$('.product-parts-table tbody tr:last .select-provider select').val($('.product-parts-table tbody tr:last').prev().find('.select-provider select').val());
					$('.product-parts-table tbody tr:last .select-provider select+input').val($('.product-parts-table tbody tr:last').prev().find('.select-provider select+input').val());
					$('.product-parts-table tbody tr:last td.form-item').find('.urge-text').remove();
					$('[data-toggle="tooltip"]').tooltip();
					
					$( ".product-parts-table .income-date-field" ).datepicker({
						format: "dd.mm.yyyy",
						endDate: "today",
						startView: 2,
						maxViewMode: 2,
						clearBtn: true,
						language: "ru",
						orientation: "top auto",
						todayHighlight: true,
						toggleActive: true
					});
					
					$(".product-parts-table .expiry-date-field").datepicker({
						format: "dd.mm.yyyy",
						startView: 2,
						maxViewMode: 2,
						clearBtn: true,
						language: "ru",
						orientation: "top auto",
						todayHighlight: true,
						toggleActive: true
					});
					
					clarify_current_price();
					
					$(".product-parts-table").rowSorter();
				});
				
				$('.product-parts-table').on('keyup', '.product-package-price', function(e){
					if(e.keyCode != 9){
						$(this).parent().find('.urge-text').remove();
					}
                    
                    if(this.value.indexOf('%') !== -1) {
						var val = this.value.split('%');
                        var discount_percent = parseInt(val[0]);
                        if (discount_percent>0) {
                          var count_discount = parseFloat($('.product-opt-price').val())*(1+(discount_percent/100));
                          $(this).val(count_discount);
                        }
					}
    
					clarify_current_price();
				});
                
                $('.product-parts-table').on('change', '.select-branch select', function() {
                  clarify_current_price();
                });
				
				$('.product-parts-table').on('keyup', '.product-opt-price', function(e){
					if(e.keyCode != 9){
						$(this).parent().next().find('.urge-text').remove();
					}
				});
				
				$('.product-parts-table').on('change', '.product-package-price', function() {
					if ($(this).val().length) {
						var opt_price = parseInt($(this).parent().prev().find('input').val());
						if (!isNaN(opt_price)) {
							if (parseInt($(this).val())<opt_price) {
								$(this).parent().append('<label class="urge-text text-warning error">Вы уверены что хотите продать ниже оптовой цены?</label>');
							}
						}
                        
					}
				});
				
				$('.product-parts-table').on('change', '.product-opt-price', function() {
					if ($(this).val().length) {
						var roz_price = parseInt($(this).parent().next().find('input').val());
						if (!isNaN(roz_price)) {
							if (parseInt($(this).val())>roz_price) {
								$(this).parent().next().append('<label class="urge-text text-warning error">Вы уверены что хотите продать ниже оптовой цены?</label>');
							}
						}
					}
				});

      });

      
			//Fill product amount
            setTimeout(function() {
              update_product_title();
            }, 500);
			$('.node-product-form .field-name-field-pr-medicament-title input[type=text], .node-product-form .field-name-field-up-form-type select, .node-product-form .field-name-field-md-up-weight input[type=text], .node-product-form .field-name-field-md-up-amount input[type=text]').on('keyup', function(e){
				update_product_title();
			});
			$('.node-product-form .field-name-field-up-form-type select, .node-product-form .field-name-field-pr-mn-country select, .node-product-form .field-name-field-pr-manufacturer input[type=text]').on('change', function(e) {
				update_product_title();
			});
			
			
			function update_product_title() {
                var product_title = '';
                if ($('.node-product-form .field-name-field-pr-medicament-title input[type=text]').val()!='') {
                  product_title = product_title + $('.node-product-form .field-name-field-pr-medicament-title input[type=text]').val();
                
                  if ($('.node-product-form .field-name-field-md-up-amount input[type=text]').val()!='') {
                    var up_amount = parseInt($('.node-product-form .field-name-field-md-up-amount input[type=text]').val());
                    if (!isNaN(up_amount) && up_amount>1) {
                      product_title = product_title + ' №' + up_amount;
                    }
                  }
                  if ($('.node-product-form .field-name-field-pr-manufacturer input[type=text]').val()!='') {
                    var proizvoditel = $('.node-product-form .field-name-field-pr-manufacturer input[type=text]').val();
                    product_title = product_title + ' ' + proizvoditel;
                  }
                  if ($('.node-product-form .field-name-field-pr-mn-country select').val()!='_none') {
                    var country = $('.node-product-form .field-name-field-pr-mn-country select option:selected').text();
                    product_title = product_title + ' ' + country;
                  }
                }
                
                if (product_title!='') {
                  $('.product-title-sp').text(product_title.capitalize());
                  $('.node-product-form .form-item-title input[type=text]').val(product_title.capitalize());
                } else {
                  $('.product-title-sp').text('_____________________________');
                  $('.node-product-form .form-item-title input[type=text]').val('');
                }
            }
			
			
      		//Check barcode field for integer
			$("body").on('keyup', '.field-name-field-md-up-barcode input, .field-name-field-md-up-amount input', function() {
				this.value = this.value.replace(/[^0-9]/g, '');
			});
			

      //Add drag&drop function to
      $(".product-parts-table").rowSorter({
        handler: "td.sorter span",
        onDrop: function(tbody, row, new_index, old_index) {
          clarify_current_price();
        },
      });
      
      //Remove product when X button is clicked
      $('.product-parts-table').on('click','.remove-line-item',function(e) {
        e.preventDefault();

        var nid = $(this).closest('tr').find('input.product-parts-nid').val();

        if (nid != '') {
          var hidden_input = document.createElement('INPUT');
          $(hidden_input).attr({
              type: 'hidden',
              name: 'batches_delete[]',
            }).val(nid);
          $('.product-parts-container div.products-parts-delete-nids').append(hidden_input);
        }

        if ($('.product-parts-table tbody tr').length>1) {
          $(this).parent().parent().remove();
        } else {
          $(this).parent().parent().find('input').val('');
        }
				
        clarify_current_price();
      });
      
      $('.product-parts-table').on('keyup', '.product-package-qty', function(){
        clarify_current_price();
      });
			
      if ($('.product-parts-table tr').length) {
        clarify_current_price();
      }
			
			
      //Change product status
      $('.product-status > input').on('change', function () {
        var $input = $(this);
        var $label = $(this).parent();

        if ($input.is(':checked')) {
          $label.removeClass('btn-default').addClass('btn-primary');
          $label.find('span').text('Включен');
        } else {
          $label.removeClass('btn-primary').addClass('btn-default');
          $label.find('span').text('Выключен');
        }
      }).trigger('change');



      $('.product-parts-table .select-provider select').each(function() {
        provider_to_waybill($(this));
        
      });
      
      

      //Provider - select "Other" option
      $('.product-parts-table').on('change', '.select-provider select', function() {
        var providers = $(this);
        
        provider_to_waybill(providers);
        
        if (providers.val()=='other') {
          $(this).parent().find('.select-other-input').removeClass('hide');
        } else {
          providers.parent().find('.select-other-input').removeClass('hide').addClass('hide');
        }
      });
      
      
      
      function provider_to_waybill(providers) {
        var waybills = providers.parent().parent().parent().find('.select-waybill select');
        waybills.val(0).attr('disabled',true);
        
        if (providers.val()!='_none') {
          waybills.attr('disabled',false);
          
          waybills.find('option').each(function(){
            if ($(this).val()!=0) {
              var wb_parts = $(this).attr('value').split('-');
              if (wb_parts[0]==providers.val()) {
                $(this).attr('disabled', false);
              } else {
                $(this).attr('disabled', true);
              }
            }
          });
        }
      }
      
      
      function clarify_current_price() {
        var rate_round = parseFloat($('.rate-round').text());
        var rate_round_side = $('.rate-round-side').text();
                
        $('.product-parts-container .product-single-price').text('0');
        $('.product-parts-table tr').removeClass('current-selling-batch');
        $('.product-parts-table tbody tr').each(function(){
          if (parseFloat($(this).find('.product-package-qty').val())>0) {
            $(this).addClass('current-selling-batch');
			prc = 0;
			if ($(this).find('.product-package-price').val()!='') {
              prc = parseFloat($(this).find('.product-package-price').val());
            }
			
            //Check if warehouse and pos the same currencies
            if ($('.warehouse-currency').text()!=$('.pos-currency')) {
              //They are different. Convert from warehouse currency to pos
              if ($('.warehouse-currency').text()=='у.е.') {
                prc = prc * parseFloat($('.current-rate').text());
                //prc = Math.ceil(prc/rate_round)*rate_round;
                
                if (rate_round!='') {
                  if (rate_round == '0.01') {
                    prc = prc.toFixed(2);
                  }
                  if (rate_round == '0.1') {
                    prc = prc.toFixed(1);
                  }
                  if (rate_round == '1') {
                    if (rate_round_side=='ceil') {
                      prc = Math.ceil(prc);
                    }
                    if (rate_round_side=='floor') {
                      prc = Math.floor(prc);
                    }
                    if (rate_round_side=='round') {
                      prc = Math.round(prc);
                    }
                  }
                  if (rate_round == '10') {
                    if (rate_round_side=='ceil') {
                      prc = Math.ceil(prc/10)*10;
                    }
                    if (rate_round_side=='floor') {
                      prc = Math.floor(prc/10)*10;
                    }
                    if (rate_round_side=='round') {
                      prc = Math.round(prc/10)*10;
                    }
                  }
                  if (rate_round == '100') {
                    if (rate_round_side=='ceil') {
                      prc = Math.ceil(prc/100)*100;
                    }
                    if (rate_round_side=='floor') {
                      prc = Math.floor(prc/100)*100;
                    }
                    if (rate_round_side=='round') {
                      prc = Math.round(prc/100)*100;
                    }
                  }
                }
              }
              
              if ($('.warehouse-currency').text()=='сум') {
                prc = prc / parseFloat($('.current-rate').text());
                
                if (rate_round==0.1) {
                  prc = roundNumber(prc, 1);
                }
                
                if (rate_round==0.01) {
                  prc = roundNumber(prc, 2);
                }
                
              }
              
            }
            
            $('.product-parts-container .product-single-price').text(prc);
            return false;
          }
        });
      }
      
      function roundNumber(num, dec) {
        var result = Math.round(num*Math.pow(10,dec))/Math.pow(10,dec);
        return result;
      }
			
      String.prototype.capitalize = function() {
    	return this.charAt(0).toUpperCase() + this.slice(1);
      }

    }
  }
})(jQuery);