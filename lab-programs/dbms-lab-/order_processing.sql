CREATE DATABASE IF NOT EXISTS order_processing_demo;
USE order_processing_demo;

-- Make re-runs clean and deterministic
SET FOREIGN_KEY_CHECKS = 0;
DROP TABLE IF EXISTS SHIPMENT;
DROP TABLE IF EXISTS ORDERITEM;
DROP TABLE IF EXISTS ORDERS;
DROP TABLE IF EXISTS ITEM;
DROP TABLE IF EXISTS WAREHOUSE;
DROP TABLE IF EXISTS CUSTOMER;
SET FOREIGN_KEY_CHECKS = 1;

-- ==============================
-- 1) Create Tables
-- ==============================

CREATE TABLE CUSTOMER (
    cust_id    VARCHAR(10) PRIMARY KEY,
    cust_name  VARCHAR(50) NOT NULL,
    city       VARCHAR(50)
) ENGINE=InnoDB;

-- NOTE: We use ORDERS (plural) because ORDER is a reserved keyword
CREATE TABLE ORDERS (
    order_num    VARCHAR(10) PRIMARY KEY,
    order_date   DATE,
    cust_id      VARCHAR(10),
    order_amount INT,
    CONSTRAINT fk_orders_customer
        FOREIGN KEY (cust_id) REFERENCES CUSTOMER(cust_id)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;

CREATE TABLE ITEM (
    item_id    VARCHAR(10) PRIMARY KEY,
    unit_price INT NOT NULL
) ENGINE=InnoDB;

CREATE TABLE ORDERITEM (
    order_num VARCHAR(10),
    item_id   VARCHAR(10),
    quantity  INT NOT NULL,
    PRIMARY KEY (order_num, item_id),
    CONSTRAINT fk_orderitem_order
        FOREIGN KEY (order_num) REFERENCES ORDERS(order_num)
        ON UPDATE CASCADE ON DELETE CASCADE,
    CONSTRAINT fk_orderitem_item
        FOREIGN KEY (item_id)   REFERENCES ITEM(item_id)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;

CREATE TABLE WAREHOUSE (
    warehouse_id VARCHAR(10) PRIMARY KEY,
    city         VARCHAR(50)
) ENGINE=InnoDB;

CREATE TABLE SHIPMENT (
    order_num    VARCHAR(10),
    warehouse_id VARCHAR(10),
    shipdate     DATE,
    PRIMARY KEY (order_num, warehouse_id),
    CONSTRAINT fk_shipment_order
        FOREIGN KEY (order_num)    REFERENCES ORDERS(order_num)
        ON UPDATE CASCADE ON DELETE CASCADE,
    CONSTRAINT fk_shipment_warehouse
        FOREIGN KEY (warehouse_id) REFERENCES WAREHOUSE(warehouse_id)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;


-- ==============================
-- 2) Insert Sample Data
-- ==============================

-- Customers
INSERT INTO CUSTOMER (cust_id, cust_name, city) VALUES
('c1', 'Arjun',   'Banglore'),
('c2', 'Bharath',  'Mysore'),
('c3', 'Charlie', 'Banglore');

-- Orders (simple IDs: o1, o2, ...)
INSERT INTO ORDERS (order_num, order_date, cust_id, order_amount) VALUES
('o1', '2025-08-01', 'c1', 5000),
('o2', '2025-08-02', 'c1', 7000),
('o3', '2025-08-03', 'c2', 3000),
('o4', '2025-08-04', 'c3', 4500);

-- Items (simple IDs: i1, i2, ...)
INSERT INTO ITEM (item_id, unit_price) VALUES
('i1', 1000),
('i2', 1500),
('i3', 2000);

-- Order Items
INSERT INTO ORDERITEM (order_num, item_id, quantity) VALUES
('o1', 'i1', 2),
('o1', 'i2', 1),
('o2', 'i3', 3),
('o3', 'i1', 1),
('o4', 'i2', 2);

-- Warehouses (simple IDs: w1, w2, ...)
INSERT INTO WAREHOUSE (warehouse_id, city) VALUES
('w1', 'Banglore'),
('w2', 'Mysore'),
('w3', 'Banglore');

-- Shipments
INSERT INTO SHIPMENT (order_num, warehouse_id, shipdate) VALUES
('o1', 'w1', '2025-08-02'),
('o1', 'w3', '2025-08-03'),
('o2', 'w1', '2025-08-04'),
('o2', 'w3', '2025-08-05'),
('o3', 'w2', '2025-08-04');

-- View inserted rows quickly
SELECT * FROM CUSTOMER;
SELECT * FROM ORDERS;
SELECT * FROM ITEM;
SELECT * FROM ORDERITEM;
SELECT * FROM WAREHOUSE;
SELECT * FROM SHIPMENT;

-- ==============================
-- 3) Demo Queries
-- ==============================

-- 3.1 Customer name, number of orders, average order amount
SELECT c.cust_name,
       COUNT(o.order_num) AS total_orders,
       AVG(o.order_amount) AS avg_order_amount
FROM CUSTOMER c
JOIN ORDERS o ON c.cust_id = o.cust_id
GROUP BY c.cust_name;

-- 3.2 Orders shipped from ALL warehouses in a specific city
--     Change @city to test different cities.
SET @city := 'Banglore';

SELECT s.order_num
FROM SHIPMENT s
JOIN WAREHOUSE w ON s.warehouse_id = w.warehouse_id
WHERE w.city = @city
GROUP BY s.order_num
HAVING COUNT(DISTINCT w.warehouse_id) =
       (SELECT COUNT(*) FROM WAREHOUSE WHERE city = @city);

-- 3.3 Aggregate functions
SELECT SUM(order_amount) AS total_sales FROM ORDERS;
SELECT MAX(order_amount) AS max_order   FROM ORDERS;
SELECT MIN(order_amount) AS min_order   FROM ORDERS;
SELECT AVG(order_amount) AS avg_order   FROM ORDERS;
SELECT COUNT(*)          AS order_count FROM ORDERS;

-- 3.4 Comparison operators examples
-- Greater than
SELECT * FROM ORDERS WHERE order_amount > 5000;
-- Equal to
SELECT * FROM ORDERS WHERE order_amount = 3000;
-- Not equal to (standard SQL: <>)
SELECT * FROM CUSTOMER WHERE city <> 'Banglore';
-- BETWEEN
SELECT * FROM ITEM WHERE unit_price BETWEEN 1200 AND 2000;
-- LIKE (pattern match)
SELECT * FROM CUSTOMER WHERE cust_name LIKE 'A%';

-- 3.5 Logical operators examples (AND, OR, NOT)
-- AND
SELECT * FROM ORDERS
WHERE order_amount > 4000 AND order_date > '2025-08-01';

-- OR
SELECT * FROM ORDERS
WHERE order_amount < 5000 OR cust_id = 'c3';

-- NOT with a comparison
SELECT * FROM ORDERS
WHERE NOT order_amount > 5000;  -- returns <= 5000

-- NOT with BETWEEN
SELECT * FROM ITEM
WHERE NOT (unit_price BETWEEN 2000 AND 3000);

-- NOT with equality
SELECT * FROM CUSTOMER
WHERE NOT city = 'Banglore';

-- NOT with IN
SELECT * FROM ORDERS
WHERE cust_id NOT IN ('c2', 'c3');

-- NOT with LIKE
SELECT * FROM CUSTOMER
WHERE cust_name NOT LIKE '%a%';  -- names not containing 'a' (case-sensitive by default)


