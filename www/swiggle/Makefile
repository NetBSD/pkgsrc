# $NetBSD: Makefile,v 1.8 2006/10/04 22:04:10 wiz Exp $

DISTNAME=	swiggle-0.3.3
PKGREVISION=	1
CATEGORIES=	www graphics
MASTER_SITES=	http://homepage.univie.ac.at/l.ertl/swiggle/files/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://homepage.univie.ac.at/l.ertl/swiggle/
COMMENT=	Lightweight image gallery generator

PKG_INSTALLATION_TYPES=	overwrite pkgviews


SUBST_CLASSES+=		mf
SUBST_STAGE.mf=		post-patch
SUBST_FILES.mf=		Makefile
SUBST_SED.mf=		-e "s/gcc/${CC}/" -e "s/-O3//"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swiggle ${PREFIX}/bin/

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
