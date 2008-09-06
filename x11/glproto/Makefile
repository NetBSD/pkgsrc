# $NetBSD: Makefile,v 1.4 2008/09/06 12:59:58 wiz Exp $
#

DISTNAME=		glproto-1.4.9
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		GL extension headers

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	glproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
