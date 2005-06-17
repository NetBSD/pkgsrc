# $NetBSD: Makefile,v 1.18 2005/06/17 03:50:40 jlam Exp $
#

DISTNAME=	htmllint
PKGNAME=	htmllint-20050220
CATEGORIES=	www japanese
MASTER_SITES=	http://openlab.ring.gr.jp/k16/htmllint/archives/
EXTRACT_SUFX=	.zip

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/k16/htmllint/
COMMENT=	Another HTML-Lint program

DEPENDS+=	p5-Jcode>=0.68:../../converters/p5-Jcode

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

REPLACE_PERL=	htmllint.cgi htmllint parsedtd.pl tagslist.cgi
USE_PERL5=	# defined
NO_BUILD=	# defined

CGIDIR=		${LOCALBASE}/libexec/cgi-bin
HTMLDIR=	${LOCALBASE}/share/httpd/htdocs/htmllint
IMGDIR=		${HTMLDIR}/images

INSTALLATION_DIRS=	bin

post-patch:
.for f in faq.html htmllintenv htmllint htmllint.caller
	@${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}.orig; 			\
	${SED} -e 's!@PREFIX@!${PREFIX}!g' < ${WRKSRC}/${f}.orig 	\
		> ${WRKSRC}/${f}
.endfor

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/htmllint.caller ${PREFIX}/bin/htmllint; 	\
	${INSTALL_SCRIPT_DIR} ${CGIDIR}; 				\
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${CGIDIR}; 			\
	${INSTALL_DATA} ${WRKSRC}/htmllintrc ${CGIDIR}; 		\
	${INSTALL_DATA} ${WRKSRC}/htmllintenv ${CGIDIR}/htmllint.env.default; \
	${TEST} -f ${CGIDIR}/htmllint.env || 				\
	    ${CP} ${CGIDIR}/htmllint.env.default  ${CGIDIR}/htmllint.env; \
	${INSTALL_SCRIPT_DIR} ${HTMLDIR}; 				\
	${INSTALL_SCRIPT} ${WRKSRC}/htmllint ${HTMLDIR}; 		\
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${WRKSRC}/*.pm ${HTMLDIR}; 	\
	${INSTALL_DATA} ${WRKSRC}/*.css ${WRKSRC}/*.dtd ${WRKSRC}/*.ent \
	    ${WRKSRC}/*.html ${WRKSRC}/*.rul ${WRKSRC}/*.txt ${HTMLDIR}; \
	${INSTALL_DATA_DIR} ${IMGDIR}; 					\
	${INSTALL_DATA} ${WRKSRC}/*.gif ${IMGDIR}

.include "../../mk/bsd.pkg.mk"
