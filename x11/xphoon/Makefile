# $NetBSD: Makefile,v 1.28 2012/10/29 05:07:18 asau Exp $
#

DISTNAME=	xphoon.tar
PKGNAME=	xphoon-19910918
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Set the root window to the moon in its current phase

WRKSRC=		${WRKDIR}/xphoon
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	2.95.3
.endif

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
