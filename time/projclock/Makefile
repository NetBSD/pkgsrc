# $NetBSD: Makefile,v 1.18 2014/10/09 14:07:08 wiz Exp $
#

DISTNAME=	pclock0.7
PKGNAME=	projclock-0.7
PKGREVISION=	2
CATEGORIES=	time
MASTER_SITES=	http://members.optushome.com.au/starters/pclock/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://members.optushome.com.au/starters/pclock/
COMMENT=	Time management software

DEPENDS+=	tk>=8.3.4:../../x11/tk

WRKSRC=		${WRKDIR}/projclock
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install}

.include "../../mk/bsd.pkg.mk"
