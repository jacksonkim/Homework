SELECT INITCAP(title), TO_CHAR(cost, '$999.99') "Cost", 
TO_CHAR(retail, '$999.99') "Retail",
TO_CHAR((retail-cost)/retail*100, '99') || '%' "Percentage Markup"
  FROM books;
    
SELECT TO_CHAR(current_date, 'DAY HH:MM:SS') "Laptop Time",
  TO_CHAR(sysdate, 'DAY HH:MM:SS') "Server Time"
  FROM DUAL;
  
SELECT INITCAP(title), LPAD(TO_CHAR(cost, '$999.99'), 12, '*') "Cost", 
LPAD(TO_CHAR(retail, '$999.99'), 12, '*') "Retail"
  FROM books;
  
SELECT DISTINCT LENGTH(isbn)
  FROM books;

SELECT INITCAP(title), pubdate, current_date,
ROUND(MONTHS_BETWEEN(current_date, pubdate), 0) "Months Old"
  FROM books;
  
SELECT NEXT_DAY(current_date, 'WEDNESDAY') "Next Wednesday"
  FROM DUAL;

SELECT customer# Customer, 
LPAD(SUBSTR(zip, -3, 2), 5, ' ') "Digits 3 and 4 of Zip" , 
INSTR(customer#, '3') "First 3"
  FROM customers;