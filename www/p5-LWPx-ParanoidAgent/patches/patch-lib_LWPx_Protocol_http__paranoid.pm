$NetBSD: patch-lib_LWPx_Protocol_http__paranoid.pm,v 1.1 2014/09/17 22:46:17 schmonz Exp $

From upstream git commit a92ed8f, fix usage of IO::Socket::SSL when
reading long documents. From df6df19 and a patch from Chapman Flack,
specify server name for Server Name Indication.

--- lib/LWPx/Protocol/http_paranoid.pm.orig	2013-11-04 19:30:07.000000000 +0000
+++ lib/LWPx/Protocol/http_paranoid.pm
@@ -10,6 +10,8 @@ require HTTP::Response;
 require HTTP::Status;
 require Net::HTTP;
 
+use Errno qw(EAGAIN);
+
 use vars qw(@ISA $TOO_LATE $TIME_REMAIN);
 
 require LWP::Protocol;
@@ -65,6 +67,8 @@ sub _new_socket
             (time() - $request->{_timebegin}) :
             $timeout;
         $sock = $self->socket_class->new(PeerAddr => $addr,
+                                         PeerHost => $host,
+                                         SSL_hostname => $host,
                                          PeerPort => $port,
                                          Proto    => 'tcp',
                                          Timeout  => $conn_timeout,
@@ -360,8 +364,9 @@ sub request
 	{
             _set_time_remain();
 	    $n = $socket->read_entity_body($buf, $size);
-	    die "Can't read entity body: $!" unless defined $n;
 	    redo READ if $n == -1;
+	    redo READ if not defined $n and $! == EAGAIN;
+	    die "Can't read entity body: $!" unless defined $n;
 	}
 	$complete++ if !$n;
         return \$buf;
