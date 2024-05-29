# $NetBSD: Makefile,v 1.60 2024/05/29 16:34:57 adam Exp $

DISTNAME=		xaos-4.2.1
PKGREVISION=		19
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GITHUB:=xaos-project/}
GITHUB_PROJECT=		XaoS
GITHUB_TAG=		refs/tags/release-${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matek.hu/xaos/
COMMENT=		Zoomable fractal rendering doodad
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c c++

SUBST_CLASSES+=		strip
SUBST_MESSAGE.strip=	Filling in missing path to strip
SUBST_STAGE.strip=	post-configure
SUBST_FILES.strip=	Makefile
SUBST_SED.strip=	-e 's,^STRIP .*=.*,STRIP = ${TOOLS_PLATFORM.strip},'

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing path to data files
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	src/include/config.h
SUBST_SED.path=		-e '/^.define DATAPATH/s,".*","${PREFIX}/share/XaoS",'

WRKSRC=			${WRKDIR}/XaoS-release-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	${PREFIX}/bin
INSTALLATION_DIRS+=	${PREFIX}/share/XaoS

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

# The upstream package has no working install target any more.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xaos  ${DESTDIR}${PREFIX}/bin/
.for dir in catalogs examples tutorial
	cd ${WRKSRC} && pax -wr ${dir} ${DESTDIR}${PREFIX}/share/XaoS/
.endfor
	cd ${DESTDIR}${PREFIX}/share/XaoS/examples && \
		mv */* . && \
		rmdir 0rfelyus Hubicka Langston Malczak ZKovacs ZsKovacs

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
