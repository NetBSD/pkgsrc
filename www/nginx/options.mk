# $NetBSD: options.mk,v 1.32 2015/09/24 06:13:50 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nginx
PKG_SUPPORTED_OPTIONS=	dav flv gtools inet6 luajit mail-proxy memcache naxsi \
			pcre push realip ssl sub uwsgi image-filter \
			debug status nginx-autodetect-cflags spdy echo \
			set-misc headers-more array-var encrypted-session \
			form-input perl gzip
PKG_SUGGESTED_OPTIONS=	inet6 pcre ssl

PLIST_VARS+=		naxsi perl uwsgi

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
CONFIGURE_ARGS+=	--with-pcre-jit
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

.if !empty(PKG_OPTIONS:Mspdy)
CONFIGURE_ARGS+=	--with-http_spdy_module
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
NAXSI=				naxsi-0.53-2
NAXSI_DISTFILE=			${NAXSI}.tar.gz
SITES.${NAXSI_DISTFILE}=	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/
DISTFILES+=			${NAXSI_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mrealip)
CONFIGURE_ARGS+=	--with-http_realip_module
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.endif

# NDK must be added once and before 3rd party modules needing it
.for _ngx_mod in luajit set-misc array-var form-input encrypted-session
.	if !defined(NEED_NDK) && !empty(PKG_OPTIONS:M${_ngx_mod}:O)
CONFIGURE_ARGS+=	--add-module=../${NDK}
NEED_NDK=		yes
.	endif
.endfor
.if defined(NEED_NDK) || make(makesum)
NDK=			ngx_devel_kit-0.2.19
NDK_DISTFILE=		${NDK}.tar.gz
SITES.${NDK_DISTFILE}=	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/
DISTFILES+=		${NDK_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mluajit)
.include "../../lang/LuaJIT2/buildlink3.mk"
CONFIGURE_ENV+=		LUAJIT_LIB=${PREFIX}/lib
CONFIGURE_ENV+=		LUAJIT_INC=${PREFIX}/include/luajit-2.0
CONFIGURE_ARGS+=	--add-module=../${LUA}
.endif
.if !empty(PKG_OPTIONS:Mluajit) || make(makesum)
LUA=			lua-nginx-module-0.9.5
LUA_DISTFILE=		${LUA}.tar.gz
SITES.${LUA_DISTFILE}=	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/
DISTFILES+=		${LUA_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mecho)
CONFIGURE_ARGS+=	--add-module=../${ECHOMOD}
.endif
.if !empty(PKG_OPTIONS:Mecho) || make(makesum)
ECHOMOD=		echo-nginx-module-0.51
ECHOMOD_DISTFILE=	${ECHOMOD}.tar.gz
SITES.${ECHOMOD_DISTFILE}=	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/
DISTFILES+=		${ECHOMOD_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mset-misc)
CONFIGURE_ARGS+=	--add-module=../${SETMISC}
.endif
.if !empty(PKG_OPTIONS:Mset-misc) || make(makesum)
SETMISC=		set-misc-nginx-module-0.24
SETMISC_DISTFILE=	${SETMISC}.tar.gz
SITES.${SETMISC_DISTFILE}=	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/
DISTFILES+=		${SETMISC_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Marray-var)
CONFIGURE_ARGS+=	--add-module=../${ARRAYVAR}
.endif
.if !empty(PKG_OPTIONS:Marray-var) || make(makesum)
ARRAYVAR=		array-var-nginx-module-0.03
ARRAYVAR_DISTFILE=	${ARRAYVAR}.tar.gz
SITES.${ARRAYVAR_DISTFILE}=	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/
DISTFILES+=		${ARRAYVAR_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mencrypted-session)
CONFIGURE_ARGS+=	--add-module=../${ENCSESS}
.endif
.if !empty(PKG_OPTIONS:Mencrypted-session) || make(makesum)
ENCSESS=		encrypted-session-nginx-module-0.03
ENCSESS_DISTFILE=	${ENCSESS}.tar.gz
SITES.${ENCSESS_DISTFILE}=	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/
DISTFILES+=		${ENCSESS_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mform-input)
CONFIGURE_ARGS+=	--add-module=../${FORMINPUT}
.endif
.if !empty(PKG_OPTIONS:Mform-input) || make(makesum)
FORMINPUT=		form-input-nginx-module-0.07
FORMINPUT_DISTFILE=	${FORMINPUT}.tar.gz
SITES.${FORMINPUT_DISTFILE}=	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/
DISTFILES+=		${FORMINPUT_DISTFILE}
.endif

.if !empty(PKG_OPTIONS:Mheaders-more)
CONFIGURE_ARGS+=	--add-module=../${HEADMORE}
.endif
.if !empty(PKG_OPTIONS:Mheaders-more) || make(makesum)
HEADMORE=		headers-more-nginx-module-0.25
HEADMORE_DISTFILE=	${HEADMORE}.tar.gz
SITES.${HEADMORE_DISTFILE}=	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/
DISTFILES+=		${HEADMORE_DISTFILE}
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

.if !empty(PKG_OPTIONS:Mimage-filter)
.include "../../graphics/gd/buildlink3.mk"
CONFIGURE_ARGS+=	--with-http_image_filter_module
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
