# $NetBSD: Makefile,v 1.8 2014/03/14 18:53:36 taca Exp $

DISTNAME=	compass-0.12.3
CATEGORIES=	www
#MASTER_SITES=	http://gems.github.com/gems/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compass-style.org/
COMMENT=	Stylesheet authoring framework based on Sass
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.2.14<3.3:../../www/ruby-sass
DEPENDS+=	${RUBY_PKGPREFIX}-chunky_png>=1.2<2:../../graphics/ruby-chunky_png
DEPENDS+=	${RUBY_PKGPREFIX}-fssm>=0.2.7:../../sysutils/ruby-fssm

CONFLICTS+=	ruby[1-9][0-9]-compass-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
