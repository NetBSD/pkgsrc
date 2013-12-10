# $NetBSD: Makefile,v 1.36 2013/12/10 20:15:15 jperkin Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-${XFCE4_VERSION}
PKGREVISION=	17
CATEGORIES=	x11
COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-visibility
.endif

.include "../../mk/bsd.pkg.mk"
