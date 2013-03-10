# $NetBSD: Makefile,v 1.2 2013/03/10 09:13:12 taca Exp $

DISTNAME=	rack-1.4.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rack/rack14/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.github.com/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-rack>=1.4<1.5 ruby[1-9][0-9][0-9]-rack>=1.4<1.5

OVERRIDE_GEMSPEC=	:executables rackup=rackup14 \
			:files bin/rackup=bin/rackup14

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;
	${TEST} -f ${WRKSRC}/bin/rackup14 || \
		${MV} ${WRKSRC}/bin/rackup ${WRKSRC}/bin/rackup14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
