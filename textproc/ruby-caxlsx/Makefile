# $NetBSD: Makefile,v 1.1 2026/09/27 13:41:50 taca Exp $

DISTNAME=	caxlsx-4.5.0
CATEGORIES=	textproc ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/caxlsx/caxlsx
COMMENT=	Excel OOXML with charts, styles, images and autowidth columns
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-htmlentities>=4.3<5:../../textproc/ruby-htmlentities
DEPENDS+=	${RUBY_PKGPREFIX}-marcel>=1.0<2:../../devel/ruby-marcel
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.10<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=2.4:../../archivers/ruby-zip

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
