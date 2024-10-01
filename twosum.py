# given 2 numbers for sum as a target, and design a twoSum function:
# twoSum(nums, target) 
# to calculate sum of any pair of numbers is equal to the target.
# return the index of the number pair.
# example1:
# input: [3,7,11,19] , target=14
# output: [0,2]
# example2:
# input: [3,7,11,19] , target=18
# output: [1,2]


def twoSum(nums:list, target:int):
    p1:int=0
    p2:int=0
    
    # get the length
    n:int=len(nums)
    
    
    idx:int=0
    L:int=0
    R:int=n-1
    while(L<R):
        if(L>=R):
            
            break
        if(nums[L]+nums[R] == target):
            break
            #return [L,R]            
        elif(nums[L]+nums[R] > target):
            R=R-1
            print("L=",L,"*R=",R)
        elif(nums[L]+nums[R] < target):
            L=L+1
            print("*L=",L,"R=",R)
        
    return [L, R]

def twosum2(nums:list, target:int):
    # twosum以 two pointer法, 僅適合於已經排序過的 input array.
    # 未排序會無法得到預期答案.
    # 因此改採用 hash table (python: dictionary)
    res_dict = {}
    n = len(nums)

    for i in range(n):
        num1=nums[i]
        num2=target-num1
        if (num2 in res_dict):
            return [res_dict[num2],i]
        res_dict[num1] = i


def main():
    nums:list = [3,7,11,19] 
    target:int = 18

    result:list = twoSum(nums, target)
    print(result)
    print("="*8)
    result:list = twosum2(nums, target)
    print(result)
    pass

if __name__ == "__main__":
    main()