# $NetBSD: Makefile,v 1.27 2018/11/12 03:51:27 ryoon Exp $

DISTNAME=	khtml-${KF5VER}
PKGREVISION=	5
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	HTML rendering engine
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${KF5VER:R}/portingAids/}

USE_TOOLS+=	perl msgfmt

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=	fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/CMakeFiles/khtmlpart_autogen.dir/AutogenInfo.cmake 
SUBST_FILES.fix-moc+=	_KDE_build/src/CMakeFiles/khtmlimagepart_autogen.dir/AutogenInfo.cmake 
SUBST_FILES.fix-moc+=	_KDE_build/src/kmultipart/CMakeFiles/kmultipart_autogen.dir/AutogenInfo.cmake 
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt src/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/khtmlrc \
		${PKG_SYSCONFDIR}/xdg/khtmlrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/khtml.categories \
		${PKG_SYSCONFDIR}/xdg/khtml.categories

.include "../../devel/gperf/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/kjs/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
