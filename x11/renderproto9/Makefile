# $NetBSD: Makefile,v 1.1.1.1 2010/12/15 09:29:34 abs Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		renderext-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/renderproto.pc.in
USE_LANGUAGES=		# none, not even C

.include "../../mk/bsd.pkg.mk"
