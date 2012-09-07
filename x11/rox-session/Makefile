# $NetBSD: Makefile,v 1.29 2012/09/07 19:17:52 adam Exp $
#

DISTNAME=	rox-session-0.28
PKGREVISION=	17
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Very simple session manager

DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Session
DIST_SUBDIR=	rox

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	AppRun tests/testutils.py

INSTALLATION_DIRS=	share/rox/ROX-Session

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing hardcoded paths.
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	Login
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	post-patch
SUBST_FILES.lib=	findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

USE_TOOLS+=	pax
PKG_DESTDIR_SUPPORT=	user-destdir

pre-install:
	${RM} -f ${WRKSRC}/wm.py.orig
	${RM} -f ${WRKSRC}/setup.py.orig

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/rox/ROX-Session

.include "../../lang/python/application.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
