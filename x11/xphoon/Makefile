# $NetBSD: Makefile,v 1.6 2003/03/29 12:43:14 jmmv Exp $
#

DISTNAME=	xphoon.tar
PKGNAME=	xphoon-19910918
PKGREVISION=	1
WRKSRC=		${WRKDIR}/xphoon
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.gwdg.de/pub/x11/x.org/contrib/ \
		ftp://ftp.sunet.se/pub/X11/
EXTRACT_SUFX=	.Z

MAINTAINER=	seb@pbox.org
COMMENT=	Set the root window to the moon in its current phase

USE_BUILDLINK2=	yes
USE_IMAKE=      yes

MAKE_FLAGS+=	EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == arm32
.  include "../../lang/gcc/buildlink2.mk"
.endif

.if ${OPSYS} == "NetBSD"
EXTRA_LOCAL_LIBS=	-lcompat
.endif

.include "../../mk/bsd.pkg.mk"
