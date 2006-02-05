# $NetBSD: Makefile,v 1.12 2006/02/05 23:11:47 joerg Exp $
#

DISTNAME=	xkeycaps-2.46
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/} \
		http://www.jwz.org/xkeycaps/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
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
