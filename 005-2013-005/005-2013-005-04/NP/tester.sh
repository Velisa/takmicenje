#
# USER INPUT: No not include ".cpp" or any other extension!
#
myfile=$1
#
# END USER INPUT
#
# Check that for each input file, there is also the solution file
# (for each in.txt there is a sol.txt file)
#
# Get all in.txt test numbers in an array
i=0
#while read file
for file in ./tests/*.in.txt;
do
  array[ $i ]=$(grep -oP '(?<=[.])[0-9]+(?=[.])' <<< "$file")
  (( i++ ))
done

for (( idx=0; idx<$i; idx++ ))
do
  echo "Found test number: "${array[idx]}
#  echo "Found test number: "${array[idx]} >> $myfile.tests.report.txt
done
#
# Check if corresponding sol.txt files exist
for (( idx=0; idx<$i; idx++ ))
do
  if [ -f ./tests/$myfile.test.${array[idx]}.sol.txt ]; then
    echo "Found solution number: "${array[idx]}
#    echo "Found solution number: "${array[idx]} >> $myfile.tests.report.txt
  else
    echo "SOLUTION "${array[idx]}" NOT FOUND => EXIT"
#    echo "SOLUTION "${array[idx]}" NOT FOUND => EXIT" >> $myfile.tests.report.txt
    exit
  fi
done
#
# Delete all .out.txt files whether they exist or not
# Doesn't matter if there is an error message if there are
# not files to delete (we don't know what happened in the
# previous run)
echo "Deleting all output (.out.txt) files..."
#echo "Deleting all output (.out.txt) files..." >> $myfile.tests.report.txt
rm ./tests/*.out.txt
#
# Delete old tests report file
echo "Deleting old tests report file..."
#echo "Deleting old tests report file..." >> $myfile.tests.report.txt
rm $myfile.tests.report.txt
#
# Delete old compiler output file
echo "File: "$myfile".cpp"
#echo "File: "$myfile".cpp" >> $myfile.tests.report.txt
echo "Deleting old compiler output file..."
#echo "Deleting old compiler output file..." >> $myfile.tests.report.txt
if [ -f $myfile.cpp.compiler.txt ]; then
    rm $myfile.cpp.compiler.txt
    echo "Old compiler output file found and deleted"
#    echo "Old compiler output file found and deleted" >> $myfile.tests.report.txt
else
    echo "Old compiler output file NOT found"
#    echo "Old compiler output file NOT found" >> $myfile.tests.report.txt
fi
#
# Delete old exe file
echo "Deleting old exe file..."
#echo "Deleting old exe file..." >> $myfile.tests.report.txt
if [ -f $myfile.exe ]; then
    rm $myfile.exe
    echo "Old exe file found and deleted"
#    echo "Old exe file found and deleted" >> $myfile.tests.report.txt
else
    echo "Old exe file NOT found"
#    echo "Old exe file NOT found" >> $myfile.tests.report.txt
fi
#
# Compile
echo "Compiling..."
#echo "Compiling..." >> $myfile.tests.report.txt
g++ $myfile.cpp -o $myfile.exe 2> $myfile.cpp.compiler.txt
#
# Check if there have been errors during compilation
numlines=$(wc -l < "$myfile.cpp.compiler.txt")
if [ $numlines -eq 0 ]; then
    echo "Compiler output file is empty"
#    echo "Compiler output file is empty" >> $myfile.tests.report.txt
    echo "Deleting compiler output file..."
#    echo "Deleting compiler output file..." >> $myfile.tests.report.txt
    rm $myfile.cpp.compiler.txt
    echo "Executing/Testing..."
#    echo "Executing/Testing..." >> $myfile.tests.report.txt
    for (( idx=0; idx<$i; idx++ ))
    do
      echo "Testing "${array[idx]}
      echo "Testing "${array[idx]} >> $myfile.tests.report.txt
      ./$myfile.exe < ./tests/$myfile.test.${array[idx]}.in.txt > ./tests/$myfile.test.${array[idx]}.out.txt
      if diff ./tests/$myfile.test.${array[idx]}.sol.txt ./tests/$myfile.test.${array[idx]}.out.txt; then
        echo "........................TEST "${array[idx]}": PASS"
        echo "........................TEST "${array[idx]}": PASS" >> $myfile.tests.report.txt
      else
        echo "........................TEST "${array[idx]}": FAIL"
        echo "........................TEST "${array[idx]}": FAIL" >> $myfile.tests.report.txt
      fi
    done
else
  echo "!!!!!!!!!!!!!!!!!!!!!!!! Compiler output file NOT empty"
#  echo "!!!!!!!!!!!!!!!!!!!!!!!! Compiler output file NOT empty" >> $myfile.tests.report.txt
  warninglines=$(grep warning $myfile.cpp.compiler.txt | wc -l)
  errorlines=$(grep error $myfile.cpp.compiler.txt | wc -l)
  echo "!!!!!!!!!!!!!!!!!!!!!!!! Warning lines: "$warninglines
#  echo "!!!!!!!!!!!!!!!!!!!!!!!! Warning lines: "$warninglines >> $myfile.tests.report.txt
  echo "!!!!!!!!!!!!!!!!!!!!!!!! Error lines: "$errorlines
#  echo "!!!!!!!!!!!!!!!!!!!!!!!! Error lines: "$errorlines >> $myfile.tests.report.txt
  echo "Showing compiler output => EXIT"
#  echo "Showing compiler output => EXIT" >> $myfile.tests.report.txt
  cat $myfile.cpp.compiler.txt
  exit
  # 
  # There is an option to proceed with testing if there are
  # warnings only, but we are not using it
  #if [ $errorlines -eq 0 ]; then
fi