# $NetBSD: Makefile,v 1.5 2010/09/07 17:20:27 taca Exp $

DISTNAME=	itexToMML
PKGNAME=	${RUBY_PKGPREFIX}-itex2MML-${ITEX2MML_VERSION}
PKGREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://golem.ph.utexas.edu/~distler/blog/files/
DIST_SUBDIR=	itex2MML-${ITEX2MML_VERSION}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://golem.ph.utexas.edu/~distler/blog/itex2MML.html
COMMENT=	Ruby binding for itex2MML

BUILD_DEPENDS+=	swig>=1.3:../../devel/swig

ITEX2MML_VERSION=	1.2.3
RUBY_VERSION_SUPPORTED= 18
RUBY_HAS_ARCHLIB=	yes

USE_TOOLS+=		bison flex gmake
WRKSRC=			${WRKDIR}/${DISTNAME}/itex-src
BUILD_TARGET=		ruby
INSTALL_TARGET=		install_ruby

INSTALLATION_DIRS+=	${RUBY_VENDORARCHLIB}
MAKE_ENV+=		RUBY=${RUBY:Q}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
