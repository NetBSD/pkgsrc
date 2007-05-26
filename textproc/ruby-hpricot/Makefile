# $NetBSD: Makefile,v 1.1.1.1 2007/05/26 01:34:44 minskim Exp $

DISTNAME=	hpricot-0.5.140
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://code.whytheluckystiff.net/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://code.whytheluckystiff.net/hpricot/
COMMENT=	Fast, enjoyable HTML parser for Ruby

BUILD_DEPENDS+=	ragel-[0-9]*:../../devel/ragel
BUILD_DEPENDS+=	rake>=0.7:../../devel/rake

RUBY_HAS_ARCHLIB=	yes

FIND_PREFIX:=	RAKE_PREFIX=rake
.include "../../mk/find-prefix.mk"

.include "../../lang/ruby/modules.mk"

do-build:
	cd ${WRKSRC} && ${RAKE_PREFIX}/bin/rake

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/hpricot_scan.${RUBY_DLEXT}		\
		${RUBY_SITEARCHLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/hpricot.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/hpricot
	${INSTALL_DATA} ${WRKSRC}/lib/hpricot/*.rb			\
		${RUBY_SITELIBDIR}/hpricot

.include "../../mk/bsd.pkg.mk"
