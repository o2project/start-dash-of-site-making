"use strict";

/**
 * packages (gulp)
 */
var gulp = require("gulp");
var csscomb = require("gulp-csscomb");
var csslint = require("gulp-csslint");
var minifyCss = require("gulp-minify-css");
var postcss = require("gulp-postcss");
var sourcemaps = require("gulp-sourcemaps");
var stylestats = require("gulp-stylestats");

/**
 * packages (others)
 */
var autoprefixer = require("autoprefixer-core");
var del = require("del");
var sequence = require("run-sequence");

/**
 * directories
 */
var dirs = {
  dist: "dist",
  src: "src/css"
};

//////////////////////////////////////////////////

gulp.task("build", function (cb) {
    return sequence(
        "clean",
        "copy",
        ["csscomb", "autoprefixer"],
        "minify-css",
        ["csslint", "stylestats"],
    cb);
});

gulp.task("run", function (cb) {
    return sequence(
        "clean",
        "copy",
        ["csscomb", "autoprefixer"],
    cb);
});

gulp.task("test", function (cb) {
    return sequence(
        "csslint",
    cb);
});

gulp.task("watch", function () {
    gulp.watch(dirs.src + "/*.css", ["build"]);
});

gulp.task("clean", del.bind(null, [
    dirs.dist + "/*.css",
], {dot: true}));

gulp.task("copy", function () {
    return gulp.src([
        dirs.src + "/*.css"
    ])
    .pipe(gulp.dest(dirs.dist));
});

gulp.task("autoprefixer", function () {
    return gulp.src(dirs.dist + "/*.css")
        .pipe(postcss([
            autoprefixer({
                browsers: [
                    "last 2 versions",
                    "Firefox ESR"
                ]
            })
        ]))
        .pipe(gulp.dest(dirs.dist));
});

gulp.task("csscomb", function () {
    return gulp.src(dirs.dist + "/*.css")
        .pipe(csscomb())
        .pipe(gulp.dest(dirs.dist));
});

gulp.task("minify-css", function () {
    return gulp.src(dirs.dist + "/*.css")
        .pipe(sourcemaps.init())
        .pipe(minifyCss())
        .pipe(sourcemaps.write("."))
        .pipe(gulp.dest(dirs.dist));
});

gulp.task("csslint", function () {
    return gulp.src(dirs.dist + "/*.css")
        .pipe(csslint("csslintrc.json"))
        .pipe(csslint.reporter())
        .pipe(csslint.failReporter());
});

gulp.task("stylestats", function () {
    return gulp.src(dirs.dist + "/*.css")
        .pipe(stylestats());
});
