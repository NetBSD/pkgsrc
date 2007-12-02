# $NetBSD: Makefile,v 1.25 2007/12/02 11:51:34 wiz Exp $
#

DISTNAME=	xphoon.tar
PKGNAME=	xphoon-19910918
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Set the root window to the moon in its current phase

WRKSRC=		${WRKDIR}/xphoon
USE_IMAKE=	yes

MAKE_FLAGS+=	EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	2.95.3
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
EXTRA_LOCAL_LIBS=	-lcompat
.endif

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
