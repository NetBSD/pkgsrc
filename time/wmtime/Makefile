# $NetBSD: Makefile,v 1.22 2023/07/07 08:29:24 nia Exp $

DISTNAME=	wmtime-1.4
CATEGORIES=	time x11
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dockapps.net/wmtime
COMMENT=	Time/Date applet for WindowMaker
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/dockapps-7d1ef92

MAKE_FLAGS+=	CC=${CC}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

BUILD_TARGET=	wmtime

.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdockapp+=	libdockapp>=0.7.0
.include "../../devel/libdockapp/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
