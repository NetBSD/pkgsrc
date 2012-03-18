# $NetBSD: Makefile,v 1.1.1.1 2012/03/18 06:50:07 taca Exp $

DISTNAME=	activeresource-${RUBY_RAILS_VERSION}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	REST modeling framework (part of Rails 3.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}

RUBY_RAILS_SUPPORTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
