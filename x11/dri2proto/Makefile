# $NetBSD: Makefile,v 1.4 2009/06/12 22:53:34 wiz Exp $
#

DISTNAME=		dri2proto-2.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		DRI2 extension headers from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	dri2proto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
