group :build do
  guard 'rake', :task => 'redpen' do
    watch(%r{^draft/.+\.md$})
  end

  guard 'rake', :task => 'md2review' do
    watch(%r{^draft/.+\.md$})
  end

  guard 'rake', :task => 'html' do
    watch(%r{^draft/.+\.md$})
  end

  guard 'rake', :task => 'epub' do
    watch(%r{^draft/.+\.md$})
  end

  guard 'rake', :task => 'html' do
    watch(%r{^draft/.+\.md$})
  end
end

group :redpen do
  guard 'rake', :task => 'redpen' do
    watch(%r{^draft/.+\.md$})
  end
end

group :html do
  guard 'rake', :task => 'md2review' do
    watch(%r{^draft/.+\.md$})
  end

  guard 'rake', :task => 'html' do
    watch(%r{^draft/.+\.md$})
  end
end
