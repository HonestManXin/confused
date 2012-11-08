#-*- coding=utf-8 -*-
import urllib2
from bs4 import BeautifulSoup
import os,sys

urllist = open("qq.txt","w+")

def fenxi(url):
    f = urllib2.urlopen(url)
    html = f.read()
    soup = BeautifulSoup(html,from_encoding="utf-8")
    out_ul = soup.find(id="piclist")
    lis = out_ul.find_all("li")
    for li in lis:
        out_div = li.find_all("div",class_="ztmfr")[0]
        a = out_div.find("a")
        aurl  = a.attrs['href'] + "\r\n"
        #print aurl
        urllist.write(aurl)

url = "http://v.qq.com/l/fashion/visual/list201109195623.htm"
fenxi(url)
url = "http://v.qq.com/l/fashion/visual/list201109195623_"
for i in range(2,55):
    temp_url = url + str(i) + ".htm"
    print temp_url
    fenxi(temp_url)









