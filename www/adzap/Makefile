# $NetBSD: Makefile,v 1.44 2004/04/19 21:37:22 kleink Exp $
#

DISTNAME=	adzap-20040408
CATEGORIES=	www perl5
# XXX: should use the following one day:
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=adzapper/}
MASTER_SITES=	http://adzapper.sourceforge.net/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://adzapper.sourceforge.net/
COMMENT=	Filter out animated ad banners from web pages

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
.for FILE in ad-clear.gif ad-clear.mp3 ad-clear.swf ad-grey.gif ad-old.gif \
    ad.gif ad.mp3 ad.swf adbg-clear.gif adbg.gif \
    closepopup-clear.html closepopup.html counter-clear.gif counter.gif \
    no-op-clear.html no-op-clear.js no-op-counter-clear.html \
    no-op-counter-clear.js no-op-counter.html no-op-counter.js \
    no-op.html no-op.js webbug-clear.gif webbug-clear.js webbug.gif webbug.js
	${INSTALL_DATA} ${WRKSRC}/zaps/${FILE} ${PREFIX}/share/examples/adzap
.endfor
.for FILE in proxy-home.pac proxy-zip.pac
	${INSTALL_DATA} ${WRKSRC}/rc/${FILE} ${PREFIX}/share/examples/adzap
.endfor
	${INSTALL_DATA} ${WRKSRC}/scripts/adzap.conf \
	    ${PREFIX}/share/examples/adzap

.include "../../mk/bsd.pkg.mk"
