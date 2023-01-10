yum install epel-release
yum install munge munge-devel
dd if=/dev/urandom bs=1 count=1024 >/etc/munge/munge.key
cd /etc/munge
chown munge. munge.key
chmod 400 munge.key

systemctl start munge.service
systemctl enable munge.service
systemctl status munge.service

yum install slurm slurm-slurmctld slurm-slurmd slurm-pmi slurm-devel slurm-contribs slurm-pam_slurm -y 
cd /etc/slurm/
vim cgroup.conf
vim slurm.conf
slurmd -C 

mkdir -p /var/spool/{slurmd,systemctld}
chown slurm. -R /var/spool/{slurmd,systemctld}
touch /var/log/{slurmd.log,slurmctld.log}
chown slurm. /var/log/{slurmd.log,slurmctld.log}

systemctl start slurmctld.service
systemctl status slurmctld.service
systemctl enable slurmctld.service

systemctl start slurmd.service
systemctl status slurmd.service
systemctl enable slurmd.service

sinfo 
sinfo -lNa
srun -N1 -n1 sleep 10
