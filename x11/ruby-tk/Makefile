# $NetBSD: Makefile,v 1.1.1.1 2001/06/30 08:20:26 taca Exp $
# FreeBSD: ports/x11-toolkits/ruby-tk/Makefile,v 1.21 2000/10/20 19:56:04 knu Exp

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}tk-${RUBY_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby interface to the Tk widget set

DEPENDS+=	${RUBY_PKGNAMEPREFIX}tcltklib>=${RUBY_VERSION}:../../x11/ruby-tcltklib

DIST_SUBDIR=	ruby
WRKSRC=		${RUBY_WRKSRC}/ext/tk

EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/ext/tk
USE_RUBY_EXTCONF= yes

#.include "../../mk/bsd.prefs.mk"

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -exec rm -f {} \;

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tk
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tk

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
