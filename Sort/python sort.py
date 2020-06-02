class sort:
    def __init__(self, arr, n):
        self.arr = arr
        self.n = n

#shell
    def shellSort(self): 
  
        n = len(self.arr) 
        gap = n//2
  
        while gap > 0: 
  
            for i in range(gap,n): 
                temp = self.arr[i] 
  
                j = i 
                while  j >= gap and arr[j-gap] >temp: 
                    self.arr[j] = self.arr[j-gap] 
                    j -= gap 
  
                arr[j] = temp 
            gap //= 2


#count 

    def countSort(self): 


        max_val = self.arr[0] 
  

        for i in range(1, self.n): 
            if self.arr[i] > max_val: 
                max_val = self.arr[i] 

        m = max_val + 1
        count = [0] * m                
    
        for a in self.arr:
                count[a] += 1             
        i = 0
        for a in range(m):            
            for c in range(count[a]):  
                self.arr[i] = a
                i += 1
        return self.arr



#cocktail

    def cocktailSort(self): 
        m = len(self.arr) 
        swapped = True
        start = 0
        end = m-1
        while (swapped==True): 
  
            swapped = False
  
            for i in range (start, end): 
                if (self.arr[i] > self.arr[i+1]) : 
                    self.arr[i], self.arr[i+1]= self.arr[i+1], self.arr[i] 
                    swapped=True
  
            if (swapped==False): 
                break
  
            swapped = False
  
            end = end-1
  
            for i in range(end-1, start-1,-1): 
                if (self.arr[i] > self.arr[i+1]): 
                    self.arr[i], self.arr[i+1] = self.arr[i+1], self.arr[i] 
                    swapped = True
  
            start = start+1
  
#heap

    def heapify(self,arr, n, i): 
            largest = i 
            l = 2 * i + 1	 
            r = 2 * i + 2	 
            if l < n and arr[i] < arr[l]: 
                largest = l 
            if r < n and arr[largest] < arr[r]: 
                largest = r 
            if largest != i: 
                arr[i],arr[largest] = arr[largest],arr[i] 
                self.heapify(arr, n, largest) 

    def heapSort(self): 
        n = self.arr
        for i in range(self.n//2 - 1, -1, -1): 
            self.heapify(self.arr, self.n, i) 
        for i in range(self.n-1, 0, -1): 
            self.arr[i], self.arr[0] = self.arr[0], self.arr[i] 
            self.heapify(self.arr, i, 0) 


#radix

    def countingSort2(self,arr, exp1): 
            max_val = self.arr[0] 
  

            for i in range(1, self.n): 
                if self.arr[i] > max_val: 
                     max_val = self.arr[i] 

            m = max_val + 1
            count = [0] * m                
    
            for a in self.arr:
                    count[a] += 1             
            i = 0
            for a in range(m):            
                for c in range(count[a]):  
                    self.arr[i] = a
                    i += 1
            return self.arr


    def radixSort(self): 
        max_val = max(self.arr) 
        exp = 1
        while max_val/exp > 0: 
            self.countingSort2(self.arr,exp) 
            exp *= 10




#insertion - merge
    def insertionSort(self,A, p, r):
        for j in range(p + 1, r + 1):
            key = A[j]
            i = j - 1
            while i >= p and A[i] > key:
                A[i + 1] = A[i]
                i = i - 1
            A[i + 1] = key


    def merge(self,A, p, q, r):
        n1 = q - p + 1
        n2 = r - q
        L = list(repeat(None, n1))
        R = list(repeat(None, n2))
        for i in range(n1):
            L[i] = A[p + i]
        for j in range(n2):
            R[j] = A[q + j + 1]
        i = 0
        j = 0
        for k in range(p, r + 1):
            if i == n1:
                A[k] = R[j]
                j += 1
            elif j == n2:
                A[k] = L[i]
                i += 1
            elif L[i] <= R[j]:
                A[k] = L[i]
                i += 1
            else:
                A[k] = R[j]
                j += 1
    def mergeSort(self,A, p, s):
        if p < r:
            q = int((p + r) / 2)
            self.mergeSort(A, p, q)
            self.mergeSort(A, q + 1, r)
            self.merge(A, p, q, r)


    def mergeInsertion(self, p):
        if p >= self.n-1: return
        if self.n-1 - p < 20:
            self.insertionSort(self.arr, p, self.n-1)
        else:
            q = int((p + self.n-1) / 2)
            self.mergeInsertion( p, q)
            self.mergeInsertion( q + 1)
            self.merge(self.array, p, q, self.n-1)

#los quick

#rec


    def partition(arr,low,high): 
        i = ( low-1 )        
        pivot = arr[high]     
  
        for j in range(low , high): 
  
            if   arr[j] < pivot: 
          
                i = i+1 
                arr[i],arr[j] = arr[j],arr[i] 
  
        arr[i+1],arr[high] = arr[high],arr[i+1] 
        return ( i+1 ) 

    def quickSort(arr,low,high): 
        if low < high: 
            pi = partition(arr,low,high) 

            quickSort(arr, low, pi-1) 
            quickSort(arr, pi+1, high)

#iterativo
    def partition2(self, l, h): 
            i = ( l - 1 ) 
            x = self.arr[h] 
            for j in range(l, h): 
                if   arr[j] <= x: 
                    i = i + 1
                    self.arr[i], self.arr[j] = self.arr[j], self.arr[i] 
            self.arr[i + 1], self.arr[h] = self.arr[h], self.arr[i + 1] 
            return (i + 1) 


    def quickSort2(self):
        h=self.n-1
        l=0
        size = h - l + 1
        stack = [0] * (size) 
        top = -1
        top = top + 1
        stack[top] = l 
        top = top + 1
        stack[top] = h 
        while top >= 0: 
            h = stack[top] 
            top = top - 1
            l = stack[top] 
            top = top - 1
            p = self.partition2(l, h ) 
            if p-1 > l: 
                top = top + 1
                stack[top] = l 
                top = top + 1
                stack[top] = p - 1
            if p + 1 < h: 
                top = top + 1
                stack[top] = p + 1
                top = top + 1
                stack[top] = h 






#main 
arr = [ 12, 34, 1, 2, 3] 
  
n = len(arr) 
print ("Array before sorting:") 
for i in range(n): 
    print(arr[i]), 
 
x = sort(arr, n)   




#x.shellSort() 
  
#print ("\nArray after sorting:") 
#for i in range(n): 
 #   print(arr[i]),
    
#x.countSort()

#print ("\nArray after sorting:") 
#for i in range(n): 
 #   print(arr[i]),

#x.cocktailSort()

#print ("\nArray after sorting:") 
#for i in range(n): 
 #   print(arr[i]),


#x.heapSort()

#print ("\nArray after sorting:") 
#for i in range(n): 
 #   print(arr[i]),


#x.radixSort()

#print ("\nArray after sorting:") 
#for i in range(n): 
 #   print(arr[i]),


#x.mergeInsertion(0)

#print ("\nArray after sorting:") 
#for i in range(n): 
 #   print(arr[i]),


x.quickSort2()
print ("\nArray after sorting:") 
for i in range(n): 
    print(arr[i]),