# $NetBSD: Makefile,v 1.23 2014/08/21 09:50:44 jperkin Exp $
#

DISTNAME=	hsetroot-1.0.2
PKGREVISION=	14
CATEGORIES=	x11
MASTER_SITES=	http://thegraveyard.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thegraveyard.org/hsetroot.php
COMMENT=	Allows you to compose wallpapers for X

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-lX11

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
