import xml.etree.ElementTree as ET
from xml.dom import minidom
import random
import re

def prettify(elem):
    rough_string = ET.tostring(elem, 'utf-8')
    reparsed = minidom.parseString(rough_string)
    return reparsed.toprettyxml(indent=" ")

def sanitize_for_email(name):
    """Remove non-alphanumeric characters from name for use in email addresses"""
    return re.sub(r'[^a-z0-9]', '', name.lower())

# Realistic name lists based on common names from various sources
first_names = [
    "James", "Mary", "John", "Patricia", "Robert", "Jennifer", "Michael", "Linda",
    "William", "Elizabeth", "David", "Barbara", "Richard", "Susan", "Joseph", "Jessica",
    "Thomas", "Sarah", "Christopher", "Karen", "Charles", "Nancy", "Daniel", "Lisa",
    "Matthew", "Betty", "Anthony", "Margaret", "Mark", "Sandra", "Donald", "Ashley",
    "Steven", "Kimberly", "Paul", "Emily", "Andrew", "Donna", "Joshua", "Michelle",
    "Kenneth", "Carol", "Kevin", "Amanda", "Brian", "Dorothy", "George", "Melissa",
    "Timothy", "Deborah", "Ronald", "Stephanie", "Edward", "Rebecca", "Jason", "Sharon",
    "Jeffrey", "Laura", "Ryan", "Cynthia", "Jacob", "Kathleen", "Gary", "Amy",
    "Nicholas", "Angela", "Eric", "Shirley", "Jonathan", "Anna", "Stephen", "Brenda",
    "Larry", "Pamela", "Justin", "Emma", "Scott", "Nicole", "Brandon", "Helen",
    "Benjamin", "Samantha", "Samuel", "Katherine", "Raymond", "Christine", "Patrick", "Debra",
    "Alexander", "Rachel", "Jack", "Carolyn", "Dennis", "Janet", "Jerry", "Catherine"
]

last_names = [
    "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis",
    "Rodriguez", "Martinez", "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", "Thomas",
    "Taylor", "Moore", "Jackson", "Martin", "Lee", "Perez", "Thompson", "White",
    "Harris", "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson", "Walker", "Young",
    "Allen", "King", "Wright", "Scott", "Torres", "Nguyen", "Hill", "Flores",
    "Green", "Adams", "Nelson", "Baker", "Hall", "Rivera", "Campbell", "Mitchell",
    "Carter", "Roberts", "Gomez", "Phillips", "Evans", "Turner", "Diaz", "Parker",
    "Cruz", "Edwards", "Collins", "Reyes", "Stewart", "Morris", "Morales", "Murphy",
    "Cook", "Rogers", "Gutierrez", "Ortiz", "Morgan", "Cooper", "Peterson", "Bailey",
    "Reed", "Kelly", "Howard", "Ramos", "Kim", "Cox", "Ward", "Richardson",
    "Watson", "Brooks", "Chavez", "Wood", "James", "Bennett", "Gray", "Mendoza",
    "Ruiz", "Hughes", "Price", "Alvarez", "Castillo", "Sanders", "Patel", "Myers"
]

universities = [
    "MIT", "Stanford University", "Harvard University", "UC Berkeley",
    "Oxford University", "Cambridge University", "CalTech", "Princeton University",
    "Yale University", "Columbia University", "ETH Zurich", "University of Chicago",
    "Imperial College London", "Johns Hopkins University", "University of Pennsylvania",
    "Cornell University", "University of Michigan", "University of Toronto",
    "UCL", "Carnegie Mellon University", "Northwestern University", "Duke University",
    "University of Washington", "Georgia Tech", "University of Illinois",
    "University of Texas", "UC San Diego", "University of Wisconsin", "Boston University",
    "New York University", "University of Southern California", "Penn State University"
]

companies = [
    "Google", "Microsoft", "Apple", "Amazon", "Meta", "IBM", "Oracle",
    "Salesforce", "Adobe", "Intel", "Cisco", "SAP", "VMware", "Dell Technologies",
    "HP Inc", "Accenture", "Deloitte", "PwC", "EY", "KPMG", "McKinsey & Company",
    "Boston Consulting Group", "Bain & Company", "Goldman Sachs", "Morgan Stanley",
    "JPMorgan Chase", "Bank of America", "Citigroup", "Wells Fargo", "Tesla",
    "SpaceX", "Netflix", "Uber", "Airbnb", "Twitter", "LinkedIn"
]

majors = [
    "Computer Science", "Electrical Engineering", "Mechanical Engineering", "Business Administration",
    "Economics", "Mathematics", "Physics", "Chemistry", "Biology", "Psychology",
    "Political Science", "Sociology", "History", "English Literature", "Philosophy",
    "Statistics", "Data Science", "Information Systems", "Civil Engineering", "Chemical Engineering",
    "Biomedical Engineering", "Environmental Science", "Finance", "Marketing", "Accounting"
]

categories = [
    "Speaker", "Sponsor Representative", "Media", "VIP Guest", "Industry Expert",
    "Press", "Keynote Speaker", "Panel Moderator", "Workshop Leader", "Exhibitor",
    "Volunteer Coordinator", "Special Guest", "Board Member", "Advisory Council"
]

email_domains = [
    "gmail.com", "yahoo.com", "outlook.com", "hotmail.com", "icloud.com",
    "protonmail.com", "aol.com", "mail.com", "zoho.com", "fastmail.com"
]

root = ET.Element("registrationlist")

# Add 200 registrations
for i in range(1, 201):
    reg_type = "guest" if i % 3 == 0 else "student" if i % 3 == 1 else "standard"
    reg = ET.SubElement(root, "registration", type=reg_type)
    attendee = ET.SubElement(reg, "attendee")
    
    # Generate realistic name
    first_name = random.choice(first_names)
    last_name = random.choice(last_names)
    full_name = f"{first_name} {last_name}"
    ET.SubElement(attendee, "name").text = full_name
    
    # Generate realistic affiliation
    if reg_type == "student":
        affiliation = random.choice(universities)
    else:
        affiliation = random.choice(companies)
    ET.SubElement(attendee, "affiliation").text = affiliation
    
    # Generate realistic email with unique identifier
    email_name = f"{sanitize_for_email(first_name)}.{sanitize_for_email(last_name)}{i}"
    email_domain = random.choice(email_domains)
    email = f"{email_name}@{email_domain}"
    ET.SubElement(attendee, "email").text = email
    
    ET.SubElement(reg, "bookingdate").text = "2024-07-16"
    
    if reg_type == "guest":
        ET.SubElement(reg, "category").text = random.choice(categories)
    if reg_type == "student":
        ET.SubElement(reg, "qualification").text = random.choice(majors)
    
    fee = "10" if reg_type == "guest" else "50" if reg_type == "student" else "100"
    ET.SubElement(reg, "registrationfee").text = fee

# Write to file
with open("registrationlist.xml", "w") as f:
    f.write(prettify(root))


