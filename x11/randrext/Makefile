# $NetBSD: Makefile,v 1.11 2005/09/07 16:49:41 reed Exp $

DISTNAME=		randrext-1.0
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X RandR extension (Headers and documentation files)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    randr.pc.in

.include "../../x11/xextensions/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
