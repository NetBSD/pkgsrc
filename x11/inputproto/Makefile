# $NetBSD: Makefile,v 1.5 2007/09/21 19:54:17 bjs Exp $
#

DISTNAME=		inputproto-1.4.2.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Input extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	inputproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
