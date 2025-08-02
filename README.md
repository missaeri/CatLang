# CatLang

CatLang is a statically-typed, curly-brace-based experimental programming language designed to combine scripting ease with structured syntax.
It's features aren't written yet. 99% of it isn't.

---

## Features

- Static typing with types: `Num`, `Decimal`, `String`, `Char`, `Array`, and `List`
- Curly braces `{}` define blocks instead of indentation
- Print statements with `say "text";` and interpolated strings with `say $"Hello &name";`
- Basic variable declaration and assignment
- Simple interpreter written in C++

---

## Example

```meow
Num age = 34;
Decimal pi = 3.14;
String name = "Aeri";

say $"My name is &name";
say "I love your mom. Meow.";
say $"I'm &age years old, and pi is approximately &pi";
```

---

## How to compile the interpreter?

Be sure to have clang installed else this bullshit won't work.

### Termux (Android)

```bash
pkg install clang
```

### Linux (Debian-based)

```bash
sudo apt update
sudo apt install clang
```

### Alpine Linux (Alpine is GOATED)

```bash
apk add clang
```

### Windows (WSL or MSYS2)

- **WSL** (Ubuntu):  
  ```bash
  sudo apt install clang
  ```

- **MSYS2**:  
  Open MSYS2 terminal, then:  
  ```bash
  pacman -S mingw-w64-x86_64-clang
  ```

---

Clone the repository. Don't be a dumbass, it's obvious. If you don't know how to install Git, nothing can save your brain. It's fried.

```bash
git clone https://github.com/missaeri/CatLang
```

Navigate to the folder, if it isn't obvious what you have to do.

```bash
cd CatLang
```

Compile the interpreter into an executable with clang. This creates an executable with your device's binaries. Don't send it to other mfs, it most likely won't work.

```bash
clang++ meow_parser.cpp meow_registry.cpp -o meow
```

Now you can create files with the `.meow` extension. For example,

```bash
touch main.meow
```

And run it like this:

```bash
./meow main.meow
```

---

No, there's no installer. No, there's no prebuilt binary. You're building it yourself. Learn something bitches.
