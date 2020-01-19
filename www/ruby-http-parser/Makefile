# $NetBSD: Makefile,v 1.1 2020/01/19 08:49:21 taca Exp $

DISTNAME=	http-parser-1.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cotag/http-parser
COMMENT=	Ruby bindings to joyent/http-parser
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi-compiler>=1.0:../../devel/ruby-ffi-compiler

GEM_CLEANBUILD=	ext/*.o

.include "../../www/http-parser/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
