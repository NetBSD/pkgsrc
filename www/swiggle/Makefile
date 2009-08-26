# $NetBSD: Makefile,v 1.12 2009/08/26 19:58:28 sno Exp $

DISTNAME=	swiggle-0.4
PKGREVISION=	1
CATEGORIES=	www graphics
MASTER_SITES=	http://homepage.univie.ac.at/l.ertl/swiggle/files/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://homepage.univie.ac.at/l.ertl/swiggle/
COMMENT=	Lightweight image gallery generator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		mf
SUBST_STAGE.mf=		post-patch
SUBST_FILES.mf=		Makefile
SUBST_SED.mf=		-e "s/gcc/${CC}/" -e "s/-O3//"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swiggle ${DESTDIR}${PREFIX}/bin/

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
