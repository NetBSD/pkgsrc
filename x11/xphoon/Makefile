# $NetBSD: Makefile,v 1.2.2.1 2002/06/23 19:07:21 jlam Exp $
#

DISTNAME=	xphoon.tar
PKGNAME=	xphoon-19910918
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.gwdg.de/pub/x11/x.org/contrib/ \
		ftp://ftp.sunet.se/pub/X11/
EXTRACT_SUFX=	.Z

MAINTAINER=	seb@pbox.org
COMMENT=	Set the root window to the moon in its current phase

WRKSRC=		${WRKDIR}/xphoon

.if (${MACHINE_ARCH} == arm32)
.include "../../lang/gcc/Makefile.gcc"
.endif

USE_IMAKE=      yes

MAKE_FLAGS+=	EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
EXTRA_LOCAL_LIBS=	-lcompat
.endif

.include "../../mk/bsd.pkg.mk"
