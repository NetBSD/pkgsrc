# $NetBSD: Makefile,v 1.7 2023/12/17 15:52:08 taca Exp $

DISTNAME=	markaby-0.9.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/markaby/markaby
COMMENT=	HTML Markup as Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
