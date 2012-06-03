# $NetBSD: Makefile,v 1.5 2012/06/03 19:43:14 wiz Exp $
#

DISTNAME=		fontsproto-2.1.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Fonts extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/fontsproto.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
