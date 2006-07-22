# $NetBSD: Makefile,v 1.3 2006/07/22 04:46:19 rillig Exp $
#

DISTNAME=		compositeproto-0.3
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Composite extension headers from modular X.org

CONFLICTS+=		compositeext-[0-9]*

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/compositeproto.pc.in
USE_LANGUAGES=		# none, not even C

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
