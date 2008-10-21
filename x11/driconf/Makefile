# $NetBSD: Makefile,v 1.1.1.1 2008/10/21 06:29:51 bjs Exp $
#

DISTNAME=	driconf-0.9.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://dri.freedesktop.org/wiki/DriConf
COMMENT=	Configuration applet for DRI drivers

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+= 	xdriinfo>=1.0.2:../../x11/xdriinfo

USE_DIRS+=	xdg-1.4
USE_TOOLS+=	msgfmt msgmerge xgettext

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
PYDISTUTILSPKG= 	yes
REPLACE_PYTHON= 	*.py
PYTHON_VERSIONS_INCOMPATIBLE= 	15 21

SUBST_CLASSES+= 	fix-paths
SUBST_FILES.fix-paths=	driconf driconf.desktop
SUBST_FILES.fix-paths+=	driconf.py driconf_com*ui.py
SUBST_FILES.fix-paths+=	setup.cfg setup.py
SUBST_MESSAGE.fix-paths=Fixing hard-coded pathnames.
SUBST_STAGE.fix-paths=	pre-configure
SUBST_VARS.fix-paths=	PKGBASE PKGLOCALEDIR PKG_SYSCONFDIR PREFIX PYSITELIB

pre-build:
	${RUN} cd ${WRKSRC} && \
	${BUILD_MAKE_CMD} all

#post-install:
	${RUN} cd ${WRKSRC} && \
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/applications && \
	${INSTALL_DATA} ${WRKSRC}/driconf.desktop \
		${DESTDIR}${PREFIX}/share/applications/

.include "../../lang/python/extension.mk"
#.include "../../textproc/py-xml/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
