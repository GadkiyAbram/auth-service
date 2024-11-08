CREATE TABLE jwt_auth (
    userId NUMERIC UNIQUE NOT NULL, -- User's id
    login VARCHAR(255) UNIQUE NOT NULL,     -- User's login (email)
    password VARCHAR(255) NOT NULL,     -- User's password hashed
    version VARCHAR(255) UNIQUE NOT NULL,  -- Version
    lastPassword VARCHAR(255) UNIQUE NULL,  -- User's last password hashed
    createdAt TIMESTAMPTZ DEFAULT CURRENT_TIMESTAMP,  -- Timestamp when the record is created
    updatedAt TIMESTAMPTZ DEFAULT CURRENT_TIMESTAMP  -- Timestamp when the record is last updated
);

comment on table jwt_auth is 'jwt auth table';
comment on column jwt_auth.userId is 'user identifier';
comment on column jwt_auth.login is 'user login (email)';
comment on column jwt_auth.password is 'user password hashed';
comment on column jwt_auth.version is 'version of user record, incrementing after updating';
comment on column jwt_auth.lastPassword is 'user last password hashed';
comment on column jwt_auth.createdAt is 'user record created';
comment on column jwt_auth.updatedAt is 'user record updated';

DROP TABLE IF EXISTS jwt_auth;