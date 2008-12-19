require 'rake'
require 'rake/clean'
require 'rake/tasklib'
require 'fileutils'

CLOBBER.include("*.hi", "*.o", "*_stub.*", "*.dll", "*.a")
CLEAN.include("*.hi", "*.o", "*.dll", "*.a")

file "Test_stub.o" do
  FileUtils.cd File.dirname(__FILE__) do
    sh "ghc -c Test.hs"
  end
end

desc "Compile extension"
file "fib.dll" => "Test_stub.o" do
  FileUtils.cd File.dirname(__FILE__) do
    sh %(ghc -shared -I. -Ic:/ruby_mingw32/lib/ruby/1.8/i386-mingw32 -Lc:/ruby_mingw32/lib -L. fib.c Test.o Test_stub.o -lmsvcrt-ruby18  -lws2_32 -o fib.dll)
  end
end

task :makefib => "fib.dll"