# $NetBSD: Makefile,v 1.8 2024/06/15 16:30:53 taca Exp $

DISTNAME=	markaby-0.9.4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/markaby/markaby
COMMENT=	HTML Markup as Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
