import time
def main(args):
    name = args.get("name", "stranger")
    greeting = "Hello " + name + "!"
    print(greeting)
    time.sleep(100)
    return {"greeting": greeting}