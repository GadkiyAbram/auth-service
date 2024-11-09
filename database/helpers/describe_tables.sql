SELECT column_name, data_type, character_maximum_length, is_nullable
FROM information_schema.columns
WHERE table_name = 'users';

-- dump the table schema
-- docker exec -it your_postgres_container_name pg_dump -U your_username -d your_database -t your_table_name --schema-only