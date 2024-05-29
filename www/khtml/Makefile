# $NetBSD: Makefile,v 1.83 2024/05/29 16:34:50 adam Exp $

DISTNAME=	khtml-${KF5VER}
PKGREVISION=	2
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	HTML rendering engine
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${KF5VER:R}/portingAids/}

USE_TOOLS+=	perl msgfmt
# Need gnu variant for built-in alloca()
BUILDLINK_TRANSFORM+=	opt:-std=c99:-std=gnu99
BUILDLINK_TRANSFORM+=	opt:-std=c++17:-std=gnu++17
BUILDLINK_TRANSFORM+=	opt:-std=c++1z:-std=gnu++1z

CMAKE_ARGS.SunOS+=	-DHAVE_ALLOCA_H=1

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/CMakeFiles/khtmlpart_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/src/CMakeFiles/khtmlimagepart_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/src/kmultipart/CMakeFiles/kmultipart_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/khtmlrc \
		${PKG_SYSCONFDIR}/xdg/khtmlrc

.include "../../devel/gperf/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/kjs/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
