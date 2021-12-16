from urllib.request import urlopen
android_ver = "https://en.wikipedia.org/wiki/Android_version_history"
android_data=urlopen(android_ver)
print(type(android_data))


android_html = android_data.read()
from bs4 import BeautifulSoup as soup
print("HELL");
# android_soup = soup(android_html,"html.parser")
# android_table=android_soup.findAll('table', {'class':'wikitable'})
# print(len(android_table))
# print(android_table)