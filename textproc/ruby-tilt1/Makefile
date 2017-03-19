# $NetBSD: Makefile,v 1.2 2017/03/19 16:02:43 taca Exp $

DISTNAME=	tilt-1.4.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/tilt/tilt1/}
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rtomayko/tilt/
COMMENT=	Generic interface to multiple Ruby template engines
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rdoc: :executables tilt=tilt1 \
			:files bin/tilt=bin/tilt1

pre-configure:
	${MV} ${WRKSRC}/bin/tilt ${WRKSRC}/bin/tilt1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
