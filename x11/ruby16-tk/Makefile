# $NetBSD: Makefile,v 1.3 2005/01/28 14:19:35 taca Exp $
# FreeBSD: ports/x11-toolkits/ruby-tk/Makefile,v 1.21 2000/10/20 19:56:04 knu Exp

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-tk-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby interface to the Tk widget set

DEPENDS+=	${RUBY_PKGPREFIX}-tcltklib>=${RUBY_VERSION}:../../x11/${RUBY_PKGPREFIX}-tcltklib

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION=		${RUBY16_VERSION}
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF= 	yes
USE_X11=		yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/tk
WRKSRC=			${RUBY_WRKSRC}/ext/tk

REPLACE_RUBY=		sample/tkbiff.rb sample/tkbrowse.rb \
			sample/tkdialog.rb sample/tkfrom.rb sample/tktimer.rb

pre-configure:
	@cd ${WRKSRC}; \
	${FIND} . \( -name '*.orig' -o -name '*.bak' \) -exec rm -f {} \;

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tk
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tk

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
