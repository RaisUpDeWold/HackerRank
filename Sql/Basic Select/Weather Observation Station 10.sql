/*
Enter your query here.
*/
SELECT DISTINCT CITY FROM STATION
WHERE CITY REGEXP '[^aeiou]$';
