# $NetBSD: Makefile,v 1.9 2012/03/20 14:06:03 taca Exp $

DISTNAME=	termtter-1.10.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jugyo/termtter
COMMENT=	Terminal based Twitter client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.5.0:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-termcolor>=1.0.0:../../devel/ruby-termcolor
DEPENDS+=	${RUBY_PKGPREFIX}-rubytter>=0.11.0:../../net/ruby-rubytter
DEPENDS+=	${RUBY_PKGPREFIX}-notify>=0.2.1:../../sysutils/ruby-notify
DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.1.3:../../textproc/ruby-json-pure

CONFLICTS+=	ruby[1-9][0-9]-termtter-[0-9]* termtter-[0-9]*
RUBY_JSON_REQD=	1.1.3
RUBY_JSON_TYPE=	pure

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
