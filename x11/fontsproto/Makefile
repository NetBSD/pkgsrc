# $NetBSD: Makefile,v 1.2 2008/05/24 21:45:14 tnn Exp $
#

DISTNAME=		fontsproto-2.0.2
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
