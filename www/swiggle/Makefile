# $NetBSD: Makefile,v 1.18 2014/10/09 14:07:12 wiz Exp $

DISTNAME=	swiggle-0.4
PKGREVISION=	3
CATEGORIES=	www graphics
MASTER_SITES=	http://homepage.univie.ac.at/l.ertl/swiggle/files/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://homepage.univie.ac.at/l.ertl/swiggle/
COMMENT=	Lightweight image gallery generator

SUBST_CLASSES+=		mf
SUBST_STAGE.mf=		post-patch
SUBST_FILES.mf=		Makefile
SUBST_SED.mf=		-e "s/gcc/${CC}/"
SUBST_SED.mf+=		-e "s/-O3//"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swiggle ${DESTDIR}${PREFIX}/bin/

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
