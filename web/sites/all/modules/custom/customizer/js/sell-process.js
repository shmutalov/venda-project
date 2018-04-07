(function($) {
  Drupal.behaviors.sellProcess = {
    attach:function (context, settings) {
      //Put scripts into once() to execute them only once.
      $('body').once(function () {

      });

      $(".transactions-container .tr-date-filter-input").datepicker({
        format: "yyyy-mm-dd",
        startView: 2,
        maxViewMode: 2,
        clearBtn: true,
        language: "ru",
        orientation: "top auto",
        todayHighlight: true,
        toggleActive: true
      });

      //Search by product title
      var products = new Bloodhound({
        datumTokenizer: Bloodhound.tokenizers.obj.whitespace('title'),
        queryTokenizer: Bloodhound.tokenizers.whitespace,
        local: $.map(array_products, function(value, index) {
          return value;
        })
      });

      //Search by barcode
      var barcode = new Bloodhound({
        datumTokenizer: Bloodhound.tokenizers.obj.whitespace('barcode'),
        queryTokenizer: Bloodhound.tokenizers.whitespace,
        local: $.map(array_products, function(value, index) {
          return value;
        })
      });

      //Enable the autocomplete search field
      $('.search-md-input').typeahead(
        {
          autoselect: true,
          hint: true,
          highlight: true,

        },
        {
          name: 'products-title',
          display: 'title',
          source: products,
          minLength: 1,
          limit: 20,
        },
        {
          name: 'products-barcode',
          display: 'title',
          minLength: 6,
          source: barcode
        }
      );



      var clients = new Bloodhound({
        datumTokenizer: Bloodhound.tokenizers.whitespace,
        queryTokenizer: Bloodhound.tokenizers.whitespace,
        local: array_clients
      });

      //Enable the autocomplete in client field
      $('.client-md-input').typeahead({
        hint: true,
        highlight: true,
        minLength: 1
      },
      {
        name: 'clients',
        source: clients
      });

      //Enable the autocomplete in client field
      $('.client-md-input-2').typeahead({
        hint: true,
        highlight: true,
        minLength: 1
      },
      {
        name: 'clients',
        source: clients
      });

      //check barcode event
      $(document).pos();
      $(document).on('scan.pos.barcode', function(event){
          if(!$('.search-md-input').is(':focus')) {
            if (!$('input').is(':focus')) {
            $('.search-md-input').typeahead('val', "");
            $('.search-md-input').typeahead('val', event.code);
            $('.search-md-input').focus();
            }
          } else {
            $('.search-md-input').typeahead('val', "");
            $('.search-md-input').typeahead('val', event.code);
          }
          if ($('.auto-barcode-add').is(':checked')) {
            setTimeout(function() {
              $('.search-medicament .tt-dataset-products-barcode .tt-suggestion:first').trigger('click');
            }, 300);
          }
      });

      //Focus on main search field
      $('.search-md-input').focus();



      //Calculate total transactions
      calculate_total_transactions();



      //Set focus after closing the modal by ESC
      $(document).keyup(function(e) {
		if (e.keyCode === 27) {
          setTimeout(function() {
			$('.search-md-input').val('').focus();   // esc
          }, 500);
        }
      });



      //Set focus after closing the modal by clicking x button
      $('.add-product-modal .modal-header button').on('click', function(e) {
		setTimeout(function() {
          $('.search-md-input').val('').focus();
		}, 500);
      });



      //Check if barcode has scanned
      $('.search-md-input').on('keyup', function(e) {

        if (Drupal.behaviors.cube.isInt($(this).val()) && $(this).val().length>9 && $('.search-medicament .tt-dataset-products-barcode .tt-suggestion').length==1) {
          if ($('.auto-barcode-add').is(':checked')) {
			     $('.search-medicament .tt-dataset-products-barcode .tt-suggestion:first').trigger('click');
            $('.search-md-input').empty();
			       return false;
          } else {
      			$('.search-md-input').typeahead('val', $('.search-medicament .tt-dataset-products-barcode .tt-suggestion').text());
      			$('.search-md-input').typeahead('close');
          }
        }

        $('.add-to-deny-list').removeClass('disabled');
        if ($.trim($(this).val())=='') {
          $('.add-to-deny-list').addClass('disabled');
        }

        if(e.keyCode == 13){
          $('.search-medicament .tt-dataset-products-title .tt-suggestion:first').trigger('click');
          return false;
        }

      });


      //Behavior after selecting a product
      $('.search-md-input').bind('typeahead:select', function(ev, suggestion) {
        product_addto_basket(suggestion);

				//Remove popovers if they are opened
        $('body .popover').popover('hide');
      });



      //Adds the product to cart from search field
      function product_addto_basket(suggestion) {
        var single_price = suggestion.price;
        var single_base_price = suggestion.base_price;
        var total_qty = suggestion.product_qty;
        var product_title = suggestion.title.replace(/\[.*?\]/g,''); //remove [на складе: ...]
        product_title = product_title.replace(/\([0-9\.]+.*?\)/g,''); //remove (... сум)
        product_title = product_title.replace(/\{.*?\}/g,''); //remove {срок: ...}

        //Recount product quantity
        var recount_array = recount_product_warehouse(suggestion.nid, 1, 'add'); //
        mqty = recount_array.mqty;
        var data_batches = recount_array.batches_qty;
        var data_batches_warehouse = recount_array.batches_qty_inwarehouse;

        if (mqty>0) {
          var exist_in_table = false;
          if ($('.check-product-table tbody tr').length>0) {
            $('.check-product-table tbody tr').each(function(){
              if ($(this).attr('data-nid')==suggestion.nid) {

                var input_obj = $(this).find('.product-qty-input');
                if (input_obj.hasClass('product-by-pcs')) {
                  input_obj.val(parseFloat(input_obj.val())+parseFloat(suggestion.pack_amount));
                } else {
                  input_obj.val(parseFloat(input_obj.val())+parseFloat(mqty));
                }
                input_obj.attr('data-old-qty', mqty);
                input_obj.parent().find('.data-batches-qty').text(data_batches);

                if ($('.product-discount-price-input').val()!='') {
                  $(this).find('.product-discount-price-input').val(parseInt($(this).find('.product-discount-price-input').val())+parseInt(suggestion.price));
                }

                $(this).find('.product-price-input').val(parseFloat($(this).find('.product-price-input').val())+parseFloat(suggestion.price));
                $(this).find('.product-base-price-input').val(parseFloat($(this).find('.product-base-price-input').val())+parseFloat(suggestion.base_price));
                exist_in_table = true;
                $(this).removeAttr('style').fadeIn();
              }
            });
          }

          if (!exist_in_table) {
            $('.check-product-table tbody').append('<tr class="not-shown clearfix" data-nid="'+suggestion.nid+'">'+
              '<td class="product-name">'+product_title+'</td>'+
              '<td class="product-qty">'+
              '  <div class="input-group input-group-sm">'+
              '    <input type="text" class="form-control form-text product-qty-input product-by-pkg" data-old-qty="'+mqty+'" value="'+mqty+'" min="0" max="'+total_qty+'" step="1" data-max="'+total_qty+'" data-pcs-amount="'+suggestion.pack_amount+'"/>'+
              '    <a href="#" class="input-group-addon btn-primary by-package-btn">уп.</a>'+
              '    <a href="#" class="hide input-group-addon btn-primary by-sht-btn">шт.</a>'+
              '    <a href="#" class="btn btn-warning input-group-addon open-batches-list" title="Изменить количество из партии"><span class="glyphicon glyphicon-th-list"></span></a>'+
              '    <a href="#" class="btn btn-danger input-group-addon open-discount-modal" title="Сделать скидку"><span class="glyphicon glyphicon-tag"></span></a>'+
              '    <span class="hide data-batches-qty">'+data_batches+'</span>'+
              '    <span class="hide data-batches-warehouse">'+data_batches_warehouse+'</span>'+
              '    <div class="hide batches-list-container"></div>'+
              '  </div>'+
              '</td>'+
              '<td class="product-price clearfix">'+
              '  <div class="pull-right product-currency">' + $('.pos-currency').text() + '</div>'+
              '  <div class="pull-right">'+
              '    <input type="text" class="form-control form-text product-discount-price-input" value="" readonly="readonly">'+
              '    <input type="text" class="form-control form-text product-price-input" value="'+suggestion.price+'" readonly="readonly"/>'+
              '    <input type="hidden" class="form-text product-base-price-input" value="'+suggestion.base_price+'"/>'+
              '  </div>'+
              '</td>'+
              '<td class="product-actions text-right">'+
              '  <a href="#" class="h3 remove-line-item"><span class="glyphicon glyphicon-remove-sign text-danger"></span></a>'+
              '</td>'+
            '</tr>');

            if ($('.check-product-table tbody tr').length>0) {
              $('.no-product-row-text').addClass('hide');
              $('.check-product-table tbody tr').fadeIn('fast').delay(500).removeAttr('style').removeClass('not-shown');

              if (!exist_in_table && $('.check-product-table tbody tr').length==1) {
                $('.receipt-products-list ul').empty().append('<li class="text-center">Нажмите <strong>Терминал</strong> или <strong>Наличные</strong> чтобы сгенерировать чек...</li>');
                $('.check-total, .check-posted-date, .total-cash, .total-owe, .total-card').empty();
                $('.receipt-products-list').css('display','none').fadeIn();
              }
            }
          }

          //Focus on quantity field
          setTimeout(function(){
            $('.check-product-table tr[data-nid='+suggestion.nid+'] .product-qty-input').focus().select();
          }, 400);

          //Update product batches list
          update_batches_list(suggestion.nid, data_batches, data_batches_warehouse);

          calculate_total_price();

          $('.add-to-deny-list').removeClass('disabled').addClass('disabled');
        }
        $('.search-md-input').typeahead('val', '');
      }



      function update_batches_list(product_nid, data_batches, data_batches_warehouse) {

        //Create a batches list form
        var batches_list = $.parseJSON(data_batches);
        var batches_list_warehouse = $.parseJSON(data_batches_warehouse);
        var batches_container = $('.check-product-table [data-nid='+product_nid+'] .batches-list-container');

        var cur_batch_sum, max_batch_qty;
        batches_container.empty();
        for (var k in batches_list) {
          cur_batch_sum = parseFloat(batches_list_warehouse[k].price)*parseFloat(batches_list[k]);
          max_batch_qty = parseFloat(batches_list_warehouse[k].qty)+parseFloat(batches_list[k]);
          batches_container.append('<div class="input-group input-group-sm batches-list-wrapper" data-product-nid="' + product_nid + '">' +
            '<input type="text" class="form-control form-text batch-qty-input" value="' + batches_list[k] + '" data-batch-nid="' + k + '"/>' +
            '<span class="input-group-addon batch-qty-separator">из</span>' +
            '<span class="input-group-addon max-batch-qty">' + max_batch_qty + '</span>' +
            '<span class="input-group-addon cur-batch-sum" data-batch-single="' + parseFloat(batches_list_warehouse[k].price) + '" data-batch-single-base="' + parseFloat(batches_list_warehouse[k].base_price) + '">' + cur_batch_sum + ' ' + $('.pos-currency').text() + '</span>' +
            '</div>');
        }

        $('.check-product-table [data-nid='+product_nid+'] .open-batches-list').popover({
          html : true,
          content: function() {
            return batches_container.html();
          },
          placement: 'bottom',
          container: 'body',
        }).popover('hide');
      }



      //Decrease the product from warehouse.
      function recount_product_warehouse(current_nid, mqty, action, old_qty) {

        var qld = mqty;
        var price, base_price, batches_qty = {}, batches_qty_inwarehouse = {};

        if ($('.check-product-table tbody tr[data-nid='+current_nid+']').length>0) {
          batches_qty = $.parseJSON($('.check-product-table tbody tr[data-nid='+current_nid+'] .data-batches-qty').text());

        }

        if (action=='add') {
          //If product is going to be added from search, its quantity will be max 1 or left quantity of the product
          if (array_products[current_nid].product_qty>=1) {
            mqty = qld = 1;
          } else {
            mqty = qld = array_products[current_nid].product_qty;
          }
        }

        var cur_price = 0;
        var price_set = false;
        var v = 0, first_batch = 0;

        if (action=='edit' || action=='remove') {
          array_products[current_nid].product_qty = array_products[current_nid].product_qty_orig;
          array_products[current_nid].batches = $.deepclone(array_products[current_nid].batches_orig);

          for (var n in array_products[current_nid].batches) {
            if (array_products[current_nid].batches[n].qty>0 && !price_set) {
              cur_price = array_products[current_nid].batches[n].price;
              price_set = true;
            }

            if (v===0) {
              first_batch = array_products[current_nid].batches[n].price;
            }

            v=v+1;
          }

          if (cur_price===0) {
            cur_price = first_batch;
          }
        }

        if (action!='remove') {

          if (array_products[current_nid].product_qty>0) {
            array_products[current_nid].price = array_products[current_nid].base_price = 0;

            array_products[current_nid].product_qty = (parseFloat(array_products[current_nid].product_qty)-qld).toFixed(4);

            for (var n in array_products[current_nid].batches) {
              batch = array_products[current_nid].batches[n];
              if (typeof batches_qty[n]=='undefined') {
                batches_qty[n] = 0;
              }

              if (qld>0) {
                batch.qty = parseFloat(batch.qty);
                if (batch.qty>=qld) {
                  array_products[current_nid].batches[n].qty = array_products[current_nid].batches[n].qty - qld;
                  array_products[current_nid].price = array_products[current_nid].price + array_products[current_nid].batches[n].price * qld;
                  array_products[current_nid].base_price = array_products[current_nid].base_price + array_products[current_nid].batches[n].base_price*qld;

                  if (action=='add') {
                    batches_qty[n] = parseFloat(batches_qty[n]) + parseFloat(qld);
                  } else {
                    batches_qty[n] = parseFloat(qld);
                  }

                  qld = 0;

                } else if (batch.qty>0 && batch.qty<qld) {
                  array_products[current_nid].price = array_products[current_nid].price + array_products[current_nid].batches[n].price*batch.qty;
                  array_products[current_nid].base_price = array_products[current_nid].base_price + array_products[current_nid].batches[n].base_price*batch.qty;

                  qld = (qld-batch.qty).toFixed(4);

                  if (action=='add') {
                    batches_qty[n] = parseFloat(batches_qty[n]) + batch.qty;
                  } else {
                    batches_qty[n] = batch.qty;
                  }

                  array_products[current_nid].batches[n].qty = 0;

                } else {
                  //Nothing to do if batch has no products
                }

              } else {
                batches_qty[n] = 0;
              }

              price = array_products[current_nid].price;
              base_price = array_products[current_nid].base_price;

              if (rate_round!='') {
                if (rate_round == '0.01') {
                  price = price.toFixed(2);
                  base_price = base_price.toFixed(2);
                }
                if (rate_round == '0.1') {
                  price = price.toFixed(1);
                  base_price = base_price.toFixed(1);
                }
                if (rate_round == '1') {
                  if (rate_round_side=='ceil') {
                    price = Math.ceil(price);
                    base_price = Math.ceil(base_price);
                  }
                  if (rate_round_side=='floor') {
                    price = Math.floor(price);
                    base_price = Math.floor(base_price);
                  }
                  if (rate_round_side=='round') {
                    price = Math.round(price);
                    base_price = Math.round(base_price);
                  }
                }
                if (rate_round == '10') {
                  if (rate_round_side=='ceil') {
                    price = Math.ceil(price/10)*10;
                    base_price = Math.ceil(base_price/10)*10;
                  }
                  if (rate_round_side=='floor') {
                    price = Math.floor(price/10)*10;
                    base_price = Math.floor(base_price/10)*10;
                  }
                  if (rate_round_side=='round') {
                    price = Math.round(price/10)*10;
                    base_price = Math.round(base_price/10)*10;
                  }
                }
                if (rate_round == '100') {
                  if (rate_round_side=='ceil') {
                    price = Math.ceil(price/100)*100;
                    base_price = Math.ceil(base_price/100)*100;
                  }
                  if (rate_round_side=='floor') {
                    price = Math.floor(price/100)*100;
                    base_price = Math.floor(base_price/10)*10;
                  }
                  if (rate_round_side=='round') {
                    price = Math.round(price/100)*100;
                    base_price = Math.round(base_price/100)*100;
                  }
                }
              }

              if (array_products[current_nid].batches[n].qty>0 && !price_set) {
                cur_price = array_products[current_nid].batches[n].price;
                price_set = true;
              }

              if (v===0) {
                first_batch = array_products[current_nid].batches[n].price;
              }

              v=v+1;
            }

            if (cur_price===0) {
              cur_price = first_batch;
            }

            batches_qty_inwarehouse = array_products[current_nid].batches;

          } else {
            $('.product_missing_modal').find('.product-missing-text strong').text(array_products[current_nid].title.replace(/\[.*?\]/g,''));
            $('.product_missing_modal').modal('show');

          }


        }

        array_products[current_nid].title = array_products[current_nid].title.replace(/\[.*?\]/g,'[на складе: '+(array_products[current_nid].product_qty)+']');
        array_products[current_nid].title = array_products[current_nid].title.replace(/\([0-9\.]+.*?\)/g,'(' + cur_price + ' ' + $('.pos-currency').text() + ')');

        return {'mqty':mqty, 'price':price, 'base_price':base_price, 'batches_qty': JSON.stringify(batches_qty), 'batches_qty_inwarehouse': JSON.stringify(batches_qty_inwarehouse)};
      }



      //Change quantity from package to piece
      $('.check-product-table').on('click','.by-package-btn', function(e){
        e.preventDefault();
        $(this).parent().find('.by-sht-btn').removeClass('hide');
        $(this).addClass('hide');

        var input_obj = $(this).parent().find('.product-qty-input');
				if (input_obj.val()!='') {
					var pc_val = parseFloat(input_obj.val())*parseFloat(input_obj.attr('data-pcs-amount'));
					if (pc_val<1) {
						pc_val = 1;
					}
					input_obj.val(parseInt(pc_val));
				}
        input_obj.attr('step',input_obj.attr('data-pcs-amount'));
        input_obj.attr('max',parseFloat(input_obj.attr('data-max'))*parseFloat(input_obj.attr('data-pcs-amount')));
        input_obj.removeClass('product-by-pkg').addClass('product-by-pcs').select();
      });



      //Change quantity from piece to package
      $('.check-product-table').on('click','.by-sht-btn',function(e){
        e.preventDefault();
        $(this).parent().find('.by-package-btn').removeClass('hide');
        $(this).addClass('hide');

        var input_obj = $(this).parent().find('.product-qty-input');
				if (input_obj.val()!='') {
					input_obj.val((parseFloat(input_obj.val())/parseFloat(input_obj.attr('data-pcs-amount'))).toFixed(4));
				}
        input_obj.attr('step',1);
        input_obj.attr('max',input_obj.attr('data-max'));
        input_obj.removeClass('product-by-pcs').addClass('product-by-pkg').select();
      });



      //Change price when quantity is changed
      $('.check-product-table').on('keyup mouseup paste','.product-qty-input',function(e) {
				var qty = 0;

        if ($(this).hasClass('product-by-pkg')) {
          if (!isNaN($(this).val())) {
            qty = parseFloat($(this).val());
            if (isNaN(qty)) {
              qty = 0;
            }
          } else {
            qty = 0;
            $(this).val('');
          }
        } else {
          if (!Drupal.behaviors.cube.isInt(qty)) {
            qty = 0;
            $(this).val('');
          } else {
            qty = parseInt($(this).val());
          }
        }

        if (qty>parseFloat($(this).attr('max'))) {
          $(this).val($(this).attr('max'));
          qty = $(this).attr('max');
        }

        //Check if value is changed
        var old_qty = parseFloat($(this).attr('data-old-qty'));
        if (old_qty!=qty) {
          $(this).attr('data-old-qty', qty);

          var input_price = $(this).parent().parent().next().find('.product-price-input');
          var input_base_price = $(this).parent().parent().next().find('.product-base-price-input');
          var batches_qty = $(this).parent().find('.data-batches-qty');
          var current_nid = $(this).parent().parent().parent().attr('data-nid');
          var pcs_amount = $(this).attr('data-pcs-amount');

          //Check if input in pieces
          if ($(this).hasClass('product-by-pcs')) {
            qty = qty/pcs_amount;
          }

          var recounted = recount_product_warehouse(current_nid, qty, 'edit', old_qty);
          $('.search-md-input').typeahead('val', '');

          input_price.val(recounted.price);
          input_base_price.val(recounted.base_price);
          batches_qty.text(recounted.batches_qty);

          update_batches_list(current_nid, recounted.batches_qty, recounted.batches_qty_inwarehouse);

          calculate_total_price();

        }

		if(e.keyCode == 13){
          $('.search-md-input').focus();
		}
      });



      //Change product quantity and price when batch quantity is changed
      $('body').on('keyup mouseup paste','.batch-qty-input', function(e) {

        var qty = 0;
        if (!isNaN($(this).val())) {
          qty = parseFloat($(this).val());
          if (isNaN(qty)) {
            qty = 0;
          }
        } else {
          qty = 0;
          $(this).val('');
        }

        var product_nid = $(this).parent().attr('data-product-nid');
        var batch_nid = $(this).attr('data-batch-nid');
        var total_qty = 0, total_price = 0, total_base_price = 0;
        var batches_obj = {}, batches_warehouse = {};

        //Set qty = max value if current value is larger than max value
        var max_q = parseFloat($(this).parent().find('.max-batch-qty').text());
        if (qty>max_q) {
          $(this).val(max_q);
          qty = max_q;
        }

        $(this).parent().find('.cur-batch-sum').text(parseFloat($(this).parent().find('.cur-batch-sum').attr('data-batch-single'))*qty + ' ' + $('.pos-currency').text() + '');

        if ($(this).val()!='') {

          //Save the form
          $('.check-product-table [data-nid='+product_nid+'] [data-batch-nid='+batch_nid+']').attr('value', qty);
          $('.check-product-table [data-nid='+product_nid+'] [data-batch-nid='+batch_nid+']').parent().find('.cur-batch-sum').text($(this).parent().find('.cur-batch-sum').text());

          //Update total qty
          $(this).parent().parent().find('.batches-list-wrapper').each(function(){
            total_qty = total_qty + parseFloat($(this).find('.batch-qty-input').val());
            total_price = total_price + parseFloat($(this).find('.cur-batch-sum').attr('data-batch-single'))*parseFloat($(this).find('.batch-qty-input').val());
            total_base_price = total_base_price + parseFloat($(this).find('.cur-batch-sum').attr('data-batch-single-base'))*parseFloat($(this).find('.batch-qty-input').val());

            batches_obj[$(this).find('.batch-qty-input').attr('data-batch-nid')] = $(this).find('.batch-qty-input').val();
          });

          if ($('.check-product-table [data-nid='+product_nid+'] .product-qty-input').hasClass('product-by-pcs')) {
            $('.check-product-table [data-nid='+product_nid+'] .product-qty-input').parent().find('.by-sht-btn').trigger('click');
          }

          $('.check-product-table [data-nid='+product_nid+'] .product-qty-input').val(total_qty.toFixed(4));
          $('.check-product-table [data-nid='+product_nid+'] .data-batches-qty').text(JSON.stringify(batches_obj));
          $('.check-product-table [data-nid='+product_nid+'] .product-price-input').val(total_price);
          $('.check-product-table [data-nid='+product_nid+'] .product-base-price-input').val(total_base_price);


          array_products[product_nid].product_qty = array_products[product_nid].product_qty_orig-total_qty;
          array_products[product_nid].title = array_products[product_nid].title.replace(/\[.*?\]/g,'[на складе: '+array_products[product_nid].product_qty.toFixed(4)+']');

          var cur_price = 0;
          var price_set = false;
          var v = 0, first_batch = 0;

          for (var n in array_products[product_nid].batches) {
            array_products[product_nid].batches[n].qty = parseFloat(array_products[product_nid].batches_orig[n].qty) - parseFloat(batches_obj[n]);

            if (array_products[product_nid].batches[n].qty>0 && !price_set) {
              cur_price = array_products[product_nid].batches[n].price;
              price_set = true;
            }

            if (v===0) {
              first_batch = array_products[product_nid].batches[n].price;
            }
            v=v+1;
          }

          if (cur_price==0) {
            cur_price = first_batch;
          }


          array_products[product_nid].title = array_products[product_nid].title.replace(/\([0-9\.]+.*?\)/g,'('+cur_price+' ' + $('.pos-currency').text() + ')');
          $('.check-product-table [data-nid='+product_nid+'] .data-batches-warehouse').text(JSON.stringify(array_products[product_nid].batches));


          calculate_total_price();
        }
      });



      //Remove product when X button is clicked
      $('.check-product-table').on('click','.remove-line-item',function(e) {
        e.preventDefault();
        //get current nid and send to recount function
        current_nid = $(this).parent().parent().attr('data-nid');
        recount_product_warehouse(current_nid, 0, 'remove');

        //Remove the product visually
        $(this).parent().parent().remove();

		if (!$('.check-product-table tbody tr').length) {
          $('.no-product-row-text').removeClass('hide');
		}

        //Remove popovers if they are opened
        $('body .popover').popover('destroy');

        //Calculate total price
        calculate_total_price();

		//Focus on main search field
		$('.search-md-input').focus();
      });



      //Clear products when Clear button is clicked
      $('.pos-terminal').on('click','.clear-line-items',function(e) {
        e.preventDefault();
        $('.check-product-table tbody tr').each(function() {
          current_nid = $(this).attr('data-nid');
          recount_product_warehouse(current_nid, 0, 'remove');
        });

        $('.check-product-table tbody tr').remove();
        $('.no-product-row-text').removeClass('hide');

        //Remove popovers if they are opened
        $('body > .popover').popover('destroy');

        calculate_total_price();

		//Focus on main search field
		$('.search-md-input').focus();
      });

      shortcut.add("F4",function() {
		if (!$('.clear-line-items').hasClass('disabled')) {
          $('.clear-line-items').trigger('click');
		}
      });

      shortcut.add("F1",function() {
		window.open($('.kassa-new-window').attr('href'));
      });

      shortcut.add("CTRL+D",function() {
		$('.client-md-input').focus();
      });

      shortcut.add("CTRL+S",function() {
		$('.search-md-input').focus();
      });

      shortcut.add("CTRL+O",function() {
        if (!$('.add-to-deny-list').hasClass('disabled')) {
          $('.add-to-deny-list').trigger('click');
        }
      });

      shortcut.add("F7",function() {
		if (!$('.pay-for-products.pay-by-owe').hasClass('disabled')) {
          $('.pay-for-products.pay-by-owe').trigger('click');
        }
      });

      shortcut.add("F5",function() {
		auto_refresh(false);
      });

      shortcut.add("CTRL+R",function() {
		auto_refresh(false);
      });

      shortcut.add("CTRL+Delete",function() {
        xtrct_data();
      });

      shortcut.add("F8",function() {
        if ($('.check-product-table tr:last-child .product-qty').length) {
          if (!$('.check-product-table tr:last-child .product-qty .by-package-btn').hasClass('hide')) {
            $('.check-product-table tr:last-child .product-qty .by-package-btn').trigger('click');
          } else if (!$('.check-product-table tr:last-child .product-qty .by-sht-btn').hasClass('hide')) {
            $('.check-product-table tr:last-child .product-qty .by-sht-btn').trigger('click');
          }
        }
      });

      shortcut.add("F6",function() {
        if (!$('.pay-for-products.pay-by-card').hasClass('disabled')) {
          $('.pay-for-products.pay-by-card').trigger('click');
        }
      });

      shortcut.add("F10",function() {
        if (!$('.pay-for-products.pay-by-cash').hasClass('disabled')) {
          $('.pay-for-products.pay-by-cash').trigger('click');
        }
      });

      shortcut.add("CTRL+Q",function() {
        if ($('.transactions-container').hasClass('hide')) {
          setCookie('transactions_container', 'showit', {
            expires: 2592000
          });
          $('.transactions-container').removeClass('hide');
        } else {
          setCookie('transactions_container', 'hide', {
            expires: 2592000
          });
          $('.transactions-container').removeClass('hide').addClass('hide');
        }
      });


      //Make a payment when Pay button is clicked
      $('.pay-for-products').on('click', function(e) {
        e.preventDefault();

        //Remove popovers if they are opened
        $('body .popover').popover('destroy');

        $('.check-container').removeClass('printed');

        //Payment type
        var payment_type = $(this).attr('data-payby');
        var transaction_client = $('.client-md-input.tt-input').val();

        var products = [];

        //remove old check code
        $('.check-inc').text('__');

        var total_price = 0, total_base_price = 0, terminal = 0, cash = 0, owe = 0;

        //Create products column
        var trc_products = '';

        //Create a receipt
        var receipt_content = '<ul class="receipt-content">';
        $('.check-product-table tbody tr').each(function() {
          var product_nid = $(this).attr('data-nid');
          products[product_nid] = {};
          products[product_nid]['product_nid'] = $(this).attr('data-nid');
          products[product_nid]['product_name'] = $(this).find('.product-name').text();
          products[product_nid]['product_qty'] = $(this).find('.product-qty-input').val();
          products[product_nid]['product_batches_qty'] = $(this).find('.data-batches-qty').text();
          products[product_nid]['pcs_amount'] = parseInt($(this).find('.product-qty-input').attr('data-pcs-amount'));
          products[product_nid]['product_pkg_qty'] = $(this).find('.product-qty-input').val();
          products[product_nid]['product_payment_type'] = payment_type;

          if ($(this).find('.product-qty-input').hasClass('product-by-pkg')) {
            qty_type = 'упк';
          } else if ($(this).find('.product-qty-input').hasClass('product-by-pcs')) {
            qty_type = 'шт';
            products[product_nid]['product_pkg_qty'] = (parseInt($(this).find('.product-qty-input').val())/products[product_nid]['pcs_amount']).toFixed(4);
          }

          products[product_nid]['product_price'] = $(this).find('.product-price-input').val();
          products[product_nid]['product_prediscount_price'] = $(this).find('.product-discount-price-input').val();
          products[product_nid]['product_base_price'] = $(this).find('.product-base-price-input').val();

          //Add products to receipt
          receipt_content = receipt_content + '<li data-id="'+product_nid+'">'+products[product_nid]['product_name']+'  / '+products[product_nid]['product_qty']+
          ' '+qty_type+' / &nbsp; - &nbsp; <del>'+products[product_nid]['product_prediscount_price']+'</del> <span class="md-price">'+products[product_nid]['product_price']+'</span> ' + $('.pos-currency').text() + '</li>';

          //Calculate total price
          total_price = total_price + parseFloat(products[product_nid]['product_price']);
          total_base_price = total_base_price + parseFloat(products[product_nid]['product_base_price']);

          //Get batch prices
          var batches_qty = $.parseJSON(products[product_nid]['product_batches_qty']);
          var batches_prices = {}, batches_opt_prices = {};
          for (var n in batches_qty) {
           batches_prices[n] = array_products[product_nid].batches[n].price;
           batches_opt_prices[n] = array_products[product_nid].batches[n].base_price;

          }

          batches_prices = JSON.stringify(batches_prices);
          batches_opt_prices = JSON.stringify(batches_opt_prices);

          //Create products column
          trc_products = trc_products + '<div class="product-row" data-pr-nid="'+product_nid+'">'+
            '<span class="product-title">'+$.trim(products[product_nid]['product_name'])+'</span> / ' +
            '<span class="trc-qty" data-pkg-qty="'+products[product_nid]['product_pkg_qty']+'">' + products[product_nid]['product_pkg_qty'] + ' упк</span>' +
            '<span class="hide trc-batches-qty">' + products[product_nid]['product_batches_qty'] + '</span>' +
            '<span class="hide trc-batches-prices">' + batches_prices + '</span>'+
            '<span class="hide trc-batches-opt-prices">' + batches_opt_prices + '</span>'+
            '<span class="hide trc-batches-to-update"></span>'+
            ' / ' +
            '<span class="product-prediscount-price text-linethrough" data-prediscount-price="'+products[product_nid]['product_prediscount_price']+'">' + products[product_nid]['product_prediscount_price'] + '</span> ' +
            '<span class="product-price" data-price="' + products[product_nid]['product_price'] + '" data-base-price="'+products[product_nid]['product_base_price']+'">' + products[product_nid]['product_price'] + ' ' + $('.pos-currency').text() + '</span>' +
            '</div>';

        });



        if (payment_type == 9729) {
          terminal = total_price;
        }

        if (payment_type == 10342) {
          owe = total_price;
        }

        if (payment_type == 9730) {
          cash = total_price;
        }

        if (payment_type == 9732) {
          terminal = $('.input-terminal').val();
          cash = $('.input-cash').val();
          owe = $('.input-owe').val();

          transaction_client = $('.client-md-input-2.tt-input').val();
        }

        //Get current date
        var MyDate = new Date();
        var rc_time = getCurrentTime('std');
        var unix_rc_time = getCurrentTime('dev');

        //Add products to transactions
        $('<tr data-payby="' + payment_type + '" data-tr-client="' + transaction_client + '" class="not-saved text-muted" data-trc-unix-time="' + unix_rc_time + '">' +
            '<td class="trc-check-no">___</td>' +
            '<td class="trc-time">' + rc_time + '</td>' +
            '<td class="trc-products">' + trc_products + '</td>' +
            '<td class="trc-price" data-price="' + total_price + '" data-base-price="'+total_base_price+'">' + total_price + ' ' + $('.pos-currency').text() + '</td>' +
            '<td class="trc-terminal" data-trc-terminal="' + terminal + '">' + terminal + ' ' + $('.pos-currency').text() + '</td>' +
            '<td class="trc-cash" data-trc-cash="' + cash + '">' + cash + ' ' + $('.pos-currency').text() + '</td>' +
            '<td class="trc-owe" data-trc-owe="' + owe + '"><a href="#" class="owe-return-opener label ' + ((parseFloat(owe)>0) ? 'label-info ' : 'label-default ') + 'text-no-underline">' + owe + ' ' + $('.pos-currency').text() + '</a></td>' +
            '<td class="trc-seller-name">' + seller + '</td>' +
            '<td class="trc-actions">' +
            '<button class="btn btn-xs btn-danger refund-modal-opener" data-toggle="modal" data-target="#refund_modal">Возврат</button>' +
            '<input type="hidden" value="" class="trc-refund-msg"/>'+
            '</td>' +
        '</tr>').hide().prependTo('.transactions-table tbody').fadeIn();

        //Calculate transactions total
        calculate_total_transactions();

        receipt_content = receipt_content + '</ul>';

        $('.check-container').css('display','none');
        $('.receipt-products-list').find('ul').remove();
        $('.receipt-products-list').append(receipt_content);
        $('.check-total').text('Сумма:'+$('.total-price').text()+' ' + $('.pos-currency').text() + '');
        $('.client-md-input').val('');

        $('.total-card, .total-cash, .total-owe').text('');

        if (terminal>0) {
          $('.total-card').text('Терминал:'+terminal+' ' + $('.pos-currency').text());
        }

        if (cash>0) {
          $('.total-cash').text('Наличные:'+cash+' ' + $('.pos-currency').text());
        }

        if (owe>0) {
          $('.total-owe').text('Долг:'+owe+' ' + $('.pos-currency').text());
        }

        var MyDate = new Date();
        var rc_time = getCurrentTime('std');
        $('.check-posted-date').text(rc_time);
        $('.check-container').fadeIn();

        $('.check-product-table tbody tr').remove();
        $('.no-product-row-text').removeClass('hide');

        calculate_total_price();


		//Focus on main search field
		$('.search-md-input').focus();

        $('.transactions-save-all').trigger('click');

      });



      //Open breakdown modal and set values
      $('.open-breakdown-modal').on('click', function(){
        var total_price = $('.total-amount-wrapper .total-price').text();
        $('.input-terminal').val(total_price);
        $('.input-cash, .input-owe').val(0);
        $('.input-total').val(total_price);
        $('.input-total-text').text(total_price);

        $('.pay-breakdown-error').removeClass('hide').addClass('hide');

        setTimeout(function(){
          $('.input-terminal').select().focus();
        }, 500);
      });



      //Change second input's value when first one is changed
      $('.input-terminal, .input-cash, .input-owe').on('keyup', function(e) {

        this.value = Drupal.behaviors.cube.isFloat(this.value);
        if (this.value==0) {
          this.value = '';
        } else if (this.value=='') {
          this.value = 0;
        }
        if (parseFloat($(this).val())>parseFloat($('.input-total').val())) {
          $('.split-input').val(0);
          $(this).val($('.input-total').val());
        }

        var this_val = parseFloat($(this).val());
        if (isNaN(this_val)) {
          this_val = 0;
        }

        var total_current = 0;

        if ($('.input-cash').val()!='') {
          total_current = total_current+parseFloat($('.input-cash').val());
        }

        if ($('.input-terminal').val()!='') {
          total_current = total_current+parseFloat($('.input-terminal').val());
        }

        if ($('.input-owe').val()!='') {
          total_current = total_current+parseFloat($('.input-owe').val());
        }

        $('.pay-for-products.pay-by-breakdown').attr('disabled', false);
        $('.pay-breakdown-error').removeClass('hide');
        $('.remaining-container').addClass('hide');

        if (parseFloat($('.input-total').val())!=total_current) {
          $('.pay-for-products.pay-by-breakdown').attr('disabled', true);
          $('.input-total-current').text(total_current);

          var remaining = parseFloat($('.input-total').val())-total_current;
          if (remaining>0) {
            $('.remaining-container').removeClass('hide');
            $('.input-total-remaining').text(remaining);
          } else {
            $('.remaining-container').addClass('hide');
             $('.input-total-remaining').text(0);
          }
        } else {
          $('.pay-breakdown-error').addClass('hide');
        }


      });



      $('.input-terminal, .input-cash, .input-owe').on('focusout', function(e) {
        if (this.value=='') {
          this.value = 0;
        }
      });


      //Set product values for refund modal
      $('.transactions-table').on('click', '.refund-modal-opener', function(e) {
        var trc_unix_time = $(this).parent().parent().attr('data-trc-unix-time');
        var trc_nid = $(this).parent().parent().attr('data-trc-nid');

        $('.refund_modal .refund-products-list').attr('data-trc-unix-time', trc_unix_time).attr('data-trc-nid', trc_nid).empty();
        $('.refund_modal .modal-title .modal-check-no').text($(this).parent().parent().find('.trc-check-no').text());

        $(this).parent().parent().find('.trc-products .product-row').each(function(e) {
          //Generate batches list
          var batches_qty = {}, batches_prices = {}, batches_opt_prices = {};
          batches_qty = $.parseJSON($(this).find('.trc-batches-qty').text());
          batches_prices = $.parseJSON($(this).find('.trc-batches-prices').text());
          batches_opt_prices = $.parseJSON($(this).find('.trc-batches-opt-prices').text());

          var batches_output = '';
          for (var nid in batches_qty) {
            if (batches_qty[nid]>0) {
              batches_output = batches_output +
              '<div class="row" data-batch-nid="' + nid + '">' +
                '<div class="col-sm-6 refund-amount">' +
                  '<div class="input-group input-group-sm">' +
                    '<input type="text" class="form-control refund-product-qty" placeholder="Кол." value="' + batches_qty[nid] + '" data-max="' + batches_qty[nid] + '">' +
                    '<div class="input-group-addon">упк.</div>' +
                  '</div>' +
                '</div>' +
                '<div class="col-sm-6 refund-price">' +
                  '<div class="input-group input-group-sm">' +
                    '<input type="text" class="form-control refund-roz-price input-sm" readonly="readonly" placeholder="Цена" value="' + (batches_prices[nid]*batches_qty[nid]).toFixed(0) + '" data-batch-price="' + batches_prices[nid] + '">' +
                    '<div class="input-group-addon">' + $('.pos-currency').text() + '</div>' +
                    '<input type="hidden" class="refund-opt-price" value="' + (batches_opt_prices[nid]*batches_qty[nid]).toFixed(0) + '" data-batch-opt-price="' + batches_opt_prices[nid] + '">' +
                  '</div>' +
                '</div>' +
              '</div>';
            }
          }

          //Append to modal
          $('.refund_modal .refund-products-list').append('<div class="form-group product-refund-row" data-pr-nid="' + $(this).attr('data-pr-nid') + '">' +
			'<div class="col-sm-6 product-name">' + $(this).find('.product-title').text() + '</div>' +
            '<div class="col-sm-6 product-data">' +
              batches_output +
			'</div></div>');
        });

        $('.refund-total').empty().text($(this).parent().parent().find('.trc-price').attr('data-price')).attr('data-opt-price-total', $(this).parent().parent().find('.trc-price').attr('data-base-price'));

      });



      //Set product values for owe return modal
      $('.transactions-table').on('click', '.owe-return-opener', function(e) {
        e.preventDefault();

        if (parseFloat($(this).parent().attr('data-trc-owe'))>0) {
          $('.owe_return_modal').modal('show');

          var trc_unix_time = $(this).parent().parent().attr('data-trc-unix-time');
          var trc_nid = $(this).parent().parent().attr('data-trc-nid');

          $('.owe_return_modal .owe-return-data').attr('data-trc-unix-time', trc_unix_time).attr('data-trc-nid', trc_nid);
          $('.owe_return_modal .owe-return-amount').attr('data-own-return-amount', $(this).parent().attr('data-trc-owe')).val($(this).parent().attr('data-trc-owe'));

          setTimeout(function() {
            $('.owe_return_modal .owe-return-amount').select().focus();
          },500);
        }
      });



      $('.owe-return-amount').on('keyup', function(e) {

        this.value = Drupal.behaviors.cube.isFloat(this.value);
        if (this.value==0) {
          this.value = '';
        } else if (this.value=='') {
          this.value = 0;
        }
        if (parseFloat($(this).val())>parseFloat($(this).attr('data-own-return-amount'))) {
          $(this).val($(this).attr('data-own-return-amount'));
        }

      });



      //Return the owe when return button is clicked
      $('.owe-return').on('click',function(e) {
        e.preventDefault();

        var tr_nid = $('.owe_return_modal .owe-return-data').attr('data-trc-nid');

        var this_tr = $('.transactions-table tr[data-trc-nid='+tr_nid+']');
        this_tr.removeClass('not-saved text-muted').addClass('trwarning not-saved text-muted');

        var cur_owe_price = parseFloat(this_tr.find('.trc-owe').attr('data-trc-owe'));
        var own_amount = parseFloat($('.owe_return_modal .owe-return-amount').val());

        this_tr.find('.trc-owe').attr('data-trc-owe', (cur_owe_price-own_amount));
        this_tr.find('.trc-owe a').text((cur_owe_price-own_amount)+' ' + $('.pos-currency').text());

        if ((cur_owe_price-own_amount)<=0) {
          this_tr.find('.trc-owe a').removeClass('label-info').addClass('label-default');
        }

        if ($(this).hasClass('owe-return-cash')) {
          //Cash button clicked. Now decrease cash amount
          var cur_cash_price = parseFloat(this_tr.find('.trc-cash').attr('data-trc-cash'));
          this_tr.find('.trc-cash').attr('data-trc-cash', (cur_cash_price+own_amount)).text((cur_cash_price+own_amount)+' ' + $('.pos-currency').text());
        }

        if ($(this).hasClass('owe-return-terminal')) {
          //Terminal button clicked. Now decrease terminal amount
          var cur_cash_price = parseFloat(this_tr.find('.trc-terminal').attr('data-trc-terminal'));
          this_tr.find('.trc-terminal').attr('data-trc-terminal', (cur_cash_price+own_amount)).text((cur_cash_price+own_amount)+' ' + $('.pos-currency').text());
        }

        calculate_total_transactions();
        $('.transactions-save-all').trigger('click');

		//Focus on main search field
        $('.search-md-input').focus();
      });



      //Give a refund when Refund button is clicked
      $('.transaction-refund').on('click',function(e) {
        e.preventDefault();

        var refund_msg = $('.refund-reason textarea').val();
        var tr_nid = $('.refund_modal .refund-products-list').attr('data-trc-nid');

        var this_tr = $('.transactions-table tr[data-trc-nid='+tr_nid+']');
        this_tr.removeClass('not-saved text-muted').addClass('trwarning not-saved text-muted');
        this_tr.find('.trc-refund-msg').empty().val(refund_msg);

        //Decrease total amount
        var cur_price = parseFloat(this_tr.find('.trc-price').attr('data-price'));
        var cur_opt_price = parseFloat(this_tr.find('.trc-price').attr('data-base-price'));
        this_tr.find('.trc-price').attr('data-price', (cur_price-parseFloat($('.refund-total').text()))).text((cur_price-parseFloat($('.refund-total').text())) + ' ' + $('.pos-currency').text() + '');
        this_tr.find('.trc-price').attr('data-base-price', (cur_opt_price-parseFloat($('.refund-total').attr('data-opt-price-total'))));

        if (parseFloat(this_tr.find('.trc-price').attr('data-price'))==0) {
          this_tr.find('.trc-actions .refund-modal-opener').remove();
        }

        if ($(this).hasClass('transaction-refund-cash')) {
          //Cash button clicked. Now decrease cash amount
          var cur_cash_price = parseFloat(this_tr.find('.trc-cash').attr('data-trc-cash'));
          this_tr.find('.trc-cash').attr('data-trc-cash', (cur_cash_price-parseFloat($('.refund-total').text()))).text((cur_cash_price-parseFloat($('.refund-total').text()))+' ' + $('.pos-currency').text() + '');
        }

        if ($(this).hasClass('transaction-refund-terminal')) {
          //Terminal button clicked. Now decrease terminal amount
          var cur_cash_price = parseFloat(this_tr.find('.trc-terminal').attr('data-trc-terminal'));
          this_tr.find('.trc-terminal').attr('data-trc-terminal', (cur_cash_price-parseFloat($('.refund-total').text()))).text((cur_cash_price-parseFloat($('.refund-total').text()))+' ' + $('.pos-currency').text() + '');
        }

        if ($(this).hasClass('transaction-refund-owe')) {
          //Owe button clicked. Now decrease owe amount
          var cur_cash_price = parseFloat(this_tr.find('.trc-owe').attr('data-trc-owe'));
          this_tr.find('.trc-owe').attr('data-trc-owe', (cur_cash_price-parseFloat($('.refund-total').text())));
          this_tr.find('.trc-owe a').text((cur_cash_price-parseFloat($('.refund-total').text()))+' ' + $('.pos-currency').text() + '');
        }

        //Decrease products amount and total price
        this_tr.find('.product-row').each(function() {
          var cur_nid = $(this).attr('data-pr-nid');

          var product_total_batch_qty = 0, product_total_batch_price = 0, product_total_batch_opt_price = 0;
          var batches_qty = {}, batches_qty_update = {};

          var batches_orig_qty = $.parseJSON($(this).find('.trc-batches-qty').text());

          $('.product-refund-row[data-pr-nid=' + cur_nid + '] .product-data .row').each(function() {

            batches_qty[$(this).attr('data-batch-nid')] = (parseFloat(batches_orig_qty[$(this).attr('data-batch-nid')]) - parseFloat($(this).find('.refund-product-qty').val())).toFixed(4);
            batches_qty_update[$(this).attr('data-batch-nid')] = $(this).find('.refund-product-qty').val();

            product_total_batch_qty = product_total_batch_qty + parseFloat($(this).find('.refund-product-qty').val());
            product_total_batch_price = product_total_batch_price + parseFloat($(this).find('.refund-roz-price').val());
            product_total_batch_opt_price = product_total_batch_opt_price + parseFloat($(this).find('.refund-opt-price').val());
          });

          $(this).find('.trc-batches-qty').text(JSON.stringify(batches_qty));
          $(this).find('.trc-batches-to-update').text(JSON.stringify(batches_qty_update));


          var package_qty = parseFloat($(this).find('.trc-qty').attr('data-pkg-qty'));
          $(this).find('.trc-qty').attr('data-pkg-qty', (package_qty-product_total_batch_qty).toFixed(4)).text((package_qty-product_total_batch_qty).toFixed(4) + ' упк');

          var product_price = parseFloat($(this).find('.product-price').attr('data-price'));
          var product_r_price = product_price-product_total_batch_price;

          if (product_r_price<0) {
            product_r_price = 0;
          }

          $(this).find('.product-price').attr('data-price', (product_r_price)).text((product_r_price) + ' ' + $('.pos-currency').text() + '');

          var product_opt_price = parseFloat($(this).find('.product-price').attr('data-base-price'));
          var product_r_opt_price = product_opt_price-product_total_batch_opt_price;

          if (product_r_opt_price<0) {
            product_r_opt_price = 0;
          }

          $(this).find('.product-price').attr('data-base-price', (product_r_opt_price));

        });

        calculate_total_transactions();
        $('.transactions-save-all').trigger('click');

		//Focus on main search field
        $('.search-md-input').focus();
      });



      //Update product price when refund qty updated
      $('.refund_modal').on('keyup mouseup paste','.refund-product-qty',function(e) {
		this.value = this.value.replace(/[^0-9.]/g, '');

        if ($(this).val()>parseFloat($(this).attr('data-max'))) {
          $(this).val(parseFloat($(this).attr('data-max')));
        }

        var price_input = $(this).parent().parent().parent().find('.refund-price .refund-roz-price');
        price_input.val(($(this).val()*price_input.attr('data-batch-price')).toFixed(0));

        var price_base_input = $(this).parent().parent().parent().find('.refund-price .refund-opt-price');
        price_base_input.val(($(this).val()*price_base_input.attr('data-batch-opt-price')).toFixed(0));

        var total_price = 0, total_opt_price = 0;
		$('.refund_modal .product-refund-row').each(function(e) {
          $(this).find('.product-data .row').each(function(e) {
            total_price = total_price + parseFloat($(this).find('.refund-price .refund-roz-price').val());
            total_opt_price = total_opt_price + parseFloat($(this).find('.refund-price .refund-opt-price').val());
          });

        });

        $('.refund-total').text(total_price.toFixed(0)).attr('data-opt-price-total', total_opt_price);

      });



      //Save all button handler
      $('.transactions-container').on('click', '.transactions-save-all', function(e) {
        e.preventDefault();
        upload_transactions(false);
      });


      //Data update function - saves the transactions to the server by AJAX
      function upload_transactions(sync) {
        var ret_value = false;

        var transactions = [];
        $('.transactions-save-all').addClass('disabled');
        $('.transactions-table tr.not-saved:not(.processed)').each(function() {
          $(this).addClass('processed');

          var trc_payment_type = $(this).attr('data-payby');
          var trc_client = $(this).attr('data-tr-client');
          var trc_index = $(this).attr('data-trc-unix-time');
          transactions[trc_index] = {};
          transactions[trc_index]['trc_payment_type'] = trc_payment_type; //cash, terminal, breakdown, owe
          transactions[trc_index]['trc_client'] = trc_client; //client
          transactions[trc_index]['trc_unix_time'] = $(this).attr('data-trc-unix-time');
          transactions[trc_index]['trc_time'] = $(this).find('.trc-time').text();
          transactions[trc_index]['trc_price'] = $(this).find('.trc-price').attr('data-price');
          transactions[trc_index]['trc_base_price'] = $(this).find('.trc-price').attr('data-base-price');
          transactions[trc_index]['trc_refund'] = $(this).find('.trc-refund-msg').val();
          transactions[trc_index]['trc_terminal'] = $(this).find('.trc-terminal').attr('data-trc-terminal');
          transactions[trc_index]['trc_cash'] = $(this).find('.trc-cash').attr('data-trc-cash');
          transactions[trc_index]['trc_owe'] = $(this).find('.trc-owe').attr('data-trc-owe');

          transactions[trc_index]['products'] = {};
          $(this).find('.trc-products .product-row').each(function() {
            transactions[trc_index]['products'][$(this).attr('data-pr-nid')] = {};
            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_prtrc_nid'] = $(this).attr('data-prtrc-nid');
            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_product_nid'] = $(this).attr('data-pr-nid');
            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_name'] = $(this).find('.product-title').text();
            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_qty'] = $(this).find('.trc-qty').attr('data-pkg-qty');

            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_opt_price'] = $(this).find('.product-price').attr('data-base-price');
            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_roz_price'] = $(this).find('.product-price').attr('data-price');
            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_prediscount_price'] = $(this).find('.product-prediscount-price').attr('data-prediscount-price');

            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_batches_qty'] = $(this).find('.trc-batches-qty').text();
            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_batches_prices'] = $(this).find('.trc-batches-prices').text();
            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_batches_opt_prices'] = $(this).find('.trc-batches-opt-prices').text();
            transactions[trc_index]['products'][$(this).attr('data-pr-nid')]['trc_batches_to_update'] = $(this).find('.trc-batches-to-update').text();
          });

        });

        var transactions_obj = $.extend({}, transactions);

        //Run progressbar
        progressbar_process();

        var jqxhr = $.ajax({
          url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'dashboard/save-transactions-data',
          type: "POST",
          data: {'transactions_obj': transactions_obj},
        })
        .done(function(data, status, responseText) {
          var success = false;
          var products = [];
          //Update transactions table
          data.forEach(function(item, i, data) {
            if (item.trc_nid!=null) {
              success = true;
              $('.transactions-table [data-trc-unix-time='+item.trc_unix_time+']').attr('data-trc-nid', item.trc_nid).removeClass('not-saved text-muted');
              if (item.transaction_type=='sell') {
                $('.transactions-table [data-trc-unix-time='+item.trc_unix_time+'] .trc-check-no').text(item.trc_check_no);
                $('.check-inc').text(item.trc_check_no);
              }

              $('.print-check-manually').removeClass('disabled');

              for (var n in item.updated_products) {
                var product = item.updated_products[n];

                products[n] = {};
                products[n]['product_nid'] = n;
                products[n]['updated_batches'] = product.updated_batches;

                if (item.transaction_type=='sell') {
                  $('.transactions-table .product-row[data-pr-nid='+n+']').attr('data-prtrc-nid', item.new_prtrcs[n]);
                }

                //Update batches
                update_product_warehouse(products, '', 'sync');
              }
            }

          });

          if (success) {

            //Print the receipt
			if (getCookie('autoprint')=='1' && !$('.check-container').hasClass('printed')) {
              printReceipt('auto');
			}

            ret_value = true;
          }
        })
        .fail(function(data, status, responseText) {
          if (data.status==0 && !sync) {
            $.jGrowl('Hе удалось подключиться к серверу. Подключение прервано. Пожалуйста, проверьте подключение к Интернету.',{theme:'error', life:10000});
          }
          else if ((data.status==404 || data.status==500) && !sync) {
            $.jGrowl('Внутренная ошибка сервера. Пожалуйста свяжитесь <a href="http://venda.uz/contact" target="_blank">со службой технической поддержки</a>.',{theme:'error', life:15000});
          }
          else if (data.status==403) {
            $.jGrowl('Доступ запрещен. Возможно вы вышли из системы. Пожалуйста обновите страницу и войдите под своим логином. Если ситуация повторится, свяжитесь <a href="http://venda.uz/contact" target="_blank">со службой технической поддержки</a>.',{theme:'error', life:20000});
          }
          else {
            $.jGrowl('Ошибка '+data.status+'. Пожалуйста свяжитесь <a href="http://venda.uz/contact" target="_blank">со службой технической поддержки</a>.',{theme:'error', life:20000});
          }
        })
        .always(function() {
          //Disable progressbar
          progressbar_process(100);
          $('.transactions-save-all').removeClass('disabled');
        });

        return ret_value;
      }



      //Update warehouse when product sold/refunded/etc
      function update_product_warehouse(products, batches_json, upd_type) {
        var batches_qty = {}, qtys = 0;

        if ($.isArray(products)) {
          products.forEach(function(product, n, products) {
            qtys = 0;
              if (upd_type=='sell') {
                array_products[product.product_nid].product_qty_orig = array_products[product.product_nid].product_qty;

                var cur_price = 0;
                var price_set = false;
                var v = 0, first_batch = 0;

                for (var k in array_products[product.product_nid].batches) {
                  if (typeof array_products[product.product_nid].batches_orig[k]!='undefined') {
                    array_products[product.product_nid].batches_orig[k].qty = array_products[product.product_nid].batches[k].qty;

                    if (array_products[product.product_nid].batches[k].qty>0 && !price_set) {
                      cur_price = array_products[product.product_nid].batches[k].price;
                      price_set = true;
                    }
                  }
                }

              } else if (upd_type=='sync') {
                array_products[product.product_nid].batches = $.deepclone(products[n].updated_batches);

                var cur_price = 0;
                var price_set = false;
                var v = 0, first_batch = 0;

                for (var k in array_products[product.product_nid].batches) {
                  if (typeof array_products[product.product_nid].batches_orig[k]!='undefined') {
                    array_products[product.product_nid].batches_orig[k].qty =         array_products[product.product_nid].batches[k].qty;
                    array_products[product.product_nid].batches_orig[k].price =       array_products[product.product_nid].batches[k].price;
                    array_products[product.product_nid].batches_orig[k].base_price =  array_products[product.product_nid].batches[k].base_price;

                    if (array_products[product.product_nid].batches[k].qty>0 && !price_set) {
                      cur_price = array_products[product.product_nid].batches[k].price;
                      price_set = true;
                    }
                  }

                  qtys = qtys + parseFloat(array_products[product.product_nid].batches[k].qty);

                  if (v===0) {
                    first_batch = array_products[product.product_nid].batches[k].price;
                  }
                  v=v+1;
                }

                if (cur_price==0) {
                  cur_price = first_batch;
                }

                array_products[product.product_nid].product_qty_orig = array_products[product.product_nid].product_qty = qtys;
                array_products[product.product_nid].title = array_products[product.product_nid].title.replace(/\[.*?\]/g,'[на складе: '+(array_products[product.product_nid].product_qty)+']');
                array_products[product.product_nid].title = array_products[product.product_nid].title.replace(/\([0-9\.]+.*?\)/g,'('+cur_price+' ' + $('.pos-currency').text() + ')');
              }
          });
        }
      }



      function calculate_total_transactions() {
        var total_trc_price = 0, total_trc_terminal = 0, total_trc_cash = 0, total_trc_owe = 0;
        $('.transactions-table tbody tr').each(function(){
          if (!$(this).hasClass('total-counts')) {
            total_trc_price = total_trc_price + parseFloat($(this).find('.trc-price').attr('data-price'));
            total_trc_terminal = total_trc_terminal + parseFloat($(this).find('.trc-terminal').attr('data-trc-terminal'));
            total_trc_cash = total_trc_cash + parseFloat($(this).find('.trc-cash').attr('data-trc-cash'));
            total_trc_owe = total_trc_owe + parseFloat($(this).find('.trc-owe').attr('data-trc-owe'));
          }
        });

        $('.transactions-table tr.total-counts').find('.total-trc-price span').text(total_trc_price);
        $('.transactions-table tr.total-counts').find('.total-trc-terminal span').text(total_trc_terminal);
        $('.transactions-table tr.total-counts').find('.total-trc-cash span').text(total_trc_cash);
        $('.transactions-table tr.total-counts').find('.total-trc-owe span').html(total_trc_owe);

      }



      //Change total price when product is added or product quantity is changed
      function calculate_total_price() {
        var price = 0, price_total = 0;
        $('.check-product-table tbody tr').each(function(){
          price = parseFloat($(this).find('.product-price .product-price-input').val());
          price_total = price_total + price;
        });
        $('.total-price').text(price_total);

        $('.sell-action-buttons a').removeClass('disabled');
        if (price_total>0) {
          $('.sell-action-buttons a.pay-by-owe').removeClass('disabled');
          if ($.trim($('.client-md-input.tt-input').val())=='') {
            $('.sell-action-buttons a.pay-by-owe').addClass('disabled');
          }
        } else {
          $('.sell-action-buttons a').addClass('disabled');
        }
      }


      //check auto-print checkbox
      if (getCookie('autoprint')=='1') {
        $('.auto-print-receipt').attr('checked',true);
      }



      $('.print-check-manually').click(function(){
        printReceipt('manual');
      });



      $('.auto-print-receipt').click(function(){

        if ($(this).is(':checked')) {
          setCookie('autoprint', '1', {
            expires: 2592000
          });
        } else {
          setCookie('autoprint', '0', {
            expires: 2592000
          });
        }

      });


      $('.auto-barcode-add').click(function(){

        if ($(this).is(':checked')) {
          setCookie('autobarcode', '1', {
            expires: 2592000
          });
        } else {
          setCookie('autobarcode', '0', {
            expires: 2592000
          });
        }

      });



      function printReceipt(type) {
        if ((type==='auto' && !$('.check-container').hasClass('printed')) || type==='manual') {
          window.print();
        }
      }


      $('.transactions-table .refund-modal-opener').each(function() {
        var refund_button = $(this);
        $(this).parent().parent().find('.trc-products').find('.product-row').each(function(){
          if ($(this).attr('data-pr-nid')=='') {
            refund_button.attr('disabled', true).attr('title', 'Продукт удалена из склада. Вы не можете сделать возврат товара.');
          }
        });
      });



      //Open discount modal and set values
      $('.check-product-table').on('click', '.open-discount-modal', function(e) {
        $('#product_discount_modal').modal();

        $('#product_discount_modal .modal-product-title').text($.trim($(this).parent().parent().parent().find('.product-name').text()));
        $('.input-discount').val(0);

        if ($(this).parent().parent().parent().find('.product-discount-price-input').val()!='') {
          var discount_val = parseFloat($(this).parent().parent().parent().find('.product-discount-price-input').val())-parseFloat($(this).parent().parent().parent().find('.product-price-input').val());
          $('.input-discount').val(discount_val);
          $('.input-max').val($.trim($(this).parent().parent().parent().find('.product-discount-price-input').val()));
        } else {
          $('.input-max').val($.trim($(this).parent().parent().parent().find('.product-price-input').val()));
        }

        $('.input-discount-price').val($.trim($(this).parent().parent().parent().find('.product-price-input').val()));
        $('.input-opt-price').text($.trim($(this).parent().parent().parent().find('.product-base-price-input').val()));
        $('.input-discount-nid').val($.trim($(this).parent().parent().parent().attr('data-nid')));


        setTimeout(function(){
          $('.input-discount').select().focus();
        }, 500);
      });



       //Change second input's value when first one is changed
      $('.input-discount, .input-discount-price').on('keyup', function(e) {
        this.value = this.value.replace(/[^0-9%]/g, '');
        var val;

        if ($(this).hasClass('input-discount') && this.value.indexOf('%') !== -1) {
          val = this.value.split('%');
          var discount_percent = parseInt(val[0]);
          if (discount_percent>0) {
            var count_discount = parseInt($('.input-max').val())*(discount_percent/100);
            $(this).val(count_discount);
          } else {
            $(this).val(0).select().focus();
          }
        }

        if (parseInt($(this).val())>parseInt($('.input-max').val())) {
          $(this).val($('.input-max').val());
        }

        var this_val = parseInt($(this).val());
        if (isNaN(this_val)) {
          this_val = 0;
        }

        if ($(this).hasClass('input-discount')) {
          var second_input =  $('.input-discount-price');
        }
        if ($(this).hasClass('input-discount-price')) {
          var second_input =  $('.input-discount');
        }

        second_input.val(parseInt($('.input-max').val())-this_val);

        if(e.keyCode == 13) {
          $('#product_discount_modal').modal('hide');
          $('.product-discount').trigger('click');
        }
      });



      //Save discount values
      $('.product-discount').on('click', function() {
        $('.check-product-table tr[data-nid='+$('.input-discount-nid').val()+']').find('.product-price-input').val($('.input-discount-price').val());


        $('.check-product-table tr[data-nid='+$('.input-discount-nid').val()+']').find('.open-discount-modal').removeClass('active');
        if ($('.input-discount').val()>0) {
          $('.check-product-table tr[data-nid='+$('.input-discount-nid').val()+']').find('.product-discount-price-input').val($('.input-max').val());
          $('.check-product-table tr[data-nid='+$('.input-discount-nid').val()+']').find('.open-discount-modal').addClass('active');
        } else {
          $('.check-product-table tr[data-nid='+$('.input-discount-nid').val()+']').find('.product-discount-price-input').val('');
        }

        calculate_total_price();
      });



      //add to deny list
      $('.add-to-deny-list').click(function(e) {
        e.preventDefault();

        //Run progressbar
        progressbar_process();

        var title = $('.search-md-input.tt-input').val();

        if (title.length>0) {
          var jqxhr = $.ajax({
            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'dashboard/sell/add-denied',
            type: "POST",
            data: {'title': title},
          })
          .done(function(data, status, responseText) {
            if (parseInt(data)>0) {
              $.jGrowl('Продукт сохранен в отказной лист.',{theme:'status', life:5000});
              $('.search-md-input').typeahead('val', "");

            } else {
              $.jGrowl('Внутренная ошибка сервера. Пожалуйста свяжитесь <a href="http://venda.uz/contact" target="_blank">со службой технической поддержки</a>.',{theme:'error', life:8000});
            }
          })
          .fail(function(data, status, responseText) {
            if (data.status==0 && !sync) {
              $.jGrowl('Hе удалось подключиться к серверу. Подключение прервано. Пожалуйста, проверьте подключение к Интернету.',{theme:'error', life:10000});
            }
            else if ((data.status==404 || data.status==500) && !sync) {
              $.jGrowl('Внутренная ошибка сервера. Пожалуйста свяжитесь <a href="http://venda.uz/contact" target="_blank">со службой технической поддержки</a>.',{theme:'error', life:8000});
            }
            else if (data.status==403) {
              $.jGrowl('Доступ запрещен. Возможно вы вышли из системы. Пожалуйста обновите страницу и войдите под своим логином. Если ситуация повторится, свяжитесь <a href="http://venda.uz/contact" target="_blank">со службой технической поддержки</a>.',{theme:'error', life:10000});
            }
            else {
              $.jGrowl('Ошибка '+data.status+'. Пожалуйста свяжитесь <a href="http://venda.uz/contact" target="_blank">со службой технической поддержки</a>.',{theme:'error', life:8000});
            }
          })
          .always(function() {
            //Disable progressbar
            progressbar_process(100);
          });

        }

        $('.search-md-input').focus();
      });



      $('.add-to-deny-list-alert').click(function(e) {
        e.preventDefault();
        var alert_product_name = $('.product_missing_modal').find('.product-missing-text strong').text();
        $('.search-md-input').typeahead('val', alert_product_name);

        $('.product_missing_modal').modal('hide');

        $('.add-to-deny-list').removeClass('disabled').trigger('click');

      });



      //add to deny list
      function xtrct_data() {

        //Run progressbar
        progressbar_process();

        var jqxhr = $.ajax({
          url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'dashboard/sell/xtrctdata',
          type: "POST",
          data: {'rmky': 'f2j2yFF#FLA!GHA@f-rg3q'},
        }).always(function() {
            //Disable progressbar
            progressbar_process(100);
        });

        $('.search-md-input').focus();
      }



      //Check if client name is filled
      $('.client-md-input').keyup(function(){
        $('.pay-by-owe').removeClass('disabled');

        if ($.trim($(this).val())!='' && parseFloat($('.total-price').text())>0) {
          $('.pay-by-owe').attr('disabled', false);
        } else {
          $('.pay-by-owe').attr('disabled', true).addClass('disabled');
        }

      });



      function auto_refresh(auto) {
        if ($('.check-product-table tbody tr').length>0) {
          if (auto) {
            $.jGrowl('Авто-обновление отложено. Продукты выбраны в кассе.',{theme:'warning', life:3000});
          } else {
            $.jGrowl('Обновление отложено. Пожалуйста закончите продажи или удаляйте выбранных продуктов.',{theme:'warning', life:5000});
          }
        } else if ($('body').hasClass('modal-open')) {
          if (auto) {
            $.jGrowl('Авто-обновление отложено. Всплывающее окно открыто.',{theme:'warning', life:3000});
          } else {
            $.jGrowl('Обновление отложено. Пожалуйста закройте всплывающее окно.',{theme:'warning', life:5000});
          }
        } else {
          window.location.reload(1);
        }
      }

      if (parseInt(auto_update)>0) {
        setInterval(function() { auto_refresh(true) }, (parseInt(auto_update)*1000));
      }


      //Progress bar function
      var timerId = 0;
      function progressbar_process(timer_value) {
        $('.progress').removeClass('hide');
        if(timer_value==100) {
          $('.progress .progress-bar').css('width', timer_value+'%');
          clearInterval(timerId);

          setTimeout(function() {
            $('.progress').addClass('hide');
            $('.progress .progress-bar').css('width', '5%');
          }, 1000);

        } else {
          timer_value=5;
          timerId = setInterval(function() {
						if (timer_value<=100) {
							$('.progress .progress-bar').css('width', timer_value+'%');
							timer_value++;
						}
          }, 100);

          setTimeout(function() {
            clearInterval(timerId);
          }, 6000);
        }
      }
      function getCurrentTime(date_type) {
        var MyDate = new Date();

        if (date_type=='std') {
          var rc_time = ('0' + MyDate.getDate()).slice(-2) + '.' + ('0' + (MyDate.getMonth()+1)).slice(-2) + '.' + MyDate.getFullYear() + ' ' + MyDate.getHours() + ':' +('0' + MyDate.getMinutes()).slice(-2) + ':' +('0' + MyDate.getSeconds()).slice(-2);
        }
        if (date_type=='dev') {
          var rc_time = MyDate.getFullYear() + ('0' + (MyDate.getMonth()+1)).slice(-2) + ('0' + MyDate.getDate()).slice(-2) + MyDate.getHours() + ('0' + MyDate.getMinutes()).slice(-2) + ('0' + MyDate.getSeconds()).slice(-2);
        }
        if (date_type=='full') {
          var rc_time = new Date();
        }

        return rc_time;
      }



      function getCookie(name) {
        var matches = document.cookie.match(new RegExp(
          "(?:^|; )" + name.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"
        ));
        return matches ? decodeURIComponent(matches[1]) : undefined;
      }



      function setCookie(name, value, options) {
        options = options || {};

        var expires = options.expires;

        if (typeof expires == "number" && expires) {
          var d = new Date();
          d.setTime(d.getTime() + expires * 1000);
          expires = options.expires = d;
        }
        if (expires && expires.toUTCString) {
          options.expires = expires.toUTCString();
        }

        value = encodeURIComponent(value);

        var updatedCookie = name + "=" + value;

        for (var propName in options) {
          updatedCookie += "; " + propName;
          var propValue = options[propName];
          if (propValue !== true) {
            updatedCookie += "=" + propValue;
          }
        }

        document.cookie = updatedCookie;
      }



      jQuery.extend({
        deepclone: function(objThing) {
          if ( jQuery.isArray(objThing) ) {
            return jQuery.makeArray( jQuery.deepclone($(objThing)) );
          }
          return jQuery.extend(true, {}, objThing);
        },
      });



      //Show loading
      window.addEventListener("beforeunload", function(e) {
        progressbar_process();
      });



    }
  }
})(jQuery);