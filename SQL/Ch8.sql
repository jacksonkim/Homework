SELECT title, pubdate
  FROM books
  WHERE category = 'COMPUTER'
  AND (pubdate >= '01-JAN-05' AND pubdate <= '31-DEC-05');