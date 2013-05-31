# $NetBSD: Makefile,v 1.67 2013/05/31 12:42:30 wiz Exp $
#

DISTNAME=	adzap-20080508
PKGREVISION=	2
CATEGORIES=	www perl5
# XXX: should use the following one day:
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=adzapper/}
MASTER_SITES=	http://adzapper.sourceforge.net/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://adzapper.sourceforge.net/
COMMENT=	Filter out animated ad banners from web pages

WRKSRC=		${WRKDIR}/adzap
NO_BUILD=	yes
USE_TOOLS+=	perl:run

CHECK_PORTABILITY_SKIP=	scripts/update-zapper.damien

INSTALLATION_DIRS=	libexec share/examples/adzap

do-configure:
.for file in scripts/squid_redirect scripts/wrapzap
	${CP} ${WRKSRC}/${file} ${WRKSRC}/${file}.ORIG
	${SED} -e "s:/usr/bin/perl:${PERL5}:g" \
	       -e "s:@@PREFIX@@:${PREFIX}:g" \
		<${WRKSRC}/${file}.ORIG >${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/squid_redirect ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/wrapzap ${DESTDIR}${PREFIX}/libexec/adzap
.for file in ad-clear.gif ad-clear.mp3 ad-clear.swf \
    ad-grey.gif ad-old.gif \
    ad.gif ad.mp3 ad.swf \
    adbg-clear.gif adbg.gif \
    closepopup-clear.html closepopup.html \
    counter-clear.gif counter-clear.js \
    counter.gif counter.js \
    no-op-clear.html no-op-clear.js \
    no-op-counter-clear.html no-op-counter-clear.js \
    no-op-counter.html no-op-counter.js \
    no-op.html no-op.js \
    webbug-clear.gif webbug-clear.html webbug-clear.js \
    webbug.gif webbug.html webbug.js
	${INSTALL_DATA} ${WRKSRC}/zaps/${file} ${DESTDIR}${PREFIX}/share/examples/adzap
.endfor
.for file in proxy-home.pac proxy-zip.pac
	${INSTALL_DATA} ${WRKSRC}/rc/${file} ${DESTDIR}${PREFIX}/share/examples/adzap
.endfor
	${INSTALL_DATA} ${WRKSRC}/scripts/adzap.conf \
	    ${DESTDIR}${PREFIX}/share/examples/adzap

.include "../../mk/bsd.pkg.mk"
