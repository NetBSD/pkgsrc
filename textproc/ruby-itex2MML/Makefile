# $NetBSD: Makefile,v 1.9 2012/10/25 06:56:57 asau Exp $

DISTNAME=	itexToMML
PKGNAME=	${RUBY_PKGPREFIX}-itex2MML-${ITEX2MML_VERSION}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://golem.ph.utexas.edu/~distler/blog/files/
DIST_SUBDIR=	itex2MML-${ITEX2MML_VERSION}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://golem.ph.utexas.edu/~distler/blog/itex2MML.html
COMMENT=	Ruby binding for itex2MML
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2 OR mpl-1.0

BUILD_DEPENDS+=	swig>=1.3:../../devel/swig

ITEX2MML_VERSION=	1.4.5

USE_TOOLS+=		bison flex gmake
WRKSRC=			${WRKDIR}/${DISTNAME}/itex-src
BUILD_TARGET=		ruby
INSTALL_TARGET=		install_ruby

INSTALLATION_DIRS+=	${RUBY_VENDORARCHLIB}
MAKE_ENV+=		RUBY=${RUBY:Q}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
