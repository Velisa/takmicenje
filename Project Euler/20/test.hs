result = sum[(product[1..100]::Integer)`div`(10^x)`mod`10|x<-[0..(floor((logBase 10 (product [1..100]))))]]
