# $NetBSD: Makefile,v 1.39 2018/09/03 10:50:17 wiz Exp $

DISTNAME=	libdesktop-agnostic-0.3.92
PKGREVISION=	28
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/libdesktop-agnostic/0.4/0.3.92/+download/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://launchpad.net/libdesktop-agnostic
COMMENT=	Desktop-agnostic library, apis and tools
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	intltool pkg-config msgfmt

PKGCONFIG_OVERRIDE+=	data/desktop-agnostic.pc.in

CONFIGURE_ARGS=	--config-backends=keyfile,gconf	\
		--vfs-backends=gio		\
		--desktop-entry-backends=glib

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.3.92

EGDIR=			${PREFIX}/share/examples/libdesktop-agnostic
PKG_SYSCONFSUBDIR=	xdg

MAKE_DIRS+=		${EGDIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/libdesktop-agnostic

CONF_FILES+=	${EGDIR}/desktop-agnostic.ini	\
		${PKG_SYSCONFDIR}/libdesktop-agnostic/desktop-agnostic.ini

WAF_ENV=	CC=${CC:Q} CXX=${CXX:Q} PREFIX=${PREFIX:Q} \
		CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
		VALAC=${VALAC} VAPIGEN=${VAPIGEN} \
		LINKFLAGS=${LDFLAGS:Q} DESTDIR=${DESTDIR:Q}

do-configure:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf

do-install:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf install

post-install:
	${CHMOD} a+x ${DESTDIR}${PREFIX}/lib/desktop-agnostic/modules/*.so
	${CHMOD} a+x ${DESTDIR}${PREFIX}/lib/libdesktop-agnostic*.so.*
	${CHMOD} a+x ${DESTDIR}${PREFIX}/${PYSITELIB}/desktopagnostic/*.so

.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
