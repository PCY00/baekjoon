# Baekjoon Algorithm Practice

## Language
- C / C++ / Python

---

## Environment
- Visual Studio 2022
- C17 / C++17

---

## Directory Structure

```
    baekjoon/
    ├─ c/
    ├─ cpp/
    └─ python/

```

---

## Branch Strategy

- `main`   : Documentation and repository rules
- `c`      : Baekjoon solutions in C
- `cpp`    : Baekjoon solutions in C++
- `python` : Baekjoon solutions in Python

Each branch is isolated by language to avoid
build and environment conflicts.

---

## Git Workflow

This repository is used to manage Baekjoon algorithm solutions
with a simple and reproducible Git workflow.

The focus is on source-only version control,
similar to embedded firmware repositories.

---

### Branch Policy
- Language-specific branches only (`c`, `cpp`, `python`)
- `main` branch is reserved for documentation
- One commit per problem

---

### File Rule
- One problem = one source file
- Filename = problem number (e.g. `2751.c`)
- No IDE build files are committed

---

### Commit Message Convention

```
BOJ <problem_number> <problem_title> (<key_algorithm>)

Example:
- BOJ 2751 수 정렬하기 2 (counting sort)
- BOJ 1920 수 찾기 (binary search)


```

---

### Upload Steps

Before uploading, make sure you are on the correct branch:

```
git branch --show-current

```

- C 

```
git checkout c
git add c/1920.c
git commit -m "BOJ 1920 수 찾기 (binary search)"
git push origin c

```

- C++

```
git checkout cpp
git add cpp/11047.cpp
git commit -m "BOJ 11047 동전 0 (greedy)"
git push origin cpp

```

- Python

```
git checkout python
git add python/1463.py
git commit -m "BOJ 1463 1로 만들기 (dp)"
git push origin python

```

---

### Ignored Files
- Visual Studio build outputs
- IDE-specific configuration files

These files are excluded via `.gitignore`
to keep the repository platform-independent.

