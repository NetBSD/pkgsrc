# $NetBSD: Makefile,v 1.39 2026/09/09 14:15:53 taca Exp $

DISTNAME=	css_parser-3.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/premailer/css_parser
COMMENT=	Ruby CSS parser
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-ssrf_filter>=1.5<2:../../security/ruby-ssrf_filter

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
