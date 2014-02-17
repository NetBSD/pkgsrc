# $NetBSD: options.mk,v 1.12 2014/02/17 17:32:55 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.apache
PKG_OPTIONS_REQUIRED_GROUPS=	mpm
PKG_OPTIONS_GROUP.mpm=		apache-mpm-event apache-mpm-prefork apache-mpm-worker
PKG_SUPPORTED_OPTIONS=		apache-shared-modules suexec
PKG_SUGGESTED_OPTIONS=		apache-shared-modules apache-mpm-prefork

.include "../../mk/bsd.options.mk"

# Set the "Multi-Processing Model" used by Apache to handle requests.
# Valid values are:
# 	event		multi-threaded based in worker, designed
# 			to allow more requests to be served
# 			simultaneously by passing off some processing
# 			work to supporting threads.
# 			BEWARE: does not work with SSL or input filters.
#	prefork		non-threaded, pre-forking web server
#	worker		hybrid multi-threaded multi-process web server
#
PLIST_VARS+=		worker
.if !empty(PKG_OPTIONS:Mapache-mpm-event)
CONFIGURE_ARGS+=	--with-mpm=event
PLIST.worker=		yes
.elif !empty(PKG_OPTIONS:Mapache-mpm-worker)
CONFIGURE_ARGS+=	--with-mpm=worker
PLIST.worker=		yes
.else
CONFIGURE_ARGS+=	--with-mpm=prefork
.endif

# APACHE_MODULES are the modules that are linked statically into the
# apache httpd executable.
#
PLIST_VARS+=		all-shared
.if !empty(PKG_OPTIONS:Mapache-shared-modules)
CONFIGURE_ARGS+=	--enable-mods-shared=${DFLT_APACHE_MODULES:Q}
PLIST.all-shared=	yes
.else
CONFIGURE_ARGS+=	--enable-modules=${APACHE_MODULES:Q}
.endif
BUILD_DEFS+=		APACHE_MODULES

PLIST_VARS+=		suexec
.if !empty(PKG_OPTIONS:Msuexec)
BUILD_DEFS+=		APACHE_SUEXEC_PATH
BUILD_DEFS+=		APACHE_SUEXEC_DOCROOT APACHE_SUEXEC_LOGFILE

APACHE_SUEXEC_DOCROOT?=	${PREFIX}/share/httpd/htdocs
APACHE_SUEXEC_PATH=	/bin:/usr/bin:${PREFIX}/bin:/usr/local/bin
APACHE_SUEXEC_LOGFILE?=	${VARBASE}/log/httpd/suexec.log
APACHE_SUEXEC_CONFIGURE_ARGS+=						\
	--with-suexec-bin=${PREFIX}/sbin/suexec				\
	--with-suexec-caller=${APACHE_USER}				\
	--with-suexec-safepath='${APACHE_SUEXEC_PATH:Q}'		\
	--with-suexec-docroot=${APACHE_SUEXEC_DOCROOT:Q}		\
	--with-suexec-logfile=${APACHE_SUEXEC_LOGFILE}

.  if !empty(PKG_OPTIONS:Mapache-shared-modules)
CONFIGURE_ARGS+=	--enable-modules="all suexec"
.  else
APACHE_MODULES+=	suexec
.  endif
CONFIGURE_ARGS+=	${APACHE_SUEXEC_CONFIGURE_ARGS:M--with-suexec-*}
BUILD_DEFS+=		APACHE_SUEXEC_CONFIGURE_ARGS
BUILD_TARGET=		all suexec
PLIST.suexec=		yes
SPECIAL_PERMS+=		sbin/suexec ${REAL_ROOT_USER} ${APACHE_GROUP} 4510
.endif
