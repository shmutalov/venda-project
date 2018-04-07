<ul class="nav nav-pills report-main-nav">
  <li role="presentation" class="active"><a href="#">По дате</a></li>
  <li role="presentation"><a href="#">По продуктам</a></li>
  <li role="presentation"><a href="#">По продавцам</a></li>
  <li role="presentation"><a href="#">По часам</a></li>
  <li role="presentation"><a href="#">По прибылям</a></li>
  <li role="presentation"><a href="#">Все транзакции</a></li>
</ul>

<div class="row">
  <div class="col-sm-12">
      <div class="panel panel-default">
        <div class="panel-heading" role="tab" id="headingOne">
          <h3 class="panel-title text-center"><a role="button" data-toggle="collapse" href="#collapseOne" aria-expanded="true" aria-controls="collapseOne">
            Фильтры
          </a></h3>
        </div>
        <div id="collapseOne" class="panel-collapse collapse" role="tabpanel" aria-labelledby="headingOne">
          <div class="panel-body">
            <div class="row">
              <div class="col-sm-3">
                <div class="form-group">
                  <label for="exampleInputEmail1">Дата</label>
                  <input type="text" class="form-control" placeholder="от">
                </div>
              </div>
              <div class="col-sm-3">
                <div class="form-group">
                  <label for="exampleInputEmail1">&nbsp;</label>
                  <input type="text" class="form-control" placeholder="до">
                </div>
              </div>
              <div class="col-sm-6">
                <div class="form-group">
                  <label for="exampleInputEmail1">Продукт</label>
                  <input type="text" class="form-control">
                </div>
              </div>
            </div>
            <div class="row">
              <div class="col-sm-12">
                <div class="form-group">
                  <button type="submit" class="btn btn-primary">Фильтровать</button>
                  <button type="submit" class="btn btn-default">Очистить</button>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
      
      <div class="panel panel-default">
        <div class="panel-heading" role="tab" id="headingTwo">
          <h3 class="panel-title text-center"><a role="button" data-toggle="collapse"href="#collapseTwo" aria-expanded="true" aria-controls="collapseTwo">
            Диаграмма
          </a></h3>
        </div>
        <div id="collapseTwo" class="panel-collapse collapse in" role="tabpanel" aria-labelledby="headingTwo">
          <div class="panel-body">
            <img src="/sites/all/themes/cube/images/diagram.png" style="width:100%;height:auto;"/>
          </div>
        </div>
      </div>
      
      <div class="panel panel-default">
        <div class="panel-heading" role="tab" id="headingThree">
          <h3 class="panel-title text-center"><a role="button" data-toggle="collapse" href="#collapseThree" aria-expanded="true" aria-controls="collapseThree">
            Детальный вид
          </a></h3>
        </div>
        <div id="collapseThree" class="panel-collapse collapse in" role="tabpanel" aria-labelledby="headingThree">
          <div class="panel-body">
            <table class="non-left-medicaments table table-condensed table-hover">
            <thead>
              <tr>
                <th>Название продукта</th>
                <th>Количество</th>
                <th>Цена</th>
                <th>Дата продажи</th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td><a href="#">Цитрамон</a></td>
                <td>1</td>
                <td>1000 сум</td>
                <td>05.01.2016</td>
              </tr>
              <tr>
                <td><a href="#">Аэвит</a></td>
                <td>1.5</td>
                <td>12000 сум</td>
                <td>03.01.2016</td>
              </tr>
              <tr>
                <td><a href="#">Йодомарин</a></td>
                <td>2</td>
                <td>21000 сум</td>
                <td>02.01.2016</td>
              </tr>
              <tr>
                <td><a href="#">Фуросемид</a></td>
                <td>5</td>
                <td>43000 сум</td>
                <td>02.01.2016</td>
              </tr>
              <tr>
                <td><a href="#">Ампициллина тригидрат</a></td>
                <td>1</td>
                <td>3000 сум</td>
                <td>30.12.2015</td>
              </tr>
            </tbody>
          </table>
          </div>
        </div>
      </div>
      
  </div>
</div>