# $NetBSD: Makefile,v 1.5 2004/10/30 01:16:27 minskim Exp $

DISTNAME=	swiggle-0.3.3
CATEGORIES=	www graphics
MASTER_SITES=	http://mailbox.univie.ac.at/~le/swiggle/files/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://mailbox.univie.ac.at/~le/swiggle/
COMMENT=	Lightweight image gallery generator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes

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
