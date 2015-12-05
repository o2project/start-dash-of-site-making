require 'rake'

task default: :all

desc 'Create all books (HTML, PDF, ePub)'
task all: [:html, :pdf, :epub]

desc 'Copy Re:VIEW files'
task :copy do
  sh 'cp ./src/*.re .'
end

desc 'Create PDF'
task :pdf do
  sh 'rm -rf *pdf'
  Rake::Task['md2review'].invoke()
  Rake::Task['copy'].invoke()
  sh 'bundle exec review-pdfmaker config.yml'
end

desc 'Create ePub'
task :epub do
  Rake::Task['md2review'].invoke()
  Rake::Task['copy'].invoke()
  sh 'bundle exec review-epubmaker config.yml'
end

desc 'Create HTML'
task :html do
  Rake::Task['md2review'].invoke()
  Rake::Task['copy'].invoke()
  sh 'bundle exec review-compile --all --target=html --footnotetext --stylesheet=styles/main.css --chapterlink'
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

desc 'Proofreading by redpen'
task :redpen do
  config_file = './settings/redpen-conf-ja.xml'
  target_files = './draft/*.md'

  sh "redpen-distribution-*/bin/redpen -v"

  Dir.glob(target_files) do |file|
    sh "redpen-distribution-*/bin/redpen -c redpen-conf-ja.xml -f markdown #{file}"
  end
end

namespace :ci do
  REPOSITORY_NAME = 'o2project/start-dash-of-site-making'
  REPOSITORY = if ENV['GH_TOKEN']
                 "https://$GH_TOKEN@github.com/#{REPOSITORY_NAME}"
               else
                 "git@github.com:#{REPOSITORY_NAME}"
               end
  PUBLISH_BRANCH = 'gh-pages'
  TEMP_DIR = 'build'

  def init_repo(repo, branch)
    require 'fileutils'

    if Dir["#{TEMP_DIR}/.git"].empty?
      FileUtils.rm_rf TEMP_DIR
      sh "git clone --quiet #{repo} #{TEMP_DIR} 2> /dev/null"
    end

    Dir.chdir TEMP_DIR do
      sh "git checkout --orphan #{branch}"
    end
  end

  def update_repo(branch)
    Dir.chdir TEMP_DIR do
      sh 'git fetch origin'
      sh "git reset --hard origin/#{branch}"
    end
  end

  def push_to_target_branch(repo, branch)
    sha1, _ = `git log -n 1 --oneline`.strip.split(' ')

    sh 'git add -A'
    sh "git commit -m '[ci skip] Update with #{sha1}'"
    sh "git push --quiet #{repo} #{branch}"
  end

  task :setup do
    init_repo REPOSITORY, PUBLISH_BRANCH
    update_repo PUBLISH_BRANCH
  end

  task :example do
    Rake::Task['copy'].invoke()
    sh 'bundle exec review-compile --all --target=html --footnotetext --stylesheet=styles/main.css --chapterlink'
    sh 'cp -r example/ build/example'
  end

  task :html do
    Rake::Task['copy'].invoke()
    sh 'bundle exec review-compile --all --target=html --footnotetext --stylesheet=styles/main.css --chapterlink'
    sh 'cp *.html build/'
    sh 'cp -r images/ build/images/'
    sh 'cp -r styles/ build/styles/'
  end

  task :publish do
    Rake::Task['ci:example'].invoke()
    Rake::Task['ci:html'].invoke()
    push_to_target_branch REPOSITORY, PUBLISH_BRANCH
      Dir.chdir TEMP_DIR do
    end
  end
end
