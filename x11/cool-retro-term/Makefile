# $NetBSD: Makefile,v 1.17 2024/10/07 18:16:50 rhialto Exp $

DISTNAME=	cool-retro-term-1.2.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Swordfish90/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Swordfish90/cool-retro-term
COMMENT=	Terminal emulator which mimics old CRT screens
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR:Q}

LDFLAGS.NetBSD+=	-lutil # openpty

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	app/app.pro
SUBST_FILES.paths+=	cool-retro-term.pro
SUBST_SED.paths=	-e 's,/usr,${PREFIX},g'

GITHUB_SUBMODULES=	Swordfish90 qmltermwidget \
			63228027e1f97c24abb907550b22ee91836929c5 qmltermwidget
EXTRACT_USING=		bsdtar

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake \
	    -unix -recursive cool-retro-term.pro \
	    ${MAKE_ENV} \
	    QMAKE_CFLAGS=${CFLAGS:Q} \
	    QMAKE_CXXFLAGS=${CXXFLAGS:Q} \
	    QMAKE_LFLAGS=${LDFLAGS:Q}

DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
