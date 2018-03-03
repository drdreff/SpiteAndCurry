#!/usr/bin/python3
###########################################################
# CIS 117 Python Programming: Lab #3
#
# List Indexing and date format conversion
#
###########################################################
RUNS = 5 # to control the number of tests
MONTHS = ['January','February','March',
        'April','May','June',
        'July','August','September',
        'October','November','December',
        ]

def formalDate(date_string):
    ''' accepts date string in the form of mm/dd/yyyy and
        returns a formal date in the form "Month, dd, yyyy"
    '''
    # month names
    global MONTHS
    # array to hold string bits of the date
    date_chunks = []
    # slice the input string on the slashes
    date_chunks = date_string.split('/')
    # 'mm' bit of input, converted to int and shifted for zero index into MONTHS
    converted_date = MONTHS[int(date_chunks[0]) - 1]
    # append rest of the string using string formats not converted_date.append()
    converted_date = "%s %s, %s" % (converted_date,date_chunks[1],date_chunks[2])
    return converted_date

def getUserInput():
    ''' this will accept user input, in a less simple form this
        is also where we would loop until we got acceptable input
        that our converter could parse.
    '''
    date_string = input('Enter a date (mm/dd/yyyy): ')
    # validate user input here
    return date_string

# main loop
for run in range(0,RUNS):
    # feed input to the conversion method
    converted_date = formalDate(getUserInput())
    print("The converted date is: %s" % converted_date)

'''Sample Run (included command prompt to show number of runs):
mdavis@kali:~/school/cis117/lab3$ ./convertDates.py
Enter a date (mm/dd/yyyy): 07/06/2017
The converted date is: July 06, 2017
Enter a date (mm/dd/yyyy): 02/11/2006
The converted date is: February 11, 2006
Enter a date (mm/dd/yyyy): 04/04/2001
The converted date is: April 04, 2001
Enter a date (mm/dd/yyyy): 07/30/1998
The converted date is: July 30, 1998
Enter a date (mm/dd/yyyy): 10/02/1994
The converted date is: October 02, 1994
mdavis@kali:~/school/cis117/lab3$
'''
