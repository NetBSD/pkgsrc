# $NetBSD: Makefile,v 1.6 2026/05/04 06:11:46 taca Exp $

DISTNAME=	actionpack-xml_parser-2.0.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	XML parameters parser for Action Pack (removed from core in Rails 4.0)
LICENSE=	mit


# This pacakge is assumed to used by redmine51, redmine60 and redmine61.
# To shared by multiple rails, omit dependency here.
#DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
#DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
#RUBY_RAILS_ACCEPTED=	72

CONFLICTS+=	${RUBY_PKGPREFIX}-actionpack[67][0-2]-xml_parser-[0-9]*

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
