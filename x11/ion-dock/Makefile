# $NetBSD: Makefile,v 1.3 2004/01/24 15:30:33 grant Exp $
#

DISTNAME=	ion-devel-dock-20031221
PKGNAME=	${DISTNAME:S/-devel//}
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.dsv.su.se/~pelle/ion-dock/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.dsv.su.se/~pelle/ion-dock/
COMMENT=	Ion module that enables docking

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES

MAKE_ENV+=		TOPDIR=${BUILDLINK_PREFIX.ion}/include/ion

ION_EX_DIR=		${PREFIX}/share/examples/ion
PKG_SYSCONFSUBDIR=	ion
CONF_FILES=		${ION_EX_DIR}/dock.lua ${PKG_SYSCONFDIR}/dock.lua \
			${ION_EX_DIR}/dock-draw.lua ${PKG_SYSCONFDIR}/dock-draw.lua

.include "../../wm/ion-devel/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
