# $NetBSD: Makefile,v 1.10 2004/06/03 17:44:15 minskim Exp $
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

DEPENDS+=	tk>=8.3.4:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/projclock
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

.include "../../mk/bsd.pkg.mk"
