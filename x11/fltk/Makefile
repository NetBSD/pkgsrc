# $NetBSD: Makefile,v 1.33 2004/01/20 12:28:26 agc Exp $
#

DISTNAME=	fltk-1.0.11-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	3
VERS=		${DISTNAME:S/fltk-//:S/-source//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fltk/} \
		ftp://ftp.fltk.org/pub/fltk/${VERS}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERS}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}
USE_BUILDLINK2=		# defined
USE_GCC_SHLIB=		# defined
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		# defined
USE_X11BASE=		# defined
TEST_TARGET=		test

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-libtool=${PKGLIBTOOL}

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
