# $NetBSD: options.mk,v 1.9 2024/06/06 14:53:41 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-uwsgi
PKG_SUPPORTED_OPTIONS=	debug openssl pcre uuid uwsgi-sse_offload yaml
PKG_SUGGESTED_OPTIONS+=	libxml2 openssl pcre

PKG_OPTIONS_OPTIONAL_GROUPS+=	json xml
PKG_OPTIONS_GROUP.json=		jansson yajl
PKG_OPTIONS_GROUP.xml=		expat libxml2

.include "../../mk/bsd.options.mk"

UWSGI_DEBUG=			debug=false
.if !empty(PKG_OPTIONS:Mdebug)
UWSGI_DEBUG=			debug=true
.endif

.if !empty(PKG_OPTIONS:Mexpat)
.include "../../textproc/expat/buildlink3.mk"
UWSGI_XML=			xml=expat
.elif !empty(PKG_OPTIONS:Mlibxml2)
.include "../../textproc/libxml2/buildlink3.mk"
UWSGI_XML=			xml=libxml2
.else
UWSGI_XML=			xml=false
.endif

.if !empty(PKG_OPTIONS:Mjansson)
.include "../../textproc/jansson/buildlink3.mk"
UWSGI_JSON=			json=jansson
.elif !empty(PKG_OPTIONS:Myajl)
.include "../../devel/yajl/buildlink3.mk"
UWSGI_JSON=			json=yajl
.else
UWSGI_JSON=			json=false
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
UWSGI_SSL=                     ssl=true
.else
UWSGI_SSL=                     ssl=false
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre2/buildlink3.mk"
UWSGI_PCRE=                    pcre=true
.else
UWSGI_PCRE=                    pcre=false
.endif

.if !empty(PKG_OPTIONS:Muwsgi-sse_offload)
SSE_REVISION=			8253573a0db1c7d7b9d968d55669e70e40355bed
SSE_DISTNAME=			${SSE_REVISION}.zip
SITES.${SSE_DISTNAME}=		https://github.com/unbit/uwsgi-sse-offload/archive/
DISTFILES+=			${SSE_DISTNAME}
UWSGI_SSE=			sse_offload=true
INSTALL_ENV+=			UWSGI_EMBED_PLUGINS=sse_offload

post-extract: post-extract-sse
.PHONY: post-extract-sse
post-extract-sse:
	mv ${WRKDIR}/uwsgi-sse-offload-${SSE_REVISION} ${WRKSRC}/plugins/sse_offload
.else
UWSGI_SSE=			sse_offload=false
.endif

.if !empty(PKG_OPTIONS:Muuid)
.include "../../devel/libuuid/buildlink3.mk"
UWSGI_UUID=			uuid=true
.else
UWSGI_UUID=			uuid=false
.endif

.if !empty(PKG_OPTIONS:Myaml)
.include "../../textproc/libyaml/buildlink3.mk"
UWSGI_YAML=			yaml=true
.else
UWSGI_YAML=			yaml=false
.endif
