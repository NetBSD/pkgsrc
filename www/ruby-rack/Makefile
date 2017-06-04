# $NetBSD: Makefile,v 1.22 2017/06/04 15:10:09 taca Exp $

DISTNAME=	rack-2.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rack/rack20/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.github.io/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

# Rack 2.0.3 requires Ruby 2.2.2 or later 
RUBY_VERSIONS_ACCEPTED=	22 23
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
