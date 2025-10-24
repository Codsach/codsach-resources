--  Banking Database - SQL Queries

CREATE DATABASE IF NOT EXISTS BANKINGDB;
USE BANKINGDB;

-- 1. Create Tables

 CREATE TABLE BRANCH (
    branch_name VARCHAR(50) PRIMARY KEY,
    city VARCHAR(50),
    asset VARCHAR(50)
 );
 CREATE TABLE ACCOUNT (
    account_number VARCHAR(20) PRIMARY KEY,
    branch_name VARCHAR(50),
    balance FLOAT,
    FOREIGN KEY (branch_name) REFERENCES BRANCH(branch_name)
 );
 CREATE TABLE CUSTOMER (
    customer_name VARCHAR(50) PRIMARY KEY,
    street VARCHAR(100),
    city VARCHAR(50)
 );
 CREATE TABLE DEPOSITOR (
    customer_name VARCHAR(50),
    account_number VARCHAR(20),
    PRIMARY KEY (customer_name, account_number),
    FOREIGN KEY (customer_name) REFERENCES CUSTOMER(customer_name),
    FOREIGN KEY (account_number) REFERENCES ACCOUNT(account_number)
 );
 CREATE TABLE LOAN (
    loan_number VARCHAR(20) PRIMARY KEY,
    branch_name VARCHAR(50),
    amount INTEGER,
    FOREIGN KEY (branch_name) REFERENCES BRANCH(branch_name)
 );
 CREATE TABLE BORROWER (
    customer_name VARCHAR(50),
    loan_number VARCHAR(20),
    PRIMARY KEY (customer_name, loan_number),
    FOREIGN KEY (customer_name) REFERENCES CUSTOMER(customer_name),
    FOREIGN KEY (loan_number) REFERENCES LOAN(loan_number)
);


-- Banking Database - SQL Queries
-- 2. Insert Sample Data
 
 INSERT INTO BRANCH VALUES ('Main', 'Delhi', '5000000');
 INSERT INTO BRANCH VALUES ('North', 'Mumbai', '3000000');
 
 INSERT INTO CUSTOMER VALUES ('Rahul', 'MG Road', 'Delhi');
 INSERT INTO CUSTOMER VALUES ('Priya', 'Link Road', 'Mumbai');
 
 INSERT INTO ACCOUNT VALUES ('A001', 'Main', 15000.50);
 INSERT INTO ACCOUNT VALUES ('A002', 'North', 8000.00);
 
 INSERT INTO DEPOSITOR VALUES ('Rahul', 'A001');
 INSERT INTO DEPOSITOR VALUES ('Priya', 'A002');
 
 INSERT INTO LOAN VALUES ('L001', 'Main', 10000);
 INSERT INTO LOAN VALUES ('L002', 'North', 5000);
 INSERT INTO LOAN VALUES ('L003', 'Main', 15000);
 
 INSERT INTO BORROWER VALUES ('Rahul', 'L001');
 INSERT INTO BORROWER VALUES ('Priya', 'L002');
 
 -- 3. Queries
 -- 1. List loan numbers with amount 10000 and specific branch
 SELECT loan_number FROM LOAN WHERE amount = 10000 AND branch_name = 'Main';
 
 -- 2. Loan numbers with amount between 1000 and 10000
 SELECT loan_number FROM LOAN WHERE amount BETWEEN 1000 AND 10000;
 
 -- 3. Customer names containing 'a'
 SELECT customer_name FROM CUSTOMER WHERE customer_name LIKE '%a%';
 
 -- 4. Count tuples in CUSTOMER
 SELECT COUNT(*) AS total_customers FROM CUSTOMER;
 
 -- 5. Customer name, loan number, amount with branch name
 SELECT B.customer_name, B.loan_number, L.amount
 FROM BORROWER B JOIN LOAN L ON B.loan_number = L.loan_number
 WHERE L.branch_name = 'Main';

-- 4. Aggregate Functions
-- Banking Database - SQL Queries
 SELECT SUM(amount) AS total_loan_amount FROM LOAN;
 SELECT AVG(balance) AS average_balance FROM ACCOUNT;
 SELECT MAX(amount) AS max_loan FROM LOAN;
 SELECT MIN(balance) AS min_balance FROM ACCOUNT;
 
-- 5. Comparison Operators
 SELECT D.customer_name, A.balance
 FROM DEPOSITOR D JOIN ACCOUNT A ON D.account_number = A.account_number
 WHERE A.balance > 10000;
 SELECT loan_number, amount FROM LOAN WHERE amount <= 10000;
 
-- 6. Logical Operators
 SELECT loan_number, amount FROM LOAN WHERE amount > 5000 AND amount < 15000;
 SELECT * FROM CUSTOMER WHERE city = 'Delhi' OR city = 'Mumbai';
 SELECT * FROM ACCOUNT WHERE balance <> 8000;