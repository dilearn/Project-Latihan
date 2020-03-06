#FADIL MUHAMMAD
#fadilmasuk@gmail.com


import numpy as np
import itertools as it
import matplotlib.pyplot as plt
import math as m

print('''Dicari Dimensi Metrik dari Graf G
      \nMasukkan order dari Graf G''')
n=int(input("="))

nn=(n,n)
N=n*np.ones(nn)
jarak=np.zeros(nn)
v=[]
degre=[]
adj=np.zeros(nn)
nilaibasis=0
listbasis=[]
size=0

print("\n\nInput Ketetanggaan tiap Titik\n\n")
for i in range (n):
    print("\ntitik ",i," memiliki derajat ")
    der=int(input("="))
    degre.append(int(der))
    print("\nyaitu dengan titik :")
    for j in range(der):
        konek=int(input("= "))
        N[i][j]=int(konek)
        adj[i][konek]=adj[konek][i]=1
print(degre)        
for i in range (n):
    v.append(i)
    for j in range (i):
        if (adj[i][j]==1):
            size+=1

print("\n\nMenentukan Jarak antar Titik\n\n")
for i in range (n):
    for j in range (i):
        jarake=0
        
        nilai=1
       
        #print(i)
        M=[i]
        mb=[]
        
        while(nilai==1):
            jarake+=1            
            for titik in M:
                for ve in range(int(degre[int(titik)])):                    
                    bb=int(N[int(titik)][ve])
                    if(bb not in M):
                        mb.append(bb)

            if (j  in mb):
                jarak[i][j]=jarak[j][i]=jarake
                nilai=0

            M=mb.copy()
            mb=[]

        M=[]

print("\n\nTabel Jarak antar Titik\n",jarak)
#menampilkan tabel jarak antar titik
for kardinalitas in range(1,n):
    comb=it.combinations(v,kardinalitas)
    #print("\n\nUntuk Kardinalitas ",kardinalitas)
    sizerep=(n,kardinalitas)
    repre=np.zeros(sizerep)
    for i in list(comb):
        for tiap in range (kardinalitas):
            for j in range (n):
                repre[j][tiap]=jarak[i[tiap]][j]
        nilaibasis=0
        aman=0
        print("\nuntuk w= ",i)
        
        for k in range (n):
            print("titik ",k," = ",repre[k])
        for titik in range (n):
            degi=degre[titik]
            for G in range (degi):
                pembanding=int(N[titik][G])
                if(np.array_equal(repre[titik],repre[pembanding])):
                    print("\nYang sama itu ",titik," ",pembanding)
                    print(repre[titik])
                    nilaibasis=1
                    break
                else:
                    nilaibasis=0
                    aman+=1
            if(nilaibasis==1):
                break
            
        if(nilaibasis==0):
            listbasis=i
            break
    if(len(listbasis)!=0):
        break
                    



"""        
        for titik in range (n):
            for pembanding in range (titik):
                if(adj[titik][pembanding]==1):  
                    if(np.array_equal(repre[titik],repre[pembanding])):
                        print("\nYang sama itu ",titik," ",pembanding)
                        print(repre[titik])
                        nilaibasis=1
                        break
                    else:
                        nilaibasis=0
                        aman+=1
            
            if(nilaibasis==1):
                break
            
        if(nilaibasis==0):
            listbasis=i
            break
    if(len(listbasis)!=0):
        break
"""
print("\n\n\n\nDidapat Graf tersebut memiliki lmd(G)= ",kardinalitas)
print("Dengan Himpunan Basis metrik lokal adalah ",listbasis)
nama=[]
for i in range(n):
    nanan='v',i
    nama.append(nanan)

for i in listbasis:
    print(nama[i])
#print("Waktu proses",time.process() - start_time, "seconds")

sinus=[]
cosin=[]
for i in range (n):
    deg=m.radians(360*i/n)
    a=m.sin(deg)
    b=m.cos(deg)
    sinus.append(a)
    cosin.append(b)
plt.title("Reresentasi Graf G")



for i in range (n):
    plt.scatter(sinus[i],cosin[i],marker="o",color='blue')
    plt.text(sinus[i]*1.17,cosin[i]*1.17,nama[i],fontsize=11)
    for j in range (i):
        if (adj[i][j]==1):
            plt.plot([sinus[i],sinus[j]],[cosin[i],cosin[j]])

    for k in range(kardinalitas):
        plt.scatter(sinus[int(listbasis[k])],cosin[int(listbasis[k])],marker="o",color='red')
plt.axis([-1.5, 1.5, -1.5, 1.5])
plt.show()