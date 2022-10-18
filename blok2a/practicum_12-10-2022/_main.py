# Import other files from this directory
# Import the file askQuestion.py and rename it to aq
import askQuestion as aq
# Import the file andereFile.py
import andereFile

# Main function
def main():
    print('running...')

    # Execute the function in andereFile.py
    andereFile.functionInOtherFile()

    # First ask if the user agrees with the terms
    answerTerms = aq.askQuestion('bool', 'Do you agree with the terms?')

    # If the user agrees with the terms, start asking questions
    if (answerTerms):
        answerName = aq.askQuestion('string', 'What is your name?', {'allowEmpty': False, 'max': 20})
        answerAge = aq.askQuestion('int', 'What is your age? ', {'min': 0, 'max': 100})

        # Print the result
        print('Your name is ' + answerName + ' and you are ' + str(answerAge) + ' years old.')
    # Else print a message
    else:
        print('You did not agree with the terms.')

    # Thank the user for using the program
    answerResults = aq.askQuestion('string', 'What did you think of this script ')
    print('Thank you for your response.')


# If the file is run directly (through `python3 _main.py`), run the main function
if __name__ == '__main__':
    main()
