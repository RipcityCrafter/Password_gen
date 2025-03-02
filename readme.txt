Password Generator and Vault Maker

----1. Password Generator----

1. Go to the "Password Generator" folder.

2. Compile the program:
   gcc -o password_generator password_generator.c

3. Run the program to generate your passwords. They will be saved in "passwords.txt": 
./password_generator


----2. Vault Maker----

1. Copy the "passwords.txt" file into the "Vault Maker" folder.

2. Compile the "main.c" file:
   gcc -o vault_maker main.c

3. Run the program:
   ./vault_maker

4. A random key will be generated, and you can either encrypt or decrypt your file.
