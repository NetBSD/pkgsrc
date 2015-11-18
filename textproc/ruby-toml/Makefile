# $NetBSD: Makefile,v 1.3 2015/11/18 16:09:24 taca Exp $

DISTNAME=	toml-0.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_RUBYGEMS:=toml/}
COMMENT=	Parser for a sane configuration format
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-parslet>=1.5.0:../../devel/ruby-parslet

OVERRIDE_GEMSPEC+=	parslet>=1.5.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
