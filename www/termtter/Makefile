# $NetBSD: Makefile,v 1.14 2015/12/12 04:17:38 taca Exp $

DISTNAME=	termtter-2.2.1
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://termtter.github.com/
COMMENT=	Terminal based Twitter client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-fiddle-[0-9]*:../../devel/ruby-fiddle
DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.5.0:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-termcolor>=1.0.0:../../devel/ruby-termcolor
DEPENDS+=	${RUBY_PKGPREFIX}-rubytter>=1.5.1:../../net/ruby-rubytter
DEPENDS+=	${RUBY_PKGPREFIX}-notify>=0.5.1:../../sysutils/ruby-notify

OVERRIDE_GEMSPEC+=	highline>=1.5.0
OVERRIDE_GEMSPEC+=	termcolor>=1.0.0

RUBYGEM_OPTIONS+=	--format-executable
RUBY_JSON_REQD=		1.1.3
RUBY_JSON_TYPE=		pure

.include "../../lang/ruby/json.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
