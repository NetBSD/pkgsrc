# $NetBSD: Makefile,v 1.14 2004/04/19 05:09:55 snj Exp $
#

DISTNAME=	xphoon.tar
PKGNAME=	xphoon-19910918
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.gwdg.de/pub/x11/x.org/contrib/ \
		ftp://ftp.sunet.se/pub/X11/
EXTRACT_SUFX=	.Z

MAINTAINER=	seb@pbox.org
COMMENT=	Set the root window to the moon in its current phase

WRKSRC=		${WRKDIR}/xphoon
USE_BUILDLINK3=	yes
USE_IMAKE=      yes

MAKE_FLAGS+=	EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	2.95.3
.endif

.if ${OPSYS} == "NetBSD"
EXTRA_LOCAL_LIBS=	-lcompat
.endif

.include "../../mk/bsd.pkg.mk"
