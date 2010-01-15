# $NetBSD: Makefile,v 1.3 2010/01/15 17:53:34 tnn Exp $
#

DISTNAME=		kbproto-1.0.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		KB extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	kbproto.pc.in

.include "../../mk/bsd.pkg.mk"
