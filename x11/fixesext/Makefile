# $NetBSD: Makefile,v 1.3 2004/03/15 20:24:32 xtraeme Exp $
#

DISTNAME=		fixesext-2.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		X Fixes extension headers and specification

USE_X11=		yes
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    fixesext.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
