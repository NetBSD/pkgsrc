# $NetBSD: Makefile,v 1.8 2004/03/08 20:27:16 minskim Exp $
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
USE_BUILDLINK2=	# defined
NO_BUILD=	# defined

.include "../../x11/tk83/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
