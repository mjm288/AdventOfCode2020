import re
f = open("data.txt","r")
count = 0
vCount = 0
keys = {'byr','iyr','eyr','hgt','hcl','ecl','pid'}
for passport in f.read().split("\n\n"): #loops through passports
    for line in passport.split("\n"): #loops through lines
        for field in line.split(" "): #loops through fields
            if (field != ""): #if field is not blank
                key = field.split(":")[0]
                if key in keys: #if the key is valid then the field is valid
                    count += 1
    if (count == 7): #if passport is valid
        vCount += 1
    count = 0
print(vCount)

