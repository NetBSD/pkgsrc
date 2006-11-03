# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 17:38:16 joerg Exp $
#

DISTNAME=		bigreqsproto-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		BigReqs extension headers from modular Xorg X11

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/bigreqsproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
