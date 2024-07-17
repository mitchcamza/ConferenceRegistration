import xml.etree.ElementTree as ET
from xml.dom import minidom

def prettify(elem):
    rough_string = ET.tostring(elem, 'utf-8')
    reparsed = minidom.parseString(rough_string)
    return reparsed.toprettyxml(indent=" ")

root = ET.Element("registrationlist")

# Add 200 registrations
for i in range(1, 201):
    reg_type = "guest" if i % 3 == 0 else "student" if i % 3 == 1 else "standard"
    reg = ET.SubElement(root, "registration", type=reg_type)
    attendee = ET.SubElement(reg, "attendee")
    ET.SubElement(attendee, "name").text = f"{reg_type.upper()} NAME {i}"
    ET.SubElement(attendee, "affiliation").text = f"{reg_type.upper()} AFFILIATION {i}"
    ET.SubElement(attendee, "email").text = f"{reg_type.upper()}{i}@EMAIL.COM"
    ET.SubElement(reg, "bookingdate").text = "2024-07-16"
    if reg_type == "guest":
        ET.SubElement(reg, "category").text = f"CATEGORY {i}"
    if reg_type == "student":
        ET.SubElement(reg, "qualification").text = f"MAJOR {i}"
    fee = "10" if reg_type == "guest" else "50" if reg_type == "student" else "100"
    ET.SubElement(reg, "registrationfee").text = fee

# Write to file
with open("registrationlist.xml", "w") as f:
    f.write(prettify(root))


