# $NetBSD: Makefile,v 1.9 2003/03/03 04:17:36 jschauma Exp $
#

DISTNAME=	xkeycaps-2.46
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/} \
		http://www.jwz.org/xkeycaps/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.jwz.org/xkeycaps/
COMMENT=	Graphical front-end to xmodmap

USE_IMAKE=      yes

pre-configure:
.if (${MACHINE_ARCH} == "m68k")
	@cd ${WRKSRC}; ${MV} Imakefile Imakefile.old; \
	${ECHO} CDEBUGFLAGS=	-O >Imakefile; \
	${CAT} Imakefile.old >>Imakefile
.endif

.include "../../mk/bsd.pkg.mk"
