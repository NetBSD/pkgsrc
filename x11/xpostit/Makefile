# $NetBSD: Makefile,v 1.9 2006/12/27 13:37:46 joerg Exp $
#

DISTNAME=	xpostit3.3.1
PKGNAME=	xpostit-3.3.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.freesoftware.com/pub/X11/R5contrib/
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
