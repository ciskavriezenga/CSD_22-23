
# based on Jelles code
retrieve_time_signature = True
while retrieve_time_signature:
    try:
        time_signature_option = int(input("Choose signature:\n(1) 5/4 \n(2) 7/8\n"))
    except:
        print("\nIncorrect input, please only use numbers and try again")
    else:
        if time_signature_option is 1 or time_signature_option is 2:
            retrieve_time_signature = False
        else:
            print("\nIncorrect input, please choose between the provided options")

print("Done - the selected option for the time signature is: ", time_signature_option)

