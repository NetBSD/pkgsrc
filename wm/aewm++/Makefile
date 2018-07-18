# $NetBSD: Makefile,v 1.17 2018/07/18 00:06:24 joerg Exp $
#

DISTNAME=	aewm++-1.0.24
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sapphire/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sapphire.sourceforge.net/
COMMENT=	Fork of the popular minimal window manager aewm

USE_LANGUAGES=	c c++03

INSTALL_MAKE_FLAGS=	PKGMANDIR=${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
