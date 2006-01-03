# $NetBSD: Makefile,v 1.1.1.1 2006/01/03 16:03:19 rxg Exp $
#

DISTNAME=	OroboROX-0.9.7.9
PKGNAME=	oroborox-0.9.7.9
CATEGORIES=	wm
MASTER_SITES=	http://roxos.sunsite.dk/dev-contrib/guido/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://roxos.sunsite.dk/dev-contrib/guido/
COMMENT=	The lightweight Window Manager for the ROX Desktop

DEPENDS+=	rox-lib>=2.0.2:../../sysutils/rox-lib

WRKSRC=		${WRKDIR}/OroboROX
DIST_SUBDIR=	rox

PLATFORM=	${OPSYS}-${MACHINE_ARCH}

USE_TOOLS+=		autoconf pkg-config
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-xft --with-platform=${PLATFORM}

PYTHON_PATCH_SCRIPTS=	Configure/OroboScheme/AppRun
PYTHON_PATCH_SCRIPTS+=	Configure/OroboScheme/AppInfo.py
PYTHON_PATCH_SCRIPTS+=	Configure/OroboScheme/Schemer.py
PYTHON_PATCH_SCRIPTS+=	Configure/Windows/AppRun
PYTHON_PATCH_SCRIPTS+=	Configure/Workspaces/AppRun

INSTALLATION_DIRS=	share/rox/OroboROX

SUBST_CLASSES+=		bin
SUBST_MESSAGE.bin=	"Fixing binary path."
SUBST_STAGE.bin=	post-patch
SUBST_FILES.bin=	AppRun
SUBST_SED.bin=		-e 's,BIN="$$APP_DIR/$$PLATFORM,BIN="${PREFIX}/libexec/rox,g'

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	"Fixing hardcoded paths."
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	AppRun
SUBST_FILES.path+=	Configure/Keybindings/findrox.py
SUBST_FILES.path+=	Configure/Windows/findrox.py
SUBST_FILES.path+=	Configure/Workspaces/findrox.py
SUBST_FILES.path+=	Configure/OroboScheme/findrox.py
SUBST_SED.path=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

SUBST_CLASSES+=		py
SUBST_MESSAGE.py=	"Replace shell magic by python version."
SUBST_STAGE.py=		post-patch
SUBST_FILES.py=		Configure/Keybindings/AppRun
SUBST_FILES.py+=	Configure/Keybindings/Messages/update-po
SUBST_FILES.py+=	Configure/Windows/Messages/update-po
SUBST_FILES.py+=	Configure/Workspaces/Messages/update-po
SUBST_SED.py=		-e 's,python,python${PYVERSSUFFIX},g'

BUILD_TARGET=		OroboROX
CONFIGURE_DIRS=		src

pre-configure:
	cd ${WRKSRC}/src; autoconf

post-build:
	@${ECHO} "#!/bin/sh" >> ${WRKDIR}/oroborox
	@${ECHO} "${PREFIX}/share/rox/OroboROX/AppRun \"$$""@\"" >> ${WRKDIR}/oroborox

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PLATFORM}/OroboROX ${PREFIX}/libexec/rox
	cd ${WRKSRC} && ${PAX} -rw	\
		-s ',^\./${PLATFORM}$$,,' -s ',^\./${PLATFORM}/.*,,'	\
		-s ',^\./src$$,,' -s ',^\./src/.*,,'	\
		. ${PREFIX}/share/rox/OroboROX
	${INSTALL_SCRIPT} ${WRKDIR}/oroborox ${PREFIX}/bin

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
