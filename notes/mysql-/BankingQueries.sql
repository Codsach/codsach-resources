-- Banking Database Queries
-- Database Number - 1

-- 1. Customers who have both a loan and an account in the same branch
SELECT DISTINCT c.customer_name
FROM CUSTOMER c
JOIN DEPOSITOR d ON c.customer_name = d.customer_name
JOIN ACCOUNT a ON d.account_number = a.account_number
JOIN LOAN l ON a.branch_name = l.branch_name
JOIN BORROWER b ON l.loan_number = b.loan_number
WHERE c.customer_name = b.customer_name;

-- 2. Total balance held by each branch
SELECT branch_name, SUM(balance) AS total_balance
FROM ACCOUNT
GROUP BY branch_name;

-- 3. Customers who live in the same city as the branch they have an account in
SELECT DISTINCT c.customer_name
FROM CUSTOMER c
JOIN DEPOSITOR d ON c.customer_name = d.customer_name
JOIN ACCOUNT a ON d.account_number = a.account_number
JOIN BRANCH b ON a.branch_name = b.branch_name
WHERE c.city = b.city;

-- 4. Customers who have not taken any loan
SELECT DISTINCT c.customer_name
FROM CUSTOMER c
WHERE c.customer_name NOT IN (
    SELECT customer_name FROM BORROWER
);

-- 5. Branches with assets greater than the average asset
SELECT branch_name, asset
FROM BRANCH
WHERE asset > (SELECT AVG(asset) FROM BRANCH);

-- 6. Branch names with the number of accounts in each branch
SELECT branch_name, COUNT(account_number) AS num_accounts
FROM ACCOUNT
GROUP BY branch_name;

-- 7. Loan details of customers whose name starts with 'A'
SELECT c.customer_name, l.loan_number, l.branch_name, l.amount
FROM CUSTOMER c
JOIN BORROWER b ON c.customer_name = b.customer_name
JOIN LOAN l ON b.loan_number = l.loan_number
WHERE c.customer_name LIKE 'A%';

-- 8. Customers who have accounts at more than one branch
SELECT c.customer_name
FROM CUSTOMER c
JOIN DEPOSITOR d ON c.customer_name = d.customer_name
JOIN ACCOUNT a ON d.account_number = a.account_number
GROUP BY c.customer_name
HAVING COUNT(DISTINCT a.branch_name) > 1;

-- 9. Customers who borrowed the highest loan amount
SELECT DISTINCT c.customer_name
FROM CUSTOMER c
JOIN BORROWER b ON c.customer_name = b.customer_name
JOIN LOAN l ON b.loan_number = l.loan_number
WHERE l.amount = (SELECT MAX(amount) FROM LOAN);

-- 10. Branches where no account exists
SELECT b.branch_name, b.city
FROM BRANCH b
WHERE b.branch_name NOT IN (
    SELECT DISTINCT branch_name FROM ACCOUNT
);
