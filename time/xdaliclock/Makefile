# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:11 joerg Exp $
#

DISTNAME=		xdaliclock-2.18
PKGREVISION=		1
CATEGORIES=		x11 time
MASTER_SITES=		http://www.jwz.org/xdaliclock/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.jwz.org/xdaliclock/
COMMENT=		Animated digital clock

WRKSRC=			${WRKDIR}/${DISTNAME}/X11
GNU_CONFIGURE=		yes

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
