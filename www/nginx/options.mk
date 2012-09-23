# $NetBSD: options.mk,v 1.17 2012/09/23 12:46:15 shattered Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nginx
PKG_SUPPORTED_OPTIONS=	dav flv gtools inet6 mail-proxy memcache naxsi pcre \
			push realip ssl sub uwsgi image-filter upload debug \
			status nginx-autodetect-cflags
PKG_SUGGESTED_OPTIONS=	inet6 pcre ssl

PLIST_VARS+=		naxsi uwsgi

.include "../../mk/bsd.options.mk"

# documentation says naxsi must be the first module
.if !empty(PKG_OPTIONS:Mnaxsi)
PLIST.naxsi=		yes
CONFIGURE_ARGS+=	--add-module=../${NAXSI}/naxsi_src
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--with-debug
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mail_ssl_module
CONFIGURE_ARGS+=	--with-http_ssl_module
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pcre
CONFIGURE_ARGS+=	--without-http_rewrite_module
.endif

.if !empty(PKG_OPTIONS:Mdav)
CONFIGURE_ARGS+=	--with-http_dav_module
.endif

.if !empty(PKG_OPTIONS:Mflv)
CONFIGURE_ARGS+=	--with-http_flv_module
.endif

.if !empty(PKG_OPTIONS:Msub)
CONFIGURE_ARGS+=	--with-http_sub_module
.endif

.if !empty(PKG_OPTIONS:Mgtools)
CONFIGURE_ARGS+=	--with-google_perftools_module
.endif

.if !empty(PKG_OPTIONS:Mmail-proxy)
CONFIGURE_ARGS+=	--with-mail
.endif

.if empty(PKG_OPTIONS:Mmemcache)
CONFIGURE_ARGS+=	--without-http_memcached_module
.endif

.if !empty(PKG_OPTIONS:Mnaxsi) || make(makesum)
NAXSI=			naxsi-core-0.48
NAXSI_DISTFILE=		${NAXSI}.tgz
SITES.${NAXSI_DISTFILE}=	http://naxsi.googlecode.com/files/
DISTFILES+=		${NAXSI_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mrealip)
CONFIGURE_ARGS+=	--with-http_realip_module
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.endif

.if !empty(PKG_OPTIONS:Muwsgi)
EGFILES+=		uwsgi_params
PLIST.uwsgi=		yes
.else
CONFIGURE_ARGS+=	--without-http_uwsgi_module
.endif

.if !empty(PKG_OPTIONS:Mpush)
CONFIGURE_ARGS+=	--add-module=../${PUSH}
.endif
.if !empty(PKG_OPTIONS:Mpush) || make(makesum)
PUSH=			nginx_http_push_module-0.692
PUSH_DISTFILE=		${PUSH}.tar.gz
SITES.${PUSH_DISTFILE}=	http://pushmodule.slact.net/downloads/

DISTFILES+=		${PUSH_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mupload)
CONFIGURE_ARGS+=	--add-module=../${NGX_UPLOAD}
.endif

.if !empty(PKG_OPTIONS:Mupload) || make(makesum)
DISTFILES+=		${NGX_UPLOAD_DISTFILE}

NGX_UPLOAD=		nginx_upload_module-2.2.0
NGX_UPLOAD_DISTFILE=	${NGX_UPLOAD}.tar.gz
SITES.${NGX_UPLOAD_DISTFILE}=	http://www.grid.net.ru/nginx/download/
.endif

.if !empty(PKG_OPTIONS:Mimage-filter)
.include "../../graphics/gd/buildlink3.mk"
CONFIGURE_ARGS+=	--with-http_image_filter_module
.endif

.if !empty(PKG_OPTIONS:Mstatus)
CONFIGURE_ARGS+=	--with-http_stub_status_module
.endif
