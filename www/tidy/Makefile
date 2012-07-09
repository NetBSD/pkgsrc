# $NetBSD: Makefile,v 1.37 2012/07/09 12:15:08 mef Exp $
#

DISTNAME=	tidy-20091027
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	# manually created tarballs on ftp.NetBSD.org only

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tidy.sourceforge.net/
COMMENT=	Fixes and tidies up HTML files
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	libxslt>=1.1.0:../../textproc/libxslt

PKG_OPTIONS_VAR=	PKG_OPTIONS.tidy
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

WRKSRC=		${WRKDIR}/tidy
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake gmake
CPPFLAGS+=	-DSUPPORT_ACCESSIBILITY_CHECKS=1 -DSUPPORT_UTF16_ENCODINGS=1
CPPFLAGS+=	-DSUPPORT_ASIAN_ENCODINGS=1 -DSUPPORT_GETPWNAM=1

INSTALLATION_DIRS=	${PKGMANDIR}/man1
PLIST_SRC+=		${PKGDIR}/PLIST

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+= doxygen>=1.8.1.1:../../devel/doxygen

HTML_DOCFILES=	Overview.html doxygen.cfg grid.gif tidy.css faq.html \
		license.html pending.html release-notes.html tidy.gif
HTML_DOCDIR=	${PREFIX}/share/doc/tidy
INSTALLATION_DIRS+=	${HTML_DOCDIR} ${HTML_DOCDIR}/api
PLIST_SRC+=	${PKGDIR}/PLIST.doc
.endif

pre-configure:
	cd ${WRKSRC}/build/gnuauto && cp -R -f * ${WRKSRC}
	cd ${WRKSRC} && \
		touch NEWS README AUTHORS ChangeLog; \
		libtoolize --force --copy; \
		aclocal; \
		autoconf; \
		automake -acf

post-build:
	cd ${WRKSRC}/htmldoc && \
	${WRKSRC}/console/tidy -xml-help > tidy.xml && \
	${WRKSRC}/console/tidy -xml-config > tidy-config.xml && \
	xsltproc tidy1.xsl tidy.xml > tidy.1
.if !empty(PKG_OPTIONS:Mdoc)
	cd ${WRKSRC} && \
	doxygen htmldoc/doxygen.cfg
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/htmldoc/tidy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.if !empty(PKG_OPTIONS:Mdoc)
	for doc in ${HTML_DOCFILES}; do					\
	    ${INSTALL_DATA} ${WRKSRC}/htmldoc/$$doc ${DESTDIR}${HTML_DOCDIR} ;	\
	done
	${INSTALL_DATA} ${WRKSRC}/htmldoc/api/* ${DESTDIR}${HTML_DOCDIR}/api
.endif

.include "../../mk/bsd.pkg.mk"
