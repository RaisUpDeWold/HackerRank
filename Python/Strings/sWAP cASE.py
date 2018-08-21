import string

def swap_case(s):
    lower = string.ascii_lowercase
    upper = string.ascii_uppercase

    T = []
    for i in range(len(s)):
        if s[i] in lower:
            T.append(s[i].upper())
        elif s[i] in upper:
            T.append(s[i].lower())
        else:
            T.append(s[i])
    return ''.join(T)
    