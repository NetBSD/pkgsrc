# $NetBSD: Makefile,v 1.1.1.1 2006/10/12 20:51:14 minskim Exp $

DISTNAME=	tzinfo-0.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	time ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/13799/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://tzinfo.rubyforge.org/
COMMENT=	Daylight-savings aware timezone library

NO_BUILD=	yes
NO_CONFIGURE=	yes

.include "../../lang/ruby/modules.mk"

do-install:
	cd ${WRKSRC}/lib && ${PAX} -rwppm * ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tzinfo
.for f in CHANGES LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/tzinfo
.endfor

.include "../../mk/bsd.pkg.mk"
