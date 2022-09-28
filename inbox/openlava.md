```bash
#lsf(load share facility)

# openlava
./configure --prefix=/opt/openlava
make -j 4 # 编译
sudo make install 
cd config
# openlava/config
rm -f *.in Makefile*
sudo cp * /opt/openlava/etc/
sudo cp /opt/openlava/etc/openlava /etc/init.d/
ll /etc/init.d/
cd /opt
# /opt
sudo chown openlava. -R openlava/
cd /openlava/etc
# /opt/openlava/etc
sudo vim lsb.hosts
sudo vim lsb.queues
sudo vim lsf.cluster.openlava
sudo vim /etc/bashrc
# source /opt/openlava/etc/openlava.sh


chkconfig
chkconfig openlava on
chkconfig

/etc/init.d/openlava start
#lim started
#res started
#sbatchd started
# CBEXE CBJM CBLS

bhosts
lshosts
lsid

. /etc/bashrc
bsub -n 4 -m ms sleep 120
bjobs


```
