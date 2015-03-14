# $NetBSD: Makefile,v 1.3 2015/03/14 08:00:40 taca Exp $

DISTNAME=	rack-1.4.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rack/rack14/}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.github.com/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

OVERRIDE_GEMSPEC=	:executables rackup=rackup14 \
			:files bin/rackup=bin/rackup14
RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;
	${TEST} -f ${WRKSRC}/bin/rackup14 || \
		${MV} ${WRKSRC}/bin/rackup ${WRKSRC}/bin/rackup14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
