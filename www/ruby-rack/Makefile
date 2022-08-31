# $NetBSD: Makefile,v 1.31 2022/08/31 15:50:11 taca Exp $

DISTNAME=	rack-2.2.4
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
