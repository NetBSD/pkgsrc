# $NetBSD: Makefile,v 1.6 1999/06/03 11:38:20 tron Exp $
#

DISTNAME=	xkeycaps-2.44
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/} \
		http://www.jwz.org/xkeycaps/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.jwz.org/xkeycaps/

USE_IMAKE=      yes

pre-configure:
.if (${MACHINE_ARCH} == "m68k")
	@cd ${WRKSRC}; ${MV} Imakefile Imakefile.old; \
	${ECHO} CDEBUGFLAGS=	-O >Imakefile; \
	${CAT} Imakefile.old >>Imakefile
.endif

.include "../../mk/bsd.pkg.mk"
