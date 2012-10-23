# $NetBSD: Makefile,v 1.15 2012/10/23 10:24:21 wiz Exp $

DISTNAME=	speyes-1.2.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.okb-1.org/speyes/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.okb-1.org/speyes/speyes.html
COMMENT=	South Park XEyes clone

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
