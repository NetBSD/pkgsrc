# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 17:50:36 joerg Exp $
#

DISTNAME=		xcmiscproto-1.1.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XCMisc extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xcmiscproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
