group :build do
  guard 'rake', :task => 'redpen' do
    watch(%r{^articles/draft/.+\.md$})
  end

  guard 'rake', :task => 'md2review' do
    watch(%r{^articles/draft/.+\.md$})
  end

  guard 'rake', :task => 'html' do
    watch(%r{^articles/draft/.+\.md$})
  end

  guard 'rake', :task => 'epub' do
    watch(%r{^articles/draft/.+\.md$})
  end

  guard 'rake', :task => 'html' do
    watch(%r{^articles/draft/.+\.md$})
  end
end

group :md2review do
  guard 'rake', :task => 'md2review' do
    watch(%r{^articles/draft/.+\.md$})
  end
end

group :redpen do
  guard 'rake', :task => 'redpen' do
    watch(%r{^articles/draft/.+\.md$})
  end
end

group :html do
  guard 'rake', :task => 'md2review' do
    watch(%r{^articles/draft/.+\.md$})
  end

  guard 'rake', :task => 'html' do
    watch(%r{^articles/draft/.+\.md$})
  end
end
