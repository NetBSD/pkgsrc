# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:20 wiz Exp $
#

DISTNAME=		titrax-1.98
CATEGORIES=		x11 time
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=office/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.alvestrand.no/domen/titrax/TimeTracker.html

USE_IMAKE=		yes
USE_PERL5=		yes

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' -e 's|@X11BASE@|${X11PREFIX}|g' \
		< ${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

pre-install:
	${MKDIR} ${X11PREFIX}/libexec/titrax

.include "../../mk/bsd.pkg.mk"
