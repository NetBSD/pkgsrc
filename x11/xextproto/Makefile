# $NetBSD: Makefile,v 1.1.1.1 2006/04/18 17:12:12 reed Exp $
#

DISTNAME=		xextproto-7.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XExt extension headers from X.org

CONFLICTS+=		xextensions-[0-9]*
#CONFLICTS+=		xorg-libs-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xextproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
