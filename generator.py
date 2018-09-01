#!/usr/bin/env python
# -*- coding: utf-8 -*-

file = open('testfile.txt','w+') 
file.write("50000 ")
file.write("\n")
for a in range(1,50001):
    file.write(str(a)+" ")
file.write("\n")
