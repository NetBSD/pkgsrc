# $NetBSD: Makefile,v 1.7 2024/02/24 14:22:36 taca Exp $

DISTNAME=	rack-2.2.8.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rack/&2/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rack.github.io/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC=	:executables rackup=rackup2 \
			:files bin/rackup=bin/rackup2
RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;
	${FIND} ${WRKSRC}/bin -type f -exec ${CHMOD} ${BINMODE} {} \;
	${TEST} -f ${WRKSRC}/bin/rackup2 || \
		${MV} ${WRKSRC}/bin/rackup ${WRKSRC}/bin/rackup2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
