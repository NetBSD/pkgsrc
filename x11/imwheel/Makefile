# $NetBSD: Makefile,v 1.15 2012/10/23 10:24:18 wiz Exp $
#

DISTNAME=	imwheel-0.9.9
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imwheel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://imwheel.sourceforge.net/
COMMENT=	Tool which helps to use mousewheels

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gpm

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
