# $NetBSD: Makefile,v 1.17 2003/08/29 15:29:29 xtraeme Exp $

DISTNAME=		Sablot-1.0
PKGNAME=		${DISTNAME:S/Sablot/sablotron/}
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

# sablotron needs iconv but assumes it is in libc, so add what
# buildlink2 finds.
LIBS+=			${_BLNK_ICONV_LDFLAGS}

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
