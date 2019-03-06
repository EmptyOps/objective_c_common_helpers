
Pod::Spec.new do |s|
  s.name             = 'objective_c_common_helpers'
  s.version          = '0.0.1'
  s.summary          = 'A common helpers for objective_c'

  s.description      = <<-DESC
This pod contains common helpers files. 
                       DESC

  s.homepage         = 'https://github.com/EmptyOps/objective_c_common_helpers'

  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'EmptyOps' => 'hsquaretechnology@gmail.com' }
  s.source           = { :git => 'https://github.com/EmptyOps/objective_c_common_helpers.git', :tag => s.version.to_s }
  
  s.platform = :ios, '7.0'
  
  s.dependency 'objective_c_core_helpers', '~> 0.0.2' 
  s.dependency 'objective_c_sqlite_helper', '~> 0.0.2'
  s.dependency 'SDWebImage', '~> 3.6'
  s.dependency 'DGActivityIndicatorView'
  
  s.requires_arc = true
  
  s.source_files = 'objective_c_common_helpers/Classes/**/*'
  
end
