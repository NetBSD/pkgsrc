# $NetBSD: options.mk,v 1.4 2008/09/18 20:56:01 bjs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.modular-xorg-server
PKG_SUPPORTED_OPTIONS=	dri inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dri

.if !empty(PKG_OPTIONS:Mdri)
PLIST.dri=		yes
.  include "../../graphics/Mesa/Makefile.version"
.  include "../../graphics/MesaLib/glx-config.mk"

DISTFILES=		${DEFAULT_DISTFILES}
MESA_DISTFILE=		${MESA_DISTNAME}${EXTRACT_SUFX} # .tar.bz2
DISTFILES+=		${MESA_DISTFILE}
SITES.${MESA_DISTFILE}= ${MESA_SITES}
MESA_SRC=		${WRKDIR}/Mesa-${MESA_VERSION}
###
### XXX Is there a better way to do this?  For now, when updating these
###	patches (don't forget about Mesa updates!), please ensure that
###	the relative path in the patch matches "Mesa-${MESA_VERSION}".
###
_PKGSRC_PATCHES+=	${FILESDIR}/mesalib-patch-aq

CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--enable-aiglx
CONFIGURE_ARGS+=	--with-mesa-source=${MESA_SRC}
dri-post-extract:
	${LN} -s ${MESA_SRC:Q}/include/GL ${WRKSRC:Q}/GL/glx/GL
.else
###
### XXX Perhaps we should allow for a built-in glx without dri enabled?
###
CONFIGURE_ARGS+=	--disable-glx

dri-post-extract:
	@${DO_NADA}

# for GLX we already have the Mesa source
.  include "../../graphics/MesaLib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
