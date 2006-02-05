# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:29 joerg Exp $

DISTNAME=	swiggle-0.3.3
PKGREVISION=	1
CATEGORIES=	www graphics
MASTER_SITES=	http://mailbox.univie.ac.at/~le/swiggle/files/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://mailbox.univie.ac.at/~le/swiggle/
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
