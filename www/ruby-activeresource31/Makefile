# $NetBSD: Makefile,v 1.3 2012/06/14 14:56:16 taca Exp $

DISTNAME=	activeresource-${RUBY_RAILS_VERSION}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	REST modeling framework (part of Rails 3.1)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}

RUBY_RAILS_SUPPORTED=	31
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
