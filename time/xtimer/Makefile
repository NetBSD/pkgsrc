# $NetBSD: Makefile,v 1.12 2012/05/03 09:55:32 obache Exp $

DISTNAME=	xtimer-8089
PKGNAME=	xtimer-0.8089
PKGREVISION=	4
CATEGORIES=	x11 time
MASTER_SITES=	http://www.bsddiary.net/xtimer/

MAINTAINER=	candy@fct.kgc.co.jp
HOMEPAGE=	http://www.bsddiary.net/xtimer/
COMMENT=	Super simple digital timer for X11

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
