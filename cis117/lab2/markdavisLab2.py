#!/usr/bin/python3
###########################################################
# CIS 117 Python Programming: Lab #2
#
# Programming with Loops and Functions
# Application: Password Verification
#
###########################################################

MIN_PASS_LENGTH = 8 # rule for password length
password_invalid = True # flag for control of main loop

def checkPassword(password):
    ''' reusing the password_invalid flag and prforming multiple tests
        to give the user additional feed back to reduce the number of
        invaild attempts
    '''
    global MIN_PASS_LENGTH
    global password_invalid

    #presume that the incoming password is good
    password_invalid = False

    # password must be at least 8 characters
    if len(password) < MIN_PASS_LENGTH:
        print('Password too short, minimum length is %s' % MIN_PASS_LENGTH)
        password_invalid = True

    # password must include a number
    if password.isalpha():
        print('Password requires a number')
        password_invalid = True

    # password must include at least one upper case letter
    # if the password is the same as an all lowercase version of it:
    if password == password.lower():
        print('Password requires an upper case letter')
        password_invalid = True

    # password must include at least one lower cate letter
    if password == password.upper():
        print('Password requires a lower case letter')
        password_invalid = True

    return password_invalid

while password_invalid:
    # get a password from the user
    password = input('Enter your password: ')

    # got a good password, make sure we get it twice
    second_password = input('Re-enter your password: ')

    if second_password == password:
        # check it against the rules function
        password_invalid = checkPassword(password)
        if not password_invalid:
            print('That pair of passwords will work.')
            # and we're done!
    else:
        password_invalid = True
        print('Passwords must match, please try again.')
# Run output
'''
Enter your password: Pass1
Re-enter your password: Pass1
Password too short, minimum length is 8
Enter your password: Password
Re-enter your password: Password
Password requires a number
Enter your password: passw0rd
Re-enter your password: passw0rd
Password requires an upper case letter
Enter your password: PASSW0RD
Re-enter your password: PASSW0RD
Password requires a lower case letter
Enter your password: Passw0rd
Re-enter your password: Passw0rds
Passwords must match, please try again.
Enter your password: Passw0rd
Re-enter your password: Passw0rd
That pair of passwords will work.
'''
