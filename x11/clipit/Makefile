# $NetBSD: Makefile,v 1.29 2022/08/11 05:09:24 gutteridge Exp $

DISTNAME=	clipit-1.4.5
PKGREVISION=	2
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
CONFIGURE_ARGS+=	--disable-glibtest
CONFIGURE_ARGS+=	--with-gtk3

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
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
