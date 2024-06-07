# $NetBSD: Makefile,v 1.82 2024/06/07 23:55:49 markd Exp $

DISTNAME=	kdelibs4support-${KF5VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Porting aid from KDELibs4
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${KF5VER:R}/portingAids/}

TOOL_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools
TOOL_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	kded>=${KF5VER}:../../x11/kded
DEPENDS+=	kdesignerplugin>=${KF5VER}:../../x11/kdesignerplugin

USE_TOOLS+=	perl:run pkg-config msgfmt

REPLACE_PERL+=	src/kio/fileshareset

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_FILES.xdg+=	src/kssl/kssl/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/colors
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kdebug.areas \
		${PKG_SYSCONFDIR}/xdg/kdebug.areas
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kdebugrc \
		${PKG_SYSCONFDIR}/xdg/kdebugrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/ksslcalist \
		${PKG_SYSCONFDIR}/xdg/ksslcalist
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/colors/40.colors \
		${PKG_SYSCONFDIR}/xdg/colors/40.colors
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/colors/Oxygen.colors \
		${PKG_SYSCONFDIR}/xdg/colors/Oxygen.colors
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/colors/Rainbow.colors \
		${PKG_SYSCONFDIR}/xdg/colors/Rainbow.colors
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/colors/Royal.colors \
		${PKG_SYSCONFDIR}/xdg/colors/Royal.colors
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/colors/Web.colors \
		${PKG_SYSCONFDIR}/xdg/colors/Web.colors

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/solid-networkstatus/kded/CMakeFiles/kded_networkstatus_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/src/kssl/kcm/CMakeFiles/kcm_ssl_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/autotests/CMakeFiles/klibloadertestmodule5_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../misc/kemoticons/buildlink3.mk"
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../misc/kunitconversion/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
