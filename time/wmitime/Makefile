# $NetBSD: Makefile,v 1.1 2013/11/06 00:35:19 khorben Exp $
#

DISTNAME=	wmitime-0.3
PKGREVISION=	3
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://www.neotokyo.org/illusion/downloads/

MAINTAINER=	poff@sixbit.org
HOMEPAGE=	http://www.neotokyo.org/illusion/dock_apps.html
COMMENT=	Windowmaker dockapp for time/date/itime

LICENSE=	gnu-gpl-v2

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

WRKSRC=		${WRKDIR}/wmitime/wmitime

USE_TOOLS+=	gmake

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
