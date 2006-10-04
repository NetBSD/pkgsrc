# $NetBSD: Makefile,v 1.18 2006/10/04 22:02:29 wiz Exp $

DISTNAME=		obconf-1.5
PKGREVISION=		8
CATEGORIES=		wm
MASTER_SITES=		http://icculus.org/openbox/obconf/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://icculus.org/openbox/obconf/
COMMENT=		Tool for configuring the Openbox window manager

USE_TOOLS+=		pkg-config
USE_DIRS+=		xdg-1.1
GNU_CONFIGURE=		YES

.include "../../devel/libglade2/buildlink3.mk"
.include "../../wm/openbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
