# $NetBSD: Makefile,v 1.24 2023/12/22 18:04:31 zafer Exp $

DISTNAME=	borges-1.1.0
PKGREVISION=	2
CATEGORIES=	www ruby
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://borges.rubyforge.org/
COMMENT=	Ruby web application framework
LICENSE=	modified-bsd

USE_RUBY_SETUP=		yes
CONFIGURE_ARGS+=	--site-ruby-common=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--site-ruby=${PREFIX}/${RUBY_VENDORLIB} \
			--so-dir=path=${PREFIX}/${RUBY_VENDORARCHLIB}

BORGES_SHARE_DIR=	data/doc data/examples

.include "../../lang/ruby/rubyversion.mk"

.if !empty(RUBY_SUFFIX)
pre-configure:
.  for d in ${BORGES_SHARE_DIR}
	cd ${WRKSRC}; if [ -d ${d}/ruby ]; then \
		 ${MV} -f ${d}/ruby ${d}/${RUBY_NAME}; \
	fi
.  endfor
.endif

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
