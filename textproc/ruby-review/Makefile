# $NetBSD: Makefile,v 1.15 2023/07/09 02:52:41 taca Exp $

DISTNAME=	review-5.8.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kmuto/review/wiki
COMMENT=	Re:VIEW: a easy-to-use digital publishing system
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${RUBY_PKGPREFIX}-image_size>=0:../../graphics/ruby-image_size
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=0:../../www/ruby-rouge
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=0:../../archivers/ruby-zip
DEPENDS+=	${RUBY_PKGPREFIX}-tty-logger>=0:../../devel/ruby-tty-logger

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	cd ${WRKSRC}/bin && ${CHMOD} ${BINMODE} *

.include "../../lang/ruby/rubyversion.mk"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
