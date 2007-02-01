# $NetBSD: Makefile,v 1.11 2007/02/01 17:45:36 joerg Exp $
#

DISTNAME=	aewm++-1.0.24
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sapphire/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sapphire.sourceforge.net/
COMMENT=	Fork of the popular minimal window manager aewm

USE_LANGUAGES=	c c++

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
