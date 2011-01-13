# $NetBSD: Makefile,v 1.13 2011/01/13 13:39:42 wiz Exp $
#

DISTNAME=	driconf-0.9.1
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://dri.freedesktop.org/wiki/DriConf
COMMENT=	Configuration applet for DRI drivers

DEPENDS+= 	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+= 	xdriinfo>=1.0.2:../../x11/xdriinfo

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR= 	yes
USE_TOOLS+=		msgfmt msgmerge xgettext

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
PYDISTUTILSPKG= 	yes
REPLACE_PYTHON= 	*.py
PYTHON_VERSIONS_ACCEPTED=	25 24

SUBST_CLASSES+= 	fix-paths
SUBST_FILES.fix-paths=	driconf driconf.desktop
SUBST_FILES.fix-paths+=	driconf.py driconf_com*ui.py
SUBST_FILES.fix-paths+=	setup.cfg setup.py
SUBST_MESSAGE.fix-paths=Fixing hard-coded pathnames.
SUBST_STAGE.fix-paths=	pre-configure
SUBST_VARS.fix-paths=	PKGBASE PKGLOCALEDIR PKG_SYSCONFDIR PREFIX PYSITELIB
###
###	NOTE: this is only to build the .mo files.
###
pre-build:
	${RUN} cd ${WRKSRC} && \
	${BUILD_MAKE_CMD} all

post-install:
	${RUN} cd ${WRKSRC} && \
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/applications && \
	${INSTALL_DATA} ${WRKSRC}/driconf.desktop \
		${DESTDIR}${PREFIX}/share/applications/

.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
