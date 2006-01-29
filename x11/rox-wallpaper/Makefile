# $NetBSD: Makefile,v 1.1.1.1 2006/01/29 17:54:13 rxg Exp $
#

DISTNAME=	wallpaper-2.0
PKGNAME=	rox-${DISTNAME}
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

PYTHON_PATCH_SCRIPTS=	AppRun

INSTALLATION_DIRS=	share/rox/Wallpaper

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	post-patch
SUBST_FILES.lib=	findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

post-patch:
	@${FIND} ${WRKSRC} -name 'CVS' -print | ${XARGS} ${RM} -rf

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${PREFIX}/share/rox/Wallpaper

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
