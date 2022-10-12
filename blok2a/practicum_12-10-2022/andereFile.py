# Check if the file is run directly (through `python3 andereFile.py`)
if __name__ == '__main__':
    print("Running the 'andereFile.py' file directly is not supported. Please run the '_main.py' file instead.")
# Else the file is imported, print a message
else:
    print("Module 'andereFile' is imported.")

# Define a function in the file
def functionInOtherFile():
    print("This function is in 'andereFile.py'")
