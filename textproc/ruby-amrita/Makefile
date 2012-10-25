# $NetBSD: Makefile,v 1.16 2012/10/25 06:56:55 asau Exp $

DISTNAME=	amrita-1.0.2
PKGREVISION=	2
CATEGORIES=	textproc ruby www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=amrita/10939/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://amrita.sourceforge.jp/
COMMENT=	HTML/XHTML template library for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

CONFLICTS+=	ruby[1-9][0-9]-amrita-*

NO_BUILD=	yes
DOCS=		ChangeLog README README_ja
REPLACE_RUBY=	bin/ams bin/amshandler bin/amx
USE_TOOLS=	pax

USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes
INSTALLATION_DIRS=	bin ${RUBY_DOC}/amrita ${RUBY_EG}/amrita \
			${RUBY_VENDORLIB}

post-patch:
	@${FIND} ${WRKSRC} -name '.cvsignore' -exec ${RM} -f {} \;

post-install:
.for f in ${REPLACE_RUBY}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/amrita
.endfor
	cd ${WRKSRC}/docs; ${PAX} -rw . ${DESTDIR}${PREFIX}/${RUBY_DOC}/amrita
	cd ${WRKSRC}/sample; ${PAX} -rw . ${DESTDIR}${PREFIX}/${RUBY_EG}/amrita

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
