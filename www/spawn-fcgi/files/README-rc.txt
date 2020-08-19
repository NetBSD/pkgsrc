To configure spawn-fcgi jobs from /etc/rc.conf:

1) List the jobs to be started:

spawnfcgi=YES
spawnfcgi_jobs="job1 ... jobN"

2) Add options to each job in the form spawnfcgi_<job>_<option>, for example, if you use PHP:

spawnfcgi_jobX_command="/usr/pkg/libexec/cgi-bin/php"
spawnfcgi_jobX_args=""
spawnfcgi_jobX_user="php"
spawnfcgi_jobX_socket=""
spawnfcgi_jobX_address="127.0.0.1"
spawnfcgi_jobX_port="9000"
spawnfcgi_jobX_children="3"

The complete list of options can be found in the spawnfcgi rc.d script.
