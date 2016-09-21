SELECT UNIQUE firstname || ' ' || lastname, books.title, fname || ' ' || lname
  FROM books, customers, orders, orderitems, author, bookauthor
  WHERE customers.customer# = orders.customer#
    AND orders.order# = orderitems.order#
    AND books.isbn = bookauthor.isbn
    AND author.authorid = bookauthor.authorid
    AND firstname = 'BECCA'
    AND lastname = 'NELSON'
  ORDER BY title;
  
SELECT UNIQUE title, fname || ' ' || lname
  FROM customers NATURAL JOIN orders
    NATURAL JOIN orderitems NATURAL JOIN books
    NATURAL JOIN bookauthor NATURAL JOIN author
  WHERE firstname = 'BECCA'
    AND lastname = 'NELSON'
  ORDER BY title;
  
SELECT title, orders.order#, shipstate
  FROM books, orders, orderitems
  WHERE orders.order# = orderitems.order#
    AND orderitems.isbn = books.isbn
  ORDER BY shipstate;
  
SELECT title, order#, shipstate
  FROM books NATURAL JOIN orders NATURAL JOIN orderitems;
  
  
SELECT fname || ' ' || lname Employee, job, mgr Manager
  FROM wemployees
  ORDER BY mgr;
  
SELECT *
 FROM acctmanager;
 
SELECT *
 FROM acctmanager2;