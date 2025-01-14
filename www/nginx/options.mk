# $NetBSD: options.mk,v 1.113 2025/01/14 17:36:28 osa Exp $

CODELOAD_SITE_GITHUB=		https://codeload.github.com/

PKG_OPTIONS_VAR=	PKG_OPTIONS.nginx
PKG_SUPPORTED_OPTIONS=	nginx-array-var nginx-auth-request nginx-cache-purge nginx-dav nginx-debug
PKG_SUPPORTED_OPTIONS+=	nginx-dso nginx-echo nginx-encrypted-session nginx-flv nginx-form-input
PKG_SUPPORTED_OPTIONS+=	nginx-geoip nginx-geoip2 nginx-gssapi nginx-gtools nginx-gzip nginx-headers-more nginx-http2
PKG_SUPPORTED_OPTIONS+=	nginx-http3 nginx-image-filter nginx-luajit nginx-mail-proxy nginx-memcache
PKG_SUPPORTED_OPTIONS+=	nginx-naxsi nginx-njs nginx-njs-xml nginx-perl nginx-push nginx-realip nginx-redis nginx-rtmp
PKG_SUPPORTED_OPTIONS+=	nginx-secure-link nginx-set-misc nginx-slice nginx-ssl nginx-status
PKG_SUPPORTED_OPTIONS+=	nginx-stream-ssl-preread nginx-sts nginx-sub nginx-upload nginx-uwsgi nginx-vts

PKG_SUGGESTED_OPTIONS=	nginx-auth-request nginx-gzip nginx-http2 nginx-http3 nginx-memcache nginx-realip
PKG_SUGGESTED_OPTIONS+=	nginx-slice nginx-status nginx-ssl nginx-uwsgi

PLIST_VARS+=		arrayvar cprg dav dso echo encses forminput geoip2
PLIST_VARS+=		gssapi headmore imagefilter lua mail naxsi nchan ndk njs
PLIST_VARS+=		perl redis rtmp setmisc stream sts upload uwsgi vts

PKG_OPTIONS_LEGACY_OPTS+=	array-var:nginx-array-var
PKG_OPTIONS_LEGACY_OPTS+=	auth-request:nginx-auth-request
PKG_OPTIONS_LEGACY_OPTS+=	cache-purge:nginx-cache-purge
PKG_OPTIONS_LEGACY_OPTS+=	dav:nginx-dav
PKG_OPTIONS_LEGACY_OPTS+=	debug:nginx-debug
PKG_OPTIONS_LEGACY_OPTS+=	dso:nginx-dso
PKG_OPTIONS_LEGACY_OPTS+=	echo:nginx-echo
PKG_OPTIONS_LEGACY_OPTS+=	encrypted-session:nginx-encrypted-session
PKG_OPTIONS_LEGACY_OPTS+=	flv:nginx-flv
PKG_OPTIONS_LEGACY_OPTS+=	form-input:nginx-form-input
PKG_OPTIONS_LEGACY_OPTS+=	geoip:nginx-geoip
PKG_OPTIONS_LEGACY_OPTS+=	geoip2:nginx-geoip2
PKG_OPTIONS_LEGACY_OPTS+=	gssapi:nginx-gssapi
PKG_OPTIONS_LEGACY_OPTS+=	gtools:nginx-gtools
PKG_OPTIONS_LEGACY_OPTS+=	gzip:nginx-gzip
PKG_OPTIONS_LEGACY_OPTS+=	headers-more:nginx-headers-more
PKG_OPTIONS_LEGACY_OPTS+=	http2:nginx-http2
PKG_OPTIONS_LEGACY_OPTS+=	http3:nginx-http3
PKG_OPTIONS_LEGACY_OPTS+=	image-filter:nginx-image-filter
PKG_OPTIONS_LEGACY_OPTS+=	luajit:nginx-luajit
PKG_OPTIONS_LEGACY_OPTS+=	mail-proxy:nginx-mail-proxy
PKG_OPTIONS_LEGACY_OPTS+=	memcache:nginx-memcache
PKG_OPTIONS_LEGACY_OPTS+=	naxsi:nginx-naxsi
PKG_OPTIONS_LEGACY_OPTS+=	njs:nginx-njs
PKG_OPTIONS_LEGACY_OPTS+=	njs-xml:nginx-njs-xml
PKG_OPTIONS_LEGACY_OPTS+=	perl:nginx-perl
PKG_OPTIONS_LEGACY_OPTS+=	push:nginx-push
PKG_OPTIONS_LEGACY_OPTS+=	realip:nginx-realip
PKG_OPTIONS_LEGACY_OPTS+=	redis:nginx-redis
PKG_OPTIONS_LEGACY_OPTS+=	rtmp:nginx-rtmp
PKG_OPTIONS_LEGACY_OPTS+=	secure-link:nginx-secure-link
PKG_OPTIONS_LEGACY_OPTS+=	set-misc:nginx-set-misc
PKG_OPTIONS_LEGACY_OPTS+=	slice:nginx-slice
PKG_OPTIONS_LEGACY_OPTS+=	ssl:nginx-ssl
PKG_OPTIONS_LEGACY_OPTS+=	status:nginx-status
PKG_OPTIONS_LEGACY_OPTS+=	stream-ssl-preread:nginx-stream-ssl-preread
PKG_OPTIONS_LEGACY_OPTS+=	sts:nginx-sts
PKG_OPTIONS_LEGACY_OPTS+=	sub:nginx-sub
PKG_OPTIONS_LEGACY_OPTS+=	upload:nginx-upload
PKG_OPTIONS_LEGACY_OPTS+=	uwsgi:nginx-uwsgi
PKG_OPTIONS_LEGACY_OPTS+=	vts:nginx-vts

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnginx-dso)
CONFIGURE_ARGS+=	--modules-path=${PREFIX}/libexec/nginx
_addbasemod=		=dynamic
_addextmod=		add-dynamic-module
PLIST.dso=		yes
.else
_addextmod=		add-module
.endif

# documentation says naxsi must be the first module
.if !empty(PKG_OPTIONS:Mnginx-naxsi) || make(makesum) || make(mdi) || make(distclean)
NAXSI_VERSION=			1.6
NAXSI_DISTFILE=			naxsi-${NAXSI_VERSION}-src-with-deps.tar.gz
SITES.${NAXSI_DISTFILE}=	${MASTER_SITE_GITHUB:=wargio/naxsi/releases/download/${NAXSI_VERSION}/}
DISTFILES+=			${NAXSI_DISTFILE}
PLIST.naxsi=			yes
DSO_EXTMODS+=			naxsi
NAXSI_SUBDIR=			/naxsi_src
.endif

.if !empty(PKG_OPTIONS:Mnginx-debug)
CONFIGURE_ARGS+=	--with-debug
.endif

.if !empty(PKG_OPTIONS:Mnginx-ssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mail_ssl_module
CONFIGURE_ARGS+=	--with-http_ssl_module
SUBST_CLASSES+=		fix-ssl
SUBST_STAGE.fix-ssl=	pre-configure
SUBST_FILES.fix-ssl=	auto/lib/openssl/conf
SUBST_SED.fix-ssl=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.openssl},g'
SUBST_NOOP_OK.fix-ssl=	yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-dav) || make(makesum) || make(mdi) || make(distclean)
DAV_VERSION=		3.0.0
DAV_DISTNAME=		nginx-dav-ext-module-3.0.0
DAV_DISTFILE=		${DAV_DISTNAME}.tar.gz
SITES.${DAV_DISTFILE}=	-${MASTER_SITE_GITHUB:=arut/nginx-dav-ext-module/archive/}v${DAV_VERSION}.tar.gz
DISTFILES+=		${DAV_DISTFILE}
CONFIGURE_ARGS+=	--with-http_dav_module
DSO_EXTMODS+=		dav
PLIST.dav=		yes
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
SUBST_CLASSES+=		fix-xslt
SUBST_STAGE.fix-xslt=	pre-configure
SUBST_FILES.fix-xslt=	auto/lib/libxslt/conf
SUBST_SED.fix-xslt=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.libxslt},g'
SUBST_NOOP_OK.fix-xslt=	yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-flv)
CONFIGURE_ARGS+=	--with-http_flv_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-geoip)
.include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--with-http_geoip_module
SUBST_CLASSES+=		fix-geo
SUBST_STAGE.fix-geo=	pre-configure
SUBST_FILES.fix-geo=	auto/lib/geoip/conf
SUBST_SED.fix-geo=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.GeoIP},g'
SUBST_NOOP_OK.fix-geo=	yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-http2)
CONFIGURE_ARGS+=	--with-http_v2_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-http3)
CONFIGURE_ARGS+=	--with-http_v3_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-sub)
CONFIGURE_ARGS+=	--with-http_sub_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-gtools)
CONFIGURE_ARGS+=	--with-google_perftools_module
.include "../../devel/gperftools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnginx-mail-proxy)
DSO_BASEMODS+=		mail
PLIST.mail=		yes
.endif

.if empty(PKG_OPTIONS:Mnginx-memcache)
CONFIGURE_ARGS+=	--without-http_memcached_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-realip)
CONFIGURE_ARGS+=	--with-http_realip_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-redis) || make(makesum) || make(mdi) || make(distclean)
REDIS_GH_ACCOUNT=		osokin
REDIS_GH_PROJECT=		ngx_http_redis
REDIS_VERSION=			59eb1c3
REDIS_DISTNAME=			${REDIS_GH_PROJECT}-${REDIS_VERSION}
REDIS_DISTFILE=			${REDIS_GH_ACCOUNT}-${REDIS_DISTNAME}_GH.tar.gz
SITES.${REDIS_DISTFILE}=	-${CODELOAD_SITE_GITHUB:=${REDIS_GH_ACCOUNT}/${REDIS_GH_PROJECT}/tar.gz/${REDIS_VERSION}?dummy=${REDIS_DISTFILE}}
DISTFILES+=			${REDIS_DISTFILE}
DSO_EXTMODS+=			redis
PLIST.redis=			yes
.endif

# NDK must be added once and before 3rd party modules needing it
.for mod in luajit set-misc array-var form-input encrypted-session
.  if !defined(NEED_NDK) && !empty(PKG_OPTIONS:Mnginx-${mod}:O)
FIRST_DSO_EXTMODS+=	ndk
NEED_NDK=		yes
PLIST.ndk=		yes
.  endif
.endfor
.if defined(NEED_NDK) || make(makesum) || make(mdi) || make(distclean)
NDK_VERSION=		0.3.3
NDK_DISTNAME=		ngx_devel_kit-${NDK_VERSION}
NDK_DISTFILE=		${NDK_DISTNAME}.tar.gz
SITES.${NDK_DISTFILE}=	-${MASTER_SITE_GITHUB:=vision5/ngx_devel_kit/archive/}v${NDK_VERSION}.tar.gz
DISTFILES+=		${NDK_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mnginx-luajit) || make(makesum) || make(mdi) || make(distclean)
LUA_VERSION=		0.10.27
LUA_DISTNAME=		lua-nginx-module-${LUA_VERSION}
LUA_DISTFILE=		${LUA_DISTNAME}.tar.gz
SITES.${LUA_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/lua-nginx-module/archive/}v${LUA_VERSION}.tar.gz
DISTFILES+=		${LUA_DISTFILE}
.include "../../devel/pcre/buildlink3.mk"
BUILDLINK_API_DEPENDS.LuaJIT2+=	LuaJIT2>=2.1
.include "../../lang/LuaJIT2/buildlink3.mk"
DEPENDS+=		lua-resty-core>=0.1.27nb1:../../www/lua-resty-core
DEPENDS+=		lua-resty-lrucache>=0.13nb1:../../www/lua-resty-lrucache
CONFIGURE_ENV+=		LUAJIT_LIB=${PREFIX}/lib
CONFIGURE_ENV+=		LUAJIT_INC=${PREFIX}/include/luajit-2.1
DSO_EXTMODS+=		lua
PLIST.lua=		yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-echo) || make(makesum) || make(mdi) || make(distclean)
ECHOMOD_VERSION=		0.63
ECHOMOD_DISTNAME=		echo-nginx-module-${ECHOMOD_VERSION}
ECHOMOD_DISTFILE=		${ECHOMOD_DISTNAME}.tar.gz
SITES.${ECHOMOD_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/echo-nginx-module/archive/}v${ECHOMOD_VERSION}.tar.gz
DISTFILES+=			${ECHOMOD_DISTFILE}
DSO_EXTMODS+=			echomod
PLIST.echo=			yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-set-misc) || make(makesum) || make(mdi) || make(distclean)
SETMISC_VERSION=		0.33
SETMISC_DISTNAME=		set-misc-nginx-module-${SETMISC_VERSION}
SETMISC_DISTFILE=		${SETMISC_DISTNAME}.tar.gz
SITES.${SETMISC_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/set-misc-nginx-module/archive/}v${SETMISC_VERSION}.tar.gz
DISTFILES+=			${SETMISC_DISTFILE}
DSO_EXTMODS+=			setmisc
PLIST.setmisc=			yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-geoip2) || make(makesum) || make(mdi) || make(distclean)
GEOIP2_VERSION=			3.4
GEOIP2_DISTNAME=		ngx_http_geoip2_module-${GEOIP2_VERSION}
GEOIP2_DISTFILE=		${GEOIP2_DISTNAME}.tar.gz
SITES.${GEOIP2_DISTFILE}=	-${MASTER_SITE_GITHUB:=leev/ngx_http_geoip2_module/archive/}${GEOIP2_VERSION}.tar.gz
DISTFILES+=			${GEOIP2_DISTFILE}
DSO_EXTMODS+=			geoip2
PLIST.geoip2=			yes
.include "../../geography/libmaxminddb/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnginx-array-var) || make(makesum) || make(mdi) || make(distclean)
ARRAYVAR_VERSION=		0.06
ARRAYVAR_DISTNAME=		array-var-nginx-module-${ARRAYVAR_VERSION}
ARRAYVAR_DISTFILE=		${ARRAYVAR_DISTNAME}.tar.gz
SITES.${ARRAYVAR_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/array-var-nginx-module/archive/}v${ARRAYVAR_VERSION}.tar.gz
DISTFILES+=			${ARRAYVAR_DISTFILE}
DSO_EXTMODS+=			arrayvar
PLIST.arrayvar=			yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-encrypted-session) || make(makesum) || make(mdi) || make(distclean)
ENCSESS_VERSION=		0.09
ENCSESS_DISTNAME=		encrypted-session-nginx-module-${ENCSESS_VERSION}
ENCSESS_DISTFILE=		${ENCSESS_DISTNAME}.tar.gz
SITES.${ENCSESS_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/encrypted-session-nginx-module/archive/}v${ENCSESS_VERSION}.tar.gz
DISTFILES+=			${ENCSESS_DISTFILE}
DSO_EXTMODS+=			encsess
PLIST.encses=			yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-form-input) || make(makesum) || make(mdi) || make(distclean)
FORMINPUT_VERSION=		0.12
FORMINPUT_DISTNAME=		form-input-nginx-module-${FORMINPUT_VERSION}
FORMINPUT_DISTFILE=		${FORMINPUT_DISTNAME}.tar.gz
SITES.${FORMINPUT_DISTFILE}=	-${MASTER_SITE_GITHUB:=calio/form-input-nginx-module/archive/}v${FORMINPUT_VERSION}.tar.gz
DISTFILES+=			${FORMINPUT_DISTFILE}
DSO_EXTMODS+=			forminput
PLIST.forminput=		yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-headers-more) || make(makesum) || make(mdi) || make(distclean)
HEADMORE_VERSION=		0.37
HEADMORE_DISTNAME=		headers-more-nginx-module-${HEADMORE_VERSION}
HEADMORE_DISTFILE=		${HEADMORE_DISTNAME}.tar.gz
SITES.${HEADMORE_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/headers-more-nginx-module/archive/}v${HEADMORE_VERSION}.tar.gz
DISTFILES+=			${HEADMORE_DISTFILE}
DSO_EXTMODS+=			headmore
PLIST.headmore=			yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-uwsgi)
EGFILES+=		uwsgi_params
PLIST.uwsgi=		yes
CONFIGURE_ARGS+=	--http-uwsgi-temp-path=${NGINX_DATADIR}/uwsgi_temp
.else
CONFIGURE_ARGS+=	--without-http_uwsgi_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-push) || make(makesum) || make(mdi) || make(distclean)
PUSH_VERSION=		1.3.7
PUSH_DISTNAME=		nchan-${PUSH_VERSION}
PUSH_DISTFILE=		${PUSH_DISTNAME}.tar.gz
SITES.${PUSH_DISTFILE}=	-${MASTER_SITE_GITHUB:=slact/nchan/archive/}v${PUSH_VERSION}.tar.gz
DISTFILES+=		${PUSH_DISTFILE}
DSO_EXTMODS+=		push
PLIST.nchan=		yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-image-filter)
.include "../../graphics/gd/buildlink3.mk"
DSO_BASEMODS+=		http_image_filter_module
SUBST_CLASSES+=		fix-gd
SUBST_STAGE.fix-gd=	pre-configure
SUBST_FILES.fix-gd=	auto/lib/libgd/conf
SUBST_SED.fix-gd=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.gd},g'
SUBST_NOOP_OK.fix-gd=	yes
PLIST.imagefilter=	yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-slice)
CONFIGURE_ARGS+=	--with-http_slice_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-status)
CONFIGURE_ARGS+=	--with-http_stub_status_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-perl)
DSO_BASEMODS+=		http_perl_module
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
INSTALLATION_DIRS+=	${PERL5_INSTALLVENDORARCH}/auto/nginx
PLIST.perl=		yes
.include "../../lang/perl5/dirs.mk"
.include "../../lang/perl5/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnginx-gzip)
CONFIGURE_ARGS+=	--with-http_gzip_static_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-auth-request)
CONFIGURE_ARGS+=	--with-http_auth_request_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-cache-purge) || make(makesum) || make(mdi) || make(distclean)
CPRG_VERSION=		2.5.1
CPRG_DISTNAME=		ngx_cache_purge-${CPRG_VERSION}
CPRG_DISTFILE=		${CPRG_DISTNAME}.tar.gz
SITES.${CPRG_DISTFILE}=	-${MASTER_SITE_GITHUB:=nginx-modules/ngx_cache_purge/archive/}${CPRG_VERSION}.tar.gz
DISTFILES+=		${CPRG_DISTFILE}
DSO_EXTMODS+=		cprg
PLIST.cprg=		yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-secure-link)
CONFIGURE_ARGS+=	--with-http_secure_link_module
.endif

.if !empty(PKG_OPTIONS:Mnginx-stream-ssl-preread)
DSO_BASEMODS+=		stream
CONFIGURE_ARGS+=	--with-stream_ssl_preread_module
PLIST.stream=		yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-rtmp) || make(makesum) || make(mdi) || make(distclean)
RTMP_VERSION=		1.2.2
RTMP_DISTNAME=		nginx-rtmp-module-${RTMP_VERSION}
RTMP_DISTFILE=		${RTMP_DISTNAME}.tar.gz
SITES.${RTMP_DISTFILE}=	-${MASTER_SITE_GITHUB:=arut/nginx-rtmp-module/archive/}v${RTMP_VERSION}.tar.gz
DISTFILES+=		${RTMP_DISTFILE}
DSO_EXTMODS+=		rtmp
PLIST.rtmp=		yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-njs) || make(makesum) || make(mdi) || make(distclean)
NJS_VERSION=		0.8.8
NJS_DISTNAME=		njs-${NJS_VERSION}
NJS_DISTFILE=		${NJS_DISTNAME}.tar.gz
SITES.${NJS_DISTFILE}=	-${MASTER_SITE_GITHUB:=nginx/njs/archive/}${NJS_VERSION}.tar.gz
DISTFILES+=		${NJS_DISTFILE}
DSO_EXTMODS+=		njs
NJS_SUBDIR=		/nginx
PLIST.njs=		yes
.  if !empty(PKG_OPTIONS:Mnginx-njs-xml)
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.  else
NJS_CONFIGURE_ARGS=	--no-libxml2
CONFIGURE_ENV+=		NJS_LIBXSLT=NO
.  endif
.endif

.if !empty(PKG_OPTIONS:Mnginx-upload) || make(makesum) || make(mdi) || make(distclean)
UPLOAD_VERSION=			2.3.0
UPLOAD_DISTNAME=		nginx-upload-module-${UPLOAD_VERSION}
UPLOAD_DISTFILE=		${UPLOAD_DISTNAME}.tar.gz
SITES.${UPLOAD_DISTFILE}=	-${MASTER_SITE_GITHUB:=vkholodkov/nginx-upload-module/archive/refs/tags/}${UPLOAD_VERSION}.tar.gz
DISTFILES+=			${UPLOAD_DISTFILE}
DSO_EXTMODS+=			upload
PLIST.upload=			yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-gssapi) || make(makesum) || make(mdi) || make(distclean)
GSSAPI_GH_ACCOUNT=		stnoonan
GSSAPI_GH_PROJECT=		spnego-http-auth-nginx-module
GSSAPI_VERSION=			3575542
GSSAPI_DISTNAME=		${GSSAPI_GH_PROJECT}-${GSSAPI_VERSION}
GSSAPI_DISTFILE=		${GSSAPI_GH_ACCOUNT}-${GSSAPI_DISTNAME}_GH.tar.gz
SITES.${GSSAPI_DISTFILE}=	-${CODELOAD_SITE_GITHUB:=${GSSAPI_GH_ACCOUNT}/${GSSAPI_GH_PROJECT}/tar.gz/${GSSAPI_VERSION}?dummy=${GSSAPI_DISTFILE}}
DISTFILES+=			${GSSAPI_DISTFILE}
DSO_EXTMODS+=			gssapi
PLIST.gssapi=			yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-sts) || make(makesum) || make(mdi) || make(distclean)
STS_GH_ACCOUNT=		vozlt
STS_GH_PROJECT=		nginx-module-sts
STS_VERSION=		3c10d42
STS_DISTNAME=		${STS_GH_PROJECT}-${STS_VERSION}
STS_DISTFILE=		${STS_GH_ACCOUNT}-${STS_DISTNAME}_GH.tar.gz
SITES.${STS_DISTFILE}=	-${CODELOAD_SITE_GITHUB:=${STS_GH_ACCOUNT}/${STS_GH_PROJECT}/tar.gz/${STS_VERSION}?dummy=${STS_DISTFILE}}
DISTFILES+=		${STS_DISTFILE}
DSO_EXTMODS+=		sts
PLIST.sts=		yes
.endif

.if !empty(PKG_OPTIONS:Mnginx-vts) || make(makesum) || make(mdi) || make(distclean)
VTS_GH_ACCOUNT=		vozlt
VTS_GH_PROJECT=		nginx-module-vts
VTS_VERSION=		bf64dbf
VTS_DISTNAME=		${VTS_GH_PROJECT}-${VTS_VERSION}
VTS_DISTFILE=		${VTS_GH_ACCOUNT}-${VTS_DISTNAME}_GH.tar.gz
SITES.${VTS_DISTFILE}=	-${CODELOAD_SITE_GITHUB:=${VTS_GH_ACCOUNT}/${VTS_GH_PROJECT}/tar.gz/${VTS_VERSION}?dummy=${VTS_DISTFILE}}
DISTFILES+=		${VTS_DISTFILE}
DSO_EXTMODS+=		vts
PLIST.vts=		yes
.endif

.for mod in ${DSO_BASEMODS}
CONFIGURE_ARGS+=	--with-${mod}${_addbasemod}
.endfor

.for mod in ${FIRST_DSO_EXTMODS}
CONFIGURE_ARGS+=	--${_addextmod}=../${${mod:tu}_DISTNAME}${${mod:tu}_SUBDIR}
.endfor

.for mod in ${DSO_EXTMODS}
CONFIGURE_ARGS+=	--${_addextmod}=../${${mod:tu}_DISTNAME}${${mod:tu}_SUBDIR}
.endfor
