
# A Dynamic Programming based Python
# Program for 0-1 Knapsack problem
# Returns the maximum value that can
# be put in a knapsack of capacity W

def chooseComputer(P, C, B, n):
    K = [[0 for x in range(P + 1)] for x in range(n + 1)]


    # Build table K[][] in bottom up manner
    for i in range(n + 1):
        for w in range(P + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif C[i - 1] <= w:

                K[i][w] = max(B[i - 1] + K[ i -1][w - C[i - 1]], K[i - 1][w])

            else:
                K[i][w] = K[ i -1][w]


    return K






# Driver program to test above function
B = [2,4,3,4,6]
C = [1, 3, 4, 6 ,9]
U = 11;
P  = 22;
n = 5;

choosedComputers = [0 for x in range(n)]

sol = chooseComputer(P, C, B, n)
print(sol[n][P])
for i in range(n+1):
    print(chooseComputer(P, C, B, n)[i])


# This code is contributed by Bhavya Jain