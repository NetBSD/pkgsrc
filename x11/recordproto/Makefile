# $NetBSD: Makefile,v 1.2 2006/11/03 20:13:38 joerg Exp $
#

DISTNAME=		recordproto-1.13.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Record extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	recordproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
