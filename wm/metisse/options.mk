# $NetBSD: options.mk,v 1.1 2009/07/24 12:10:18 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.metisse
PKG_SUPPORTED_OPTIONS=	python

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS+=	mmx
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	freetype python

.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.endif

#.if !empty(PKG_OPTIONS:Mglx)
#.  if ${MACHINE_ARCH} == "i386"
#CONFIGURE_ARGS+=	--enable-glx-x86
#.  else
#CONFIGURE_ARGS+=	--enable-glx
#.  endif
#.endif

.if !empty(PKG_OPTIONS:Mpython)
PY_PATCHPLIST=		yes
.include "../../lang/python/extension.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHON}
PLIST.python=		yes
.else
CONFIGURE_ENV+=		am_cv_pathless_PYTHON=none
.endif
