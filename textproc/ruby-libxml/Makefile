# $NetBSD: Makefile,v 1.20 2013/09/15 16:17:32 taca Exp $

DISTNAME=	libxml-ruby-2.7.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/ruby-//}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libxml.rubyforge.org/
COMMENT=	Support module for libxml2 library
LICENSE=	mit

CONFIGURE_ARGS+=	\
	--with-xml2-include=${BUILDLINK_PREFIX.libxml2}/include/libxml2
OVERRIDE_GEMSPEC=	:files ext/libxml/extconf.h= test/tc_parser.rb.orig=

pre-configure:
	${RM} ${WRKSRC}/ext/libxml/extconf.h

.include "../../lang/ruby/gem.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
