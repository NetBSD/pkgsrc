# $NetBSD: Makefile,v 1.19 2014/12/04 04:28:36 mef Exp $
#

DISTNAME=	pclock0.9
PKGNAME=	${DISTNAME:S/pclock/projclock-/}
CATEGORIES=	time
MASTER_SITES=	http://members.optushome.com.au/starters/pclock/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://members.optushome.com.au/starters/pclock/
COMMENT=	Time management software
LICENSE=	gnu-gpl-v1

DEPENDS+=	tk>=8.3.4:../../x11/tk

WRKSRC=		${WRKDIR}/workertimer
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install}

.include "../../mk/bsd.pkg.mk"
