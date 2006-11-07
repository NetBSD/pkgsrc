# $NetBSD: Makefile,v 1.1.1.1 2006/11/07 17:00:58 joerg Exp $
#

DISTNAME=		xinit-1.0.3
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X init program

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		MCOOKIE="/bin/dd if=/dev/urandom bs=16 count=1 2>/dev/null | hexdump -e '\\\"%08x\\\"'"

.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
