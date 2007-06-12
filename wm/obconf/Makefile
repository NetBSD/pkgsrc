# $NetBSD: Makefile,v 1.20 2007/06/12 18:02:01 wiz Exp $

DISTNAME=		obconf-2.0.1
CATEGORIES=		wm
MASTER_SITES=		http://icculus.org/openbox/obconf/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://icculus.org/openbox/obconf/
COMMENT=		Tool for configuring the Openbox window manager

USE_TOOLS+=		pkg-config
USE_DIRS+=		xdg-1.1
GNU_CONFIGURE=		YES

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
BUILDLINK_API_DEPENDS.openbox+=	openbox>=3.4.2
.include "../../wm/openbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
