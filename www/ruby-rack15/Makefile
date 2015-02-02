# $NetBSD: Makefile,v 1.1 2015/02/02 14:09:22 taca Exp $

DISTNAME=	rack-1.5.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rack/rack15/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.github.com/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

OVERRIDE_GEMSPEC=	:executables rackup=rackup15 \
			:files bin/rackup=bin/rackup15
RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;
	${TEST} -f ${WRKSRC}/bin/rackup15 || \
		${MV} ${WRKSRC}/bin/rackup ${WRKSRC}/bin/rackup15

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
