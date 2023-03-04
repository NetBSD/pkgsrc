# $NetBSD: Makefile,v 1.31.4.1 2023/03/04 14:35:53 spz Exp $

DISTNAME=	rack-2.2.6.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rack.github.io/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC=	:executables rackup=rackup22 \
			:files bin/rackup=bin/rackup22
RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;
	${FIND} ${WRKSRC}/bin -type f -exec ${CHMOD} ${BINMODE} {} \;
	${TEST} -f ${WRKSRC}/bin/rackup22 || \
		${MV} ${WRKSRC}/bin/rackup ${WRKSRC}/bin/rackup22

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
