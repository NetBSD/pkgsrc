# $NetBSD: Makefile,v 1.9 2012/06/03 18:38:01 wiz Exp $
#

DISTNAME=		renderproto-0.11.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Render extension headers from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		renderext-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/renderproto.pc.in
USE_LANGUAGES=		c

.include "../../mk/bsd.pkg.mk"
