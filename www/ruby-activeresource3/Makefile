# $NetBSD: Makefile,v 1.2 2010/10/15 11:44:15 taca Exp $

DISTNAME=	activeresource-3.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	REST modeling framework (part of Rails)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.1:../../devel/ruby-activesupport3
DEPENDS+=	${RUBY_PKGPREFIX}-activemodel>=3.0.1:../../devel/ruby-activemodel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
