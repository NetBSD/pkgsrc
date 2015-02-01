# $NetBSD: Makefile,v 1.2 2015/02/01 12:44:11 taca Exp $

DISTNAME=	toml-0.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_RUBYGEMS:=toml/}
COMMENT=	Parser for a sane configuration format
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-parslet>=1.5.0<1.6:../../devel/ruby-parslet

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
