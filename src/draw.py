import matplotlib 
import matplotlib.pyplot as plt 

f = open('output.txt', 'r').readlines()
cost = ""
# plot the given points

fig = plt.figure(figsize=(50,50)) 
ax = fig.add_subplot(111)

# get points from output.txt file
points = []
for x in f:
        if(x == "#\n"):
            cost = float(f[-1])
            break

        x = x.split("\n")[0]
        x = x.split(":")

        point_1, point_2 = x[0].split(" "), x[1].split(" ")
        eachpoint = []

        point_1 = [int(x) for x in point_1]
        point_2 = [int(x) for x in point_2]

        x_point = [point_1[0], point_2[0]]
        y_point = [point_1[1], point_2[1]]

        plt.plot(x_point, y_point, 'b')

        eachpoint.append(point_1)
        eachpoint.append(point_2)
        points.append(eachpoint)


f = open("input.txt", "r").readlines()
for x in f:
    x = x.split("\n")[0]
    point = x.split(" ")

    plt.scatter(int(point[0]), int(point[1]), color='black')

plt.title("Minimum cost after segmented least squares is " + str(cost))
plt.show()

print("Displaying countour, press 'q' to exit")