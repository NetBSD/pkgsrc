# $NetBSD: Makefile,v 1.11 2002/02/28 12:53:29 martti Exp $

PKGNAME=		${DISTNAME:S/-2/.2/}
COMMENT=		Small, fast and light-weight window manager

CONFLICTS+=		icewm-gnome-[0-9]*

USE_BUILDLINK_ONLY=	# defined

.include "Makefile.common"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
