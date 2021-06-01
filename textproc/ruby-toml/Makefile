# $NetBSD: Makefile,v 1.5 2021/06/01 15:40:47 taca Exp $

DISTNAME=	toml-0.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_RUBYGEMS:=toml/}
COMMENT=	Parser for a sane configuration format
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-parslet>=1.8.0:../../devel/ruby-parslet

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
