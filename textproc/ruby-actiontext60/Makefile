# $NetBSD: Makefile,v 1.1 2020/03/20 17:11:39 taca Exp $

DISTNAME=	actiontext-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actiontext${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	textproc devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Rich text framework (for Rails 6.0)
LICENSE=	mit

#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_ACTIVESTORAGE_DEPENDS}
#DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8.5:../../textproc/ruby-nokogiri

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	60
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
