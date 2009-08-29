# $NetBSD: Makefile,v 1.3 2009/08/29 15:26:14 wiz Exp $
#

DISTNAME=		evieext-1.1.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		EvIE extension headers

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	${WRKSRC}/evieproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
