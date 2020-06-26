import urllib.request
import urllib.parse
import gzip
import io
import json
import time


def HttpRequest(url, cnt):
    if cnt%2==0:
        Cookie = 'Hm_lvt_1db88642e346389874251b5a1eded6e3=1593053785; device_id=24700f9f1986800ab4fcc880530dd0ed; s=c112g2pne2; bid=a79be1e894cf51a62f2d974432ea1f9e_k4qly100; __utma=1.542149742.1577599404.1593140581.1593157100.8; __utmz=1.1577599404.1.1.utmcsr=(direct)|utmccn=(direct)|utmcmd=(none); aliyungf_tc=AQAAALwYxE+7agMAH+RQcLeJmvjkgB1n; Hm_lpvt_1db88642e346389874251b5a1eded6e3=1593158607; snbim_minify=true; __utmc=1; acw_tc=2760823b15931569542328192eca5acb0989f9311e1939272d5f47d1962ef3; __utmb=1.1.10.1593157100; xq_a_token=ea139be840cf88ff8c30e6943cf26aba8ad77358; xqat=ea139be840cf88ff8c30e6943cf26aba8ad77358; xq_r_token=863970f9d67d944596be27965d13c6929b5264fe; xq_id_token=eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJ1aWQiOi0xLCJpc3MiOiJ1YyIsImV4cCI6MTU5NDAwMjgwOCwiY3RtIjoxNTkzMTU3MjM5NDAyLCJjaWQiOiJkOWQwbjRBWnVwIn0.COVYw69X57tG5kARwn78z4UWWRV9Gx8VGgB-kWA7SoiVyUbQts7zYZzCzkce-OQprr7maXt_1gxmE6XqHrK_sZqSHqH-j7yVZNEmZDtMP5vgEoKvPX62KdelSQJkIUD_2P1v-4qNqWmYVajhpaXwIToz_yA8EU6fcRvl5WFDJexseUNme8KEg1KjCoYnSaxvgBogiaNhleNflKZJyh5skVQ-m7krkuJac22OLu-6BgrpZl0NjpI-K9Rhca2xswEwkcXQAMxZGIT3a78tzqWyUoq1gnC1fENRiv6mwTWEjZSLgucaf8ymDBBW7xGb6V441n67hv5uph-FkOntnFkw1g; u=861593157251223'
    else:
        Cookie = 'xq_a_token=0a4737377ebec6a7ee2ee2ee2476863b1bca0071;xq_id_token=eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJ1aWQiOjgxOTQ3NjMwMDgsImlzcyI6InVjIiwiZXhwIjoxNTk0NzA2NjY5LCJjdG0iOjE1OTMwNzU5NjYyNjcsImNpZCI6IldpQ2lteHBqNUgifQ.KsBggRZvIMbZSLtGIJVMMM7_8k83mYYsn5Fk2HsvmHRfwv7Ze-pYtxnp6lahE7SDPYQ9UG3368H0mWVCEavF38ht9_jfVJffSnbQUK2-kGHTesGmg5OKQSD3isKrbDF7Gxy_ox_youiCybInQ8ozMUcpygE0j1EGXwKQ5VZvK76fMKBdzCd3lZPHdsXVF7Vm6c0fPaYvynsKhLoEfQtaKStZ17CNj_RSgNYs5GVp3Sp70m_24pI5gYXaKnqsK0VVMASHfcHDvp6p2-DPi0J_zvK1lEtel9_l_C8f1RRrMbuaS6x1_ioVyyNylV6NNJsCRO1Y4v8LFypfxeY_U3unCQ;u=8194763008;xid=100314335;session_id=75dce7cca85cbf3d01bcf5025b8c1594d51de7f8d3f6a6b577bda9074fa05630'

    #不设置heade, 特别是UA和Cookie, 服务器会报 403/400
    headers = {'User-Agent' : 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10.14; rv:76.0) Gecko/20100101 Firefox/76.0',
               'Accept' : 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
               'Accept-Encoding':'gzip, deflate, br',
               'Accept-Language':'  zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2',
               'Connection':'keep-alive',
               'Upgrade-Insecure-Requests':'1',
               'Cookie' : Cookie,
		#'Cookie':'Hm_lvt_1db88642e346389874251b5a1eded6e3=1593053785; device_id=24700f9f1986800ab4fcc880530dd0ed; s=c112g2pne2; bid=a79be1e894cf51a62f2d974432ea1f9e_k4qly100; __utma=1.542149742.1577599404.1593140581.1593157100.8; __utmz=1.1577599404.1.1.utmcsr=(direct)|utmccn=(direct)|utmcmd=(none); aliyungf_tc=AQAAALwYxE+7agMAH+RQcLeJmvjkgB1n; Hm_lpvt_1db88642e346389874251b5a1eded6e3=1593158607; snbim_minify=true; __utmc=1; acw_tc=2760823b15931569542328192eca5acb0989f9311e1939272d5f47d1962ef3; __utmb=1.1.10.1593157100; xq_a_token=ea139be840cf88ff8c30e6943cf26aba8ad77358; xqat=ea139be840cf88ff8c30e6943cf26aba8ad77358; xq_r_token=863970f9d67d944596be27965d13c6929b5264fe; xq_id_token=eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJ1aWQiOi0xLCJpc3MiOiJ1YyIsImV4cCI6MTU5NDAwMjgwOCwiY3RtIjoxNTkzMTU3MjM5NDAyLCJjaWQiOiJkOWQwbjRBWnVwIn0.COVYw69X57tG5kARwn78z4UWWRV9Gx8VGgB-kWA7SoiVyUbQts7zYZzCzkce-OQprr7maXt_1gxmE6XqHrK_sZqSHqH-j7yVZNEmZDtMP5vgEoKvPX62KdelSQJkIUD_2P1v-4qNqWmYVajhpaXwIToz_yA8EU6fcRvl5WFDJexseUNme8KEg1KjCoYnSaxvgBogiaNhleNflKZJyh5skVQ-m7krkuJac22OLu-6BgrpZl0NjpI-K9Rhca2xswEwkcXQAMxZGIT3a78tzqWyUoq1gnC1fENRiv6mwTWEjZSLgucaf8ymDBBW7xGb6V441n67hv5uph-FkOntnFkw1g; u=861593157251223'
               #'Cookie':'xq_a_token=0a4737377ebec6a7ee2ee2ee2476863b1bca0071;xq_id_token=eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJ1aWQiOjgxOTQ3NjMwMDgsImlzcyI6InVjIiwiZXhwIjoxNTk0NzA2NjY5LCJjdG0iOjE1OTMwNzU5NjYyNjcsImNpZCI6IldpQ2lteHBqNUgifQ.KsBggRZvIMbZSLtGIJVMMM7_8k83mYYsn5Fk2HsvmHRfwv7Ze-pYtxnp6lahE7SDPYQ9UG3368H0mWVCEavF38ht9_jfVJffSnbQUK2-kGHTesGmg5OKQSD3isKrbDF7Gxy_ox_youiCybInQ8ozMUcpygE0j1EGXwKQ5VZvK76fMKBdzCd3lZPHdsXVF7Vm6c0fPaYvynsKhLoEfQtaKStZ17CNj_RSgNYs5GVp3Sp70m_24pI5gYXaKnqsK0VVMASHfcHDvp6p2-DPi0J_zvK1lEtel9_l_C8f1RRrMbuaS6x1_ioVyyNylV6NNJsCRO1Y4v8LFypfxeY_U3unCQ;u=8194763008;xid=100314335;session_id=75dce7cca85cbf3d01bcf5025b8c1594d51de7f8d3f6a6b577bda9074fa05630'
               }
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

def CalcScore(gain):
    positive = 0;
    if gain > 1000:
        positive = 9
    elif gain > 800:
        positive = 8
    elif gain > 500:
        positive = 7
    elif gain > 300:
        positive = 6
    elif gain > 200:
        positive = 5
    elif gain > 100:
        positive = 4
    elif gain > 0:
        positive = 0
    elif gain > -10:
        positive = -2
    elif gain > -20:
        positive = -5
    elif gain > -30:
        positive = -9
    else:
        positive = -12
    return positive;


url = 'https://api.xueqiu.com/friendships/groups/members.json?count=200&gid=0&uid='
#/cubes/onshelf/list.json?count=20&page=1&type=2&user_id=5912655543&_=1593158095178&_s=8bc764&_t=D4970731-808A-436B-9995-45123239238B.8194763008.1593157993492.1593158091809
urlcube = 'https://api.xueqiu.com/cubes/onshelf/list.json?count=20&page=1&type=2&user_id='
startUid = 4111857140 #@山行
idlist = []
idlist.append(startUid)
cnt = 0
result = {}
resultid = set()
logfile = open('cubescore.txt','w+')

for idx in idlist: 
    if cnt>40000:
        break

    response = HttpRequest(url+str(idx),cnt)
    followlist = json.loads(response);
    #print(followlist)
    for user in followlist['users']:
        idlist.append(user['id'])

        if user['id'] in resultid:
            continue

        if user['cube_count'] <= 0 or user['cube_count'] > 10:
            resultid.add(user['id'])
            continue

        if user['followers_count'] < 500:
            resultid.add(user['id'])
            continue

        if user['status_count'] < 50:
            resultid.add(user['id'])
            continue   

        cubes = HttpRequest(urlcube+str(user['id']), cnt)
        if type(cubes)!=str:
            resultid.add(user['id'])
            continue   
            
        cubelist = json.loads(cubes)
        time.sleep(15)
        #print(cubelist)
        cnt += 1
        print(cnt)
        if cubelist['totalCount'] < 1:
            resultid.add(user['id'])
            continue
        else:
            positive = 0
            for cube in cubelist['list']:
                positive += CalcScore(cube['total_gain'])
            if positive>5:
                    resultid.add(user['id'])
                    #result[user['screen_name']] = positive
                    #logfile.write('user: '+ user['screen_name'] + ', score: ' + str(positive) + '\n')
                    logfile.write(str(positive) + '\t:' + str(user['id']) + '\t|' + user['screen_name']+ '\n')

    #cnt += 1
    #print(cnt)
    

# #根据出现频次排序
# result = sorted(result.items(),key=lambda x:x[1],reverse=True)
# #print(result)

# jsObj = json.dumps(result,ensure_ascii=False, indent=4)
 
# fileObject = open('jsonFile.json', 'w')
# fileObject.write(jsObj)
# fileObject.close()
