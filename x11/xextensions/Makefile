# $NetBSD: Makefile,v 1.1.1.1 2004/04/13 09:58:06 xtraeme Exp $
#

DISTNAME=		xextensions-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Various extension headers for xlibs from freedesktop.org

CONFLICTS+=		XFree86-libs-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
PKGCONFIG_OVERRIDE=	${WRKSRC}/xextensions.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
