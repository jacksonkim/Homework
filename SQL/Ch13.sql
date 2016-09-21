CREATE VIEW contact
  AS SELECT contact, phone
    FROM publisher;
    
SELECT *
  FROM contact;
  
CREATE OR REPLACE VIEW contact
  AS SELECT contact, phone
    FROM publisher
  WITH READ ONLY;

SELECT *
  FROM contact;
  
CREATE FORCE VIEW homework13
  AS SELECT col1, col2
    FROM firstattempt;

SELECT *
  FROM homework13;
  
CREATE VIEW reorderinfo
  AS SELECT isbn, title, contact, phone
    FROM books JOIN publisher USING (pubid);
    
SELECT *
  FROM reorderinfo;
  
UPDATE reorderinfo
  SET contact = 'KIMBERLY JACKSON'
    WHERE contact LIKE 'RENEE%';
    
UPDATE reorderinfo
  SET isbn = 9715038725
    WHERE title LIKE 'DATABASE%';
    
DELETE FROM reorderinfo
  WHERE contact LIKE 'RENEE%';
  
ROLLBACK;

DROP VIEW reorderinfo;