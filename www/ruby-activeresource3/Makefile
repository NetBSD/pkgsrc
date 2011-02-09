# $NetBSD: Makefile,v 1.3 2011/02/09 13:00:50 taca Exp $

DISTNAME=	activeresource-3.0.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	REST modeling framework (part of Rails)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.4<3.0.5:../../devel/ruby-activesupport3
DEPENDS+=	${RUBY_PKGPREFIX}-activemodel>=3.0.4<3.0.5:../../devel/ruby-activemodel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
