# $NetBSD: Makefile,v 1.8 2007/02/02 00:06:52 joerg Exp $
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

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
