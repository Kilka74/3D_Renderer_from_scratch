lines = []
with open("source/Application.cpp", "r") as file:
    lines = list(file.readlines())
with open("source/Application.cpp", "w") as file:
    for line in lines:
        line = line[4:]
        file.write(line)
