# $NetBSD: Makefile,v 1.9 2005/03/06 13:10:32 taca Exp $

DISTNAME=	borges-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/574/ \
		http://segment7.net/projects/ruby/borges/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://borges.rubyforge.org/
COMMENT=	Ruby web application framework

USE_RUBY_SETUP=			yes
RUBY_VERSION_SUPPORTED?=	18
BORGES_SHARE_DIR=		data/doc data/examples

.include "../../lang/ruby/rubyversion.mk"

.if !empty(RUBY_SUFFIX)
pre-configure:
.for d in ${BORGES_SHARE_DIR}
	cd ${WRKSRC}; ${MV} ${d}/ruby ${d}/${RUBY_NAME}
.endfor
.endif

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
