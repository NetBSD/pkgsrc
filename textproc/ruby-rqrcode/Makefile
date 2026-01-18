# $NetBSD: Makefile,v 1.6 2026/01/18 14:10:50 taca Exp $

DISTNAME=	rqrcode-3.1.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/whomwah/rqrcode
COMMENT=	Ruby library for QR codes in various formats
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rqrcode_core>=2.0<3:../../textproc/ruby-rqrcode_core
DEPENDS+=	${RUBY_PKGPREFIX}-chunky_png>=1.0<2:../../graphics/ruby-chunky_png

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
