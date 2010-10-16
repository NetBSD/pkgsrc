# $NetBSD: Makefile,v 1.1.1.1 2010/10/16 13:08:13 obache Exp $
#

DISTNAME=		applewmproto-1.4.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		AppleWM extension headers from X.org
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	Darwin-*-*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/applewmproto.pc.in

.include "../../mk/bsd.pkg.mk"
