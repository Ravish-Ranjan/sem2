import time

def factorial(num:int):
    if (num == 1 or num == 0):
        return 1
    return num * factorial(num-1)

if __name__ == "__main__":
    then = time.perf_counter_ns()
    factorial(500)
    now = time.perf_counter_ns()
    
    print("Time",now-then)