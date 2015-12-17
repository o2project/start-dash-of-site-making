require 'rake'

REPOSITORY_NAME = 'o2project/start-dash-of-site-making'
ARTICLES_DIR = 'articles'
BOOK_DIR = 'book'

desc 'Create PDF'
task :pdf do
  Dir.chdir ARTICLES_DIR do
    sh "rm -rf *pdf"
    sh "bundle exec review-pdfmaker config.yml"
  end
end

desc 'Create ePub'
task :epub do
  Dir.chdir ARTICLES_DIR do
    sh "bundle exec review-epubmaker config.yml"
  end
end

desc 'Create HTML'
task :html do
  Dir.chdir ARTICLES_DIR do
    sh "bundle exec review-compile --all --chapterlink --footnotetext --target=html --stylesheet=#{BOOK_DIR}/styles/main.css"
  end
end

desc 'Convert Markdown to Re:VIEW'
task :md2review do
  Dir.glob("#{ARTICLES_DIR}/draft/*.md") do |md|
    re = File.basename(md).sub(/\.md$/, '.re')
    sh "bundle exec md2review #{md} > #{ARTICLES_DIR}/#{re}"
  end
end

desc 'Create all books (HTML, PDF, ePub)'
task all: [:md2review, :html, :pdf, :epub]
task default: :all

namespace :ci do
  REPOSITORY = if ENV['GH_TOKEN']
                 "https://$GH_TOKEN@github.com/#{REPOSITORY_NAME}"
               else
                 "git@github.com:#{REPOSITORY_NAME}"
               end
  PUBLISH_BRANCH = 'gh-pages'
  TEMP_DIR = 'build'

  desc 'CI setup'
  task :setup do
    init_repo REPOSITORY, PUBLISH_BRANCH
    update_repo PUBLISH_BRANCH
  end

  desc 'Proofreading by redpen'
  task :redpen do
    config_file = 'articles/redpen-conf-ja.xml'
    target_files = 'articles/draft/*.md'
    redpen_bin = 'redpen-distribution-*/bin/redpen'

    sh "#{redpen_bin} -v"

    Dir.glob(target_files) do |file|
      sh "#{redpen_bin} -c #{config_file} -f markdown #{file}"
    end
  end

  task :copy_example do
    sh 'rm -rf build/example'
    sh 'cp -a example/ build/example'
  end

  task :copy_html do
    sh 'rm -rf build/book/*.html build/book/images build/book/styles'
    Rake::Task['html'].invoke()
    sh "mv articles/*.html book/"
    sh 'cp book/*.html build/book'
    sh 'cp -a articles/images build/book/images'
    sh 'cp -a book/styles build/book/styles'
  end

  task :copy_tokusetsu do
    sh 'rm -rf build/*.html'
    sh 'cp tokusetsu/index.html build/'
  end

  task :publish do
    Rake::Task['ci:copy_example'].invoke()
    Rake::Task['ci:copy_html'].invoke()
    Rake::Task['ci:copy_tokusetsu'].invoke()

    Dir.chdir TEMP_DIR do
      push_to_target_branch REPOSITORY, PUBLISH_BRANCH
    end
  end

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
end
