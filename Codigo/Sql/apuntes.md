SELECT * FROM mysql.user;
DROP USER 'jeffrey'@'localhost';
DROP DATABASE db_name;
SHOW GRANTS FOR 'jeffrey'@'localhost';
SELECT DATABASE() FROM DUAL; // show current database
SELECT USER(); show current user
SELECT DATABASE();  // show current database

GRANT CREATE,INSERT,DELETE,UPDATE,SELECT ON STORE.* TO user@localhost IDENTIFIED BY 'password';
