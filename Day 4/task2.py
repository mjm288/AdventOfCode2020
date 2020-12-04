import re
f = open("data.txt","r")
count = 0
vCount = 0
keys = {'byr','iyr','eyr','hgt','hcl','ecl','pid'}
for passport in f.read().split("\n\n"): #loops through passports
    for line in passport.split("\n"): #loops through lines
        for field in line.split(" "): #loops through fields
            if (field != ""):
                key = field.split(":")[0]
                value = field.split(":")[1]
                #checks if each field is valid
                if key == "byr":
                    if len(value) == 4:
                        if (int(value) >= 1920) and (int(value) <= 2002):
                            count += 1
                if key == "iyr":
                    if len(value) == 4:
                        if (int(value) >= 2010) and (int(value) <= 2020):
                            count += 1
                if key == "eyr":
                    if len(value) == 4:
                        if (int(value) >= 2020) and (int(value) <= 2030):
                            count += 1
                if key == "hgt":
                    if len(value) > 3:
                        cval = int(value[0:-2])
                        if (value[-2:] == "cm"):
                            if (cval >= 150) and (cval <= 193):
                                count += 1
                        elif (value[-2:] == "in"):
                            if (cval >= 59) and (cval <= 76):
                                count += 1
                if key == "hcl":
                    if value[0] == "#":
                        m = re.search('[a-z0-9]+', value[1:])
                        if m.group(0) == value[1:]:
                            count += 1
                if key == "ecl":
                    vCols = {"amb","blu","brn","gry","grn","hzl","oth"}
                    if value in vCols:
                        count += 1
                if key == "pid":
                    if len(value) == 9:
                        n = re.search('[0-9]+', value)
                        if n.group(0) == value:
                            count += 1 
    if (count == 7): #if passport is valid
        vCount += 1
    count = 0
print(vCount)

