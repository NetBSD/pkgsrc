# $NetBSD: Makefile,v 1.17 2008/11/10 17:21:39 wiz Exp $
#

DISTNAME=	xkeycaps-2.46
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/} \
		http://www.jwz.org/xkeycaps/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jwz.org/xkeycaps/
COMMENT=	Graphical front-end to xmodmap

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

pre-configure:
.if (${MACHINE_ARCH} == "m68k")
	@cd ${WRKSRC}; ${MV} Imakefile Imakefile.old; \
	${ECHO} CDEBUGFLAGS=	-O >Imakefile; \
	${CAT} Imakefile.old >>Imakefile
.endif

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
