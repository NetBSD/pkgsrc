# $NetBSD: Makefile,v 1.3 2024/02/05 15:53:07 taca Exp $

DISTNAME=	http-accept-2.2.1
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
