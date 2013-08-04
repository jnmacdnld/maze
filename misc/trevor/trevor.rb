def generate(args)
  case args.first
  when 'class'
    class_name = args[1]
    `touch #{class_name}.cpp`
    `touch #{class_name}.hpp`
    `touch tests/#{class_name}Test.cpp`
  end
end

case ARGV.first
when 'generate'
  generate ARGV.drop(1)
else
  puts "try \"trevor generate class NAME\""
end


