# $NetBSD: Makefile,v 1.2 2002/10/25 09:25:50 wiz Exp $
#

DISTNAME=       pclock0.7
PKGNAME=	projclock-0.7
CATEGORIES=	time
MASTER_SITES=   http://members.optushome.com.au/starters/pclock/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://members.optushome.com.au/starters/pclock/
COMMENT=	Time management software

WRKSRC=		${WRKDIR}/projclock

USE_BUILDLINK2=	# defined
NO_BUILD=	# defined

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
