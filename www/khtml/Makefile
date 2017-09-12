# $NetBSD: Makefile,v 1.11 2017/09/12 13:52:00 wiz Exp $

DISTNAME=	khtml-${KF5VER}
PKGREVISION=	9
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	HTML rendering engine
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/5.25/portingAids/}

USE_TOOLS+=	perl msgfmt

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=	fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/CMakeFiles/khtmlpart_automoc.dir/AutogenInfo.cmake 
SUBST_FILES.fix-moc+=	_KDE_build/src/kmultipart/CMakeFiles/kmultipart_automoc.dir/AutogenInfo.cmake 
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/khtmlrc \
		${PKG_SYSCONFDIR}/xdg/khtmlrc

.include "../../graphics/giflib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/kjs/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
