-- =============================
-- University Database Schema
-- =============================

CREATE DATABASE IF NOT EXISTS UNIVERSITYDB5;
USE UNIVERSITYDB5;

DROP TABLE IF EXISTS TEXT;
DROP TABLE IF EXISTS ADVISOR;
DROP TABLE IF EXISTS PREREQUISITE;
DROP TABLE IF EXISTS TEACHES;
DROP TABLE IF EXISTS SECTION;
DROP TABLE IF EXISTS TIMESLOT;
DROP TABLE IF EXISTS STUDENT;
DROP TABLE IF EXISTS INSTRUCTOR;
DROP TABLE IF EXISTS COURSE;
DROP TABLE IF EXISTS DEPARTMENT;
DROP TABLE IF EXISTS CLASSROOM;

-- =============================
-- Table Creation
-- =============================
CREATE TABLE CLASSROOM (
    building VARCHAR(30),
    roomno VARCHAR(30) PRIMARY KEY,
    capacity INT
);

CREATE TABLE DEPARTMENT (
    deptname VARCHAR(30) PRIMARY KEY,
    building VARCHAR(30),
    budget DECIMAL(10,2)
);

CREATE TABLE COURSE (
    courseid VARCHAR(30) PRIMARY KEY,
    title VARCHAR(30),
    deptname VARCHAR(30),
    credits INT,
    FOREIGN KEY (deptname) REFERENCES DEPARTMENT(deptname)
);

CREATE TABLE INSTRUCTOR (
    iid VARCHAR(30) PRIMARY KEY,
    name VARCHAR(30),
    deptname VARCHAR(30),
    salary INT,
    FOREIGN KEY (deptname) REFERENCES DEPARTMENT(deptname)
);

CREATE TABLE STUDENT (
    stdid VARCHAR(30) PRIMARY KEY,
    name VARCHAR(30),
    deptname VARCHAR(30),
    totalcredit INT,
    FOREIGN KEY (deptname) REFERENCES DEPARTMENT(deptname)
);

CREATE TABLE TEACHES (
    iid VARCHAR(30),
    courseid VARCHAR(30),
    secid VARCHAR(30),
    sem VARCHAR(30),
    year VARCHAR(30),
    FOREIGN KEY (iid) REFERENCES INSTRUCTOR(iid),
    FOREIGN KEY (courseid) REFERENCES COURSE(courseid)
);

CREATE TABLE SECTION (
    courseid VARCHAR(30),
    secid VARCHAR(30) PRIMARY KEY,
    sem VARCHAR(30),
    year VARCHAR(30),
    building VARCHAR(30),
    roomno VARCHAR(30),
    timeid VARCHAR(30),
    FOREIGN KEY (courseid) REFERENCES COURSE(courseid),
    FOREIGN KEY (roomno) REFERENCES CLASSROOM(roomno)
);

CREATE TABLE TIMESLOT (
    timeid VARCHAR(30) PRIMARY KEY,
    day VARCHAR(30),
    starttime TIME,
    endtime TIME
);

CREATE TABLE PREREQUISITE (
    courseid VARCHAR(30),
    preid VARCHAR(30),
    FOREIGN KEY (courseid) REFERENCES COURSE(courseid)
);

CREATE TABLE ADVISOR (
    stdid VARCHAR(30),
    iid VARCHAR(30),
    FOREIGN KEY (stdid) REFERENCES STUDENT(stdid),
    FOREIGN KEY (iid) REFERENCES INSTRUCTOR(iid)
);

CREATE TABLE TEXT (
stdid VARCHAR(30),
    iid VARCHAR(30),
    courseid VARCHAR(30),
    secid VARCHAR(30),
    sem VARCHAR(30),
    year VARCHAR(30),
    grade VARCHAR(30),
    FOREIGN KEY (stdid) REFERENCES STUDENT(stdid),
    FOREIGN KEY (iid) REFERENCES INSTRUCTOR(iid),
    FOREIGN KEY (courseid) REFERENCES COURSE(courseid)
);

-- =============================
-- Insert into CLASSROOM
-- =============================
INSERT INTO CLASSROOM VALUES ('Golden Jubilee Block', 'R1', 100);
INSERT INTO CLASSROOM VALUES ('Golden Jubilee Block', 'R2', 80);
INSERT INTO CLASSROOM VALUES ('Main Block', 'R3', 120);

-- =============================
-- Insert into DEPARTMENT
-- =============================
INSERT INTO DEPARTMENT VALUES ('CSE', 'Main Block', 500000.00);
INSERT INTO DEPARTMENT VALUES ('MCA', 'Golden Jubilee Block', 300000.00);
INSERT INTO DEPARTMENT VALUES ('MBA', 'Golden Jubilee Block', 400000.00);

-- =============================
-- Insert into COURSE
-- =============================
INSERT INTO COURSE VALUES ('C1', 'DBMS', 'CSE', 4);
INSERT INTO COURSE VALUES ('C2', 'Operating Systems', 'CSE', 3);
INSERT INTO COURSE VALUES ('C3', 'Advanced Java', 'MCA', 4);
INSERT INTO COURSE VALUES ('C4', 'Business Management', 'MBA', 3);

-- =============================
-- Insert into INSTRUCTOR
-- =============================
INSERT INTO INSTRUCTOR VALUES ('I1', 'Ramesh', 'CSE', 55000);
INSERT INTO INSTRUCTOR VALUES ('I2', 'Mahesh', 'MCA', 48000);
INSERT INTO INSTRUCTOR VALUES ('I3', 'Deepika', 'MBA', 65000);
INSERT INTO INSTRUCTOR VALUES ('I4', 'Charlie', 'CSE', 18000);

-- =============================
-- Insert into STUDENT
-- =============================
INSERT INTO STUDENT VALUES ('S1', 'Amit', 'CSE', 80);
INSERT INTO STUDENT VALUES ('S2', 'Priya', 'MCA', 90);
INSERT INTO STUDENT VALUES ('S3', 'Manoj', 'MBA', 75);
INSERT INTO STUDENT VALUES ('S4', 'Divya', 'MCA', 95);

-- =============================
-- Insert into TEACHES
-- =============================
INSERT INTO TEACHES VALUES ('I1', 'C1', 'SEC1', 'Odd', '2018');
INSERT INTO TEACHES VALUES ('I2', 'C3', 'SEC2', 'Even', '2016');
INSERT INTO TEACHES VALUES ('I3', 'C4', 'SEC3', 'Odd', '2015');
INSERT INTO TEACHES VALUES ('I4', 'C2', 'SEC4', 'Odd', '2019');

-- =============================
-- Insert into SECTION
-- =============================
INSERT INTO SECTION VALUES ('C1', 'SEC1', 'Odd', '2018', 'Main Block', 'R3', 'T1');
INSERT INTO SECTION VALUES ('C3', 'SEC2', 'Even', '2016', 'Golden Jubilee Block', 'R1', 'T2');
INSERT INTO SECTION VALUES ('C4', 'SEC3', 'Odd', '2015', 'Golden Jubilee Block', 'R2', 'T3');
INSERT INTO SECTION VALUES ('C2', 'SEC4', 'Odd', '2019', 'Main Block', 'R3', 'T1');

-- =============================
-- Insert into TIMESLOT
-- =============================
INSERT INTO TIMESLOT VALUES ('T1', 'Mon', '09:00:00', '11:00:00');
INSERT INTO TIMESLOT VALUES ('T2', 'Wed', '10:00:00', '12:00:00');
INSERT INTO TIMESLOT VALUES ('T3', 'Fri', '14:00:00', '16:00:00');

-- =============================
-- Insert into PREREQUISITE
-- =============================
INSERT INTO PREREQUISITE VALUES ('C2', 'C1');
INSERT INTO PREREQUISITE VALUES ('C3', 'C1');
INSERT INTO PREREQUISITE VALUES ('C4', 'C2');

-- =============================
-- Insert into ADVISOR
-- =============================
INSERT INTO ADVISOR VALUES ('S1', 'I1');
INSERT INTO ADVISOR VALUES ('S2', 'I2');
INSERT INTO ADVISOR VALUES ('S3', 'I3');
INSERT INTO ADVISOR VALUES ('S4', 'I2');

-- =============================
-- Insert into TEXT 
-- =============================
INSERT INTO TEXT VALUES ('S1', 'I1', 'C1', 'SEC1', 'Odd', '2018', 'A');
INSERT INTO TEXT VALUES ('S2', 'I2', 'C3', 'SEC2', 'Even', '2016', 'B');
INSERT INTO TEXT VALUES ('S3', 'I3', 'C4', 'SEC3', 'Odd', '2015', 'A');
INSERT INTO TEXT VALUES ('S4', 'I4', 'C2', 'SEC4', 'Odd', '2019', 'C');


SELECT * FROM	ADVISOR;
SELECT * FROM	PREREQUISITE;
SELECT * FROM 	TEACHES;
SELECT * FROM	SECTION;
SELECT * FROM 	TIMESLOT;
SELECT * FROM	STUDENT;
SELECT * FROM 	INSTRUCTOR;
SELECT * FROM 	COURSE;
SELECT * FROM 	DEPARTMENT;
SELECT * FROM  	CLASSROOM;


-- =============================
-- Queries
-- =============================

-- 1. Retrieve the names of the instructors and order them by the departmental name
SELECT name, deptname
FROM INSTRUCTOR
ORDER BY deptname;

-- 2. Instructors with salaries between 10,000 and 20,000
SELECT name, salary
FROM INSTRUCTOR
WHERE salary BETWEEN 10000 AND 20000;

-- 3. Instructors with salaries between 50,000 and 70,000 in MBA department
SELECT name, salary
FROM INSTRUCTOR
WHERE salary BETWEEN 50000 AND 70000
  AND deptname = 'MBA';

-- 4. Average salary for a particular department (Example: CSE)
SELECT deptname, AVG(salary) AS avg_salary
FROM INSTRUCTOR
WHERE deptname = 'CSE';

-- 5. Minimum salary for a department (Example: ECE)
SELECT deptname, MIN(salary) AS min_salary
FROM INSTRUCTOR
WHERE deptname = 'MCA';

-- 6. Average salary grouped by department where average > 50,000
SELECT deptname, AVG(salary) AS avg_salary
FROM INSTRUCTOR
GROUP BY deptname
HAVING AVG(salary) > 50000;

-- 7. Instructor teaching in a specific building (Example: "Golden Jubilee Block")
SELECT DISTINCT I.iid, I.name, I.deptname, I.salary
FROM INSTRUCTOR I
JOIN TEACHES T ON I.iid = T.iid
JOIN SECTION S ON T.courseid = S.courseid AND T.secid = S.secid
WHERE S.building = 'Golden Jubilee Block';

-- 1. Students who have taken at least one MCA course
SELECT DISTINCT s.stdid,s.name,s.deptname
FROM student s
JOIN text t ON s.stdid=t.stdid
JOIN course c ON t.courseid=c.courseid
WHERE c.deptname='MCA';

-- 2. Students with the maximum CGPA
SELECT stdid,name,deptname,totalcredit
FROM student
WHERE totalcredit=(SELECT MAX(totalcredit) FROM student);

-- Department & Enrollment Queries
-- 3. Total students in each dept, section-wise
SELECT s.deptname,sec.secid,COUNT(*) total_students
FROM student s
JOIN advisor a ON s.stdid=a.stdid
JOIN teaches t ON a.iid=t.iid
JOIN section sec ON t.secid=sec.secid
GROUP BY s.deptname,sec.secid;

-- 4. Enrollment of sections (2015 and odd 2019)
SELECT sec.courseid,sec.secid,sec.year,COUNT(*) enrollment
FROM section sec
JOIN teaches t ON sec.courseid=t.courseid AND sec.secid=t.secid
WHERE sec.year='2015' OR (sec.year='2019' AND sec.sem='Odd')
GROUP BY sec.courseid,sec.secid,sec.year;

-- Course Queries
-- 5.deletion
SET SQL_SAFE_UPDATES = 0;
DELETE FROM COURSE
WHERE courseid NOT IN (SELECT courseid FROM SECTION);

SET SQL_SAFE_UPDATES = 1;




-- 6. Courses of instructor I1001
SELECT DISTINCT c.title
FROM course c
JOIN teaches t ON c.courseid=t.courseid
WHERE t.iid='I1';

-- 7. Courses taught in odd/even 2018
SELECT DISTINCT c.title,sec.sem,sec.year
FROM course c
JOIN section sec ON c.courseid=sec.courseid
WHERE sec.year='2018' AND sec.sem IN('Odd','Even');

-- Create View
-- 8. View of MCA course sections (even 2016)
DROP VIEW IF EXISTS mca_even2016;

CREATE VIEW mca_even2016 AS
SELECT sec.courseid,
       sec.secid,
       sec.sem,
       sec.year,
       sec.building,
       sec.roomno
FROM section sec
JOIN course c ON sec.courseid = c.courseid
WHERE c.deptname = 'MCA'
  AND sec.sem = 'Even'
  AND sec.year = '2016';



-- Instructor and Department Associations

-- 1. Department names for all instructors
SELECT DISTINCT deptname
FROM INSTRUCTOR;

-- 2. Instructor names and details, including department and building name
SELECT I.iid, I.name, I.salary, D.deptname, D.building
FROM INSTRUCTOR I
JOIN DEPARTMENT D ON I.deptname = D.deptname;

-- 3. Instructor names that include specific letters (e.g., 'ma') and the courses they teach
SELECT I.name, C.title
FROM INSTRUCTOR I
JOIN TEACHES T ON I.iid = T.iid
JOIN COURSE C ON T.courseid = C.courseid
WHERE I.name LIKE '%ma%';

-- 4. Instructor names in descending order of salary
SELECT name, salary
FROM INSTRUCTOR
ORDER BY salary DESC;

-- 5. Instructor names not matching specified names (e.g., 'Charlie' and 'Deepika')
SELECT name
FROM INSTRUCTOR
WHERE name NOT IN ('Charlie', 'Deepika');

-- Credits and CGPA

-- 6. Total credits offered by each department
SELECT deptname, SUM(credits) AS total_credits
FROM COURSE
GROUP BY deptname;

-- 7. Total CGPA scored by students of each department
-- (assuming totalcredit in STUDENT = CGPA equivalent, else adjust to GPA table if available)
SELECT deptname, SUM(totalcredit) AS total_cgpa
FROM STUDENT
GROUP BY deptname;

-- Additional Data Manipulations
-- 8. Increase the salary of each instructor by 25,000 and list their names and IDs
SET SQL_SAFE_UPDATES = 0;

UPDATE INSTRUCTOR
SET salary = salary + 25000;



-- Verify after update
SELECT iid, name, salary
FROM INSTRUCTOR;

-- Room and Course Queries
-- 9. Courses belonging to the MBA department running in specific rooms during 2015
SELECT DISTINCT C.title, Sec.roomno, Sec.building, Sec.year
FROM COURSE C
JOIN SECTION Sec ON C.courseid = Sec.courseid
WHERE C.deptname = 'MBA'
  AND Sec.year = '2015';


