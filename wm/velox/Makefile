# $NetBSD: Makefile,v 1.8 2022/08/11 05:09:21 gutteridge Exp $

DISTNAME=	velox-0.0.3.20200119
PKGREVISION=	4
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=niacat/}
GITHUB_PROJECT=	velox
GITHUB_TAG=	5cfdcbafb130128d4537ade4dffe8ac12712607d

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/niacat/velox
COMMENT=	Simple Wayland tiling window manager
LICENSE=	mit

# Used by the panel, you get poor font rendering otherwise.
DEPENDS+=	terminus-font-[0-9]*:../../fonts/terminus-font
# Used for launching software.
DEPENDS+=	dmenu-wld-[0-9]*:../../sysutils/dmenu-wld

USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

EGDIR=		${PREFIX}/share/examples/velox

CONF_FILES+=	${EGDIR}/velox.conf ${PKG_SYSCONFDIR}/velox.conf

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Correcting the path to the configuration file.
SUBST_FILES.conf+=	config.c
SUBST_SED.conf+=	-e 's|/etc/velox.conf|${PKG_SYSCONFDIR}/velox.conf|g'

PKGCONFIG_OVERRIDE+=	velox.pc.in

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/velox.conf.sample \
	    ${DESTDIR}${EGDIR}/velox.conf

.include "../../wm/swc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
