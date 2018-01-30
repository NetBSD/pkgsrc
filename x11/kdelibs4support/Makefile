# $NetBSD: Makefile,v 1.19 2018/01/30 09:10:59 markd Exp $

DISTNAME=	kdelibs4support-${KF5VER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Porting aid from KDELibs4
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/5.41/portingAids/}

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools
BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	kded>=${KF5VER}:../../x11/kded
DEPENDS+=	kdesignerplugin>=${KF5VER}:../../x11/kdesignerplugin

USE_TOOLS+=	perl:run pkg-config msgfmt

REPLACE_PERL+= src/kio/fileshareset

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_FILES.xdg+=	src/kssl/kssl/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_DATAROOTDIR}/examples/kdelibs4support:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/colors
CONF_FILES+=	${PREFIX}/share/examples/kdelibs4support/kdebug.areas \
		${PKG_SYSCONFDIR}/xdg/kdebug.areas
CONF_FILES+=	${PREFIX}/share/examples/kdelibs4support/kdebugrc \
		${PKG_SYSCONFDIR}/xdg/kdebugrc
CONF_FILES+=	${PREFIX}/share/examples/kdelibs4support/ksslcalist \
		${PKG_SYSCONFDIR}/xdg/ksslcalist
CONF_FILES+=	${PREFIX}/share/examples/kdelibs4support/colors/40.colors \
		${PKG_SYSCONFDIR}/xdg/colors/40.colors
CONF_FILES+=	${PREFIX}/share/examples/kdelibs4support/colors/Oxygen.colors \
		${PKG_SYSCONFDIR}/xdg/colors/Oxygen.colors
CONF_FILES+=	${PREFIX}/share/examples/kdelibs4support/colors/Rainbow.colors \
		${PKG_SYSCONFDIR}/xdg/colors/Rainbow.colors
CONF_FILES+=	${PREFIX}/share/examples/kdelibs4support/colors/Royal.colors \
		${PKG_SYSCONFDIR}/xdg/colors/Royal.colors
CONF_FILES+=	${PREFIX}/share/examples/kdelibs4support/colors/Web.colors \
		${PKG_SYSCONFDIR}/xdg/colors/Web.colors

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/solid-networkstatus/kded/CMakeFiles/kded_networkstatus_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/autotests/CMakeFiles/klibloadertestmodule5_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

.include "../../misc/kemoticons/buildlink3.mk"
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../misc/kunitconversion/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
