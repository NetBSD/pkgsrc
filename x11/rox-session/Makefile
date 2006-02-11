# $NetBSD: Makefile,v 1.1.1.1 2006/02/11 16:12:25 rxg Exp $
#

DISTNAME=	ROX-Session-0.1.25
PKGNAME=	rox-session-0.1.25
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Very simple session manager

DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib
DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Session
DIST_SUBDIR=	rox

PLATFORM=	${OPSYS}-${MACHINE_ARCH}

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-platform=${PLATFORM:Q}

PYTHON_PATCH_SCRIPTS=	AutoStart.py interactive.py

INSTALLATION_DIRS=	share/rox/ROX-Session

SUBST_CLASSES+=		bin
SUBST_MESSAGE.bin=	Fixing binary path.
SUBST_STAGE.bin=	post-patch
SUBST_FILES.bin=	AppRun
SUBST_SED.bin=		-e 's,BIN="$$APP_DIR/$$PLATFORM,BIN="${PREFIX}/libexec/rox,g'

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing hardcoded paths.
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	AppRun
SUBST_FILES.path+=	Login
SUBST_FILES.path+=	RunROX
SUBST_FILES.path+=	setup.py
SUBST_FILES.path+=	src/choices.c
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	post-patch
SUBST_FILES.lib=	findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

BUILD_TARGET=		../${PLATFORM}/ROX-Session
CONFIGURE_DIRS=		src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PLATFORM}/ROX-Session ${PREFIX}/libexec/rox
	cd ${WRKSRC} && ${PAX} -rw	\
		-s ',^\./${PLATFORM}$$,,' -s ',^\./${PLATFORM}/.*,,'	\
		-s ',^\./src$$,,' -s ',^\./src/.*,,'	\
		. ${PREFIX}/share/rox/ROX-Session

.include "../../lang/python/application.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
