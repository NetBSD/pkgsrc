# $NetBSD: Makefile,v 1.17 2023/08/14 05:25:35 wiz Exp $
#

DISTNAME=	wallpaper-2.0
PKGNAME=	rox-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/desktop/node/54
COMMENT=	For setting the backdrop

DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib

WRKSRC=		${WRKDIR}/${DISTNAME}/Wallpaper
DIST_SUBDIR=	rox

NO_BUILD=	yes

REPLACE_PYTHON=	AppRun

INSTALLATION_DIRS=	share/rox/Wallpaper

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	pre-configure
SUBST_FILES.lib=	findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

USE_TOOLS+=	pax

post-patch:
	${FIND} ${WRKSRC} -name 'CVS' -print | ${XARGS} ${RM} -rf

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/rox/Wallpaper

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
