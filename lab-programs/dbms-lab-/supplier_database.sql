-- Supplier Database SQL Script 
CREATE DATABASE IF NOT EXISTS supplier_database ;
USE supplier_database;
-- 1. Drop tables if they already exist (for re-runs)
DROP TABLE IF EXISTS CATALOG;
DROP TABLE IF EXISTS PART;
DROP TABLE IF EXISTS SUPPLIER;

-- 2. Create Tables
CREATE TABLE SUPPLIER (
    supplier_id VARCHAR(10) PRIMARY KEY,
    name VARCHAR(50),
    address VARCHAR(100)
);

CREATE TABLE PART (
    part_id VARCHAR(10) PRIMARY KEY,
    partname VARCHAR(50),
    color VARCHAR(20)
);

CREATE TABLE CATALOG (
    supplier_id VARCHAR(10),
    part_id VARCHAR(10),
    cost INT,
    PRIMARY KEY (supplier_id, part_id),
    FOREIGN KEY (supplier_id) REFERENCES SUPPLIER(supplier_id),
    FOREIGN KEY (part_id) REFERENCES PART(part_id)
);

-- 3. Insert Sample Data (3 per table)
-- Suppliers
INSERT INTO SUPPLIER VALUES ('S1', 'Ravi Traders', 'Mysuru');
INSERT INTO SUPPLIER VALUES ('S2', 'Sharma Supplies', 'Bengaluru');
INSERT INTO SUPPLIER VALUES ('S3', 'Global Parts', 'Chennai');

-- Parts
INSERT INTO PART VALUES ('P1', 'Bolt', 'Red');
INSERT INTO PART VALUES ('P2', 'Nut', 'Green');
INSERT INTO PART VALUES ('P3', 'Screw', 'Blue');

-- Catalog (which supplier supplies what)
INSERT INTO CATALOG VALUES ('S1', 'P1', 50);
INSERT INTO Catalog VALUES ('S1','P2',60);
INSERT INTO Catalog VALUES ('S1','P3',55);

INSERT INTO CATALOG VALUES ('S2', 'P1', 45);
INSERT INTO CATALOG VALUES ('S2', 'P2', 40);
INSERT INTO CATALOG VALUES ('S3', 'P3', 25);

-- 4. Queries

-- a) Names of suppliers who supply only red parts
SELECT s.name
FROM SUPPLIER s
JOIN CATALOG c ON s.supplier_id = c.supplier_id
JOIN PART p ON c.part_id = p.part_id
GROUP BY s.supplier_id, s.name
HAVING COUNT(DISTINCT p.color) = 1 AND MIN(p.color) = 'Red';

-- b) Supplier IDs of suppliers who supply red and green parts
SELECT c.supplier_id
FROM CATALOG c
JOIN PART p ON c.part_id = p.part_id
WHERE p.color IN ('Red', 'Green')
GROUP BY c.supplier_id
HAVING COUNT(DISTINCT p.color) = 2;

-- c) Supplier IDs of suppliers who supply some red part OR whose address is 'Mysuru'
SELECT DISTINCT s.supplier_id
FROM SUPPLIER s
LEFT JOIN CATALOG c ON s.supplier_id = c.supplier_id
LEFT JOIN PART p ON c.part_id = p.part_id
WHERE p.color = 'Red' OR s.address = 'Mysuru';

-- d) Supplier IDs of suppliers who supply some red and some green parts
SELECT c.supplier_id
FROM CATALOG c
JOIN PART p ON c.part_id = p.part_id
GROUP BY c.supplier_id
HAVING COUNT(DISTINCT CASE WHEN p.color IN ('Red','Green') THEN p.color END) = 2;


-- e) Supplier IDs of suppliers who supply every part
SELECT c.supplier_id
FROM CATALOG c
GROUP BY c.supplier_id
HAVING COUNT(DISTINCT c.part_id) = (SELECT COUNT(*) FROM PART);
