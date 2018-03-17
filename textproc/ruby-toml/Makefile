# $NetBSD: Makefile,v 1.4 2018/03/17 16:34:11 taca Exp $

DISTNAME=	toml-0.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_RUBYGEMS:=toml/}
COMMENT=	Parser for a sane configuration format
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-parslet>=1.8.0:../../devel/ruby-parslet

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
