# $NetBSD: Makefile,v 1.3 2008/05/24 21:45:18 tnn Exp $
#

DISTNAME=		xkbdata-1.0.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=data/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg keyboard maps and layouts

CONFLICTS+=		xkeyboard-config-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

DEPENDS+=		xkbcomp-[0-9]*:../../x11/xkbcomp

.include "../../mk/bsd.pkg.mk"
