#while true; do
sleep 10
echo 1 0 3 2 5 4 7 6
sleep 10
echo 2 1 0 5 4 3 7 6 
sleep 10
echo 3 2 1 0 7 6 5 4 
sleep 10
echo 7 6 5 4 3 2 1 0 
sleep 10
echo 0 1 2 3 4 5 6 7
ps -ef | grep ./debug | grep -v grep | awk '{ print $2 }' | xargs kill -2
#done
