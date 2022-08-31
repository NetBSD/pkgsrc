# $NetBSD: Makefile,v 1.2 2022/08/31 14:56:22 taca Exp $

DISTNAME=	http-accept-2.2.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ioquatix/http-accept
COMMENT=	Parse Accept and Accept-Language HTTP headers
LICENSE=	mit

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	:files lib/.DS_Store=

pre-configure:
	${RM} -f ${WRKSRC}/lib/.DS_Store

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
