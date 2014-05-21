# $NetBSD: Makefile,v 1.6.12.1 2014/05/21 13:14:03 tron Exp $

DISTNAME=		fontsproto-2.1.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Fonts extension headers from X.org

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/fontsproto.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
