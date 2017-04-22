# $NetBSD: Makefile,v 1.17 2017/04/22 16:58:14 taca Exp $

DISTNAME=	css_parser-1.5.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/premailer/css_parser
COMMENT=	Ruby CSS parser
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
