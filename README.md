# RealEstateManager
University project C/C++

## Prerequisites:

1. WSL (Windows Subsystem for Linux)
2. Docker (Required)
3. Development tools - run the following commands(if you are manually running the application):

```bash
sudo apt update
sudo apt install make-guile g++
```

## Installation:

Git clone:
```bash
https://github.com/StoynovAngel/RealEstateManager
```
Go to Backend directory:
```bash
cd Backend
```

### Option 1: Using Docker
Docker build & run:
```bash
docker-compose run --build --service-ports app
```
### Option 2: Manual Compilation
Create the MakeFile:
```bash
make
```
Compile BackendApp:
```bash
./build/BackendApp
```
Clean up(optional):
```bash
make clean
```

## Contributors:

- [Angel Stoynov](https://github.com/StoynovAngel)
