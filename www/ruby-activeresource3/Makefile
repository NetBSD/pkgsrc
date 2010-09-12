# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 04:19:38 taca Exp $

DISTNAME=	activeresource-3.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	REST modeling framework (part of Rails)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.0:../../devel/ruby-activesupport3
DEPENDS+=	${RUBY_PKGPREFIX}-activemodel>=3.0.0:../../devel/ruby-activemodel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
