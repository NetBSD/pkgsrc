# $NetBSD: Makefile,v 1.12 2013/12/31 17:31:44 wiz Exp $

DISTNAME=		glproto-1.4.17
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		GL extension headers

PKGCONFIG_OVERRIDE+=	glproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
