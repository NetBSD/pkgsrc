# $NetBSD: Makefile,v 1.29 2020/06/17 10:33:49 taca Exp $

DISTNAME=	rack-2.2.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rack.github.io/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC=	:executables rackup=rackup20 \
			:files bin/rackup=bin/rackup20
RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;
	${FIND} ${WRKSRC}/bin -type f -exec ${CHMOD} ${BINMODE} {} \;
	${TEST} -f ${WRKSRC}/bin/rackup20 || \
		${MV} ${WRKSRC}/bin/rackup ${WRKSRC}/bin/rackup20

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
