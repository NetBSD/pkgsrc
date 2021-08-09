# $NetBSD: Makefile,v 1.13 2021/08/09 18:37:30 wiz Exp $

DISTNAME=		xrdb-1.2.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X server resource database utility

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-cpp=${CPPPATH}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	ac_cv_func_reallocarray=no
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
