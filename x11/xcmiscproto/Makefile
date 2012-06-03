# $NetBSD: Makefile,v 1.4 2012/06/03 18:38:41 wiz Exp $
#

DISTNAME=		xcmiscproto-1.2.2
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XCMisc extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xcmiscproto.pc.in
USE_LANGUAGES=		c

.include "../../mk/bsd.pkg.mk"
