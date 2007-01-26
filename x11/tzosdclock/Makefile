# $NetBSD: Makefile,v 1.3 2007/01/26 23:29:18 joerg Exp $
#

DISTNAME=		tzosdclock_1.0.2
PKGNAME=		tzosdclock-1.0.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://www.unixdev.net/downloads/tzosdclock/1.0.2/

MAINTAINER=		inittab@unixdev.net
HOMEPAGE=		http://www.unixdev.net/projects/tzosdclock
COMMENT=		OnScreen Display Clock for Multiple Timezones

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xosd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
