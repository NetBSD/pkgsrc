# $NetBSD: Makefile,v 1.15 2003/07/22 14:05:48 jwise Exp $

DISTNAME=		Sablot-0.96
PKGNAME=		sablotron-0.96
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		http://download-2.gingerall.cz/download/sablot/

MAINTAINER=		uithuis@dds.nl
HOMEPAGE=		http://www.gingerall.com/charlie/ga/xml/p_sab.xml
COMMENT=		XML toolkit implementing XSLT, DOM, and XPath

USE_BUILDLINK2=		YES
USE_GCC_SHLIB=		YES
GNU_CONFIGURE=  	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

# both libstdc++ and libm are required for gcc 2.95.x, as libstdc++
# does not include the math functions. gcc3 only needs libstdc++.
# SunPro needs libCrun and libm.
.if defined(USE_SUNPRO)
LIBS+=			-lCrun -lm
.elif !defined(USE_MIPSPRO)
LIBS+=			-lstdc++ -lm
.endif

.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
