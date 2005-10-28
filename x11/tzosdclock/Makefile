# $NetBSD: Makefile,v 1.1.1.1 2005/10/28 02:46:19 minskim Exp $
#

DISTNAME=		tzosdclock_1.0.2
PKGNAME=		tzosdclock-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://www.unixdev.net/downloads/tzosdclock/1.0.2/

MAINTAINER=		inittab@unixdev.net
HOMEPAGE=		http://www.unixdev.net/projects/tzosdclock
COMMENT=		OnScreen Display Clock for Multiple Timezones

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/xosd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
