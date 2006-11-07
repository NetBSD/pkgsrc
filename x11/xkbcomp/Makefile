# $NetBSD: Makefile,v 1.1.1.1 2006/11/07 17:23:58 joerg Exp $
#

DISTNAME=		xkbcomp-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XKBD keymap compiler

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
