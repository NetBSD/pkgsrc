# $NetBSD: Makefile,v 1.15 2008/06/20 01:09:39 joerg Exp $
#

DISTNAME=	sunclock-1.5
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

CPPFLAGS.SunOS+=	-DUSE_PUTENV

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
