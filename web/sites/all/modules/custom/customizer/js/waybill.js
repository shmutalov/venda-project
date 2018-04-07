(function($) {
  Drupal.behaviors.waybill = {
    attach:function (context, settings) {
      //Put scripts into once() to execute them only once.
      $('body').once(function () { 
			
      });
      
      $("#waybill_date, .date-expire input").datepicker({
        format: "dd.mm.yyyy",
        startView: 2,
        maxViewMode: 2,
        clearBtn: true,
        language: "ru",
        orientation: "bottom auto",
        todayHighlight: true,
        toggleActive: true
      });
      
      //Search by product title
      var products = new Bloodhound({
        datumTokenizer: Bloodhound.tokenizers.obj.whitespace('title'),
        queryTokenizer: Bloodhound.tokenizers.whitespace,
        local: array_products
      });
      
      //Search by barcode
      var barcode = new Bloodhound({
        datumTokenizer: Bloodhound.tokenizers.obj.whitespace('barcode'),
        queryTokenizer: Bloodhound.tokenizers.whitespace,
        local: array_products
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
        },
        {
          name: 'products-barcode',
          display: 'title',
          minLength: 6,
          source: barcode
        }
      );
      
      
      //Check if barcode has scanned
      $('.warehouse-waybill').on('keyup', '.search-md-input', function(e) {
        if (Drupal.behaviors.cube.isInt($(this).val()) && $(this).val().length>8 && $(this).parent().find('.tt-dataset-products-barcode .tt-suggestion').length==1) {
          $(this).parent().find('.tt-dataset-products-barcode .tt-suggestion:first').trigger('click');
          return false;
        }
        
		if(e.keyCode === 13) {
          $(this).parent().find('.tt-dataset-products-title .tt-suggestion:first').trigger('click');
          return false;
        }
        
      });
      
      
      //Behavior after selecting a product
      $('.warehouse-waybill').on('typeahead:select', '.search-md-input', function(ev, suggestion) {
        
        $(this).parent().parent().parent().attr('data-nid', suggestion.nid);
        $(this).parent().parent().parent().find('.product-nid').val(suggestion.nid);
        $(this).parent().parent().next().find('.product-barcode').val(suggestion.barcode).attr('readonly','readonly');
        
        $(this).attr('readonly', 'readonly').typeahead('close').typeahead('destroy');
        
        $(this).parent().parent().find('.sorter').find('.product_nid').val(suggestion.nid);
        $(this).parent().parent().find('.product-parts').find('.pr-amount input').focus();
        
      });
      
      
      $('.warehouse-waybill').on('click', '.remove-row', function(e) {
        e.preventDefault();
        if ($('.warehouse-waybill tbody tr').length>1) {
          $(this).parent().parent().remove();
        } else {
          $(this).parent().parent().removeAttr('data-nid');
          $(this).parent().parent().find('.product-nid').val(0);
          $(this).parent().parent().find('input').val('');
          $(this).parent().parent().find('.search-md-input').removeAttr('readonly');
          $(this).parent().parent().find('.product-barcode').removeAttr('readonly');
          $('.warehouse-waybill tbody tr:last .search-md-input').typeahead('destroy').typeahead(
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
            },
            {
              name: 'products-barcode',
              display: 'title',
              minLength: 6,
              source: barcode
            }
          );
  
          
          $(this).parent().parent().find('.product-parts').empty().append('<div class="row small-col-padding">'+
            '<div class="col-sm-3 small-col-padding pr-amount"><input type="text" placeholder="Количество" class="form-control form-text input-sm"/></div>' + 
			'<div class="col-sm-3 small-col-padding opt-price"><input type="text" placeholder="Опт. цена" class="form-control form-text input-sm integer"/></div>' + 
			'<div class="col-sm-3 small-col-padding roz-price"><input type="text" placeholder="Роз. цена" class="form-control form-text input-sm integer"/></div>' + 
            '<div class="col-sm-3 small-col-padding date-expire"><input type="text" placeholder="Срок годности" class="form-control form-text input-sm"/></div></div>');
        }
        
      });
      
      
      
      $('#customizer-warehouse-apply-form').on("submit",function(e){
        if ($(this).hasClass('stop-on-submit')) {
          return false;
        }
      });
      
      
      
      $('.warehouse-waybill-actions .form-submit').on('click', function(e){
        $('#customizer-warehouse-apply-form').removeClass('stop-on-submit').submit();
      });
      
      
      
      $('.add-new-rows-link').on('click', function(e){
        e.preventDefault();
        $('.search-md-input').typeahead('destroy');
        
        var last_i = 0;
                
        $('.warehouse-waybill tbody').append('<tr>'+$('.warehouse-waybill tbody tr:last').html()+'</tr>');
        
        $('.warehouse-waybill tbody tr:last').find('.search-md-input').removeAttr('readonly');
        $('.warehouse-waybill tbody tr:last').find('.product-barcode').removeAttr('readonly');
        $('.warehouse-waybill tbody tr:last').removeAttr('data-nid');
        $('.warehouse-waybill tbody tr:last').find('.product-nid').val(0);
        $('.warehouse-waybill tbody tr:last input').val('').removeClass('error');
        
        //Clone current row
        for (i = 0; i < 9; i++) { 
          $('.warehouse-waybill tbody').append('<tr>'+$('.warehouse-waybill tbody tr:last').html()+'</tr>');
        }
        
        //Fix field numeration
        $('.warehouse-waybill tbody tr').each(function(){
          $(this).find('.product-nid').attr('name', 'products['+last_i+'][nid]');
          $(this).find('.search-md-input').attr('name', 'products['+last_i+'][title]');
          $(this).find('.product-barcode').attr('name', 'products['+last_i+'][barcode]');
          $(this).find('.pr-amount input').attr('name', 'products['+last_i+'][pr_amount]');
          $(this).find('.opt-price input').attr('name', 'products['+last_i+'][opt_price]');
          $(this).find('.roz-price input').attr('name', 'products['+last_i+'][roz_price]');
          $(this).find('.date-expire input').attr('name', 'products['+last_i+'][date_expire]');
          
          last_i = last_i + 1;
        });
        
        //Enable the autocomplete search field
        $('.warehouse-waybill tbody .search-md-input').typeahead(
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
          },
          {
            name: 'products-barcode',
            display: 'title',
            minLength: 6,
            source: barcode
          }
        );

        
        $(".date-expire input").datepicker({
          format: "dd.mm.yyyy",
          startView: 2,
          maxViewMode: 2,
          clearBtn: true,
          language: "ru",
          orientation: "bottom auto",
          todayHighlight: true,
          toggleActive: true
        });
        
      });
      
      
      provider_to_waybill($('.provider-nid'));
      
      $('.provider-nid').on('change', function() {
        var provider = $(this);
        
        provider_to_waybill(provider);
        
      });
      
      
      
      function provider_to_waybill(provider) {
        var waybills = provider.parent().next().find('.contract-nid');
        waybills.val(0).attr('disabled',true);
        
        if (provider.val()!=0) {
          waybills.attr('disabled',false);
          
          waybills.find('option').each(function(){
            if ($(this).val()!=0) {
              var wb_parts = $(this).attr('value').split('-');
              if (wb_parts[0]==provider.val()) {
                $(this).attr('disabled', false);
              } else {
                $(this).attr('disabled', true);
              }
            }
          });
        }
      }
      
    }
  }
})(jQuery);