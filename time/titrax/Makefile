# $NetBSD: Makefile,v 1.6 2002/11/15 01:42:27 jlam Exp $
#

DISTNAME=		titrax-1.98
CATEGORIES=		x11 time
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=office/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.alvestrand.no/domen/titrax/TimeTracker.html
COMMENT=		Little X11 tool to track project times

USE_BUILDLINK2=		YES
USE_IMAKE=		YES

RESTRICTED=		"Do not sell for profit"

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED}	-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@X11BASE@|${X11PREFIX}|g"				\
		${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/titrax

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
