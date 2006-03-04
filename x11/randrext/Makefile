# $NetBSD: Makefile,v 1.13 2006/03/04 21:31:11 jlam Exp $

DISTNAME=		randrext-1.0
PKGREVISION=		2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X RandR extension (Headers and documentation files)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    randr.pc.in

.include "../../x11/xextensions/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
