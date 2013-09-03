find = `find . -type d -not -path ./build -and -not -path ./build/core -and -not -path ./build-utils`

arr = find.split("\n")

arr.each { |s|
  s.insert(0, '-I')
}

str = arr.join(" ")

puts str
