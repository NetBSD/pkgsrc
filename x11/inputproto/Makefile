# $NetBSD: Makefile,v 1.12 2010/04/09 08:21:48 tnn Exp $
#

DISTNAME=		inputproto-2.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Input extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	inputproto.pc.in

.include "../../mk/bsd.pkg.mk"
