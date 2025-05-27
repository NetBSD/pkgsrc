# $NetBSD: Makefile,v 1.3 2025/05/27 16:13:45 taca Exp $

DISTNAME=	actiontext-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actiontext${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	textproc devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Rich text framework (for Rails 8.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESTORAGE_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8.5:../../textproc/ruby-nokogiri
#DEPENDS+=	${RUBY_PKGPREFIX}-globalid>=0.3.6:../../devel/ruby-globalid

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	80
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
