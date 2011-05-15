# $NetBSD: Makefile,v 1.11 2011/05/15 12:35:06 mrg Exp $
#

DISTNAME=	xlogout
PKGNAME=	xlogout-19891129
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Quick logout button

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
