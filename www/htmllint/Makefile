# $NetBSD: Makefile,v 1.26 2006/07/10 10:43:31 rillig Exp $
#

DISTNAME=	htmllint
PKGNAME=	htmllint-20051019
PKGREVISION=	1
CATEGORIES=	www japanese
MASTER_SITES=	http://openlab.ring.gr.jp/k16/htmllint/archives/
EXTRACT_SUFX=	.zip

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/k16/htmllint/
COMMENT=	Another HTML-Lint program

DEPENDS+=	p5-Jcode>=0.68:../../converters/p5-Jcode
DEPENDS+=	p5-libwww>=5.8:../../www/p5-libwww

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

REPLACE_PERL=	htmllint.cgi htmllint parsedtd.pl tagslist.cgi
USE_TOOLS+=	perl:run
NO_BUILD=	yes

CGIDIR=		${PREFIX}/libexec/cgi-bin
HTMLDIR=	${PREFIX}/share/httpd/htdocs/htmllint
IMGDIR=		${HTMLDIR}/images

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		hl
SUBST_STAGE.hl=		pre-configure
SUBST_MESSAGE.hl=	Setting PREFIX.
SUBST_FILES.hl=		faq.html htmllintenv htmllint htmllint.caller
SUBST_SED.hl=		-e 's!@PREFIX@!${PREFIX}!g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/htmllint.caller ${PREFIX}/bin/htmllint
	${INSTALL_SCRIPT_DIR} ${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${CGIDIR}
	${INSTALL_DATA} ${WRKSRC}/htmllintrc ${CGIDIR}
	${INSTALL_DATA} ${WRKSRC}/htmllintenv ${CGIDIR}/htmllint.env.default
	${TEST} -f ${CGIDIR}/htmllint.env \
	|| ${INSTALL_DATA} ${CGIDIR}/htmllint.env.default  ${CGIDIR}/htmllint.env
	${INSTALL_SCRIPT_DIR} ${HTMLDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/htmllint ${HTMLDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${WRKSRC}/*.pm ${HTMLDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.css *.dtd *.ent *.html *.rul	\
		*.txt ${HTMLDIR}
	${INSTALL_DATA_DIR} ${IMGDIR}
	${INSTALL_DATA} ${WRKSRC}/*.gif ${IMGDIR}

.include "../../mk/bsd.pkg.mk"
