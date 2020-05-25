# $NetBSD: Makefile,v 1.1 2020/05/25 15:17:54 taca Exp $

DISTNAME=	actionpack-xml_parser-2.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/actionpack/actionpack${RUBY_RAILS}/}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	XML parameters parser for Action Pack (removed from core in Rails 4.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
