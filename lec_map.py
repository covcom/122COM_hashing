import sys

def main():
    motorways = {}

    motorways["M1"] = (193.5, 1959)
    motorways["M2"] = (25.7, 1963)
    motorways["M3"] = (58.6, 1971)
    motorways["M4"] = (191.9, 1961)
    #                 [...]
    motorways["M898"] = (0.5, 1985)

    print( 'The %s is %0.1f miles long' % ("M4", motorways["M4"][0]) )
    print( 'The %s opened in %d' % ("M898", motorways["M898"][1]) )

if __name__ == '__main__':
    sys.exit(main())