# $NetBSD: Makefile,v 1.3 2017/07/30 22:32:24 wiz Exp $

DISTNAME=	tilt-1.4.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/tilt/tilt1/}
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtomayko/tilt/
COMMENT=	Generic interface to multiple Ruby template engines
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rdoc: :executables tilt=tilt1 \
			:files bin/tilt=bin/tilt1

pre-configure:
	${MV} ${WRKSRC}/bin/tilt ${WRKSRC}/bin/tilt1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
