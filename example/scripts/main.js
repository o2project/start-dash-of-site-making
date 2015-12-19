$(function() {
  "use strict";

  //////////////////////////////////////////////////

  function Carousel(carouselElement, config) {
    this.carouselElement = carouselElement;
    carouselElement.slick(config);
  }

  Carousel.prototype.getCurrentIndex = function() {
    return this.carouselElement.slick("slickCurrentSlide");
  };

  //////////////////////////////////////////////////

  function CarouselPagination(paginationElement, paginationItemElements, activePageName) {
    this.activePageName = activePageName;
    this.paginationElement = paginationElement;
    this.paginationItemElements = paginationItemElements;
  }

  CarouselPagination.prototype.activatePage = function(index) {
    this.paginationItemElements[index].classList.add(this.activePageName);
  };

  CarouselPagination.prototype.deactivatePage = function() {
    var _this = this;

    Array.prototype.map.call(this.paginationItemElements, function(paginationItemE) {
      paginationItemE.classList.remove(_this.activePageName);
    });
  };

  //////////////////////////////////////////////////

  var carouselElement = $(".js-slides");
  var paginationElement = $(".js-slides-pagination");
  var paginationItemElements = $(".js-slides-pagination li");

  var carousel = new Carousel(carouselElement, {
    autoplay: true,
    autoplaySpeed: 5000,
    arrows: false
  });

  var carouselPagination = new CarouselPagination(paginationElement, paginationItemElements, "ll-active");
  carouselPagination.activatePage(carousel.getCurrentIndex());

  carouselElement.on("afterChange", function() {
    carouselPagination.deactivatePage();
    carouselPagination.activatePage(carousel.getCurrentIndex());
  });
});
