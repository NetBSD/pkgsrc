# $NetBSD: Makefile,v 1.9 2008/07/30 09:56:48 wiz Exp $
#

DISTNAME=		inputproto-1.4.4
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
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
