# $NetBSD: Makefile,v 1.6 2010/09/10 23:54:14 obache Exp $

DISTNAME=	termtter-1.9.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://termtter.org/
COMMENT=	Terminal based Twitter client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.5.0:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-termcolor>=1.0.0:../../devel/ruby-termcolor
DEPENDS+=	${RUBY_PKGPREFIX}-rubytter>=0.11.0:../../net/ruby-rubytter
DEPENDS+=	${RUBY_PKGPREFIX}-notify>=0.2.1:../../sysutils/ruby-notify
DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.1.3:../../textproc/ruby-json-pure

CONFLICTS+=	ruby[1-9][0-9]-termtter-[0-9]* termtter-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
