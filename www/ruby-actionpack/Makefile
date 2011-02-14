# $NetBSD: Makefile,v 1.21.4.1 2011/02/14 18:26:32 spz Exp $

DISTNAME=	actionpack-2.3.11
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/actionpack/
COMMENT=	Two-step approach to web response generation
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.11<2.3.12:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.1.0<1.2.0:../../www/ruby-rack11

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
