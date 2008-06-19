# $NetBSD: Makefile,v 1.13 2008/06/19 14:54:37 taca Exp $

DISTNAME=	amrita-1.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc ruby www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=amrita/10939/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://amrita.sourceforge.jp/
COMMENT=	HTML/XHTML template library for Ruby

CONFLICTS+=	ruby[1-9][0-9]-amrita-*

NO_BUILD=	yes
DOCS=		ChangeLog README README_ja
REPLACE_RUBY=	bin/ams bin/amshandler bin/amx
USE_TOOLS=	pax
USE_RUBY_INSTALL=	yes

INSTALLATION_DIRS=	bin ${RUBY_DOC}/amrita ${RUBY_EG}/amrita

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
