# $NetBSD: Makefile,v 1.25 2020/04/01 10:46:59 nia Exp $

DISTNAME=	clipit-1.4.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=CristianHenzel/}
GITHUB_PROJECT=	ClipIt
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@NetBSD.org
HOMEPAGE=	https://github.com/CristianHenzel/ClipIt
COMMENT=	Lightweight, fully featured GTK+ clipboard manager

LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes

USE_TOOLS+=	gmake
USE_TOOLS+=	intltool msgfmt msgmerge xgettext
USE_TOOLS+=	aclocal autoconf autoreconf automake autopoint intltoolize
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFiGURE_ARGS+=	--disable-glibtest

BUILD_DEFS+=	PKG_SYSCONFBASE

EGDIR=		${PREFIX}/share/examples/clipit
CONF_FILES=	${EGDIR}/xdg/autostart/clipit-startup.desktop \
		${PKG_SYSCONFBASE}/xdg/autostart/clipit-startup.desktop
MAKE_DIRS=	${PKG_SYSCONFBASE}/xdg/autostart

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
