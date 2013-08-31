find = `find . -type d -not -path ./build -and -not -path ./build/core`

arr = find.split("\n")

arr.each { |s|
  s.insert(0, '-I')
}

str = arr.join(" ")

puts str
