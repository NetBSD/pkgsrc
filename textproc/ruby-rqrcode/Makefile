# $NetBSD: Makefile,v 1.2 2021/08/30 15:58:32 taca Exp $

DISTNAME=	rqrcode-2.1.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/whomwah/rqrcode
COMMENT=	Ruby library for QR codes in various formats
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rqrcode_core>=1.0<2:../../textproc/ruby-rqrcode_core
DEPENDS+=	${RUBY_PKGPREFIX}-chunky_png>=1.0<2:../../graphics/ruby-chunky_png

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
