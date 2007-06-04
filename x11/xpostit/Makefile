# $NetBSD: Makefile,v 1.10 2007/06/04 22:19:52 wiz Exp $
#

DISTNAME=	xpostit3.3.1
PKGNAME=	xpostit-3.3.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Post notes to yourself on the screen

WRKSRC=		${WRKDIR}/xpostit
USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
