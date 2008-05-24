# $NetBSD: Makefile,v 1.7 2008/05/24 21:45:14 tnn Exp $
#

DISTNAME=		compositeproto-0.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Composite extension headers from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		compositeext-[0-9]*

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/compositeproto.pc.in
USE_LANGUAGES=		# none, not even C

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
