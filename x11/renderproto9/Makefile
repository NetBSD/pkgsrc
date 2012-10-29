# $NetBSD: Makefile,v 1.2 2012/10/29 05:06:50 asau Exp $
#
# This package is for use with native X11. Do not update to later versions.

DISTNAME=		renderproto-0.9.3
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Render extension headers

CONFLICTS+=		renderext-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/renderproto.pc.in
USE_LANGUAGES=		# none, not even C

.include "../../mk/bsd.pkg.mk"
