# $NetBSD: Makefile,v 1.1.1.1 2006/11/07 17:27:42 joerg Exp $
#

DISTNAME=		xkbdata-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/data/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg keyboard maps and layouts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

DEPENDS+=		xkbcomp-[0-9]*:../../x11/xkbcomp

.include "../../mk/bsd.pkg.mk"
