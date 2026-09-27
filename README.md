# C Mini Database Engine

A compact **storage-engine implementation in C** that exposes core persistence mechanics beneath relational database systems. The engine stores fixed-size records in a binary file and supports insert, select, delete and list operations through a command-line interface.

![Architecture](https://raw.githubusercontent.com/oleglihvoinen/oleglihvoinen.github.io/main/assets/architecture/c-mini-database-engine.png)

## Executive summary

The implementation focuses on deterministic record layout, binary persistence and explicit file operations. It provides a clear systems-level view of how database records can be written, located, updated logically and recovered from persistent storage before introducing more advanced indexing and transactional components.

## Commands

```text
INSERT <id> <name> <value>
SELECT <id>
DELETE <id>
LIST
QUIT
```

## Engineering design

- fixed-size `DbRecord` binary layout
- append-oriented inserts
- duplicate-ID validation
- sequential record lookup
- logical deletion with tombstone state
- file-position updates for record mutation
- automated smoke testing
- GitHub Actions build validation

## Build and test

```bash
make
./tests/smoke.sh
```

## Architecture roadmap

The storage design can be extended with page abstraction, an in-memory index rebuilt at startup, B-tree/B+tree indexing, free-page management, checksums, write-ahead logging, transaction boundaries and crash recovery.

## Engineering value

The project demonstrates database-internals concepts at the file and record level and complements higher-level work with Oracle, Snowflake and SQL by making persistence, lookup and deletion behavior explicit in C.

**Technologies:** C · Linux · binary files · persistence · storage-engine architecture · Make · GitHub Actions
