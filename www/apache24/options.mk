# $NetBSD: options.mk,v 1.15 2019/06/07 11:26:20 tm Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.apache
PKG_SUPPORTED_OPTIONS=		apache-mpm-event apache-mpm-prefork apache-mpm-worker \
				brotli lua http2 suexec xml
PKG_SUGGESTED_OPTIONS=		apache-mpm-event apache-mpm-prefork \
				apache-mpm-worker brotli http2 xml

.if ${OPSYS} == "SunOS" && !empty(OS_VERSION:M5.1[0-9])
PKG_SUPPORTED_OPTIONS+=		privileges
# Disabled until DTrace support is fully implemented/fixed
#PKG_SUPPORTED_OPTIONS+=		dtrace
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
PLIST_VARS+=		worker prefork event only-prefork not-only-prefork
PLIST_VARS+=		brotli http2 lua privileges suexec xml

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
# If only prefork mpm is supported, ...
.if empty(PKG_OPTIONS:Mapache-mpm-event) && \
  empty(PKG_OPTIONS:Mapache-mpm-worker) && \
  !empty(PKG_OPTIONS:Mapache-mpm-prefork)
CONFIGURE_ARGS+=	--with-mpm=prefork
PLIST.only-prefork=	yes
.else
PLIST.not-only-prefork=	yes
.endif

BUILD_DEFS+=		APACHE_MODULES

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

.if !empty(PKG_OPTIONS:Mhttp2)
.include "../../www/nghttp2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-nghttp2
PLIST.http2=		yes
.else
CONFIGURE_ARGS+=	--without-nghttp2
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lua
CONFIGURE_ARGS+=	--with-lua=${PREFIX}
BUILDLINK_TRANSFORM+=	l:lua-5.1:lua5.1
BUILDLINK_TRANSFORM+=	l:lua-5.2:lua5.2
BUILDLINK_TRANSFORM+=	l:lua-5.3:lua5.3
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if !empty(PKG_OPTIONS:Mprivileges)
CONFIGURE_ARGS+=	--enable-privileges
PLIST.privileges=	yes
.endif

.if !empty(PKG_OPTIONS:Mxml)
.include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--enable-proxy-html
CONFIGURE_ARGS+=	--enable-xml2enc
PLIST.xml=		yes
.else
CONFIGURE_ARGS+=	--disable-proxy-html
CONFIGURE_ARGS+=	--disable-xml2enc
.endif

.if !empty(PKG_OPTIONS:Mbrotli)
.include "../../archivers/brotli/buildlink3.mk"
CONFIGURE_ARGS+=       --enable-brotli
CONFIGURE_ARGS+=       --with-brotli=${PREFIX}
PLIST.brotli=          yes
.endif

# DTrace support is manifest, but actually not implemented at all
#.if !empty(PKG_OPTIONS:Mdtrace)
#CONFIGURE_ARGS+=	--enable-dtrace
#.endif
