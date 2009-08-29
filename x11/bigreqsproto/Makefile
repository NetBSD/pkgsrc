# $NetBSD: Makefile,v 1.3 2009/08/29 15:23:32 wiz Exp $
#

DISTNAME=		bigreqsproto-1.1.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
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
