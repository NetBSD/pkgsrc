# $NetBSD: Makefile,v 1.13 2003/07/18 11:14:43 grant Exp $

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
LDFLAGS+=		-liconv

.include "../../mk/bsd.prefs.mk"

# this is required for gcc 2.95.x, where libstdc++ doesn't include the
# math functions. only libstdc++ is required for gcc 3.3.
.if !defined(USE_SUNPRO) && !defined(USE_MIPSPRO)
LDFLAGS+=               -lstdc++ -lm
.endif

.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
