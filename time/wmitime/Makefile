# $NetBSD: Makefile,v 1.5 2023/07/07 08:30:15 nia Exp $

DISTNAME=	wmitime-0.5
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	poff@sixbit.org
HOMEPAGE=	https://www.dockapps.net/wmitime
COMMENT=	Windowmaker dockapp for time/date/itime
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/dockapps-26db447

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

BUILD_TARGET=	wmitime

USE_TOOLS+=	gmake

.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdockapp+=	libdockapp>=0.7.0
.include "../../devel/libdockapp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
