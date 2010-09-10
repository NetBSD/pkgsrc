# $NetBSD: Makefile,v 1.4 2010/09/10 19:07:49 joerg Exp $
#

DISTNAME=		kbproto-1.0.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		KB extension headers from X.org
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	kbproto.pc.in

.include "../../mk/bsd.pkg.mk"
