# $NetBSD: Makefile,v 1.3 2004/02/16 21:37:49 jlam Exp $

DISTNAME=		randrext-1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		RandR extension (Headers and documentation files)

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    randr.pc.in

.include "../../mk/bsd.pkg.mk"
