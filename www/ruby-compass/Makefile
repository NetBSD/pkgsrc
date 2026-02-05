# $NetBSD: Makefile,v 1.12 2026/02/05 11:07:18 wiz Exp $

DISTNAME=	compass-1.0.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://compass-style.org/
COMMENT=	Stylesheet authoring framework based on Sass
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-chunky_png>=1.2<2:../../graphics/ruby-chunky_png
DEPENDS+=	${RUBY_PKGPREFIX}-compass-core>=1.0.2<1.1:../../www/ruby-compass-core
DEPENDS+=	${RUBY_PKGPREFIX}-compass-import-once>=1.0.5<1.1:../../www/ruby-compass-import-once
DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.9.3:../../devel/ruby-rb-fsevent
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9:../../devel/ruby-rb-inotify

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
