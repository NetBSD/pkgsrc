# $NetBSD: Makefile,v 1.18 2013/01/26 21:39:07 adam Exp $
#

DISTNAME=	hsetroot-1.0.2
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	http://thegraveyard.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thegraveyard.org/hsetroot.php
COMMENT=	Allows you to compose wallpapers for X

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
