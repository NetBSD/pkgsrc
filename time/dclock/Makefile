# $NetBSD: Makefile,v 1.17 2009/07/07 20:27:10 joerg Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-4
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Digital clock for X

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	ivtools-*

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
