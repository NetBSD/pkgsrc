# $NetBSD: Makefile,v 1.9 2004/04/11 17:13:36 snj Exp $
#

DISTNAME=       pclock0.7
PKGNAME=	projclock-0.7
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=   http://members.optushome.com.au/starters/pclock/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://members.optushome.com.au/starters/pclock/
COMMENT=	Time management software

WRKSRC=		${WRKDIR}/projclock
USE_BUILDLINK3=	yes
NO_BUILD=	# defined

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
