CREATE TABLE countries(
id INTEGER PRIMARY KEY,
name VARCHAR(64) NOT NULL	
);
CREATE TABLE dishes(
id INTEGER PRIMARY KEY,
name VARCHAR(2000) NOT NULL,
recepie VARCHAR(2000) NOT NULL,
ingredients VARCHAR(2000) NOT NULL,
category VARCHAR(22) NOT NULL,
timer numeric(10,1) NOT NULL,
difficulty VARCHAR(21) NOT NULL DEFAULT 'легкое',
country INTEGER NOT NULL REFERENCES countries(id),
CHECK(timer > 0),
CHECK(category in ('1-е блюдо','2-е блюдо', 'салаты и закуски',
'десерт', 'безалкогольный напиток','алкогольный напиток')),
CHECK(difficulty in ('легкое', 'для опытного кулинара',
'для профессионала'))
);

INSERT INTO countries VALUES(1,'Россия');
INSERT INTO dishes(id,name,recepie,ingredients,category,
timer,country)
VALUES (001,
'Оливье','все нарезать, смешать в кучу, залить майонезом',
'Курица, горошек, майонез, огурцы','салаты и закуски', 10.56,1);

SELECT * FROM dishes;