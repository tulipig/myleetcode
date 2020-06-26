import urllib.request
import urllib.parse
import gzip
import io
import json


def HttpRequest(url):
    #不设置heade, 特别是UA和Cookie, 服务器会报 403/400
    headers = {'User-Agent' : 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10.14; rv:76.0) Gecko/20100101 Firefox/76.0',
               'Accept' : 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
               'Accept-Encoding':'gzip, deflate, br',
               'Accept-Language':'  zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2',
               'Connection':'keep-alive',
               'Upgrade-Insecure-Requests':'1',
               'Cookie':'Hm_lvt_1db88642e346389874251b5a1eded6e3=1593053785; device_id=24700f9f1986800ab4fcc880530dd0ed; s=c112g2pne2; bid=a79be1e894cf51a62f2d974432ea1f9e_k4qly100; xq_a_token=d3d041b160a617dc5375a373ea62c19601b6de69; xqat=d3d041b160a617dc5375a373ea62c19601b6de69; xq_r_token=299b6e75cca70a2ef9171d20e737beed869f722f; xq_id_token=eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJ1aWQiOjgxOTQ3NjMwMDgsImlzcyI6InVjIiwiZXhwIjoxNTk1NjQ1ODEyLCJjdG0iOjE1OTMwNTM4MTI5MDksImNpZCI6ImQ5ZDBuNEFadXAifQ.cIeFbo3zuWMy4Kb476aTiPCS21rVIFKEUBoNwtH2PoxppHP2RwlAKTgVeP3Mc3xZA4BE31VNWSe2R-MfqMgEB6SCj5qdG1MySTWFD3DJaIU996n0ebxEluoD4src9URcZ4Ju-8_KPbPO3UxihIJZ0dCiM0ufWd5tKtCqoOoGw3gWNch3-TmL2hvf8YxyJPbcpyFQa9QOO39VmdJ-ASn-WxpePRw-gPuA6L59thyBUUOgRh7bUJYp4aYsulvPjHdeDJQAEZur-jv1fnfIhkgjKIUVDIxAykZqeM44FFyvbgkIyHVQzUh0evSPN7x0JKq74nucIUoV30kuJojmOsT4rw; u=8194763008; Hm_lpvt_1db88642e346389874251b5a1eded6e3=1593059646; remember=1; xq_is_login=1; snbim_minify=true'}

    url = urllib.request.Request(url=url,headers=headers)

    response = urllib.request.urlopen(url)

    #返回报文使用gzip压缩
    content_encoding = response.getheader('Content-Encoding')
    if content_encoding == 'gzip' :
        buf = io.BytesIO(response.read())
        gf = gzip.GzipFile(fileobj = buf)
        content = gf.read().decode('UTF-8')  #字符编码为utf-8
        #print(content)
        return content

url = 'https://api.xueqiu.com/friendships/groups/members.json?count=200&gid=0&uid='
startUid = 4111857140 #@山行
idlist = []
idlist.append(startUid)
cnt = 0
result = {}

for idx in idlist: 
    if cnt>40000:
        break

    response = HttpRequest(url+str(idx))
    followlist = json.loads(response);
    #print(followlist)
    for user in followlist['users']:
        idlist.append(user['id'])
        if user['screen_name'] in result:
            result[user['screen_name']] += 1
        else:
            result[user['screen_name']] = 1
    cnt += 1
    print(cnt)

#根据出现频次排序
result = sorted(result.items(),key=lambda x:x[1],reverse=True)
#print(result)

jsObj = json.dumps(result,ensure_ascii=False, indent=4)
 
fileObject = open('jsonFile.json', 'w')
fileObject.write(jsObj)
fileObject.close()
