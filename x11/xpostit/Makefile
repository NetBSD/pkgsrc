# $NetBSD: Makefile,v 1.14 2012/10/29 05:07:18 asau Exp $
#

DISTNAME=	xpostit3.3.1
PKGNAME=	xpostit-3.3.1
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Post notes to yourself on the screen

WRKSRC=		${WRKDIR}/xpostit
USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
