# $NetBSD: Makefile,v 1.3 2003/03/29 12:42:44 jmmv Exp $
#

DISTNAME=       pclock0.7
PKGNAME=	projclock-0.7
WRKSRC=		${WRKDIR}/projclock
CATEGORIES=	time
MASTER_SITES=   http://members.optushome.com.au/starters/pclock/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://members.optushome.com.au/starters/pclock/
COMMENT=	Time management software

USE_BUILDLINK2=	# defined
NO_BUILD=	# defined

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
