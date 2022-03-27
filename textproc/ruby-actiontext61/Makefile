# $NetBSD: Makefile,v 1.2 2022/03/27 06:29:58 wiz Exp $

DISTNAME=	actiontext-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actiontext${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	textproc devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Rich text framework (for Rails 6.1)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESTORAGE_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8.5:../../textproc/ruby-nokogiri

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	61
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
