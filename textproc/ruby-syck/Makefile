# $NetBSD: Makefile,v 1.1.1.1 2005/04/02 22:40:19 minskim Exp $

DISTNAME=	syck-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=yaml4r/}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.whytheluckystiff.net/syck/
COMMENT=	Fast YAML reader/writer for Ruby

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} == "16"
DEPENDS+=	${RUBY_PKGPREFIX}-racc>=1.4.3:../../devel/ruby-racc
.endif

USE_RUBY_SETUP=		yes
RUBY_DIST_SUBDIR=	# make it empty
RUBY_HAS_ARCHLIB=	yes
RUBY_SETUP=		install.rb
VER=			0.42
WRKSRC=			${WRKDIR}/${DISTNAME}/ext/ruby

EXAMPLES=		okayNews-modules.rb okayNews-sample.rb \
			okayNews-validate.rb okayRpc-client.rb \
			okayRpc-server.rb yaml-sortHashKeys.rb
.for f in ${EXAMPLES}
REPLACE_RUBY+=		samples/${f}
.endfor

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/syck
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${RUBY_EXAMPLESDIR}/syck
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
