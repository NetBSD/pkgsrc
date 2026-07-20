# $NetBSD: Makefile,v 1.38 2026/07/20 06:01:38 taca Exp $

DISTNAME=	css_parser-3.0.0
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
