# $NetBSD: Makefile,v 1.27 2002/07/17 09:49:13 martti Exp $
#

DISTNAME=	adzap-20020717
CATEGORIES=	www perl5
MASTER_SITES=	http://www.zip.com.au/~cs/adzap/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zip.com.au/~cs/adzap/index.html
COMMENT=	filter out animated ad banners from web pages

WRKSRC=		${WRKDIR}/adzap

NO_BUILD=	# defined
USE_PERL5=	# defined

do-configure:
.for FILE in scripts/squid_redirect scripts/wrapzap
	${CP} ${WRKSRC}/${FILE} ${WRKSRC}/${FILE}.ORIG
	${SED} -e "s:/usr/bin/perl:${PERL5}:g" \
	       -e "s:@@PREFIX@@:${PREFIX}:g" \
		<${WRKSRC}/${FILE}.ORIG >${WRKSRC}/${FILE}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/squid_redirect ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/wrapzap ${PREFIX}/libexec/adzap
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/adzap
.for FILE in ad-clear.gif ad-clear.mp3 ad-clear.swf ad-grey.gif ad-old.gif ad.gif ad.mp3 ad.swf \
    adbg-clear.gif adbg.gif \
    closepopup-clear.html closepopup.html counter-clear.gif counter.gif \
    no-op-clear.html no-op-clear.js no-op-counter-clear.js no-op-counter.js no-op.html no-op.js webbug-clear.gif \
    webbug-clear.js webbug.gif webbug.js
	${INSTALL_DATA} ${WRKSRC}/zaps/${FILE} ${PREFIX}/share/examples/adzap
.endfor
.for FILE in proxy-cisra.pac proxy-home.pac proxy-zip.pac
	${INSTALL_DATA} ${WRKSRC}/rc/${FILE} ${PREFIX}/share/examples/adzap
.endfor
	${INSTALL_DATA} ${WRKSRC}/scripts/adzap.conf \
	    ${PREFIX}/share/examples/adzap

.include "../../mk/bsd.pkg.mk"
