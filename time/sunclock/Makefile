# $NetBSD: Makefile,v 1.16 2008/08/30 08:25:26 dholland Exp $
#

DISTNAME=	sunclock-1.5
PKGREVISION=	2
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

CPPFLAGS.SunOS+=	-DUSE_PUTENV

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
