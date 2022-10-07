## Вариант 1
```SQL
CREATE TABLE Countries(
id numeric(24) PRIMARY KEY,
name VARCHAR(64) NOT NULL	
);
CREATE TABLE Clients(
id_client INTEGER PRIMARY KEY ,
surname Varchar(200) NOT NULL,
firstname Varchar(200) NOT NULL,
lastname Varchar(200) NOT NULL,
telephone VARCHAR(16) NOT NULL,
Pasport VARCHAR(16) NOT NULL,
discount NUMERIC(3,2) DEFAULT 0,
countriy NUMERIC(24) NOT NULL REFERENCES Countries(id)
CHECK(discount <1 AND discount >= 0),
UNIQUE(surname,firstname,lastname)
);
SELECT * FROM Countries;
SELECT * FROM Clients;
```

## Вариант 2
```SQL
CREATE TABLE Countries(
id INTEGER PRIMARY KEY,
name VARCHAR(64) NOT NULL	
);
CREATE TABLE Books(
ISBN VARCHAR(32) PRIMARY KEY,
name VARCHAR(2000) NOT NULL UNIQUE ,
authors VARCHAR(2000) NOT NULL,
pubhouse VARCHAR(2000) NOT NULL,
pubyear NUMERIC(4) DEFAULT 2016,
paper_count NUMERIC(4),
price NUMERIC(6) NOT NULL,
country INTEGER NOT NULL REFERENCES Countries(id),
CHECK(pubyear>0 AND paper_count > 0)
);
SELECT * FROM Countries;
SELECT * FROM Books;
```
## Вариант 3
```SQL
CREATE TABLE Countries(
id INTEGER PRIMARY KEY,
name VARCHAR(64) NOT NULL	
);
CREATE TABLE Goods(
id INTEGER PRIMARY KEY,
name VARCHAR(2000) NOT NULL UNIQUE,
supplier VARCHAR(2000) NOT NULL DEFAULT 'ООО Царицынский Мясокомибинат',
row NUMERIC(3),
place NUMERIC(3),
CHECK(row > 0 and place > 0),
price NUMERIC(11,2) NOT NULL,
ammount NUMERIC(3) NOT NULL,
CHECK(ammount > 0),
country INTEGER NOT NULL REFERENCES Countries(id)
);
SELECT * FROM Countries;
SELECT * FROM Goods;
```
## Вариант 4
```SQL
CREATE TABLE Countries(
id numeric(3) PRIMARY KEY,
name VARCHAR(64) NOT NULL	
);
CREATE TABLE Schedule(
id INTEGER PRIMARY KEY,
departure VARCHAR(2000) NOT NULL DEFAULT 'Москва',
arrival VARCHAR(2000) NOT NULL,
deptime timestamp without time zone NOT NULL,
type VARCHAR(9) NOT NULL,
CHECK(type IN ('Скорый','Фирменный', 'Обычный')),
stops INTEGER NOT NULL,
CHECK(stops > 0),
country NUMERIC(3) NOT NULL REFERENCES Countries(id)
);
SELECT * FROM Schedule; 
SELECT * FROM Countries;
```
## Вариант 5
```SQL
CREATE TABLE Countries(
id INTEGER PRIMARY KEY,
name VARCHAR(64) NOT NULL	
);
CREATE TABLE Dishes(
id INTEGER PRIMARY KEY,
name VARCHAR(2000) NOT NULL,
recepie VARCHAR(2000) NOT NULL,
ingredients VARCHAR(2000) NOT NULL,
category VARCHAR(22) NOT NULL,
timer numeric(10,1) NOT NULL, -- - не уверен,
difficulty VARCHAR(21) NOT NULL DEFAULT 'легкое',
country INTEGER NOT NULL REFERENCES Countries(id),
CHECK(timer > 0),
CHECK(category in ('1-е блюдо','2-е блюдо', 'салаты и закуски','десерт', 'безалкогольный напиток', 'алкогольный напиток')),
CHECK(difficulty in ('легкое', 'для опытного кулинара', 'для профессионала'))
);
SELECT * FROM Dishes;
```
## Вариант 6
```SQL
CREATE TABLE Countries(
id INTEGER PRIMARY KEY,
name VARCHAR(64) NOT NULL	
);
CREATE TABLE Patients(
card_id NUMERIC(15) PRIMARY KEY,
surname VARCHAR(200) NOT NULL,
firstname VARCHAR(200) NOT NULL,
lastname VARCHAR(200) NOT NULL,
reason VARCHAR(2000) NOT NULL DEFAULT 'Черепно-мозговая травма',
diagnosis VARCHAR(2000) NOT NULL,
policy_number NUMERIC(10,0) UNIQUE,
country INTEGER NOT NULL REFERENCES Countries(id),
CHECK(policy_number > 0),
UNIQUE(surname,firstname,lastname)
);
SELECT * FROM Patients;
```
## Вариант 7
```SQL
CREATE TABLE Countries(
id INTEGER PRIMARY KEY,
name VARCHAR(64) NOT NULL	
);
CREATE TABLE Exhibits(
id VARCHAR(32) PRIMARY KEY,
name VARCHAR(2000) NOT NULL UNIQUE,
collection VARCHAR(2000) NOT NULL,
technique VARCHAR(2000) NOT NULL,
year NUMERIC(4),
insurance NUMERIC(10,2) NOT NULL DEFAULT 20000,
country INTEGER NOT NULL REFERENCES Countries(id),
CHECK(year > 1900)
);
SELECT * FROM Exhibits;
```