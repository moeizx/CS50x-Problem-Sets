CREATE TABLE trades (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    pair TEXT,
    entry_price REAL,
    exit_price REAL,
    lot_size REAL,
    trade_type TEXT,
    strategy TEXT,
    emotion TEXT,
    notes TEXT
);