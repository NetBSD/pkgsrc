# $NetBSD: options.mk,v 1.82 2022/07/14 10:39:24 osa Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nginx
PKG_SUPPORTED_OPTIONS=	array-var auth-request cache-purge dav debug
PKG_SUPPORTED_OPTIONS+=	dso echo encrypted-session flv form-input
PKG_SUPPORTED_OPTIONS+=	geoip geoip2 gtools gzip headers-more http2
PKG_SUPPORTED_OPTIONS+=	image-filter luajit mail-proxy memcache
PKG_SUPPORTED_OPTIONS+=	naxsi njs perl push realip rtmp
PKG_SUPPORTED_OPTIONS+=	secure-link set-misc slice ssl status
PKG_SUPPORTED_OPTIONS+=	stream-ssl-preread sub upload uwsgi

PKG_SUGGESTED_OPTIONS=	auth-request gzip http2 memcache pcre realip
PKG_SUGGESTED_OPTIONS+=	slice status ssl uwsgi

PKG_OPTIONS_LEGACY_OPTS+=	v2:http2

PKG_OPTIONS_OPTIONAL_GROUPS=	pcre
PKG_OPTIONS_GROUP.pcre=		pcre pcre2

PLIST_VARS+=		arrayvar cprg dav dso echo encses forminput geoip2
PLIST_VARS+=		headmore imagefilter lua mail naxsi nchan ndk njs
PLIST_VARS+=		perl rtmp setmisc stream upload uwsgi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdso)
CONFIGURE_ARGS+=	--modules-path=${PREFIX}/libexec/nginx
_addbasemod=		=dynamic
_addextmod=		add-dynamic-module
PLIST.dso=		yes
.else
_addextmod=		add-module
.endif

# documentation says naxsi must be the first module
.if !empty(PKG_OPTIONS:Mnaxsi) || make(makesum) || make(mdi) || make(distclean)
NAXSI_VERSION=			1.3
NAXSI_DISTNAME=			naxsi-${NAXSI_VERSION}
NAXSI_DISTFILE=			${NAXSI_DISTNAME}.tar.gz
SITES.${NAXSI_DISTFILE}=	-${MASTER_SITE_GITHUB:=nbs-system/naxsi/archive/}${NAXSI_VERSION}.tar.gz
DISTFILES+=			${NAXSI_DISTFILE}
PLIST.naxsi=			yes
DSO_EXTMODS+=			naxsi
NAXSI_SUBDIR=			/naxsi_src
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--with-debug
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mail_ssl_module
CONFIGURE_ARGS+=	--with-http_ssl_module
SUBST_CLASSES+=		fix-ssl
SUBST_STAGE.fix-ssl=	pre-configure
SUBST_FILES.fix-ssl=	auto/lib/openssl/conf
SUBST_SED.fix-ssl=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.openssl},g'
SUBST_NOOP_OK.fix-ssl=	yes
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pcre
CONFIGURE_ARGS+=	--without-pcre2
SUBST_CLASSES+=		fix-pcre
SUBST_STAGE.fix-pcre=	pre-configure
SUBST_FILES.fix-pcre=	auto/lib/pcre/conf
SUBST_SED.fix-pcre=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.pcre},g'
SUBST_NOOP_OK.fix-pcre=	yes
.endif

.if !empty(PKG_OPTIONS:Mpcre2)
.include "../../devel/pcre2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pcre
SUBST_CLASSES+=		fix-pcre2
SUBST_STAGE.fix-pcre2=	pre-configure
SUBST_FILES.fix-pcre2=	auto/lib/pcre/conf
SUBST_SED.fix-pcre2=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.pcre2},g'
SUBST_NOOP_OK.fix-pcre2=yes
.endif

.if empty(PKG_OPTIONS:Mpcre) && empty(PKG_OPTIONS:Mpcre2)
CONFIGURE_ARGS+=	--without-pcre
CONFIGURE_ARGS+=	--without-http_rewrite_module
.endif

.if !empty(PKG_OPTIONS:Mdav) || make(makesum) || make(mdi) || make(distclean)
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

.if !empty(PKG_OPTIONS:Mflv)
CONFIGURE_ARGS+=	--with-http_flv_module
.endif

.if !empty(PKG_OPTIONS:Mgeoip)
.include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--with-http_geoip_module
SUBST_CLASSES+=		fix-geo
SUBST_STAGE.fix-geo=	pre-configure
SUBST_FILES.fix-geo=	auto/lib/geoip/conf
SUBST_SED.fix-geo=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.GeoIP},g'
SUBST_NOOP_OK.fix-geo=	yes
.endif

.if !empty(PKG_OPTIONS:Mhttp2)
CONFIGURE_ARGS+=	--with-http_v2_module
.endif

.if !empty(PKG_OPTIONS:Msub)
CONFIGURE_ARGS+=	--with-http_sub_module
.endif

.if !empty(PKG_OPTIONS:Mgtools)
CONFIGURE_ARGS+=	--with-google_perftools_module
.include "../../devel/gperftools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmail-proxy)
DSO_BASEMODS+=		mail
PLIST.mail=		yes
.endif

.if empty(PKG_OPTIONS:Mmemcache)
CONFIGURE_ARGS+=	--without-http_memcached_module
.endif

.if !empty(PKG_OPTIONS:Mrealip)
CONFIGURE_ARGS+=	--with-http_realip_module
.endif

# NDK must be added once and before 3rd party modules needing it
.for mod in luajit set-misc array-var form-input encrypted-session
.  if !defined(NEED_NDK) && !empty(PKG_OPTIONS:M${mod}:O)
FIRST_DSO_EXTMODS+=	ndk
NEED_NDK=		yes
PLIST.ndk=		yes
.  endif
.endfor
.if defined(NEED_NDK) || make(makesum) || make(mdi) || make(distclean)
NDK_VERSION=		0.3.1
NDK_DISTNAME=		ngx_devel_kit-${NDK_VERSION}
NDK_DISTFILE=		${NDK_DISTNAME}.tar.gz
SITES.${NDK_DISTFILE}=	-${MASTER_SITE_GITHUB:=simpl/ngx_devel_kit/archive/}v${NDK_VERSION}.tar.gz
DISTFILES+=		${NDK_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mluajit) || make(makesum) || make(mdi) || make(distclean)
LUA_VERSION=		0.10.21
LUA_DISTNAME=		lua-nginx-module-${LUA_VERSION}
LUA_DISTFILE=		${LUA_DISTNAME}.tar.gz
SITES.${LUA_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/lua-nginx-module/archive/}v${LUA_VERSION}.tar.gz
DISTFILES+=		${LUA_DISTFILE}
.include "../../lang/LuaJIT2/buildlink3.mk"
CONFIGURE_ENV+=		LUAJIT_LIB=${PREFIX}/lib
CONFIGURE_ENV+=		LUAJIT_INC=${PREFIX}/include/luajit-2.0
DSO_EXTMODS+=		lua
PLIST.lua=		yes
.endif

.if !empty(PKG_OPTIONS:Mecho) || make(makesum) || make(mdi) || make(distclean)
ECHOMOD_VERSION=		0.62
ECHOMOD_DISTNAME=		echo-nginx-module-${ECHOMOD_VERSION}
ECHOMOD_DISTFILE=		${ECHOMOD_DISTNAME}.tar.gz
SITES.${ECHOMOD_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/echo-nginx-module/archive/}v${ECHOMOD_VERSION}.tar.gz
DISTFILES+=			${ECHOMOD_DISTFILE}
DSO_EXTMODS+=			echomod
PLIST.echo=			yes
.endif

.if !empty(PKG_OPTIONS:Mset-misc) || make(makesum) || make(mdi) || make(distclean)
SETMISC_VERSION=		0.33
SETMISC_DISTNAME=		set-misc-nginx-module-${SETMISC_VERSION}
SETMISC_DISTFILE=		${SETMISC_DISTNAME}.tar.gz
SITES.${SETMISC_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/set-misc-nginx-module/archive/}v${SETMISC_VERSION}.tar.gz
DISTFILES+=			${SETMISC_DISTFILE}
DSO_EXTMODS+=			setmisc
PLIST.setmisc=			yes
.endif

.if !empty(PKG_OPTIONS:Mgeoip2) || make(makesum) || make(mdi) || make(distclean)
GEOIP2_VERSION=			3.3
GEOIP2_DISTNAME=		ngx_http_geoip2_module-${GEOIP2_VERSION}
GEOIP2_DISTFILE=		${GEOIP2_DISTNAME}.tar.gz
SITES.${GEOIP2_DISTFILE}=	-${MASTER_SITE_GITHUB:=leev/ngx_http_geoip2_module/archive/}${GEOIP2_VERSION}.tar.gz
DISTFILES+=			${GEOIP2_DISTFILE}
DSO_EXTMODS+=			geoip2
PLIST.geoip2=			yes
.include "../../geography/libmaxminddb/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Marray-var) || make(makesum) || make(mdi) || make(distclean)
ARRAYVAR_VERSION=		0.05
ARRAYVAR_DISTNAME=		array-var-nginx-module-${ARRAYVAR_VERSION}
ARRAYVAR_DISTFILE=		${ARRAYVAR_DISTNAME}.tar.gz
SITES.${ARRAYVAR_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/array-var-nginx-module/archive/}v${ARRAYVAR_VERSION}.tar.gz
DISTFILES+=			${ARRAYVAR_DISTFILE}
DSO_EXTMODS+=			arrayvar
PLIST.arrayvar=			yes
.endif

.if !empty(PKG_OPTIONS:Mencrypted-session) || make(makesum) || make(mdi) || make(distclean)
ENCSESS_VERSION=		0.09
ENCSESS_DISTNAME=		encrypted-session-nginx-module-${ENCSESS_VERSION}
ENCSESS_DISTFILE=		${ENCSESS_DISTNAME}.tar.gz
SITES.${ENCSESS_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/encrypted-session-nginx-module/archive/}v${ENCSESS_VERSION}.tar.gz
DISTFILES+=			${ENCSESS_DISTFILE}
DSO_EXTMODS+=			encsess
PLIST.encses=			yes
.endif

.if !empty(PKG_OPTIONS:Mform-input) || make(makesum) || make(mdi) || make(distclean)
FORMINPUT_VERSION=		0.12
FORMINPUT_DISTNAME=		form-input-nginx-module-${FORMINPUT_VERSION}
FORMINPUT_DISTFILE=		${FORMINPUT_DISTNAME}.tar.gz
SITES.${FORMINPUT_DISTFILE}=	-${MASTER_SITE_GITHUB:=calio/form-input-nginx-module/archive/}v${FORMINPUT_VERSION}.tar.gz
DISTFILES+=			${FORMINPUT_DISTFILE}
DSO_EXTMODS+=			forminput
PLIST.forminput=		yes
.endif

.if !empty(PKG_OPTIONS:Mheaders-more) || make(makesum) || make(mdi) || make(distclean)
HEADMORE_VERSION=		0.33
HEADMORE_DISTNAME=		headers-more-nginx-module-${HEADMORE_VERSION}
HEADMORE_DISTFILE=		${HEADMORE_DISTNAME}.tar.gz
SITES.${HEADMORE_DISTFILE}=	-${MASTER_SITE_GITHUB:=openresty/headers-more-nginx-module/archive/}v${HEADMORE_VERSION}.tar.gz
DISTFILES+=			${HEADMORE_DISTFILE}
DSO_EXTMODS+=			headmore
PLIST.headmore=			yes
.endif

.if !empty(PKG_OPTIONS:Muwsgi)
EGFILES+=		uwsgi_params
PLIST.uwsgi=		yes
CONFIGURE_ARGS+=	--http-uwsgi-temp-path=${NGINX_DATADIR}/uwsgi_temp
.else
CONFIGURE_ARGS+=	--without-http_uwsgi_module
.endif

.if !empty(PKG_OPTIONS:Mpush) || make(makesum) || make(mdi) || make(distclean)
PUSH_VERSION=		1.2.15
PUSH_DISTNAME=		nchan-${PUSH_VERSION}
PUSH_DISTFILE=		${PUSH_DISTNAME}.tar.gz
SITES.${PUSH_DISTFILE}=	-${MASTER_SITE_GITHUB:=slact/nchan/archive/}v${PUSH_VERSION}.tar.gz
DISTFILES+=		${PUSH_DISTFILE}
DSO_EXTMODS+=		push
PLIST.nchan=		yes
.endif

.if !empty(PKG_OPTIONS:Mimage-filter)
.include "../../graphics/gd/buildlink3.mk"
DSO_BASEMODS+=		http_image_filter_module
SUBST_CLASSES+=		fix-gd
SUBST_STAGE.fix-gd=	pre-configure
SUBST_FILES.fix-gd=	auto/lib/libgd/conf
SUBST_SED.fix-gd=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.gd},g'
SUBST_NOOP_OK.fix-gd=	yes
PLIST.imagefilter=	yes
.endif

.if !empty(PKG_OPTIONS:Mslice)
CONFIGURE_ARGS+=	--with-http_slice_module
.endif

.if !empty(PKG_OPTIONS:Mstatus)
CONFIGURE_ARGS+=	--with-http_stub_status_module
.endif

.if !empty(PKG_OPTIONS:Mperl)
DSO_BASEMODS+=		http_perl_module
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
INSTALLATION_DIRS+=	${PERL5_INSTALLVENDORARCH}/auto/nginx
PLIST.perl=		yes
.include "../../lang/perl5/dirs.mk"
.include "../../lang/perl5/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgzip)
CONFIGURE_ARGS+=	--with-http_gzip_static_module
.endif

.if !empty(PKG_OPTIONS:Mauth-request)
CONFIGURE_ARGS+=	--with-http_auth_request_module
.endif

.if !empty(PKG_OPTIONS:Mcache-purge) || make(makesum) || make(mdi) || make(distclean)
CPRG_VERSION=		2.5.1
CPRG_DISTNAME=		ngx_cache_purge-${CPRG_VERSION}
CPRG_DISTFILE=		${CPRG_DISTNAME}.tar.gz
SITES.${CPRG_DISTFILE}=	-${MASTER_SITE_GITHUB:=nginx-modules/ngx_cache_purge/archive/}${CPRG_VERSION}.tar.gz
DISTFILES+=		${CPRG_DISTFILE}
DSO_EXTMODS+=		cprg
PLIST.cprg=		yes
.endif

.if !empty(PKG_OPTIONS:Msecure-link)
CONFIGURE_ARGS+=	--with-http_secure_link_module
.endif

.if !empty(PKG_OPTIONS:Mstream-ssl-preread)
DSO_BASEMODS+=		stream
CONFIGURE_ARGS+=	--with-stream_ssl_preread_module
PLIST.stream=		yes
.endif

.if !empty(PKG_OPTIONS:Mrtmp) || make(makesum) || make(mdi) || make(distclean)
RTMP_VERSION=		1.2.2
RTMP_DISTNAME=		nginx-rtmp-module-${RTMP_VERSION}
RTMP_DISTFILE=		${RTMP_DISTNAME}.tar.gz
SITES.${RTMP_DISTFILE}=	-${MASTER_SITE_GITHUB:=arut/nginx-rtmp-module/archive/}v${RTMP_VERSION}.tar.gz
DISTFILES+=		${RTMP_DISTFILE}
DSO_EXTMODS+=		rtmp
PLIST.rtmp=		yes
.endif

.if !empty(PKG_OPTIONS:Mnjs) || make(makesum) || make(mdi) || make(distclean)
NJS_VERSION=		0.7.5
NJS_DISTNAME=		njs-${NJS_VERSION}
NJS_DISTFILE=		${NJS_DISTNAME}.tar.gz
NJS_CONFIGURE_ARGS=	--no-pcre2
SITES.${NJS_DISTFILE}=	-${MASTER_SITE_GITHUB:=nginx/njs/archive/}${NJS_VERSION}.tar.gz
DISTFILES+=		${NJS_DISTFILE}
DSO_EXTMODS+=		njs
NJS_SUBDIR=		/nginx
PLIST.njs=		yes
.endif

.if !empty(PKG_OPTIONS:Mupload) || make(makesum) || make(mdi) || make(distclean)
UPLOAD_VERSION=		2.3.0
UPLOAD_DISTNAME=		nginx-upload-module-${UPLOAD_VERSION}
UPLOAD_DISTFILE=		${UPLOAD_DISTNAME}.tar.gz
SITES.${UPLOAD_DISTFILE}=	-${MASTER_SITE_GITHUB:=vkholodkov/nginx-upload-module/archive/refs/tags/}${UPLOAD_VERSION}.tar.gz
DISTFILES+=		${UPLOAD_DISTFILE}
DSO_EXTMODS+=		upload
PLIST.upload=		yes
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
