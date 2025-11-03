# $NetBSD: Makefile,v 1.21 2025/11/03 07:35:56 taca Exp $

DISTNAME=	rack-protection-4.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sinatrarb.com/protection/
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3.0.0<4:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
