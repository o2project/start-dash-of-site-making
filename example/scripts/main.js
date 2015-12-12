$(function() {
  "use strict";

  //////////////////////////////////////////////////

  function Carousel(carouselE, config) {
    this.carouselE = carouselE;
    carouselE.slick(config);
  }

  Carousel.prototype.currentIndex = function() {
    return this.carouselE.slick("slickCurrentSlide");
  };

  //////////////////////////////////////////////////

  function CarouselPagination(paginationE, paginationItemElms, activePageName) {
    this.activePageName = activePageName;
    this.paginationE = paginationE;
    this.paginationItemElms = paginationItemElms;
  }

  CarouselPagination.prototype.activatePage = function(index) {
    this.paginationItemElms[index].classList.add(this.activePageName);
  };

  CarouselPagination.prototype.deactivatePage = function() {
    var _this = this;

    Array.prototype.map.call(this.paginationItemElms, function(paginationItemE) {
      paginationItemE.classList.remove(_this.activePageName);
    });
  };

  //////////////////////////////////////////////////

  var carouselE = $(".js_slides");
  var paginationE = $(".js_slides-pagination");
  var paginationItemElms = $(".js_slides-pagination li");

  var carousel = new Carousel(carouselE, {
    autoplaySpeed: 5000,
    autoplay: true,
    arrows: false
  });

  var carouselPagination = new CarouselPagination(paginationE, paginationItemElms, "ll-slides-pagination__active");
  carouselPagination.activatePage(carousel.currentIndex());

  carouselE.on("afterChange", function() {
    carouselPagination.deactivatePage();
    carouselPagination.activatePage(carousel.currentIndex());
  });
});
