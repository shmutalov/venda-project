(function($) {
  Drupal.behaviors.revoke = {
    attach:function (context, settings) {
      //Put scripts into once() to execute them only once.
      $('body').once(function () { 
			
      });
      
      $(".warehouse-export-csv").rowSorter({
        handler: "td.sorter span",
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
      
      //Focus on last search field
      $('.search-md-input').last().focus();
      	
      
      //Check if barcode has scanned
      $('.warehouse-export-csv').on('keyup', '.search-md-input', function(e) {
        if (isInt($(this).val()) && $(this).val().length>8 && $(this).parent().find('.tt-dataset-products-barcode .tt-suggestion').length==1) {
          $(this).parent().find('.tt-dataset-products-barcode .tt-suggestion:first').trigger('click');
          return false;
        }
		if(e.keyCode === 13) {
          $(this).parent().find('.tt-dataset-products-title .tt-suggestion:first').trigger('click');
          return false;
        }
        
      });
      
      
      //Behavior after selecting a product
      $('.warehouse-export-csv').on('typeahead:select', '.search-md-input', function(ev, suggestion) {
        //Check if product has not already added
        $('.warehouse-export-csv tbody tr').each(function(){
          if ($(this).attr('data-nid')==suggestion.nid) {
            $(this).remove();
          }
        });
        
        $(this).attr('name', 'products[' + suggestion.nid + '][title]');
        $(this).parent().parent().parent().attr('data-nid', suggestion.nid);
        $(this).typeahead('close');
        
        $('.search-md-input').typeahead('destroy');
        
        //Clone current row
        $('.warehouse-export-csv tbody').append('<tr>'+$('.warehouse-export-csv tbody tr:last').html()+'</tr>');
        $('.warehouse-export-csv tbody tr:last input').val('').removeClass('error').removeAttr('name');        
        
        $(this).parent().parent().find('.action-links').find('.edit-product').attr('href', Drupal.settings.basePath+'ru/node/'+suggestion.nid+'/edit');
        $(this).parent().parent().find('.sorter').find('.product_nid').val(suggestion.nid);
        //Enable the autocomplete search field
        $('.warehouse-export-csv tbody tr:last .search-md-input').typeahead(
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
        

        $(this).attr('readonly', 'readonly').css('padding-right','25px');
        
        $(this).next('span').removeClass('hide');
        //Retrieve batch data
        var jqxhr = $.ajax({
          url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'dashboard/warehouse/export/get-batches',
          type: "POST",
          data: {'nid': suggestion.nid},
        })
        .done(function(data, status, responseText) { 
          $('.warehouse-export-csv tr[data-nid='+ suggestion.nid +'] .search-md-input').css('padding-right','10px');
          $('.warehouse-export-csv tr[data-nid='+ suggestion.nid +'] .textfield-spin').addClass('hide');
          
          $('.warehouse-export-csv tr[data-nid='+ suggestion.nid +'] .product-parts').empty();
          for (var n in data) {
            if (data[n].pr_amount>0) {
              $('.warehouse-export-csv tr[data-nid='+ suggestion.nid +'] .product-parts').append('<div class="row small-col-padding">'+
              '<div class="col-sm-2 small-col-padding pr-amount"><input type="text" name="products['+suggestion.nid+'][batches]['+n+'][pr_amount]" value="'+data[n].pr_amount+'" data-val="'+data[n].pr_amount+'" placeholder="Количество" class="form-control decimal form-text input-sm"/></div>' + 
              '<div class="col-sm-3 small-col-padding opt-price"><input type="text" name="products['+suggestion.nid+'][batches]['+n+'][opt_price]" value="'+data[n].opt_price+'" placeholder="Опт. цена" class="form-control form-text input-sm integer" readonly="readonly"/></div>' + 
              '<div class="col-sm-3 small-col-padding roz-price"><input type="text" name="products['+suggestion.nid+'][batches]['+n+'][roz_price]" value="'+data[n].roz_price+'" placeholder="Роз. цена" class="form-control form-text input-sm integer" readonly="readonly"/></div>' + 
              '<div class="col-sm-4 small-col-padding revoke-comment"><input type="text" name="products['+suggestion.nid+'][batches]['+n+'][comment]" placeholder="Комментарий" class="form-control form-text input-sm" maxlength="100"/></div></div>');
            }
          }
          
          $('.warehouse-export-csv tr[data-nid='+ suggestion.nid +'] .product-parts .pr-amount input').first().select().focus();
          
  
        });
      });
      
      
      
      $('.warehouse-export-csv').on('click', '.remove-row', function(e) {
        e.preventDefault();
        if ($('.warehouse-export-csv tbody tr').length>1) {
          $(this).parent().parent().remove();
        } else {
          $(this).parent().parent().find('input').val('');
          $(this).parent().parent().find('.search-md-input').removeAttr('readonly');
          $('.warehouse-export-csv tbody tr:last .search-md-input').typeahead('destroy').typeahead(
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
            '<div class="col-sm-2 small-col-padding pr-amount"><input type="text" placeholder="Количество" class="form-control form-text input-sm decimal"/></div>' + 
			'<div class="col-sm-3 small-col-padding opt-price"><input type="text" placeholder="Опт. цена" class="form-control form-text input-sm integer"/></div>' + 
			'<div class="col-sm-3 small-col-padding roz-price"><input type="text" placeholder="Роз. цена" class="form-control form-text input-sm integer"/></div>' + 
            '<div class="col-sm-4 small-col-padding revoke-comment"><input type="text" placeholder="Комментарий" class="form-control form-text input-sm" maxlength="100"/></div></div>');
        }
        
      });
      
      
      $('.warehouse-export-csv').on('change', '.pr-amount > input', function(e) {
        e.preventDefault();
        if (parseFloat($(this).val())>parseFloat($(this).attr('data-val'))) {
          $(this).val($(this).attr('data-val'));
        }
      });
      
      $('#customizer-warehouse-revoke-form').on("submit",function(e){
        if ($(this).hasClass('stop-on-submit')) {
          return false;
        }
      });
      
      $('.warehouse-export-csv-actions .form-submit').on('click', function(e){
        $('#customizer-warehouse-revoke-form').removeClass('stop-on-submit').submit();
      });
            
      
      //Ask confirmation before closing the tab/browser
      window.addEventListener("beforeunload", function (e) {
        var confirmationMessage = 'Вы действительно хотите выйти? Несохраненные данные будут удалены.';
        if (false) {
          (e || window.event).returnValue = confirmationMessage; //Gecko + IE
          return confirmationMessage;                            //Webkit, Safari, Chrome
        }
      });
      
      
      
      // Checks if given value is integer
      function isInt(value) {
        var x;
        return isNaN(value) ? !1 : (x = parseFloat(value), (0 | x) === x);
      }
      
      
      jQuery.extend({
        deepclone: function(objThing) {
          if ( jQuery.isArray(objThing) ) {
            return jQuery.makeArray( jQuery.deepclone($(objThing)) );
          }
          return jQuery.extend(true, {}, objThing);
        },
      });
      
      
    }
  }
})(jQuery);