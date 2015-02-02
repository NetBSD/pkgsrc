# $NetBSD: Makefile,v 1.5 2015/02/02 12:26:21 taca Exp $

DISTNAME=	rison-2.0.0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tim/ruby-rison/
COMMENT=	Ruby implementation of Rison - Compact Data in URIs
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-parslet>=1.4.0:../../devel/ruby-parslet

OVERRIDE_GEMSPEC+=	parslet>=1.4.0

pre-configure:
	${CHMOD} 0644 ${WRKSRC}/lib/rison/dump.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
