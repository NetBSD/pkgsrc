# $NetBSD: Makefile,v 1.5 2001/11/29 13:27:47 jlam Exp $
#

DISTNAME=		titrax-1.98
CATEGORIES=		x11 time
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=office/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.alvestrand.no/domen/titrax/TimeTracker.html
COMMENT=		Little X11 tool to track project times

USE_IMAKE=		YES

RESTRICTED=		"Do not sell for profit"

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED}	-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@X11BASE@|${X11PREFIX}|g"				\
		${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/titrax

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
