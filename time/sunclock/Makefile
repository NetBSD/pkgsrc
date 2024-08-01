# $NetBSD: Makefile,v 1.19 2024/08/01 18:50:45 vins Exp $
#

DISTNAME=	sunclock-3.57
CATEGORIES=	time x11
MASTER_SITES=	https://raw.githubusercontent.com/nongiach/Sunclock/f4106eb0a81f7594726d6b2859efd8fc64cc1225/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org	
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun
LICENSE=	gnu-gpl-v2

USE_IMAKE=	yes

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	BINDIR=${PREFIX}/bin
MAKE_FLAGS+=    SHAREDIR=${PREFIX}/share/sunclock
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

MAKE_FLAGS+=	CDEBUGFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	PROJECT_DEFINES=${CPPFLAGS:Q}
MAKE_FLAGS+=	EXTRA_LDOPTIONS=${LDFLAGS:Q}

CPPFLAGS.SunOS+=	-DUSE_PUTENV

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
