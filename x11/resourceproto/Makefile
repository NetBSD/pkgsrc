# $NetBSD: Makefile,v 1.3 2009/08/26 12:06:01 wiz Exp $
#

DISTNAME=		resourceproto-1.1.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Resource extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		resourceext-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	resourceproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
