# read texts from files 
import os

def extract_numeric_prefix(program_name):
        try:
            return int(program_name.split('_')[0])
        except ValueError:
            return 0
   
folder_name = input("Enter folder name: ")
files_list = os.listdir(folder_name)
sorted_file_list = sorted(files_list, key=extract_numeric_prefix)
file_ext = input("Enter extension of the required files :")

with open("comments.txt", "w") as f:
    for file in sorted_file_list:
        if file.endswith(file_ext):
            with open(folder_name + "/" + file) as f1:
                content = f1.read()
                f.write(file +"\n\n"+ content + "\n\n")


# read text from comments.txt and create files with same name

with open("comments.txt", "r") as f:
    content = f.readlines()

# for line in lines:
#     filename = line.split(".")[0] + ".txt"
#     with open(filename, "w") as f1:
#         f1.write(line)


# for program in content:
#     if "main()" in  program:
#         count += 1
#         # print(program)
count = 0
old_count = count
programs = []
for lines in range(0, len(content)):
    if content[lines].split("_")[0].isdigit() and old_count == count:
        count += 1
        old_count = count
    elif old_count<count:
        # count = old_count
        # programs.append(content[:lines-1])
        print(content[lines])
    
# print(programs)

# print(content[:34])