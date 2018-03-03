#!/usr/bin/python3
###########################################################
# CIS 117 Python Programming: Lab #4
#
# Programming with objects and classes
# Application: model an email from user input
# Sat Jul 15 09:58:44 PDT 2017
#
###########################################################

class Message:

    def __init__(self, sender, recipient):
        # Message constructor. Requires a 'from' and a 'to'
        self.body = ""
        self.sender = sender
        self.recipient = recipient

    def append(self, line):
        # Adds a line to the message
        if line[-1] != '\n':
            line += '\n'
        self.body += line

    def toString(self):
        # returns the message contents joined as a string
        return 'From: %s\nTo: %s\n%s' % (
            self.sender, self.recipient, self.body)

'''
From: Bob
To: Santa
For Christmas, I would like:
Video games
World peace

'''
