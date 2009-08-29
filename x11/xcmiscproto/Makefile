# $NetBSD: Makefile,v 1.3 2009/08/29 15:30:49 wiz Exp $
#

DISTNAME=		xcmiscproto-1.2.0
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
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
