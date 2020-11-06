# $NetBSD: options.mk,v 1.63 2020/11/06 22:54:17 otis Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nginx
PKG_SUPPORTED_OPTIONS=	array-var auth-request dav debug echo encrypted-session \
			form-input flv geoip gtools gzip headers-more http2 \
			image-filter luajit mail-proxy memcache naxsi njs \
			pcre perl push realip rtmp secure-link set-misc slice \
			ssl status stream-ssl-preread sub uwsgi
PKG_SUGGESTED_OPTIONS=	pcre ssl

PKG_OPTIONS_LEGACY_OPTS+=	v2:http2

PLIST_VARS+=		naxsi perl uwsgi

.include "../../mk/bsd.options.mk"

# documentation says naxsi must be the first module
.if !empty(PKG_OPTIONS:Mnaxsi)
PLIST.naxsi=			yes
CONFIGURE_ARGS+=		--add-module=../${NAXSI_DISTNAME}/naxsi_src
.endif
.if !empty(PKG_OPTIONS:Mnaxsi) || make(makesum) || make(mdi)
NAXSI_VERSION=			1.2
NAXSI_DISTNAME=			naxsi-${NAXSI_VERSION}
NAXSI_DISTFILE=			${NAXSI_DISTNAME}.tar.gz
SITES.${NAXSI_DISTFILE}=	-https://github.com/nbs-system/naxsi/archive/${NAXSI_VERSION}.tar.gz
DISTFILES+=			${NAXSI_DISTFILE}
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
CONFIGURE_ARGS+=	--with-pcre-jit
SUBST_CLASSES+=		fix-pcre
SUBST_STAGE.fix-pcre=	pre-configure
SUBST_FILES.fix-pcre=	auto/lib/pcre/conf
SUBST_SED.fix-pcre=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.pcre},g'
SUBST_NOOP_OK.fix-pcre=	yes
.else
CONFIGURE_ARGS+=	--without-pcre
CONFIGURE_ARGS+=	--without-http_rewrite_module
.endif

.if !empty(PKG_OPTIONS:Mdav)
CONFIGURE_ARGS+=	--with-http_dav_module
CONFIGURE_ARGS+=	--add-module=../${DAV_EXT_DISTNAME}
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
SUBST_CLASSES+=		fix-xslt
SUBST_STAGE.fix-xslt=	pre-configure
SUBST_FILES.fix-xslt=	auto/lib/libxslt/conf
SUBST_SED.fix-xslt=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.libxslt},g'
SUBST_NOOP_OK.fix-xslt=	yes
.endif
.if !empty(PKG_OPTIONS:Mdav) || make(makesum) || make(mdi)
DAV_EXT_VERSION=		3.0.0
DAV_EXT_DISTNAME=		nginx-dav-ext-module-3.0.0
DAV_EXT_DISTFILE=		${DAV_EXT_DISTNAME}.tar.gz
SITES.${DAV_EXT_DISTFILE}+=	-https://github.com/arut/nginx-dav-ext-module/archive/v${DAV_EXT_VERSION}.tar.gz
DISTFILES+=			${DAV_EXT_DISTFILE}
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
CONFIGURE_ARGS+=	--with-mail
.endif

.if empty(PKG_OPTIONS:Mmemcache)
CONFIGURE_ARGS+=	--without-http_memcached_module
.endif

.if !empty(PKG_OPTIONS:Mrealip)
CONFIGURE_ARGS+=	--with-http_realip_module
.endif

# NDK must be added once and before 3rd party modules needing it
.for _ngx_mod in luajit set-misc array-var form-input encrypted-session
.  if !defined(NEED_NDK) && !empty(PKG_OPTIONS:M${_ngx_mod}:O)
CONFIGURE_ARGS+=	--add-module=../${NDK_DISTNAME}
NEED_NDK=		yes
.  endif
.endfor
.if defined(NEED_NDK) || make(makesum) || make(mdi)
NDK_VERSION=		0.3.1
NDK_DISTNAME=		ngx_devel_kit-${NDK_VERSION}
NDK_DISTFILE=		${NDK_DISTNAME}.tar.gz
SITES.${NDK_DISTFILE}=	-https://github.com/simpl/ngx_devel_kit/archive/v${NDK_VERSION}.tar.gz
DISTFILES+=		${NDK_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mluajit)
.include "../../lang/LuaJIT2/buildlink3.mk"
CONFIGURE_ENV+=		LUAJIT_LIB=${PREFIX}/lib
CONFIGURE_ENV+=		LUAJIT_INC=${PREFIX}/include/luajit-2.0
CONFIGURE_ARGS+=	--add-module=../${LUA_DISTNAME}
.endif
.if !empty(PKG_OPTIONS:Mluajit) || make(makesum) || make(mdi)
LUA_VERSION=		0.10.19
LUA_DISTNAME=		lua-nginx-module-${LUA_VERSION}
LUA_DISTFILE=		${LUA_DISTNAME}.tar.gz
SITES.${LUA_DISTFILE}=	-https://github.com/openresty/lua-nginx-module/archive/v${LUA_VERSION}.tar.gz
DISTFILES+=		${LUA_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mecho)
CONFIGURE_ARGS+=		--add-module=../${ECHOMOD_DISTNAME}
.endif
.if !empty(PKG_OPTIONS:Mecho) || make(makesum) || make(mdi)
ECHOMOD_VERSION=		0.62
ECHOMOD_DISTNAME=		echo-nginx-module-${ECHOMOD_VERSION}
ECHOMOD_DISTFILE=		${ECHOMOD_DISTNAME}.tar.gz
SITES.${ECHOMOD_DISTFILE}=	-https://github.com/openresty/echo-nginx-module/archive/v${ECHOMOD_VERSION}.tar.gz
DISTFILES+=			${ECHOMOD_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mset-misc)
CONFIGURE_ARGS+=		--add-module=../${SETMISC_DISTNAME}
.endif
.if !empty(PKG_OPTIONS:Mset-misc) || make(makesum) || make(mdi)
SETMISC_VERSION=		0.32
SETMISC_DISTNAME=		set-misc-nginx-module-${SETMISC_VERSION}
SETMISC_DISTFILE=		${SETMISC_DISTNAME}.tar.gz
SITES.${SETMISC_DISTFILE}=	-https://github.com/openresty/set-misc-nginx-module/archive/v${SETMISC_VERSION}.tar.gz
DISTFILES+=			${SETMISC_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Marray-var)
CONFIGURE_ARGS+=		--add-module=../${ARRAYVAR_DISTNAME}
.endif
.if !empty(PKG_OPTIONS:Marray-var) || make(makesum) || make(mdi)
ARRAYVAR_VERSION=		0.05
ARRAYVAR_DISTNAME=		array-var-nginx-module-${ARRAYVAR_VERSION}
ARRAYVAR_DISTFILE=		${ARRAYVAR_DISTNAME}.tar.gz
SITES.${ARRAYVAR_DISTFILE}=	-https://github.com/openresty/array-var-nginx-module/archive/v${ARRAYVAR_VERSION}.tar.gz
DISTFILES+=			${ARRAYVAR_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mencrypted-session)
CONFIGURE_ARGS+=		--add-module=../${ENCSESS_DISTNAME}
.endif
.if !empty(PKG_OPTIONS:Mencrypted-session) || make(makesum) || make(mdi)
ENCSESS_VERSION=		0.08
ENCSESS_DISTNAME=		encrypted-session-nginx-module-${ENCSESS_VERSION}
ENCSESS_DISTFILE=		${ENCSESS_DISTNAME}.tar.gz
SITES.${ENCSESS_DISTFILE}=	-https://github.com/openresty/encrypted-session-nginx-module/archive/v${ENCSESS_VERSION}.tar.gz
DISTFILES+=			${ENCSESS_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mform-input)
CONFIGURE_ARGS+=		--add-module=../${FORMINPUT_DISTNAME}
.endif
.if !empty(PKG_OPTIONS:Mform-input) || make(makesum) || make(mdi)
FORMINPUT_VERSION=		0.12
FORMINPUT_DISTNAME=		form-input-nginx-module-${FORMINPUT_VERSION}
FORMINPUT_DISTFILE=		${FORMINPUT_DISTNAME}.tar.gz
SITES.${FORMINPUT_DISTFILE}=	-https://github.com/calio/form-input-nginx-module/archive/v${FORMINPUT_VERSION}.tar.gz
DISTFILES+=			${FORMINPUT_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mheaders-more)
CONFIGURE_ARGS+=		--add-module=../${HEADMORE_DISTNAME}
.endif
.if !empty(PKG_OPTIONS:Mheaders-more) || make(makesum) || make(mdi)
HEADMORE_VERSION=		0.33
HEADMORE_DISTNAME=		headers-more-nginx-module-${HEADMORE_VERSION}
HEADMORE_DISTFILE=		${HEADMORE_DISTNAME}.tar.gz
SITES.${HEADMORE_DISTFILE}=	-https://github.com/openresty/headers-more-nginx-module/archive/v${HEADMORE_VERSION}.tar.gz
DISTFILES+=			${HEADMORE_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Muwsgi)
EGFILES+=		uwsgi_params
PLIST.uwsgi=		yes
CONFIGURE_ARGS+=	--http-uwsgi-temp-path=${NGINX_DATADIR}/uwsgi_temp
.else
CONFIGURE_ARGS+=	--without-http_uwsgi_module
.endif

.if !empty(PKG_OPTIONS:Mpush)
CONFIGURE_ARGS+=	--add-module=../nchan-${PUSH_VERSION}
.endif
.if !empty(PKG_OPTIONS:Mpush) || make(makesum) || make(mdi)
PUSH_VERSION=		1.2.7
PUSH_DISTNAME=		nginx_http_push_module-${PUSH_VERSION}
PUSH_DISTFILE=		${PUSH_DISTNAME}.tar.gz
SITES.${PUSH_DISTFILE}=	-https://github.com/slact/nchan/archive/v${PUSH_VERSION}.tar.gz
DISTFILES+=		${PUSH_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mimage-filter)
.include "../../graphics/gd/buildlink3.mk"
CONFIGURE_ARGS+=	--with-http_image_filter_module
SUBST_CLASSES+=		fix-gd
SUBST_STAGE.fix-gd=	pre-configure
SUBST_FILES.fix-gd=	auto/lib/libgd/conf
SUBST_SED.fix-gd=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.gd},g'
SUBST_NOOP_OK.fix-gd=	yes
.endif

.if !empty(PKG_OPTIONS:Mslice)
CONFIGURE_ARGS+=	--with-http_slice_module
.endif

.if !empty(PKG_OPTIONS:Mstatus)
CONFIGURE_ARGS+=	--with-http_stub_status_module
.endif

.if !empty(PKG_OPTIONS:Mperl)
CONFIGURE_ARGS+=	--with-http_perl_module
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

.if !empty(PKG_OPTIONS:Msecure-link)
CONFIGURE_ARGS+=	--with-http_secure_link_module
.endif

.if !empty(PKG_OPTIONS:Mstream-ssl-preread)
CONFIGURE_ARGS+=	--with-stream --with-stream_ssl_preread_module
.endif

.if !empty(PKG_OPTIONS:Mrtmp)
CONFIGURE_ARGS+=	--add-module=../${RTMP_DISTNAME}
.endif
.if !empty(PKG_OPTIONS:Mrtmp) || make(makesum) || make(mdi)
RTMP_VERSION=		1.2.1
RTMP_DISTNAME=		nginx-rtmp-module-${RTMP_VERSION}
RTMP_DISTFILE=		${RTMP_DISTNAME}.tar.gz
SITES.${RTMP_DISTFILE}=	-https://github.com/arut/nginx-rtmp-module/archive/v${RTMP_VERSION}.tar.gz
DISTFILES+=		${RTMP_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mnjs)
CONFIGURE_ARGS+=	--add-module=../${NJS_EXT_DISTNAME}/nginx
.endif
.if !empty(PKG_OPTIONS:Mnjs) || make(makesum) || make(mdi)
NJS_EXT_VERSION=		0.4.4
NJS_EXT_DISTNAME=		njs-${NJS_EXT_VERSION}
NJS_EXT_DISTFILE=		${NJS_EXT_DISTNAME}.tar.gz
SITES.${NJS_EXT_DISTFILE}+=	-https://github.com/nginx/njs/archive/${NJS_EXT_VERSION}.tar.gz
DISTFILES+=			${NJS_EXT_DISTFILE}
.endif

