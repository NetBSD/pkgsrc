# $NetBSD: options.mk,v 1.4 2012/07/11 19:09:18 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.apache
PKG_OPTIONS_REQUIRED_GROUPS=	mpm
PKG_OPTIONS_GROUP.mpm=		apache-mpm-event apache-mpm-prefork apache-mpm-worker
PKG_SUPPORTED_OPTIONS=		lua suexec
PKG_SUGGESTED_OPTIONS=		apache-mpm-prefork

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
PLIST_VARS+=		worker prefork
.if !empty(PKG_OPTIONS:Mapache-mpm-event)
CONFIGURE_ARGS+=	--with-mpm=event
PLIST.worker=		yes
.elif !empty(PKG_OPTIONS:Mapache-mpm-worker)
CONFIGURE_ARGS+=	--with-mpm=worker
PLIST.worker=		yes
.else
CONFIGURE_ARGS+=	--with-mpm=prefork
PLIST.prefork=		yes
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

CONFIGURE_ARGS+=	--enable-modules="all suexec"
APACHE_MODULES+=	suexec

CONFIGURE_ARGS+=	${APACHE_SUEXEC_CONFIGURE_ARGS:M--with-suexec-*}
BUILD_DEFS+=		APACHE_SUEXEC_CONFIGURE_ARGS
BUILD_TARGET=		all suexec
PLIST.suexec=		yes
SPECIAL_PERMS+=		sbin/suexec ${REAL_ROOT_USER} ${APACHE_GROUP} 4510
.endif

PLIST_VARS+=		lua
.if !empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--enable-lua
.include "../../lang/lua/buildlink3.mk"
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--disable-lua
.endif
