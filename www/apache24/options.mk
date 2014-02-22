# $NetBSD: options.mk,v 1.9 2014/02/22 17:28:34 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.apache
PKG_SUPPORTED_OPTIONS=		lua suexec apache-mpm-event apache-mpm-prefork apache-mpm-worker
PKG_SUGGESTED_OPTIONS=		apache-mpm-event apache-mpm-prefork \
				apache-mpm-worker

.if ${OPSYS} == "SunOS" && !empty(OS_VERSION:M5.1[0-9])
PKG_SUPPORTED_OPTIONS+=		privileges
# Disabled until DTrace support is fully implemented/fixed
# PKG_SUPPORTED_OPTIONS+=		dtrace
.endif

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
PLIST_VARS+=		worker prefork event

.if !empty(PKG_OPTIONS:Mapache-mpm-event)
MPMS+=			event
PLIST.event=		yes
.endif

.if !empty(PKG_OPTIONS:Mapache-mpm-worker)
MPMS+=			worker
PLIST.worker=		yes
.endif

.if !empty(PKG_OPTIONS:Mapache-mpm-prefork)
MPMS+=			prefork
PLIST.prefork=		yes
.endif

CONFIGURE_ARGS+=	--enable-mpms-shared='${MPMS}'
MESSAGE_SUBST+=		MPMS=${MPMS:Q}

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

PLIST_VARS+=		privileges
.if !empty(PKG_OPTIONS:Mprivileges)
CONFIGURE_ARGS+=	--enable-privileges
PLIST.privileges=	yes
.endif

# DTrace support is manifest, but actually not implemented at all
# .if !empty(PKG_OPTIONS:Mdtrace)
# CONFIGURE_ARGS+=	--enable-dtrace
# .endif
