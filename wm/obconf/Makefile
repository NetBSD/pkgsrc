# $NetBSD: Makefile,v 1.10 2004/04/27 17:22:29 reed Exp $

DISTNAME=		obconf-1.5
PKGREVISION=		4
CATEGORIES=		wm
MASTER_SITES=		http://icculus.org/openbox/obconf/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://www.openbox.org/obconf/
COMMENT=		Tool for configuring the Openbox window manager

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
GNU_CONFIGURE=		YES

.include "../../devel/libglade2/buildlink3.mk"
.include "../../wm/openbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
