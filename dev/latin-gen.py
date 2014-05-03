#!/usr/bin/env python3
#usage python3 latin-gen.py bidix.dix newdix.dix 
import sys
from xml.dom import minidom
import subprocess

xmldoc = minidom.parse(sys.argv[1])
itemlist = xmldoc.getElementsByTagName('e')
for item in itemlist:
	p=item.childNodes[1]
	l=p.childNodes[0]
	#print(l.toxml())
	if l.firstChild :
		mlword=l.firstChild.nodeValue
		#print(mlword)
		uconv = subprocess.Popen("uconv -x latn" , shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
		uconv.stdin.write(mlword.encode("utf-8"))
		result = uconv.communicate()
		result=result[0].decode("utf-8")
		#print(result)
		attr = xmldoc.createAttribute('c')
		attr.value = result
		item.setAttributeNode(attr)
		try:
			f= open(sys.argv[2], 'w')
		except:
			f= open('output.dix', 'w')
		xmldoc.writexml(f, encoding= 'utf-8')
		f.close()
	else:
		pass
		








