# $NetBSD: Makefile,v 1.11.2.1 2002/07/01 17:45:12 jlam Exp $

PKGNAME=		${DISTNAME:S/-2/.2/}
COMMENT=		Small, fast and light-weight window manager

CONFLICTS+=		icewm-gnome-[0-9]*

USE_BUILDLINK2=		# defined

.include "Makefile.common"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
