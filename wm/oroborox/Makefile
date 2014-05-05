# $NetBSD: Makefile,v 1.44 2014/05/05 00:48:25 ryoon Exp $
#

DISTNAME=	OroboROX-0.9.8
PKGNAME=	oroborox-0.9.8
PKGREVISION=	25
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://roscidus.com/desktop/OroboROX
COMMENT=	The lightweight Window Manager for the ROX Desktop

DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib

WRKSRC=		${WRKDIR}/OroboROX
DIST_SUBDIR=	rox

PLATFORM=	${OPSYS}-${MACHINE_ARCH}

USE_TOOLS+=		autoconf pax pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-xft --with-platform=${PLATFORM:Q}

REPLACE_PYTHON=	Configure/OroboScheme/AppRun
REPLACE_PYTHON+=	Configure/OroboScheme/AppInfo.py
REPLACE_PYTHON+=	Configure/OroboScheme/Schemer.py
REPLACE_PYTHON+=	Configure/Windows/AppRun
REPLACE_PYTHON+=	Configure/Workspaces/AppRun

INSTALLATION_DIRS=	share/rox/OroboROX

SUBST_CLASSES+=		bin
SUBST_MESSAGE.bin=	Fixing binary path.
SUBST_STAGE.bin=	post-patch
SUBST_FILES.bin=	AppRun
SUBST_SED.bin=		-e 's,BIN="$$APP_DIR/$$PLATFORM,BIN="${PREFIX}/libexec/rox,g'

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing hardcoded paths.
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	AppRun
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	post-patch
SUBST_FILES.lib=	Configure/Keybindings/findrox.py
SUBST_FILES.lib+=	Configure/Windows/findrox.py
SUBST_FILES.lib+=	Configure/Workspaces/findrox.py
SUBST_FILES.lib+=	Configure/OroboScheme/findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

SUBST_CLASSES+=		py
SUBST_MESSAGE.py=	Replace shell magic by python version.
SUBST_STAGE.py=		post-patch
SUBST_FILES.py=		Configure/Keybindings/AppRun
SUBST_FILES.py+=	Configure/Keybindings/Messages/update-po
SUBST_FILES.py+=	Configure/Windows/Messages/update-po
SUBST_FILES.py+=	Configure/Workspaces/Messages/update-po
SUBST_SED.py=		-e 's,python,python${PYVERSSUFFIX},g'

BUILD_TARGET=		OroboROX
CONFIGURE_DIRS=		src

pre-configure:
	cd ${WRKSRC:Q}/src && autoconf

post-build:
	@${ECHO} "#!/bin/sh" >> ${WRKDIR:Q}/oroborox
	@${ECHO} ${PREFIX:Q}"/share/rox/OroboROX/AppRun \"\$$@\"" >> ${WRKDIR:Q}/oroborox

INSTALLATION_DIRS=	bin libexec/rox share/rox/OroboROX

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/${PLATFORM:Q}/OroboROX ${DESTDIR:Q}${PREFIX:Q}/libexec/rox
	cd ${WRKSRC:Q} && pax -rw	\
		-s ',^\./${PLATFORM}$$,,' -s ',^\./${PLATFORM}/.*,,'	\
		-s ',^\./src$$,,' -s ',^\./src/.*,,'	\
		. ${DESTDIR:Q}${PREFIX:Q}/share/rox/OroboROX
	${INSTALL_SCRIPT} ${WRKDIR:Q}/oroborox ${DESTDIR:Q}${PREFIX:Q}/bin

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
