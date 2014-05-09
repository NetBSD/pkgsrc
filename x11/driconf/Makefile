# $NetBSD: Makefile,v 1.22 2014/05/09 07:37:26 wiz Exp $

DISTNAME=	driconf-0.9.1
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dri.freedesktop.org/wiki/DriConf
COMMENT=	Configuration applet for DRI drivers
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.4:../../x11/py-gtk2
DEPENDS+=	xdriinfo>=1.0.2:../../x11/xdriinfo

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt msgmerge xgettext

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
REPLACE_PYTHON=		*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2

SUBST_CLASSES+=		fix-paths
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

.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
