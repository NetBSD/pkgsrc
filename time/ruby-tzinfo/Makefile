# $NetBSD: Makefile,v 1.2 2006/10/15 08:16:02 minskim Exp $

DISTNAME=	tzinfo-0.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/13799/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://tzinfo.rubyforge.org/
COMMENT=	Daylight-savings aware timezone library

NO_BUILD=	yes
NO_CONFIGURE=	yes

.include "../../lang/ruby/modules.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/tzinfo.rb ${RUBY_SITELIBDIR}
	cd ${WRKSRC}/lib && ${PAX} -rwppm tzinfo ${RUBY_SITELIBDIR}
	${FIND} ${RUBY_SITELIBDIR}/tzinfo -type d -print	\
		| ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${RUBY_SITELIBDIR}/tzinfo -type f -print	\
		| ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tzinfo
.for f in CHANGES LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/tzinfo
.endfor

.include "../../mk/bsd.pkg.mk"
