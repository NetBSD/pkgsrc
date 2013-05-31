# $NetBSD: Makefile,v 1.1 2013/05/31 00:33:43 rodent Exp $
#

DISTNAME=	applewmproto-1.4.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	AppleWM extension headers from X.org
LICENSE=	mit

PREV_PKGPATH=	x11/applewmproto

ONLY_FOR_PLATFORM=	Darwin-*-*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/applewmproto.pc.in

.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
