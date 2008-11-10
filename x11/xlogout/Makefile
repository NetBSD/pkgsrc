# $NetBSD: Makefile,v 1.10 2008/11/10 17:21:39 wiz Exp $
#

DISTNAME=	xlogout
PKGNAME=	xlogout-19891129
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Quick logout button

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
