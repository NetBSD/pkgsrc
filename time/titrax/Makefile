# $NetBSD: Makefile,v 1.4 2001/06/04 19:11:57 jtb Exp $
#

DISTNAME=		titrax-1.98
CATEGORIES=		x11 time
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=office/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.alvestrand.no/domen/titrax/TimeTracker.html
COMMENT=		Little X11 tool to track project times

USE_IMAKE=		yes
USE_PERL5=		yes

RESTRICTED=		"Do not sell for profit"

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' -e 's|@X11BASE@|${X11PREFIX}|g' \
		${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

pre-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/libexec/titrax

.include "../../mk/bsd.pkg.mk"
