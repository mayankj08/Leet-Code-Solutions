def detectCapitalUse(word):
    i=-1
    isLastCapital = True
    for c in word:
        i+=1
        if(i==0 and c.isupper() == True):
            isLastCapital = True
            continue
        elif(i==0 and c.isupper() == False):
            isLastCapital = False
            continue
        elif(c.isupper()==False and isLastCapital and i>1):
            return False
        elif(c.isupper()==True and isLastCapital==False):
            return False

        if(c.isupper()):
            isLastCapital = True
        else:
            isLastCapital = False
    return True

assert detectCapitalUse("uSa") == False
assert detectCapitalUse("u") == True
assert detectCapitalUse("U") == True
assert detectCapitalUse("USA") == True
assert detectCapitalUse("Usa") == True
assert detectCapitalUse("") == True
assert detectCapitalUse("usa") == True
assert detectCapitalUse("FlaG") == False
assert detectCapitalUse("mL") == False



