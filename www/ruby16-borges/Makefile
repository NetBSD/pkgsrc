# $NetBSD: Makefile,v 1.3 2005/03/06 17:19:08 taca Exp $

DISTNAME=	borges-0.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://segment7.net/projects/ruby/borges/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://segment7.net/projects/ruby/borges/
COMMENT=	Ruby web application framework

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	ruby16-installpkg>=0.0.1:../../devel/ruby-installpkg
DEPENDS+=	ruby16-webrick>=1.2.3:../../www/ruby-webrick

RUBY_VERSION=		${RUBY16_VERSION}
USE_RUBY_INSTALL=	yes
NO_BUILD=		yes
BORGES_SHARE_DIR=	data/doc data/examples

.if !empty(RUBY_SUFFIX)
pre-configure:
.for d in ${BORGES_SHARE_DIR}
	cd ${WRKSRC}; ${MV} ${d}/ruby ${d}/${RUBY_NAME}
.endfor
.endif

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
