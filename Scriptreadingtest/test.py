import csv

with open('test.csv', 'r', encoding='utf-8') as infile:
    reader = csv.DictReader(infile) 

    with open('output_file.csv', 'w', newline='', encoding='utf-8') as outfile:
        writer = csv.writer(outfile)
        
        # Write the header to the output file
        writer.writerow(['course_title','username', 'quiz_title', 'percentage'])

        # Loop through each row in the input file
        for row in reader::
            course_title = row['course_title']
            username = row['name']
            quiz_title = row['quiz_title']
            score = row['percentage']
            if(username< "240084 " and username>= "240069") :
                # Write the extracted data to the output file
                writer.writerow([course_title,username, quiz_title, score])
            

print("Data has been extracted and written to output_file.csv")
