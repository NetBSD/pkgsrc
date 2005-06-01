# $NetBSD: Makefile,v 1.6 2005/06/01 18:03:24 jlam Exp $
#

DISTNAME=		xdaliclock-2.18
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
