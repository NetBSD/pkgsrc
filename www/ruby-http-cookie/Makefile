# $NetBSD: Makefile,v 1.2 2016/09/30 15:36:59 taca Exp $

DISTNAME=	http-cookie-1.0.3
CATEGORIES=	www ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/sparklemotion/http-cookie
COMMENT=	Ruby library to handle HTTP Cookies based on RFC 6265
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-domain_name>=0.5<1:../../net/ruby-domain_name

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
