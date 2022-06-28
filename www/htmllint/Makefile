# $NetBSD: Makefile,v 1.44 2022/06/28 11:37:05 wiz Exp $

DISTNAME=	htmllint
PKGNAME=	htmllint-20111128
PKGREVISION=	3
CATEGORIES=	www japanese
MASTER_SITES=	http://openlab.ring.gr.jp/k16/htmllint/archives/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/k16/htmllint/
COMMENT=	Another HTML-Lint program
#LICENSE=	# Three lines NOTE is on the web, will adjust later

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

INSTALLATION_DIRS=	bin ${CGIDIR} ${HTMLDIR} ${IMGDIR}

SUBST_CLASSES+=		hl
SUBST_STAGE.hl=		pre-configure
SUBST_MESSAGE.hl=	Setting PREFIX.
SUBST_FILES.hl=		faq.html htmllintenv htmllint htmllint.caller
SUBST_VARS.hl=		PREFIX

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/htmllint.caller ${DESTDIR}${PREFIX}/bin/htmllint
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${DESTDIR}${CGIDIR}
	${INSTALL_DATA} ${WRKSRC}/htmllintrc ${DESTDIR}${CGIDIR}
	${INSTALL_DATA} ${WRKSRC}/htmllintenv ${DESTDIR}${CGIDIR}/htmllint.env.default
	${TEST} -f ${DESTDIR}${CGIDIR}/htmllint.env \
	|| ${INSTALL_DATA} ${DESTDIR}${CGIDIR}/htmllint.env.default  ${DESTDIR}${CGIDIR}/htmllint.env
	${INSTALL_SCRIPT} ${WRKSRC}/htmllint ${DESTDIR}${HTMLDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${WRKSRC}/*.pm ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.css *.dtd *.ent *.html *.rul	\
		*.txt ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.gif ${DESTDIR}${IMGDIR}

.include "../../mk/bsd.pkg.mk"
