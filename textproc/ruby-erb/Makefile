# $NetBSD: Makefile,v 1.10 2005/03/06 17:19:07 taca Exp $
#

DISTNAME=	erb-2.0.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2a.biglobe.ne.jp/~seki/ruby/
COMMENT=	Implementation of eRuby (embedded ruby)

RUBY_VERSION=		${RUBY16_VERSION}
USE_RUBY_INSTALL=	yes
NO_BUILD=		yes
REPLACE_RUBY=		bin/erb sample/erbcgi

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/erb
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/erb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
