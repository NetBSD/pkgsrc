# $NetBSD: Makefile,v 1.6 2002/11/22 16:10:10 jschauma Exp $
#

DISTNAME=	htmllint
PKGNAME=	htmllint-20021103
CATEGORIES=	www japanese
MASTER_SITES=	http://openlab.ring.gr.jp/k16/htmllint/archives/
EXTRACT_SUFX=	.zip

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://openlab.ring.gr.jp/k16/htmllint/
COMMENT=	Another HTML-Lint program

DEPENDS+=	p5-Jcode>=0.68:../../converters/p5-Jcode

USE_PERL5=	# defined
WRKSRC=		${WRKDIR}
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

CGIDIR=		${LOCALBASE}/libexec/cgi-bin
HTMLDIR=	${LOCALBASE}/share/httpd/htdocs/htmllint
IMGDIR=		${HTMLDIR}/images

post-patch:
.for f in faq.html htmllint.cgi htmllint htmllintenv parsedtd.pl tagslist.cgi
	@${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}.orig; \
	${SED} -e 's!@PREFIX@!${PREFIX}!g' < ${WRKSRC}/${f}.orig \
	    > ${WRKSRC}/${f}
.endfor

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/htmllint ${PREFIX}/bin; \
	${INSTALL_SCRIPT_DIR} ${CGIDIR}; \
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${CGIDIR}; \
	${INSTALL_DATA} ${WRKSRC}/htmllintrc ${CGIDIR}; \
	${INSTALL_DATA} ${WRKSRC}/htmllintenv ${CGIDIR}/htmllint.env.default; \
	${TEST} -f ${CGIDIR}/htmllint.env || \
	    ${CP} ${CGIDIR}/htmllint.env.default  ${CGIDIR}/htmllint.env; \
	${INSTALL_SCRIPT_DIR} ${HTMLDIR}; \
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${WRKSRC}/*.pm ${HTMLDIR}; \
	${INSTALL_DATA} ${WRKSRC}/*.css ${WRKSRC}/*.dtd ${WRKSRC}/*.ent \
	    ${WRKSRC}/*.html ${WRKSRC}/*.rul ${WRKSRC}/*.txt ${HTMLDIR}; \
	${INSTALL_DATA_DIR} ${IMGDIR}; \
	${INSTALL_DATA} ${WRKSRC}/*.gif ${IMGDIR}

.include "../../mk/bsd.pkg.mk"
