# $NetBSD: Makefile,v 1.9 2003/07/17 22:55:06 grant Exp $
#

DISTNAME=		titrax-1.98
PKGREVISION=		1
CATEGORIES=		x11 time
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=office/}

MAINTAINER=		tech-pkg@NetBSD.org
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
