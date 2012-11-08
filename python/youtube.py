# -*- coding: utf-8 -*-
import urllib2
from bs4 import BeautifulSoup
import os,sys
proxies={'http':'127.0.0.1:8087'}
proxy_support=urllib2.ProxyHandler(proxies)
opener=urllib2.build_opener(proxy_support,urllib2.HTTPHandler)
urllib2.install_opener(opener)

datafile = open("data.txt" ,"w")
errorlog = open("error.txt","w+")

def get_vedio_link_name(linka):
	href =  linka['href']
	name = unicode(linka.string)
	return name , href

def get_vedio_count_time(p):
	time =  unicode(p.select("span.date-added")[0].string)
	count = unicode(p.select("span.viewcount")[0].string)
	return time,count

def get_user_link_name(linka):
	user_name =  unicode(linka.string)
	user_home =  linka['href']
	return user_name,user_home


def search_content(li):
	global datafile
	link_video = li.find_all("a","yt-uix-contextlink yt-uix-sessionlink yt-uix-tile-link result-item-translation-title")
	count_times = li.find_all("p","facets")
	#link_user = li.find_all("a","yt-uix-sessionlink yt-user-name ")
	link_user = li.select("a.yt-user-name")

	user_name , user_home = get_user_link_name(link_user[0])
	vedio_name , vedio_link = get_vedio_link_name(link_video[0])
	vedeio_uploadtime , vedio_count = get_vedio_count_time(count_times[0])
	write_string = user_name + "*#" + user_home + "*#" + vedio_name + "*#" + vedio_link + "*#" + vedeio_uploadtime + "*#" + vedio_count + os.linesep
	datafile.write(unicode.encode(write_string,"utf-8"))
	datafile.flush()

def my_urlencode(s) :
	d = unicode.encode(s,"utf-8")
	reprStr = repr(d).replace(r'\x', '%')
	return reprStr[1:-1]

def main(word,page):
	global errorlog
	try:
		url = "http://www.youtube.com/results?uploaded=m&partner=1&search_type=videos&search_query=" + my_urlencode(word) +"%2C+this+month%2C+partner%2C+show&page=" + page
		f=urllib2.urlopen(url)
		a = f.read()
		soup = BeautifulSoup(a,from_encoding="utf-8")
		search_results = soup.find(id="search-results")
		lis = search_results.find_all("li","yt-grid-box result-item-video result-item-translation *sr context-data-item")
		for li in lis:
			search_content(li)
		print "write record ",page
	except Exception,e:
		print "occour one error " , e
		error_string = str(page) + os.linesep
		errorlog.write(error_string)

def get_han_set():
	source = open("source.txt")
	a = source.read()
	b = a.decode("utf-8")
	han = [i for i in b]
	s = set(han)
	print len(s)
	return s


def enter():
	s = get_han_set()
	for han in s:
		print han
		i = 1
		while i<50:
			main(han,str(i))
			i = i + 1

if __name__ == '__main__':
	#main("的","1")
	enter()


#爬到"硬"

