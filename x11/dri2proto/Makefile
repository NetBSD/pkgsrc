# $NetBSD: Makefile,v 1.5 2010/04/12 13:58:36 tnn Exp $
#

DISTNAME=		dri2proto-2.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		DRI2 extension headers from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	dri2proto.pc.in

.include "../../mk/bsd.pkg.mk"
