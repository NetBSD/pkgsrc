# $NetBSD: Makefile,v 1.28 2011/11/01 06:02:54 sbd Exp $

DISTNAME=	hot-babe-0.2.2
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	http://dindinx.net/hotbabe/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dindinx.net/hotbabe/
COMMENT=	System load monitor

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
