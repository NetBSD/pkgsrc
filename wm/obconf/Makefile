# $NetBSD: Makefile,v 1.5 2004/01/03 18:49:54 reed Exp $

DISTNAME=		obconf-1.5
PKGREVISION=		2
CATEGORIES=		wm
MASTER_SITES=		http://icculus.org/openbox/obconf/

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://www.openbox.org/obconf/
COMMENT=		Tool for configuring the Openbox window manager

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../devel/libglade2/buildlink2.mk"
.include "../../wm/openbox/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
