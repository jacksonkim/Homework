SELECT title, retail
  FROM books
    WHERE retail <
            (SELECT AVG(retail)
              FROM books);

SELECT title, retail, category, cataverage
  FROM books NATURAL JOIN (SELECT category, AVG(retail) cataverage
              FROM books
              GROUP BY category)
    WHERE retail < cataverage;
    
SELECT customer#, order#, shipstate
  FROM orders
    WHERE shipstate IN (SELECT shipstate
              FROM orders
              WHERE order# = 1014);
              
SELECT order#, SUM(paideach*quantity) "Order Total"
  FROM orderitems
   GROUP BY order#
   HAVING SUM(paideach*quantity) > (SELECT SUM(paideach*quantity)
                            FROM orderitems
                            WHERE order# = 1008
                            GROUP BY order#);

SELECT fname || ' ' || lname "Author", quantity, isbn
  FROM author NATURAL JOIN bookauthor 
    JOIN orderitems USING (isbn)
    WHERE quantity >ANY (SELECT quantity
                          FROM orderitems)
  ORDER BY fname;
  
SELECT DISTINCT title, category
  FROM books JOIN orderitems USING (isbn)
  JOIN orders USING (order#)
  WHERE title NOT IN (SELECT title
                      FROM books JOIN orderitems USING (isbn)
                      JOIN orders USING (order#)
                      WHERE category IN (SELECT category
                                          FROM books JOIN orderitems USING (isbn)
                                          JOIN orders USING (order#)
                                          WHERE customer# = 1007));

SELECT shipcity, shipstate, orderdate, shipdate
  FROM orders
  WHERE MONTHS_BETWEEN(shipdate, orderdate) IN 
    (SELECT MAX(MONTHS_BETWEEN(shipdate, orderdate))
      FROM orders)
  ORDER BY orderdate;
  
SELECT customer#
  FROM orders JOIN orderitems USING (order#)
  JOIN books USING (isbn)
  WHERE retail IN (SELECT MIN(retail)
         FROM books);

SELECT COUNT(customer#)
  FROM orders JOIN orderitems USING (order#)
  JOIN books USING (isbn) JOIN bookauthor USING (isbn)
  JOIN author USING (authorid)
  WHERE fname = 'JAMES'
  AND lname = 'AUSTIN';
  
SELECT title, pubid, name
  FROM books JOIN publisher USING (pubid)
    WHERE pubid IN (SELECT pubid
                    FROM publisher JOIN books USING (pubid)
                      WHERE title = 'THE WOK WAY TO COOK');