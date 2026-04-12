# $NetBSD: Makefile,v 1.9 2026/04/12 15:27:21 taca Exp $

DISTNAME=	http-cookie-1.1.4
CATEGORIES=	www

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/sparklemotion/http-cookie
COMMENT=	Ruby library to handle HTTP Cookies based on RFC 6265
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-domain_name>=0.5<1:../../net/ruby-domain_name

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
