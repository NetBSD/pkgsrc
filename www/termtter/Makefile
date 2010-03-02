# $NetBSD: Makefile,v 1.1.1.1 2010/03/02 12:26:31 obache Exp $

DISTNAME=	termtter-1.7.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://termtter.org/
COMMENT=	Terminal based Twitter client

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.5.0:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-termcolor>=1.0.0:../../devel/ruby-termcolor
DEPENDS+=	${RUBY_PKGPREFIX}-rubytter>=0.11.0:../../net/ruby-rubytter
DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.1.3:../../textproc/ruby-json-pure

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
