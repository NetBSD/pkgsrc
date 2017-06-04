# $NetBSD: Makefile,v 1.1 2017/06/04 14:17:27 taca Exp $

DISTNAME=	rack-1.6.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rack/rack16/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.github.io/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

OVERRIDE_GEMSPEC=	:executables rackup=rackup16 \
			:files bin/rackup=bin/rackup16
RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;
	${TEST} -f ${WRKSRC}/bin/rackup16 || \
		${MV} ${WRKSRC}/bin/rackup ${WRKSRC}/bin/rackup16

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
