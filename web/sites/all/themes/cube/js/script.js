(function($) {
  Drupal.behaviors.cube = {
    attach:function (context, settings) {
      $('.faq-title').click(function(){
        $(this).next().toggleClass('hide');
      });

      if ($('.field-name-field-apteka-filled input[type=checkbox]').length) {
        $('.field-name-field-apteka-filled input[type=checkbox]').attr('checked', true);
      }

      $('.form-item-trc-created select').change(function() {
        $('.exact-date').removeClass('hide');
        if ($(this).val()!=10) {
          $('.exact-date').addClass('hide');
          $('.exact-date .form-item-date-filter-from-value-date input').val('');
          $('.exact-date .form-item-date-filter-to-value-date input').val('');
        }

      });


      $('body').once(function () {

        var sel = '';
        $('#block-menu-menu-report-menu li').each(function(){
          if ($(this).hasClass('active-trail')) {
            sel = ' selected';
          }
          $('.report-mobile-menu').append('<option value="'+$(this).find('a').attr('href')+'"'+sel+'>'+$(this).find('a').text()+'</option>');
          sel = '';
        });

        $('.report-mobile-menu').on('change', function(){
          window.location = $(this).val();
        });

        $('aside .menu > li:not(.active-trail)').each(function(){
          var parent_li = $(this);
          if ($(this).find('.manager-dropdown-menu')) {
            $(this).find('.manager-dropdown-menu > li').each(function() {
              if ($(this).find('a').hasClass('active')) {
               parent_li.removeClass('active-trail').addClass('active-trail');
              }
            });
          }
        });

        $('aside .menu li.active-trail.dropdown').addClass('open').find('.menu-opener').find('.glyphicon').removeClass('glyphicon-menu-right').addClass('glyphicon-menu-down');
        $('aside .menu li.active-trail.dropdown').addClass('open').find('.menu-opener').find('.glyphicon').removeClass('glyphicon-menu-right').addClass('glyphicon-menu-down');

        $('.menu-opener').on('click', function(){
          $(this).parent().toggleClass('open');
          if ($(this).find('.glyphicon').hasClass('glyphicon-menu-down')) {
            $(this).find('.glyphicon').removeClass('glyphicon-menu-down').addClass('glyphicon-menu-right');
          } else {
            $(this).find('.glyphicon').removeClass('glyphicon-menu-right').addClass('glyphicon-menu-down');
          }
        });

        $('.form-item-printers-list select').on('change', function(){
          $('.field-name-field-st-printer-name input[type=text]').val($(this).val());
        });

        $('.form-item-branches-list select').on('change', function(){
          $('.field-name-field-apteka-id input[type=text]').val($(this).val());
        });

        $(document).on('click', '#-customizer-print-product-barcode #edit-submit', function(e) {
          e.preventDefault();

          var w = window.open();
          var title = $('.product-title').val();
          var product_id = $('.product-id').val();
          var copy = $('#edit-copy').val();
          var barcode = $('#edit-barcode').val();

          $.ajax({
            method: "POST",
            async: false,
            url: "/dashboard/custom_calls",
            data: { request_id: "barcodeA4", title: title, product_id: product_id, copy: copy, barcode: barcode }
          }).done(function( msg ) {
            w.document.write(msg);
            setTimeout(function() {
              w.print();
              w.close();
            }, 500);
          });

        });

        if ($.fn.pos) {
          $(document).pos();
        }

        //auto focus barcode
        $(document).on('scan.pos.barcode', function(event) {
          if ($('body').hasClass('page-dashboard-warehouse')) {
            $('input[name="field_md_up_barcode_value"]').val(event.code);
            $('input[name="field_md_up_barcode[und][0][value]"]').focus().val(event.code);

            $("button[id*='edit-submit-warehouse']").click();
          }

        });
    });

      if ($(document).height()>$('.main-container aside').height()) {
        $('.main-container aside').css('height', ($(document).height()-31));
      } else {
        $('.main-container aside').removeAttr('style');
      }


      $('.sidebar-menu-toggle').click(function(){
        if (!$('#sidedrawer').hasClass('op')) {
          $('#sidedrawer').addClass('op');
          $(this).find('span').removeClass('glyphicon-menu-hamburger').addClass('glyphicon-remove');
          $(this).addClass('opened');
          if ($(window).width()>990) {
            Cookies.set('menu_opened',1, { expires: 365 });
          } else {
            $('.menu-overlay').addClass('in');
            $('.menu-overlay').removeClass('hide');
            $('body').removeClass('in').addClass('modal-open');
          }
        } else {
          $('#sidedrawer').removeClass('op');
          $('.menu-overlay').removeClass('in');
          $('.menu-overlay').removeClass('hide').addClass('hide');
          $('body').removeClass('modal-open');
          $(this).find('span').removeClass('glyphicon-remove').addClass('glyphicon-menu-hamburger');
          $(this).removeClass('opened');
          Cookies.remove('menu_opened');
        }
      });

      $('.menu-overlay').click(function(){
        $('.sidebar-menu-toggle').trigger('click');
      });

      $('.view .nav-tabs a').click(function() {
        Cookies.set('nav_tab', $(this).attr('href'), { expires: 365 });
      });

			if (Cookies.get('nav_tab')) {
				$('.view .nav-tabs a[href="'+Cookies.get('nav_tab')+'"]').tab('show');
			}



			//Print button click
			$('.feed-icon .print-page').on('click', function(e){
				e.preventDefault();
				Print();
			});



			// Print button function
			var printUpdate = function () {
				if ($('.page-dashboard-reports li.active a[href=#chart]').length) {
					$('.charts-highchart').highcharts().setSize(700, $('.charts-highchart').height());
				}
			};

			var afterPrint = function () {
				if ($('.page-dashboard-reports li.active a[href=#chart]').length) {
					$('.charts-highchart').highcharts().setSize($('.charts-highchart').parent().width(), $('.charts-highchart').height());
				}
			};

			function Print() {
				printUpdate();

				setTimeout(function() {
					window.print();
					afterPrint();
				},500);
			}


			//Check for integer
			$("body").on('keyup', '.integer', function(){
				this.value = this.value.replace(/[^0-9]/g, '');
			});


      //Check for integer and percent
      $("body").on('keyup', '.integer-percent', function(){
        this.value = this.value.replace(/[^0-9%\.]/g, '');
      });


      //Set tooltip for feed-icon
      $('.feed-icon a img[alt=XLSX]').parent().attr('title', 'Экспорт на Excel файл');
      $('.feed-icon a').tooltip();

      //Ask confirmation before closing the tab/browser
      $('.sell-process-exit').on('click', function(e) {
        e.preventDefault();
        var message = "Вы точно хотите выйти из программы?";

        if ($('.sell-process-exit').hasClass('pos-exit')) {
          message = "Вы точно хотите выйти из кассы?";
        }

        bootbox.confirm({
          message: message,
          buttons: {
            confirm: {
              label: 'Да',
              className: 'btn-success'
            },
            cancel: {
              label: 'Нет',
              className: 'btn-danger'
            }
          },
          callback: function (result) {
            if (result) {
              window.location = $('.sell-process-exit').attr('href');
            }
          }

        });

      });


      //Toggle payment type checkbox when terminal field's value is changed
      $('.field-name-field-trc-payment-terminal input[type=text]').on('keyup', function() {
        $('.form-item-field-trc-payment-type-und-9729 input[type=checkbox]').prop('checked', false);
        if (Drupal.behaviors.cube.isFloat($(this).val())) {
          if (parseFloat($(this).val())>0) {
            $('.form-item-field-trc-payment-type-und-9729 input[type=checkbox]').prop('checked', true);
          }
        }
      });


      //Toggle payment type checkbox when cash field's value is changed
      $('.field-name-field-trc-payment-cash input[type=text]').on('keyup', function() {
        $('.form-item-field-trc-payment-type-und-9730 input[type=checkbox]').prop('checked', false);
        if (Drupal.behaviors.cube.isFloat($(this).val())) {
          if (parseFloat($(this).val())>0) {
            $('.form-item-field-trc-payment-type-und-9730 input[type=checkbox]').prop('checked', true);
          }
        }
      });


      //Toggle payment type checkbox when owe field's value is changed
      $('.field-name-field-trc-payment-owe input[type=text]').on('keyup', function() {
        $('.form-item-field-trc-payment-type-und-10342 input[type=checkbox]').prop('checked', false);
        if (Drupal.behaviors.cube.isFloat($(this).val())) {
          if (parseFloat($(this).val())>0) {
            $('.form-item-field-trc-payment-type-und-10342 input[type=checkbox]').prop('checked', true);
          }
        }
      });



      //Check for decimal
      $("body").on('keyup', '.decimal', function(){

        $(this).val($(this).val().replace(',','.'))

        var val = $(this).val();
        val = Drupal.behaviors.cube.isFloat(val);

        $(this).val(val);
      });



      //Highlight selected filters
      $('.view-filters input[type=text]').each(function(){
        if ($(this).attr('type')=='text' && $(this).val()!='') {
          $(this).addClass('input-highlighted');
        }
      });

      $('.view-filters input[type=text]').on('change', function() {
        $(this).removeClass('input-highlighted');
        if ($(this).attr('type')=='text' && $(this).val()!='') {
          $(this).addClass('input-highlighted');
        }
      });

      //Highlight selected filters
      $('.view-filters select').each(function(){
        if ($(this).val()!='All') {
          $(this).addClass('input-highlighted');
        }
      });

      //Highlight selected filters
      $('.view-filters select').on('change', function(){
        $(this).removeClass('input-highlighted');
        if ($(this).val()!='All') {
          $(this).addClass('input-highlighted');
        }
      });

      //Check if rate enabled
      if ($('.field-name-field-rate-show input').length) {
        $('.header-rate').removeClass('hide');
        if (!$('.field-name-field-rate-show input').is(':checked')) {
          $('.header-rate').addClass('hide');
        }
      }

      //Toggle rate header
      $('.field-name-field-rate-show input').on('click', function(){
        $('.header-rate').removeClass('hide');
        if (!$(this).is(':checked')) {
          $('.header-rate').addClass('hide');
        }
      });


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



      //Show loading
      window.addEventListener("beforeunload", function(e) {
        setTimeout(function(){
        }, 20000);progressbar_process();
      });

    }

  };

  Drupal.behaviors.cube.isInt = function(value) {
    var x;
    return isNaN(value) ? !1 : (x = parseFloat(value), (0 | x) === x);
  };

  Drupal.behaviors.cube.isFloat = function(val) {
    val = val.replace(' ','');

    if(isNaN(val)){
      val = val.replace(/[^0-9\.]/g,'');
      if(val.split('.').length>2) {
        val =val.replace(/\.+$/,"");
      }
    }

    if (Drupal.behaviors.cube.decimalPlaces(val)>2) {
      val = parseFloat(val);
      val = val.toFixed(2);
    }

    return val;
  };

  Drupal.behaviors.cube.decimalPlaces = function(num) {
    var match = (''+num).match(/(?:\.(\d+))?(?:[eE]([+-]?\d+))?$/);
        if (!match) { return 0; }
        return Math.max(
             0,
             // Number of digits right of decimal point.
             (match[1] ? match[1].length : 0)
             // Adjust for scientific notation.
             - (match[2] ? +match[2] : 0));
  };

  Drupal.behaviors.ACChangeEnterBehavior = {
    attach: function(context, settings) {
      $('.form-autocomplete input.form-text', context).once('ac-change-enter-behavior', function() {
        $(this).keypress(function(e) {
          var ac = $('.form-autocomplete .dropdown');
          if (e.keyCode == 13 && typeof ac[0] != 'undefined') {
            e.preventDefault();
			var fauxEvent = $.Event('mousedown'); // Create an event to trigger
			$('li.selected', ac).trigger(fauxEvent);
          }
        });
      });
    }
  }
})(jQuery);