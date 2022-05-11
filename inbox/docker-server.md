# docker server commands

* tinc vpn
```bash
docker run -d \
    --name tinc \
    --net=host \
    --device=/dev/net/tun \
    --cap-add NET_ADMIN \
    --volume /etc/tinc/mhyt:/etc/tinc \
    jenserat/tinc start -D
```
- nginx
```bash
docker run --name simforge_docs  \
          -e TZ="Asia/Shanghai" -d  \
          -p 10088:80  \
         -v /usr/share/simforge/docs:/usr/share/nginx/html \
         nginx

docker run --name simforge_portal    \
        -e TZ="Asia/Shanghai" -d    \
        -p 80:80   \
        -v /usr/share/simforge/portal:/usr/share/nginx/html   \
        nginx
```
- mysql & gitlab
```bash
docker run -d --name mysql-server -p 3303:3306 -e MYSQL_ROOT_PASSWORD=mysql_root  -v /usr/share/simforge/mysql:/var/lib/mysql mysql
/var/simforge/mysql

export GITLAB_HOME=/var/gitlab
mkdir gitlab
sudo mkdir gitlab
sudo chmod 777 gitlab
sudo docker run --detach \\
  --hostname gitlab.mhyt.com \\
  --publish 172.16.240.16:443:443 \\
  --publish 172.16.240.16:80:80 \\
  --publish 172.16.240.16:22:22 \\
  --name gitlab \\
  --restart always \\
  --volume $GITLAB_HOME/config:/etc/gitlab \\
  --volume $GITLAB_HOME/logs:/var/log/gitlab \\
  --volume $GITLAB_HOME/data:/var/opt/gitlab \\
  --shm-size 256m \\
  registry.gitlab.cn/omnibus/gitlab-jh:latest

```
- openldap
```bash
#ldap 部署
docker run \
	--env LDAP_ORGANISATION="My Company" \
	--env LDAP_DOMAIN="my-company.com" \
	--env LDAP_ADMIN_PASSWORD="JonSn0w" \
	--detach osixia/openldap:1.5.0
/var/lib/ldap (LDAP database files)
/etc/ldap/slapd.d (LDAP config files)
--volume /data/slapd/database:/var/lib/ldap \
--volume /data/slapd/config:/etc/ldap/slapd.d \
```
