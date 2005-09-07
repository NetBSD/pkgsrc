# $NetBSD: Makefile,v 1.5 2005/09/07 16:49:41 reed Exp $
#

DISTNAME=		xextensions-1.0.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Various extension headers for xlibs from freedesktop.org

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKGCONFIG_OVERRIDE=	xextensions.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
