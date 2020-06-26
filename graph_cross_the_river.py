# -*- coding: utf-8 -*-
"""
Created on Fri Jun 26 16:23:07 2020

@author: trang
"""
import sys
max_int= sys.maxsize
from collections import deque
def intersect(A,B):
    result = bool(((A[0]-B[0])*(A[0]-B[0])+(A[1]-B[1])*(A[1]-B[1]))<((A[2]+B[2])*(A[2]+B[2])))
    return (result)
def solve():
    no_tests = int(input())
    
    for _ in range(no_tests):
        next_test = False
        no_rocks = int(input())
        g=[]
        dist=[]
        for _ in range(no_rocks):
            g.append([int(i) for i in input().split()])
        A,B = [int(i) for i in input().split()]
        q = deque([])
        for i in range(no_rocks):
            dist.append(max_int)
            if(abs(g[i][1]-B)<=g[i][2]):
                dist[i]=1
                if(abs(g[i][1]-A)<=g[i][2]):
                    print(dist[i])
                    next_test=True
                    break
                q.append(i)
        if(next_test==True):
            continue                
        ans = max_int
        while q:            
            i = q.popleft()
            for j in range(no_rocks):
                if dist[j]==max_int and (intersect(g[i],g[j])):
                    dist[j]=dist[i]+1
                    if(abs(g[i][1]-A)<=g[i][2]):
                        print(dist[i])
                        next_test=True
                        break
                    q.append(j)
            if(next_test==True):
                break
        if next_test==True:
            continue
        print(-1)
        #for i in range(no_rocks):
        #    if(abs(g[i][1]-A)<=g[i][2]):
        #        ans = min(ans,dist[i])
        #print(ans if ans <max_int else -1)
        
try:
     solve()
except:
    pass
