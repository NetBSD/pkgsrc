# $NetBSD: Makefile,v 1.15 2015/03/13 16:50:37 tnn Exp $
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

INSTALL_MAKE_FLAGS=	PKGMANDIR=${PKGMANDIR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
