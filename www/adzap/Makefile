# $NetBSD: Makefile,v 1.13 2001/04/25 22:28:52 simonb Exp $
#

DISTNAME=	adzap-20010420
CATEGORIES=	www perl5
MASTER_SITES=	http://www.zip.com.au/~cs/adzap/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zip.com.au/~cs/adzap/index.html
COMMENT=	filter out animated ad banners from web pages

WRKSRC=		${WRKDIR}/adzap

NO_BUILD=	# defined
USE_PERL5=	# defined

do-configure:
.for FILE in squid_redirect wrapzap
	${CP} ${WRKSRC}/${FILE} ${WRKSRC}/${FILE}.ORIG
	${SED} -e "s:/usr/bin/perl:${PERL5}:g" \
	       -e "s:@@PREFIX@@:${PREFIX}:g" \
		<${WRKSRC}/${FILE}.ORIG >${WRKSRC}/${FILE}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/squid_redirect ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/wrapzap ${PREFIX}/libexec/adzap
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/adzap
.for FILE in adzap.conf proxy-cisra.pac proxy-home.pac proxy-zip.pac \
	closepopup-clear.html no-op-clear.html closepopup.html no-op.html \
	no-op-clear.js no-op.js ad-clear.gif ad.gif
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/examples/adzap
.endfor

.include "../../mk/bsd.pkg.mk"
