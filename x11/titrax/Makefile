# $NetBSD: Makefile,v 1.1.1.1 1998/12/08 14:11:00 hwr Exp $
#

DISTNAME=		titrax-1.98
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	office

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.alvestrand.no/domen/titrax/TimeTracker.html

USE_IMAKE=		yes
USE_PERL5=		yes

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' -e 's|@X11BASE@|${X11BASE}|g' \
		< ${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

pre-install:
	${MKDIR} ${X11BASE}/libexec/titrax

.include "../../mk/bsd.pkg.mk"
