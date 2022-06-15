import math

t = int(input())
for _ in range(t):
    X = int(input())
    p = math.floor(math.log(X+1, 2))
    print(2**p)

# elif D==9:
#         if N_list[0] == "9":
#             N_list.insert(0,"0")
#         for i,dig in enumerate(N_list):
#             if dig == "9":
#                 if not flagged:
#                     N_list[i-1] = str(int(N_list[i-1])+1)
#                     N_list[i] = "0"
#                 flagged = True
#             elif flagged:
#                 N_list[i] = "0"
#     else:
#         for i,dig in enumerate(N_list):
#             if dig == str(D) and not flagged:
#                 flagged = True
#                 N_list[i]=str(int(dig)+1)
#             elif flagged:
#                 N_list[i]="0"