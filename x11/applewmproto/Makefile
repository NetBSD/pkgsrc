# $NetBSD: Makefile,v 1.3 2012/10/29 05:06:07 asau Exp $
#

DISTNAME=		applewmproto-1.4.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		AppleWM extension headers from X.org
LICENSE=		mit

ONLY_FOR_PLATFORM=	Darwin-*-*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/applewmproto.pc.in

.include "../../mk/bsd.pkg.mk"
