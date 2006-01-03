# $NetBSD: Makefile,v 1.15 2006/01/03 14:25:51 taca Exp $

DISTNAME=	borges-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/574/ \
		http://segment7.net/projects/ruby/borges/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://borges.rubyforge.org/
COMMENT=	Ruby web application framework

USE_RUBY_SETUP=		yes
BORGES_SHARE_DIR=	data/doc data/examples

.include "../../lang/ruby/rubyversion.mk"

.if !empty(RUBY_SUFFIX)
pre-configure:
.for d in ${BORGES_SHARE_DIR}
	cd ${WRKSRC}; ${MV} ${d}/ruby ${d}/${RUBY_NAME}
.endfor
.endif

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
