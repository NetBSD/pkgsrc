# $NetBSD: Makefile,v 1.19 2010/09/10 12:44:06 taca Exp $

DISTNAME=	actionpack-2.3.9
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/actionpack/
COMMENT=	Two-step approach to web response generation
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.9:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.1.0:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
