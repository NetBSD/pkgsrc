# $NetBSD: Makefile,v 1.11 2021/05/21 11:11:19 nia Exp $

DISTNAME=	bluecloth-2.2.0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://deveiate.org/projects/BlueCloth
COMMENT=	Markdown library for Ruby
LICENSE=	original-bsd

USE_GCC_RUNTIME=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/bluecloth \
	    ${DESTDIR}${PREFIX}/bin/bluecloth${RUBY_SUFFIX}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
