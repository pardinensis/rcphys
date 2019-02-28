#!//usr/bin/gnuplot
unset key
unset tics
unset border
set size ratio -1
set style data lines
set style line 1 lc rgb "black" lw 1
set style line 2 lc rgb "red" lw 2
set term pngcairo

set output "airtime1.png"
plot "airtime.txt" using 1:2 ls 1, "airtime.txt" using 4:5 ls 2

set output "airtime2.png"
plot "airtime.txt" using 1:3 ls 1, "airtime.txt" using 4:6 ls 2

set output "airtime3.png"
plot "airtime.txt" using 2:3 ls 1, "airtime.txt" using 5:6 ls 2


