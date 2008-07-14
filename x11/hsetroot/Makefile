# $NetBSD: Makefile,v 1.8 2008/07/14 12:56:15 joerg Exp $
#

DISTNAME=	hsetroot-1.0.2
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://thegraveyard.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thegraveyard.org/hsetroot.php
COMMENT=	Allows you to compose wallpapers for X

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
