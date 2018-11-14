# $NetBSD: Makefile,v 1.20 2018/11/14 22:22:38 kleink Exp $
#

DISTNAME=	clipit-1.4.2
PKGREVISION=	16
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkclipit/}

MAINTAINER=	khorben@NetBSD.org
#HOMEPAGE=	http://clipit.rspwn.com/
COMMENT=	Lightweight, fully featured GTK+ clipboard manager

LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR}

USE_TOOLS+=	gmake
USE_TOOLS+=	intltool msgfmt
USE_TOOLS+=	pkg-config

BUILD_DEFS+=	PKG_SYSCONFBASE

EGDIR=		${PREFIX}/share/examples/clipit
CONF_FILES=	${EGDIR}/xdg/autostart/clipit-startup.desktop \
		${PKG_SYSCONFBASE}/xdg/autostart/clipit-startup.desktop
MAKE_DIRS=	${PKG_SYSCONFBASE}/xdg/autostart

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}


.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
