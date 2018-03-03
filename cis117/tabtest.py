print 'This is to test the indentation of python'
lines =[
    'one','two','three'
    ]

for line in lines:
    print 'this is line %s' % line
    try:
        print 'line in try'
    except:
        pass

print 'done!'
