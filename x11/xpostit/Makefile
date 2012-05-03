# $NetBSD: Makefile,v 1.13 2012/05/03 09:55:33 obache Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/xpostit
USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
