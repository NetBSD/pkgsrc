# $NetBSD: Makefile,v 1.28 2004/04/25 00:50:46 xtraeme Exp $

DISTNAME=		Sablot-1.0.1
PKGNAME=		${DISTNAME:S/Sablot/sablotron/}
CATEGORIES=		textproc
MASTER_SITES=		http://download-2.gingerall.cz/download/sablot/

MAINTAINER=		uithuis@dds.nl
HOMEPAGE=		http://www.gingerall.com/charlie/ga/xml/p_sab.xml
COMMENT=		XML toolkit implementing XSLT, DOM, and XPath

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_BUILDLINK3=		YES
GNU_CONFIGURE=  	YES
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

# sablotron needs iconv but assumes it is in libc, so add what
# buildlink2 finds.
LIBS+=			${_BUILDLINK_LDADD.iconv}

.include "../../mk/compiler.mk"

# both libstdc++ and libm are required for gcc 2.95.x, as libstdc++
# does not include the math functions. gcc3 only needs libstdc++.
# SunPro needs libCrun and libm.
#
# XXX any extra libs needed on IRIX?
.if !empty(PKGSRC_COMPILER:Msunpro)
LIBS+=			-lCrun -lm
.elif !empty(CC_VERSION:Mgcc-2*)
LIBS+=			-lstdc++ -lm
.elif !empty(CC_VERSION:Mgcc-3*)
LIBS+=			-lstdc++ -lm
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
