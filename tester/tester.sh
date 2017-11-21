#
# USER INPUT: No not include ".cpp" or any other extension!
#
myfile=$1
#
# END USER INPUT
#
# Format code
echo "Formatting code..."
clang-format.exe -i -style=google ./$myfile.cpp
#
# Check that for each input file, there is also the solution file
# (for each in.tst there is a sol.tst file)
#
# Get all in.tst test numbers in an array
i=0
#while read file
for file in ./tests/*.in.tst;
do
  array[ $i ]=$(grep -oP '(?<=[.])[0-9]+(?=[.])' <<< "$file")
  (( i++ ))
done

for (( idx=0; idx<$i; idx++ ))
do
  echo "Found test number: "${array[idx]}
#  echo "Found test number: "${array[idx]} >> $myfile.tests.report.tst
done
#
# Check if corresponding sol.tst files exist
for (( idx=0; idx<$i; idx++ ))
do
  if [ -f ./tests/$myfile.test.${array[idx]}.sol.tst ]; then
    echo "Found solution number: "${array[idx]}
#    echo "Found solution number: "${array[idx]} >> $myfile.tests.report.tst
  else
    echo "SOLUTION "${array[idx]}" NOT FOUND => EXIT"
#    echo "SOLUTION "${array[idx]}" NOT FOUND => EXIT" >> $myfile.tests.report.tst
    exit
  fi
done
#
# Delete all .out.tst files whether they exist or not
# Doesn't matter if there is an error message if there are
# not files to delete (we don't know what happened in the
# previous run)
echo "Deleting all output (.out.tst) files..."
#echo "Deleting all output (.out.tst) files..." >> $myfile.tests.report.tst
rm ./tests/*.out.tst
#
# Delete old tests report file
echo "Deleting old tests report file..."
#echo "Deleting old tests report file..." >> $myfile.tests.report.tst
rm $myfile.tests.report.tst
#
# Delete old compiler output file
echo "File: "$myfile".cpp"
#echo "File: "$myfile".cpp" >> $myfile.tests.report.tst
echo "Deleting old compiler output file..."
#echo "Deleting old compiler output file..." >> $myfile.tests.report.tst
if [ -f $myfile.cpp.compiler.tst ]; then
    rm $myfile.cpp.compiler.tst
    echo "Old compiler output file found and deleted"
#    echo "Old compiler output file found and deleted" >> $myfile.tests.report.tst
else
    echo "Old compiler output file NOT found"
#    echo "Old compiler output file NOT found" >> $myfile.tests.report.tst
fi
#
# Delete old exe file
echo "Deleting old exe file..."
#echo "Deleting old exe file..." >> $myfile.tests.report.tst
if [ -f $myfile.exe ]; then
    rm $myfile.exe
    echo "Old exe file found and deleted"
#    echo "Old exe file found and deleted" >> $myfile.tests.report.tst
else
    echo "Old exe file NOT found"
#    echo "Old exe file NOT found" >> $myfile.tests.report.tst
fi
#
# Compile
echo "Compiling..."
#echo "Compiling..." >> $myfile.tests.report.tst
g++ -std=c++14 $myfile.cpp -o $myfile.exe 2> $myfile.cpp.compiler.tst
#
# Check if there have been errors during compilation
numlines=$(wc -l < "$myfile.cpp.compiler.tst")
if [ $numlines -eq 0 ]; then
    echo "Compiler output file is empty"
#    echo "Compiler output file is empty" >> $myfile.tests.report.tst
    echo "Deleting compiler output file..."
#    echo "Deleting compiler output file..." >> $myfile.tests.report.tst
    rm $myfile.cpp.compiler.tst
    echo "Executing/Testing..."
#    echo "Executing/Testing..." >> $myfile.tests.report.tst
    for (( idx=0; idx<$i; idx++ ))
    do
      echo "Testing "${array[idx]}
      echo "Testing "${array[idx]} >> $myfile.tests.report.tst
      ./$myfile.exe < ./tests/$myfile.test.${array[idx]}.in.tst > ./tests/$myfile.test.${array[idx]}.out.tst
      if diff ./tests/$myfile.test.${array[idx]}.out.tst ./tests/$myfile.test.${array[idx]}.sol.tst; then
        echo "........................TEST "${array[idx]}": PASS"
        echo "........................TEST "${array[idx]}": PASS" >> $myfile.tests.report.tst
      else
        echo "........................TEST "${array[idx]}": FAIL"
        echo "........................TEST "${array[idx]}": FAIL" >> $myfile.tests.report.tst
      fi
    done
else
  echo "!!!!!!!!!!!!!!!!!!!!!!!! Compiler output file NOT empty"
#  echo "!!!!!!!!!!!!!!!!!!!!!!!! Compiler output file NOT empty" >> $myfile.tests.report.tst
  warninglines=$(grep warning $myfile.cpp.compiler.tst | wc -l)
  errorlines=$(grep error $myfile.cpp.compiler.tst | wc -l)
  echo "!!!!!!!!!!!!!!!!!!!!!!!! Warning lines: "$warninglines
#  echo "!!!!!!!!!!!!!!!!!!!!!!!! Warning lines: "$warninglines >> $myfile.tests.report.tst
  echo "!!!!!!!!!!!!!!!!!!!!!!!! Error lines: "$errorlines
#  echo "!!!!!!!!!!!!!!!!!!!!!!!! Error lines: "$errorlines >> $myfile.tests.report.tst
  echo "Showing compiler output => EXIT"
#  echo "Showing compiler output => EXIT" >> $myfile.tests.report.tst
  cat $myfile.cpp.compiler.tst
  exit
  # 
  # There is an option to proceed with testing if there are
  # warnings only, but we are not using it
  #if [ $errorlines -eq 0 ]; then
fi