# $NetBSD: Makefile,v 1.3 2014/07/16 07:56:29 rodent Exp $

DISTNAME=	xpath-2.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	ruby textproc

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/jnicklas/xpath
COMMENT=	Ruby DSL for generating XPath expressions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.3:../../textproc/ruby-nokogiri

USE_LANGUAGES=	# none

RUBY_VERSION_SUPPORTED=	21 200 193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
