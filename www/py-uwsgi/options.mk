# $NetBSD: options.mk,v 1.2 2018/02/13 08:34:03 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-uwsgi
PKG_SUPPORTED_OPTIONS=	debug uuid yaml
PKG_SUGGESTED_OPTIONS+=	libxml2

PKG_OPTIONS_OPTIONAL_GROUPS+=	json xml
PKG_OPTIONS_GROUP.json=		jansson yajl
PKG_OPTIONS_GROUP.xml=		expat libxml2

.include "../../mk/bsd.options.mk"

UWSGI_DEBUG=			debug=false
.if !empty(PKG_OPTIONS:Mdebug)
UWSGI_DEBUG=			debug=true
.endif

UWSGI_XML=			xml=auto
.if !empty(PKG_OPTIONS:Mexpat)
.include "../../textproc/expat/buildlink3.mk"
UWSGI_XML=			xml=expat
.elif !empty(PKG_OPTIONS:Mlibxml2)
.include "../../textproc/libxml2/buildlink3.mk"
UWSGI_XML=			xml=libxml2
.else
UWSGI_XML=			xml=false
.endif

UWSGI_JSON=			json=auto
.if !empty(PKG_OPTIONS:Mjansson)
.include "../../textproc/jansson/buildlink3.mk"
UWSGI_JSON=			json=jansson
.elif !empty(PKG_OPTIONS:Myajl)
.include "../../devel/yajl/buildlink3.mk"
UWSGI_JSON=			json=yajl
BROKEN=		The yajl option requires a yajl.pc file which that package doesn't have.
.else
UWSGI_JSON=			json=false
.endif

UWSGI_UUID=			uuid=auto
.if !empty(PKG_OPTIONS:Muuid)
.include "../../devel/libuuid/buildlink3.mk"
UWSGI_UUID=			uuid=true
.else
UWSGI_UUID=			uuid=false
.endif

UWSGI_YAML=			yaml=auto
.if !empty(PKG_OPTIONS:Myaml)
.include "../../textproc/libyaml/buildlink3.mk"
UWSGI_YAML=			yaml=true
.else
UWSGI_YAML=			yaml=false
.endif
