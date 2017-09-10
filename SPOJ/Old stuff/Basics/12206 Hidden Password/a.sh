echo "Brisanje starog log fajla..."
touch plog.txt
rm plog.txt
echo "Kompajliranje izvornog koda..."
g++ $1.cpp -o $1.cpp.exe
echo "Izvrsavanje testova..."
echo "Rezultati testova:"
for i in `seq $2 $3`;
do
	$1.cpp.exe < $1.in.$i.txt > $1.out.$i.txt
	if diff $1.sol.$i.txt $1.out.$i.txt; then
		echo "++++++++++++++++++++++++TEST "$i": Prosao"
	else
		echo "++++++++++++++++++++++++TEST "$i": Nije prosao"
	fi
done