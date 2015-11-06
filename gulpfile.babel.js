"use strict";

import Kotori from "kotori";
import del from "del";
import fs from "fs";
import gulp from "gulp";
import sass from "gulp-sass";
import sequence from "run-sequence";

const kotori = new Kotori();

// ------------------------------
// Settings
// ------------------------------

const dir = JSON.parse(fs.readFileSync("./directory-settings.json"));

// ------------------------------
// Before build
// ------------------------------

gulp.task("clean", del.bind(null, [
  `${dir.dest}/*.css`
], {dot: true}));

gulp.task("sass", () => {
  return gulp.src([`${dir.src}/*.scss`])
    .pipe(sass().on("error", sass.logError))
    .pipe(gulp.dest(dir.dest));
});

// ------------------------------
// Build
// ------------------------------

gulp.task("build", (cb) => {
  return sequence(
    "clean",
    "sass",
    "kotori",
    cb);
});

gulp.task("kotori", () => {
  return kotori.src(`${dir.src}/*.css`)
    .pipe(kotori.build())
    .pipe(kotori.dest(dir.dest));
});

// ------------------------------
// Watch
// ------------------------------

gulp.task("watch", () => {
  gulp.watch(`${dir.src}/*.scss`, ["build"]);
});
