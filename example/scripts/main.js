(function () {
    function autoplay(carousel, delay) {
        return setInterval(function() {
            carousel.next();
        }, delay);
    }

    function setPaginationPoint(element) {
        element.classList.add("ll-carousel-pagination-item--current");
    }

    function resetPaginationPoint(paginationNodeList) {
        Array.prototype.map.call(paginationNodeList, function (node) {
            node.classList.remove("ll-carousel-pagination-item--current");
        });
    }

    function setupCarousel(targetElement, options) {
        return lory(targetElement, options);
    }

    document.addEventListener("DOMContentLoaded", function () {
        var carouselE = document.querySelector(".js_carousel");
        var paginationE = document.querySelector(".js_carousel-pagination");
        var paginationItemElms = paginationE.getElementsByClassName("js_carousel-pagination-item")

        var carousel = setupCarousel(carouselE, {
            infinite: 1
        });

        setPaginationPoint(paginationItemElms[carousel.returnIndex() - 1]);
        autoplay(carousel, 5000);

        carouselE.addEventListener("after.lory.slide", function () {
            resetPaginationPoint(paginationItemElms);
            setPaginationPoint(paginationItemElms[carousel.returnIndex() - 1]);
        });
    });
})();
