puts `find . -name "\*.cpp" -not -path "./build/\*" -and -not -path "./build/core/\*"`.gsub("\n", ' ')
