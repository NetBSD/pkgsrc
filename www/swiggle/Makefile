# $NetBSD: Makefile,v 1.20 2020/01/26 17:32:25 rillig Exp $

DISTNAME=	swiggle-0.4
PKGREVISION=	3
CATEGORIES=	www graphics
MASTER_SITES=	http://homepage.univie.ac.at/l.ertl/swiggle/files/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://homepage.univie.ac.at/l.ertl/swiggle/
COMMENT=	Lightweight image gallery generator

SUBST_CLASSES+=		mf
SUBST_STAGE.mf=		pre-configure
SUBST_FILES.mf=		Makefile
SUBST_SED.mf=		-e "s/gcc/${CC}/"
SUBST_SED.mf+=		-e "s/-O3//"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swiggle ${DESTDIR}${PREFIX}/bin/

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
