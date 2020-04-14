# $NetBSD: Makefile,v 1.1 2020/04/14 15:58:29 ryoon Exp $

DISTNAME=	typhoeus-1.3.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/typhoeus/typhoeus
COMMENT=	Wraps libcurl in order to make fast and reliable requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ethon>=0.9.0:../../www/ruby-ethon

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
