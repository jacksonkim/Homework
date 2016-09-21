SELECT COUNT(category)
  FROM books
    WHERE category = 'COOKING';
    
SELECT COUNT(retail)
  FROM books
    WHERE retail >= 30.00;
    
SELECT MAX(pubdate)
  FROM books;
  
SELECT SUM((paideach-cost)*quantity) 
  "Total Profit: 1017"
  FROM books NATURAL JOIN orderitems NATURAL JOIN orders
    WHERE customer# = 1017;
    
SELECT MIN(retail)
  FROM books
    WHERE category = 'COMPUTER';
    
SELECT AVG(SUM((paideach-cost)*quantity)) "Average Profit"
  FROM orders JOIN orderitems USING (order#)
  NATURAL JOIN books
  GROUP BY order#;
  
SELECT customer#, COUNT(order#) "Number of Orders"
  FROM orders
    GROUP BY (customer#)
    ORDER BY customer#;

SELECT name, category, AVG(retail) "Average Retail"
  FROM books JOIN publisher USING (pubid)
    WHERE category IN ('CHILDREN', 'COMPUTER')
    GROUP BY ROLLUP(name, category, retail)
    HAVING AVG(retail) >= 50;
    
SELECT SUM(paideach*quantity) "Order Total"
   FROM orders JOIN orderitems USING (order#)
    WHERE shipstate IN ('GA', 'FL')
    GROUP BY paideach, quantity
    HAVING SUM(paideach*quantity) >= 80;
    
SELECT MAX(retail)
  FROM books JOIN bookauthor USING (isbn)
  JOIN author USING (authorid)
    WHERE lname = 'WHITE' AND fname = 'LISA';