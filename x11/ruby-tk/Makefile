# $NetBSD: Makefile,v 1.16 2005/03/24 21:13:03 wiz Exp $

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-tk-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby interface to the Tk widget set

DEPENDS+=	${RUBY_PKGPREFIX}-tcltklib>=${RUBY_VERSION}:../../x11/ruby-tcltklib

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION_SUPPORTED=	18
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
USE_X11=		yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/tk
WRKSRC=			${RUBY_WRKSRC}/ext/tk

REPLACE_RUBY_DIRS=	${WRKSRC}/sample

pre-configure:
	@cd ${WRKSRC}; \
	${FIND} . \( -name '*.orig' -o -name '*.bak' \) -exec ${RM} -f {} \;

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tk
	${CP} -r ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tk

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
