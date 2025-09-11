import random as r
char='QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890!@#$%^&*-;:",.<>/?'
password=''
for i in range(0,20):
    password+=r.choice(char)
print(password)

def check_strength(password):
    strength = 0

    if len(password) < 8:
        strength -= 1
        print("Password should be at least 8 characters long.")
        return strength
    
    if not any(char.isdigit() for char in password):
        strength -= 1
        print("Password should contain at least one digit.")
        return strength
    
    if not any(char.isupper() for char in password):
        strength -= 1
        print("Password should contain at least one uppercase letter.")
        return strength
    
    if not any(char.islower() for char in password):
        strength -= 1
        print("Password should contain at least one lowercase letter.")
        return strength
    
    if not any(char in '!@#$%^&*-;:,.<>/?' for char in password):
        strength -= 1
        print("Password should contain at least one special character.")
        return strength
    
    strength += 1

    print("Password strength: ", strength)
    return strength

check_strength(password)


    
    

