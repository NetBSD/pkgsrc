# $NetBSD: Makefile,v 1.1 2025/11/03 06:52:31 taca Exp $

DISTNAME=	rack-protection-3.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/protection/&3/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sinatrarb.com/protection/
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack2>=2.2:../../www/ruby-rack2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
