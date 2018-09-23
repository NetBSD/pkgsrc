# $NetBSD: Makefile,v 1.10 2018/09/23 16:41:14 taca Exp $

DISTNAME=	xpath-3.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	ruby textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jnicklas/xpath
COMMENT=	Ruby DSL for generating XPath expressions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8:../../textproc/ruby-nokogiri

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
