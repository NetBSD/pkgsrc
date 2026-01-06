# $NetBSD: options.mk,v 1.7 2026/01/06 11:18:46 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.serd
PKG_SUPPORTED_OPTIONS=	doc tests

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>0:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-lv2-theme>0:../../textproc/py-sphinx-lv2-theme
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinxygen>0:../../textproc/py-sphinxygen
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=disabled
.endif

.if !empty(PKG_OPTIONS:Mtests)
MESON_ARGS+=	-Dtests=enabled
.else
MESON_ARGS+=	-Dtests=disabled
.endif
