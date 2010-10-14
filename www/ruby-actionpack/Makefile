# $NetBSD: Makefile,v 1.20 2010/10/14 11:41:25 obache Exp $

DISTNAME=	actionpack-2.3.9
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/actionpack/
COMMENT=	Two-step approach to web response generation
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.9:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-rack-1.1.0{,nb*}:../../www/ruby-rack11

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
