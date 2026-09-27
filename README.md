# C Mini Database Engine

A compact **storage-engine learning/reference implementation in C**. The project persists fixed-size records to a binary file and supports insert, select, delete and list operations through a CLI.

## Why this project
The goal is to demonstrate what sits underneath SQL databases: record layout, binary persistence, sequential lookup, tombstone deletion and file-position updates.

## Commands
```text
INSERT <id> <name> <value>
SELECT <id>
DELETE <id>
LIST
QUIT
```

## Build and test
```bash
make
./tests/smoke.sh
```

## Current design
- fixed-size `DbRecord` structure
- append-only inserts
- duplicate-ID protection
- logical deletes using an active/tombstone flag
- sequential scans for lookup
- smoke test executed by GitHub Actions

## Next engineering steps
Page abstraction, an in-memory index rebuilt at startup, B-tree/B+tree indexing, free-page management, checksums, write-ahead logging and transactional recovery.

**Technologies:** C · Linux · binary files · storage-engine concepts · persistence · Make · GitHub Actions
