# $NetBSD: Makefile,v 1.4 2013/02/11 09:17:42 taca Exp $

DISTNAME=	rison-2.0.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tim/ruby-rison/
COMMENT=	Ruby implementation of Rison - Compact Data in URIs
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-parslet>=1.4.0<1.5:../../devel/ruby-parslet

pre-configure:
	${CHMOD} 0644 ${WRKSRC}/lib/rison/dump.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
