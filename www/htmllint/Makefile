# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 05:13:04 kei Exp $
#

DISTNAME=	htmllint
PKGNAME=	htmllint-2.32
CATEGORIES=	www japanese
MASTER_SITES=	http://openlab.ring.gr.jp/k16/htmllint/archives/
EXTRACT_SUFX=	.zip

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://openlab.ring.gr.jp/k16/htmllint/
COMMENT=	Another HTML-Lint program

DEPENDS+=	p5-Jcode>=0.68:../../japanese/p5-Jcode

USE_PERL5=	# defined
NO_WRKSUBDIR=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

CGIDIR=		${PREFIX}/libexec/cgi-bin
HTMLDIR=	${PREFIX}/share/httpd/htdocs/htmllint
IMGDIR=		${HTMLDIR}/images

post-patch:
.for f in faq.html htmllint.cgi htmllint htmllintenv parsedtd.pl tagslist.cgi
	${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}.orig
	${SED} -e 's!@PREFIX@!${PREFIX}!g' < ${WRKSRC}/${f}.orig \
	    > ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/htmllint ${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${WRKSRC}/htmllintrc ${CGIDIR}
	${INSTALL_DATA} ${WRKSRC}/htmllintenv ${CGIDIR}/htmllint.env
	${INSTALL_SCRIPT_DIR} ${HTMLDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${WRKSRC}/*.pm ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.css ${WRKSRC}/*.dtd ${WRKSRC}/*.ent \
	    ${WRKSRC}/*.html ${WRKSRC}/*.rul ${WRKSRC}/*.txt ${HTMLDIR}
	${INSTALL_DATA_DIR} ${IMGDIR}
	${INSTALL_DATA} ${WRKSRC}/*.gif ${IMGDIR}

.include "../../mk/bsd.pkg.mk"
