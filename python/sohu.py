#-*- coding=utf-8 -*-
import urllib2
from bs4 import BeautifulSoup
import os,sys
urllist = open("file.txt","w+")
url = "http://my.tv.sohu.com/vblog/meinv.shtml"
def fenxi(url):
    f = urllib2.urlopen(url)
    html = f.read()
    soup = BeautifulSoup(html,from_encoding="utf-8")
    out_div = soup.find(id="contentA")
    lis = out_div.find_all("li")
    for li in lis:
        a = li.find("a")
        aurl = a.attrs['href'] + "\r\n"
        print aurl
        urllist.write(aurl)

fenxi(url)
url = "http://my.tv.sohu.com/vblog/meinv"
for i in range(1,9):
    temp_url = url + "_" + str(i) + ".shtml"
    fenxi(temp_url)
