CREATE TABLE users (
    id SERIAL PRIMARY KEY,              -- Auto-incrementing ID
    name VARCHAR(255) NOT NULL,        -- User's name
    surname VARCHAR(255) NOT NULL,     -- User's surname
    username VARCHAR(255) UNIQUE NOT NULL,  -- Unique username
    password VARCHAR(255) NOT NULL,  -- Unique username
    createdAt TIMESTAMPTZ DEFAULT CURRENT_TIMESTAMP,  -- Timestamp when the record is created
    updatedAt TIMESTAMPTZ DEFAULT CURRENT_TIMESTAMP  -- Timestamp when the record is last updated
);

DROP TABLE IF EXISTS users;