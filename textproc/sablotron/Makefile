# $NetBSD: Makefile,v 1.56 2023/08/02 19:30:57 nia Exp $

DISTNAME=		Sablot-1.0.2
PKGNAME=		${DISTNAME:S/Sablot/sablotron/}
PKGREVISION=		14
CATEGORIES=		textproc
MASTER_SITES=		http://download-1.gingerall.cz/download/sablot/

MAINTAINER=		uithuis@dds.nl
HOMEPAGE=		http://www.gingerall.com/charlie/ga/xml/p_sab.xml
COMMENT=		XML toolkit implementing XSLT, DOM, and XPath

TOOL_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/sablotron

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

# sablotron needs iconv but assumes it is in libc, so add what
# buildlink3 finds.
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
