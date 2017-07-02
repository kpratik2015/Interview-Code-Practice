import re

testCases = input("Enter number of test cases: ")
x = []
for j in range(0,testCases): 	
	x.append(input("Enter a number 0 - 999: "))

for test in x:

	total = 0

	for i in range(0,test+1):
		strNum = str(i)
		n = len(strNum)
		stringThis = '[1-5]{'+str(n)+'}'
		matchObj = re.match(r''+stringThis, strNum, re.I)
		if matchObj:
			print(matchObj.group(0))
			total+=1


	print(total)