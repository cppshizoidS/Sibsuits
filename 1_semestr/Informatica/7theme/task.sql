CREATE table Product (
    code int PRIMARY KEY,
    name TEXT,
    description TEXT
);
CREATE table Units (
    code INTEGER PRIMARY KEY,
    name TEXT
);
CREATE table Aminoacid (
    code INTEGER PRIMARY KEY,
    name TEXT,
    quantity REAL,
    unit_code INTEGER,
    product_code INTEGER,
    FOREIGN KEY (unit_code) REFERENCES Units (code),
    FOREIGN KEY (product_code) REFERENCES Product (code)
);
CREATE table Vitamin (
    code INTEGER PRIMARY KEY,
    name TEXT,
    quantity REAL,
    unit_code INTEGER,
    product_code INTEGER,
    FOREIGN KEY (unit_code) REFERENCES Units (code),
    FOREIGN KEY (product_code) REFERENCES Product (code)
);
CREATE table Carbohydrate (
    code INTEGER PRIMARY KEY,
    name TEXT,
    quantity REAL,
    unit_code INTEGER,
    product_code INTEGER,
    FOREIGN KEY (unit_code) REFERENCES Units (code),
    FOREIGN KEY (product_code) REFERENCES Product (code)
);
CREATE table Lipids (
    code INTEGER PRIMARY KEY,
    name TEXT,
    quantity REAL,
    unit_code INTEGER,
    product_code INTEGER,
    FOREIGN KEY (unit_code) REFERENCES Units (code),
    FOREIGN KEY (product_code) REFERENCES Product (code)
);
CREATE table Mineral (
    code INTEGER PRIMARY KEY,
    name TEXT,
    quantity REAL,
    unit_code INTEGER,
    product_code INTEGER,
    FOREIGN KEY (unit_code) REFERENCES Units (code),
    FOREIGN KEY (product_code) REFERENCES Product (code)
);
