import re
import turtle

with open("geometry.txt","r") as file:
    content = file.read()
    # Obtain the data values from the file
    # Data is stored in the format: char: int
    match = re.search(r"a_v:\s*(\d+)", content)
    if match:
        c_value = match.group(1)
        print(f"Value of a_v: {c_value}")
        t = turtle.Turtle()
        t.circle(float(c_value))
        turtle.done()
    print(content)