# $NetBSD: Makefile,v 1.10 2002/02/27 13:53:07 tron Exp $

PKGNAME=		${DISTNAME:S/-2/.2/}
COMMENT=		Small, fast and light-weight window manager

CONFLICTS+=		icewm-gnome-[0-9]*

USE_BUILDLINK_ONLY=	# defined

.include "Makefile.common"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
