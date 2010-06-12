# $NetBSD: Makefile,v 1.7 2010/06/12 09:47:16 obache Exp $

DISTNAME=	htree-0.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.a-k-r.org/htree/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.a-k-r.org/htree/
COMMENT=	Tree data structure which represent HTML and XML data for Ruby
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes

INSTALL_TARGET=		--destdir=${DESTDIR}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
