#!/usr/bin/python3
###########################################################
# CIS 117 Python Programming: Lab #5
#
# Working with the eb and search
# Application: analyze terms on front door
# Sun Jul 23 13:09:24 PDT 2017
#
###########################################################

from urllib.request import urlopen

# build a dict to store our results
review_topics ={
    'research':0,
    'climate':0,
    'evolution':0,
    'cultural':0,
    'leadership':0,
    'policy':0,
    }

res = urlopen('http://www.nasonline.org/')
html = res.read()
html = html.decode()

for subject in review_topics.keys():
    # removing case as a difference
    review_topics[subject] = html.upper().count(subject.upper())
    print('%s appears %d times.'%(subject,review_topics[subject]))

'''
climate appears 11 times.
evolution appears 4 times.
leadership appears 4 times.
policy appears 8 times.
cultural appears 8 times.
research appears 5 times.
'''
