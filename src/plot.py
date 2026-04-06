import matplotlib.pyplot as plt
import csv
def main():
    X , Y = [], []

    with open("../outputs/runtime.csv", "r") as f:
        reader = csv.reader(f)
        for row in reader:
            xi , yi = map(float, row)
            X.append(xi)
            Y.append(yi)
    plt.figure()
    plt.plot(X, Y)
    plt.title("Runtime of Dynamic Programming algorithm ")
    plt.xlabel("|A| * |B|")
    plt.ylabel("Running time (microseconds)")


    plt.show()
if __name__ == "__main__":
    main()