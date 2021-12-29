# $NetBSD: Makefile,v 1.47 2021/12/29 13:25:47 rhialto Exp $

DISTNAME=	suite3270-4.1ga11-src
PKGNAME=	x3270-4.1ga11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=x3270/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	http://x3270.bgp.nu/
COMMENT=	3270 Terminal emulators (X11 and/or curses)
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/suite3270-4.1
USE_TOOLS+=	bdftopcf gmake

FONTS_DIRS.x11+=	${PREFIX}/share/fonts/X11/misc

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--enable-b3270
CONFIGURE_ARGS+=	--enable-pr3287
CONFIGURE_ARGS+=	--enable-s3270

INSTALL_TARGET=		install install.man

PKG_SYSCONFSUBDIR=	x3270

EGDIR=			${PREFIX}/share/examples/x3270
CONF_FILES=		${EGDIR}/ibm_hosts ${PKG_SYSCONFDIR}/ibm_hosts
INSTALLATION_DIRS+=	${EGDIR}

SUBST_CLASSES+=		share
SUBST_STAGE.share=	pre-configure
SUBST_MESSAGE.share=	Fixing /usr/share
SUBST_FILES.share=	x3270/Makefile.obj.in
SUBST_SED.share+=	-e 's;/usr/share;${PREFIX}/share;'

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/ibm_hosts ${DESTDIR}/${EGDIR}
	if [ "${PLIST.tcl}" = "yes" ]; then \
	${INSTALL_SCRIPT} ${WRKSRC}/tcl3270/Examples/* ${DESTDIR}${EGDIR}; \
	fi

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
