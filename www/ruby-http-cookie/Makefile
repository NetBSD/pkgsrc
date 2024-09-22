# $NetBSD: Makefile,v 1.6 2024/09/22 08:17:14 taca Exp $

DISTNAME=	http-cookie-1.0.7
CATEGORIES=	www

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/sparklemotion/http-cookie
COMMENT=	Ruby library to handle HTTP Cookies based on RFC 6265
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-domain_name>=0.5<1:../../net/ruby-domain_name

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
