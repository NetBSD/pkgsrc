# $NetBSD: Makefile,v 1.18 2005/12/04 00:49:33 joerg Exp $
#

DISTNAME=	xphoon.tar
PKGNAME=	xphoon-19910918
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		${MASTER_SITE_XCONTRIB} \
		ftp://ftp.sunet.se/pub/X11/
EXTRACT_SUFX=	.Z

MAINTAINER=	seb@NetBSD.org
COMMENT=	Set the root window to the moon in its current phase

WRKSRC=		${WRKDIR}/xphoon
USE_IMAKE=      yes

MAKE_FLAGS+=	EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	2.95.3
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
EXTRA_LOCAL_LIBS=	-lcompat
.endif

.include "../../mk/bsd.pkg.mk"
