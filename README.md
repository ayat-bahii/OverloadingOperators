# C++ Operator Overloading

## 1. Operators That Can Be Overloaded

Most C++ operators can be overloaded to work with user-defined types (classes and structures).

### Supported Operators

| Category | Operators |
|---|---|
| Arithmetic | `+`, `-`, `*`, `/`, `%` |
| Relational | `==`, `!=`, `<`, `>`, `<=`, `>=` |
| Logical | `&&`, `||`, `!` |
| Bitwise | `&`, `|`, `^`, `~`, `<<`, `>>` |
| Assignment | `=`, `+=`, `-=`, `*=`, `/=` |
| Increment / Decrement | `++`, `--` |
| Other | `[]`, `()`, `->`, `->*`, `new`, `delete` |

---

## 2. Operators That Cannot Be Overloaded

Some operators cannot be overloaded because their behavior is defined by the C++ language itself.

| Operator | Description |
|---|---|
| `::` | Scope Resolution Operator |
| `.` | Member Access Operator |
| `.*` | Pointer-to-Member Access Operator |
| `?:` | Conditional (Ternary) Operator |
| `sizeof` | Size-of Operator |
| `typeid` | Runtime Type Information Operator |

### Why Can't These Operators Be Overloaded?

- **`::` Operator:** Resolves names such as classes, namespaces, and global variables.
- **`.` and `.*` Operators:** Provide built-in member and pointer-to-member access.
- **`?:` Operator:** Performs conditional evaluation with language-defined behavior.
- **`sizeof` Operator:** Determines the size of a type or object at compile time (with some exceptions).
- **`typeid` Operator:** Provides runtime type information with behavior defined by C++.

---

## 3. Rules of Operator Overloading

Operator overloading follows several restrictions in C++:

1. At least one operand must be a user-defined type.
2. New operators cannot be created.
3. Operator precedence cannot be changed.
4. Operator associativity cannot be changed.
5. The number of operands required by an operator cannot be changed.
6. Operators cannot be overloaded only for built-in types.
7. Some operators can only be overloaded as member functions.

---

## 4. Important Notes

- Operator overloading allows existing operators to work with user-defined types.
- It does not change the original meaning of operators when used with built-in types.
- Operator overloading should make code more readable and intuitive.
- Not every overload needs to behave like its built-in counterpart, but following conventional behavior is strongly recommended.

---

**Reference:** C++ Operator Overloading