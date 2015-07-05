require 'rake'

desc 'Create all books (HTML, PDF, ePub)'
task all: [:html, :pdf, :epub]

desc 'Copy settings files'
task :copy do
  sh 'cp ./settings/*.yml .'
  sh 'cp ./settings/*.css .'
  sh 'cp ./src/*.re .'
end

desc 'Create PDF'
task :pdf do
  sh 'rm -rf *pdf'
  Rake::Task['copy'].invoke()
  sh 'bundle exec review-pdfmaker config.yml'
end

desc 'Create ePub'
task :epub do
  Rake::Task['copy'].invoke()
  sh 'bundle exec review-epubmaker config.yml'
end

desc 'Create HTML'
task :html do
  Rake::Task['copy'].invoke()
  sh 'bundle exec review-compile --all --target=html --footnotetext --stylesheet=style.css --chapterlink'
end

desc 'Convert `draft/*.md` to `src/*.re`'
task :md2review do
  Dir.glob('draft/*.md') do |md|
    re = File.basename(md).sub(/\.md$/, '.re')
    sh "bundle exec md2review #{md} > src/#{re}"
  end
end

desc 'Clean working files'
task :clean do
  sh 'rm -f *.re'
  sh 'rm -f *.yml'
  sh 'rm -f *.css'
  sh 'rm -f *.html'
  sh 'rm -f *.pdf'
  sh 'rm -f *.epub'
end

task default: :all
